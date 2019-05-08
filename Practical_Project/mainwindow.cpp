#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
    database = new Database(this);
    dataWindow = new DataWindow(this, database );
    sDialog = new settingDialog(this);
    timer = new QTimer(this);
    //set tableWidgetColumnWidth
    ui->tableWidget->setColumnWidth(0, ui->tableWidget->width() * 30 / 100);
    ui->tableWidget->setColumnWidth(1, ui->tableWidget->width() * 15 / 100);
    ui->tableWidget->setColumnWidth(2, ui->tableWidget->width() * 15 / 100);
    ui->tableWidget->setColumnWidth(3, ui->tableWidget->width() * 40 / 100);
    ui->tableWidget->verticalHeader()->hide();
    //set lineEdit readOnly
    ui->dateEdit->setReadOnly(true);
    ui->productLineEdit->setReadOnly(true);
    ui->amountLineEdit->setReadOnly(true);
    ui->NGLineEdit->setReadOnly(true);
    ui->renderLabel->setStyleSheet("QLabel {font-weight:bold; font-size: 20px;background-color : yellow; color : black; }");
    ui->renderLabel->setText(QStringLiteral("    停止"));

    initNetworkConfig();
    sDialog->update_camera();
    sDialog->setProductComboBox(dataWindow->getProductIds());
    updateConfig(sDialog->getConfig());

    QList<int> count = database->getCounting( QDate::currentDate() ,config["pid"]);
    setAmount(count[0],count[1]);



    componentInfo = database->getComponentSetting(config["pid"]);
    setTableWidget();

    connect( sDialog, SIGNAL(submitConfig(QMap<QString,QString>)), this, SLOT(updateConfig( QMap<QString,QString> )));
    ui->pausePushButton->setEnabled(false);
    sDialog->show();

    connect( timer, SIGNAL(timeout()), this, SLOT(updateCurrentTime()));
    timer->start(1000);
    thread = new QThread(this);
    detector = new Detect(ui->detectView, config["dataFile"], config["configFile"], config["weightFile"],
                          0.9, 0.5, config["cameraIndex"].toInt() );
    thread = new QThread(this);
    detector->moveToThread(thread);
    connect(detector, SIGNAL(detectionSignal()), this, SLOT(updateData()));
    detector->Stop();
    connect(thread, SIGNAL(started()), detector, SLOT(process()));
    thread->start();
}

MainWindow::~MainWindow()
{
    storeNetworkConfig();
    detector->Stop();
    delete detector;
    thread->exit();
    delete ui;
}

//jump to next page
void MainWindow::on_testingPushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//back to homepage
void MainWindow::on_backToHomePagePushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//when click the settingPushButton
void MainWindow::on_settingPushButton_clicked()
{
    sDialog->update_camera();
    sDialog->setProductComboBox(dataWindow->getProductIds());
    sDialog->show();
}



void MainWindow::on_startTestingPushButton_clicked()
{
    ui->renderLabel->setStyleSheet("QLabel {font-weight:bold; font-size: 20px;background-color : #00FF00; color : black; }");
    ui->renderLabel->setText(QStringLiteral("    運行"));
    detector->Start();
    ui->startTestingPushButton->setEnabled(false);
    ui->pausePushButton->setEnabled(true);
    ui->settingPushButton->setEnabled(false);
}

void MainWindow::on_pausePushButton_clicked()
{
    ui->renderLabel->setStyleSheet("QLabel {font-weight:bold; font-size: 20px;background-color : yellow; color : black; }");
    ui->renderLabel->setText(QStringLiteral("    停止"));
    detector->Stop();
    ui->startTestingPushButton->setEnabled(true);
    ui->pausePushButton->setEnabled(false);
    ui->settingPushButton->setEnabled(true);
}

void MainWindow::updateCurrentTime()
{
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
}

void MainWindow::on_checkingPushButton_clicked()
{
    dataWindow->show();
}

void MainWindow::updateConfig( QMap<QString,QString> config )
{
    this->config = config;
    ui->productLineEdit->setText(dataWindow->getProductName(config["pid"]));
}

void MainWindow::initNetworkConfig()
{
    QFile configFile("detcfg.xml");
    if( !configFile.exists() ) {
        QMessageBox::critical(this,"Fatal Error","Not found configure file!<br>Please set configuration");
        sDialog->show();
    } else {
        if( !configFile.open(QIODevice::ReadOnly) ) {
            QMessageBox::critical(this,"Fatal Error","Can't open configure file!<br>Please set configuration");
            sDialog->show();
        } else {
            QDomDocument xml;
            xml.setContent(&configFile);
            QDomElement docElem = xml.documentElement();
            QDomNode n = docElem.firstChild();
            while(!n.isNull())
            {
               if (n.isElement())
               {
                  QDomElement e = n.toElement();
                  config.insert(e.tagName(),e.text());
                }
                  n = n.nextSibling();
            }
            sDialog->setConfig(config);
        }
        configFile.close();
    }
}

void MainWindow::storeNetworkConfig()
{
    QDomDocument doc;
    QDomProcessingInstruction instr = doc.createProcessingInstruction(
                        "xml", "version='1.0' encoding='UTF-8'");
    QDomElement detcfg = doc.createElement("detcfg");
    doc.appendChild(instr);
    doc.appendChild(detcfg);
    QMap<QString,QString>::iterator i;
    for( i = config.begin(); i != config.end() ; i++ ) {
        QDomElement key = doc.createElement(i.key());
        QDomText value = doc.createTextNode(i.value());
        key.appendChild(value);
        detcfg.appendChild(key);
    }
    QFile configFile("detcfg.xml");
    if(!configFile.open(QIODevice::WriteOnly|QIODevice::Text)) {
        QMessageBox::critical(this,"Fatal Error","Can't write configure to file!");
        return;
    }
    QTextStream out(&configFile);
    doc.save(out,4);
    configFile.close();
}

void MainWindow::setTableWidget()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(componentInfo.count());
    int count = 0;
    QMap<QString, ComponentInfo>::Iterator it;
    for( it = componentInfo.begin(); it != componentInfo.end(); it++ )
    {
        ui->tableWidget->setItem(count, 0, new QTableWidgetItem(it->getName()));
        ui->tableWidget->setItem(count, 1, new QTableWidgetItem(QString::number(it->getOrdered())));
        ui->tableWidget->setItem(count, 2, new QTableWidgetItem(QString::number(it->getProduced())));

        if( it->getErrorStatus().empty() && it->getOrdered() == it->getProduced()  ) {
            ui->tableWidget->setItem(count, 3, new QTableWidgetItem(QStringLiteral("良好")));
            ui->tableWidget->item(count, 0)->setBackgroundColor(Qt::white);
            ui->tableWidget->item(count, 1)->setBackgroundColor(Qt::white);
            ui->tableWidget->item(count, 2)->setBackgroundColor(Qt::white);
            ui->tableWidget->item(count, 3)->setBackgroundColor(Qt::white);
        }

        if( it->getOrdered() != it->getProduced() || !it->getErrorStatus().empty()  ) {
            NGQuantity++;
            if( it->getOrdered() != it->getProduced() && !it->getErrorStatus().empty() ) {
                ui->tableWidget->setItem(count, 3, new QTableWidgetItem(QStringLiteral("缺項且有缺陷")));
            } else if( it->getOrdered() != it->getProduced() ) {
                ui->tableWidget->setItem(count, 3, new QTableWidgetItem(QStringLiteral("缺項")));
            } else {
                ui->tableWidget->setItem(count, 3, new QTableWidgetItem(QStringLiteral("缺陷")));
            }

            ui->tableWidget->item(count, 0)->setBackgroundColor(Qt::red);
            ui->tableWidget->item(count, 1)->setBackgroundColor(Qt::red);
            ui->tableWidget->item(count, 2)->setBackgroundColor(Qt::red);
            ui->tableWidget->item(count, 3)->setBackgroundColor(Qt::red);
        }
        count++;
    }
}

void MainWindow::setAmount( int produced, int NG ) {
    productQuantity = produced;
    NGQuantity = NG;
    ui->amountLineEdit->setText(QString::number(productQuantity));
    ui->NGLineEdit->setText(QString::number(NGQuantity));
}

void MainWindow::updateAmount()
{
    ui->amountLineEdit->setText(QString::number(productQuantity));
    ui->NGLineEdit->setText(QString::number(NGQuantity));
}

void MainWindow::dataProcessing( QList<Component> components )
{
    QMap<QString, ComponentInfo>::Iterator it;
    for( it = componentInfo.begin(); it != componentInfo.end(); it++ )
    {
        it->initInfo();
    }

    QList<Component>::Iterator listIt;
    for( listIt = components.begin(); listIt != components.end(); listIt++ )
    {
        if( componentInfo.contains(listIt->getName()))
        {
            ComponentInfo temp = componentInfo[listIt->getName()];
            temp.increasePQ();
            componentInfo[listIt->getName()] = temp;
        }
    }
}

void MainWindow::updateData() {
    productQuantity++;
    dataProcessing( detector->getComponents() );
    setTableWidget();
    updateAmount();
}

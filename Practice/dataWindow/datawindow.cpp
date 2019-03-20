#include "datawindow.h"
#include "ui_datawindow.h"

DataWindow::DataWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Not connect to database!");
    ui->statusBar->setStyleSheet("background-color: rgb(255, 0, 0);");
    setDialog = new DatabaseSetDialog(this);
    database = new Database(this);
    product = new QStringListModel(this);

    initDBConfig();
    connectDB();

    updateTimer = new QTimer();
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->currentTimeEdit->setDateTime(QDateTime::currentDateTime());
    connect( setDialog, SIGNAL(configSignal()),this,SLOT(setDBconfig()));
    connect( updateTimer, SIGNAL(timeout()), this, SLOT(updateCurrentTime()));
    updateTimer->start(1000);
    ui->startDateEdit->setDate(QDate::currentDate());
    ui->endDateEdit->setDate(QDate::currentDate());
    ui->startTimeEdit->setTime( QTime(00,00,00));
    ui->endTimeEdit->setTime( QTime(23,59,59));
}

DataWindow::~DataWindow()
{
    storeDBConfig();
    delete ui;
}

void DataWindow::resizeEvent(QResizeEvent *event)
{
    ui->tableView->setColumnWidth(0, 26 * ui->tableView->width()/100);
    ui->tableView->setColumnWidth(1, 10 * ui->tableView->width()/100);
    ui->tableView->setColumnWidth(2, 20 * ui->tableView->width()/100);
    ui->tableView->setColumnWidth(3, 30 * ui->tableView->width()/100);
    ui->tableView->setColumnWidth(4, 5 * ui->tableView->width()/100);
    QMainWindow::resizeEvent(event);
}

void DataWindow::updateCurrentTime() {
    ui->currentTimeEdit->setDateTime(QDateTime::currentDateTime());
}

void DataWindow::on_actionabout_triggered()
{
    QMessageBox::about(this,QStringLiteral("關於"),QStringLiteral("此頁面用於顯示數據與圖表"));
}

void DataWindow::on_startDateEdit_userDateChanged(const QDate &date)
{
    if( date > ui->endDateEdit->date() )
        ui->startDateEdit->setDate( ui->endDateEdit->date() );
}

void DataWindow::on_endDateEdit_userDateChanged(const QDate &date)
{
    if( date < ui->startDateEdit->date() )
        ui->endDateEdit->setDate( ui->startDateEdit->date());
}

void DataWindow::on_startTimeEdit_userTimeChanged(const QTime &time)
{
    if( time < ui->startTimeEdit->time() )
        ui->endTimeEdit->setTime( QTime(00,00,00));
}

void DataWindow::on_endTimeEdit_userTimeChanged(const QTime &time)
{
    if( time < ui->startTimeEdit->time() )
        ui->endTimeEdit->setTime( QTime(23,59,59) );
}

void DataWindow::on_actionset_triggered()
{
    setDialog->show();
}

void DataWindow::initDBConfig()
{
    QFile configFile("dbcfg.xml");
    if( !configFile.exists() ) {
        QMessageBox::critical(this,"Fatal Error","Not found configure file!<br>Please set configuration");
        setDialog->show();
    } else {
        if( !configFile.open(QIODevice::ReadOnly) ) {
            QMessageBox::critical(this,"Fatal Error","Can't open configure file!<br>Please set configuration");
            setDialog->show();
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
            setDialog->setConfig(config);
        }
        configFile.close();
    }
}

void DataWindow::storeDBConfig()
{
    QDomDocument doc;
    QDomProcessingInstruction instr = doc.createProcessingInstruction(
                        "xml", "version='1.0' encoding='UTF-8'");
    QDomElement dbcfg = doc.createElement("dbcfg");
    doc.appendChild(instr);
    doc.appendChild(dbcfg);
    QMap<QString,QString>::iterator i;
    for( i = config.begin(); i != config.end() ; i++ ) {
        QDomElement key = doc.createElement(i.key());
        QDomText value = doc.createTextNode(i.value());
        key.appendChild(value);
        dbcfg.appendChild(key);
    }
    QFile configFile("dbcfg.xml");
    if(!configFile.open(QIODevice::WriteOnly|QIODevice::Text)) {
        QMessageBox::critical(this,"Fatal Error","Can't write configure to file!");
        return;
    }
    QTextStream out(&configFile);
    doc.save(out,4);
    configFile.close();
}

void DataWindow::setDBconfig()
{
    config = setDialog->getConfig();
    connectDB();
}

void DataWindow::connectDB()
{
    if( database->connectDB( config ) ) {
        ui->statusBar->showMessage("MySQL Host: " + config["host"] + "    "
                + "Database: " + config["database"] +
                "    User: " + config["user"],0);
        ui->statusBar->setStyleSheet("background-color: rgb(0, 255, 0);");
    } else {
        ui->statusBar->showMessage("Not connect to database!",0);
        ui->statusBar->setStyleSheet("background-color: rgb(255, 0, 0);");
    }

    product->setStringList(database->getProduct());
    ui->comboBox->setModel(product);
    ui->comboBox->setCurrentIndex(0);


    ui->tableView->setModel(database->getProductDataModel());
    ui->tableView->setColumnWidth(0, 26 * ui->tableView->width()/100);
    ui->tableView->setColumnWidth(1, 10 * ui->tableView->width()/100);
    ui->tableView->setColumnWidth(2, 20 * ui->tableView->width()/100);
    ui->tableView->setColumnWidth(3, 30 * ui->tableView->width()/100);
    ui->tableView->setColumnWidth(4, 5 * ui->tableView->width()/100);
}

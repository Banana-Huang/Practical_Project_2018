#include "datawindow.h"
#include "ui_datawindow.h"
#include <QPixmap>

DataWindow::DataWindow(QWidget *parent,Database *db ) :
    QMainWindow(parent),
    ui(new Ui::DataWindow)
{
    ui->setupUi(this);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->statusBar->showMessage("Not connect to database!");
    ui->statusBar->setStyleSheet("background-color: rgb(255, 0, 0);");
    setDialog = new DatabaseSetDialog(this);
    if( db == nullptr)
        database = new Database(this);
    else
        database = db;
    defectWindow = new DefectWindow(this);
    product = new QStringListModel(this);

    initDBConfig();
    connectDB();
    ui->startDateTimeEdit->setDate(QDate::currentDate());
    ui->endDateTimeEdit->setDate(QDate::currentDate());
    ui->startDateTimeEdit->setTime(QTime(0,0,0));
    ui->endDateTimeEdit->setTime(QTime(23,59,59));
    updateTimer = new QTimer();
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->currentTimeEdit->setDateTime(QDateTime::currentDateTime());
    connect( setDialog, SIGNAL(configSignal()),this,SLOT(setDBconfig()));
    connect( updateTimer, SIGNAL(timeout()), this, SLOT(updateCurrentTime()));
    updateTimer->start(1000);
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

        product->setStringList(database->getProduct());
        ui->comboBox->setModel(product);
        ui->comboBox->setCurrentIndex(0);


        ui->tableView->setModel(database->getProductDataModel());
        ui->tableView->setColumnWidth(0, 26 * ui->tableView->width()/100);
        ui->tableView->setColumnWidth(1, 10 * ui->tableView->width()/100);
        ui->tableView->setColumnWidth(2, 20 * ui->tableView->width()/100);
        ui->tableView->setColumnWidth(3, 30 * ui->tableView->width()/100);
        ui->tableView->setColumnWidth(4, 5 * ui->tableView->width()/100);

        connect( ui->tableView->selectionModel(), SIGNAL(currentRowChanged( const QModelIndex&, const QModelIndex& )),
                 this, SLOT(setStuffData(QModelIndex)) );
    } else {
        ui->tableView->setModel(database->getProductDataModel());
        ui->tableView->setColumnWidth(0, 26 * ui->tableView->width()/100);
        ui->tableView->setColumnWidth(1, 10 * ui->tableView->width()/100);
        ui->tableView->setColumnWidth(2, 20 * ui->tableView->width()/100);
        ui->tableView->setColumnWidth(3, 30 * ui->tableView->width()/100);
        ui->tableView->setColumnWidth(4, 5 * ui->tableView->width()/100);
        ui->statusBar->showMessage("Not connect to database!",0);
        ui->statusBar->setStyleSheet("background-color: rgb(255, 0, 0);");
        disconnect( ui->tableView->selectionModel(), SIGNAL(currentRowChanged( const QModelIndex&, const QModelIndex& )),
                 this, SLOT(setStuffData(QModelIndex)) );
    }

}

QString DataWindow::getStatusRadioButton()
{
    if( ui->goodRadioButton->isChecked() ) {
        return ui->goodRadioButton->text();
    } else if ( ui->defectRadioButton->isChecked() ) {
        return ui->defectRadioButton->text();
    } else {
        return ui->allRadioButton->text();
    }
}

void DataWindow::on_startDateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    if( ui->startDateTimeEdit->dateTime() > ui->endDateTimeEdit->dateTime() ) {
        ui->startDateTimeEdit->setDateTime( ui->endDateTimeEdit->dateTime() );
    }
    database->setCondiction( ui->comboBox->currentText(), ui->startDateTimeEdit->dateTime(), ui->endDateTimeEdit->dateTime(), getStatusRadioButton());
}

void DataWindow::on_endDateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    if( ui->endDateTimeEdit->dateTime() < ui->startDateTimeEdit->dateTime() ) {
        ui->endDateTimeEdit->setDateTime( ui->startDateTimeEdit->dateTime() );
    }
    database->setCondiction( ui->comboBox->currentText(), ui->startDateTimeEdit->dateTime(), ui->endDateTimeEdit->dateTime(), getStatusRadioButton());
}

void DataWindow::on_allRadioButton_clicked()
{
    database->setCondiction( ui->comboBox->currentText(), ui->startDateTimeEdit->dateTime(), ui->endDateTimeEdit->dateTime(), getStatusRadioButton());
}

void DataWindow::on_goodRadioButton_clicked()
{
    database->setCondiction( ui->comboBox->currentText(), ui->startDateTimeEdit->dateTime(), ui->endDateTimeEdit->dateTime(), getStatusRadioButton());
}

void DataWindow::on_defectRadioButton_clicked()
{
    database->setCondiction( ui->comboBox->currentText(), ui->startDateTimeEdit->dateTime(), ui->endDateTimeEdit->dateTime(), getStatusRadioButton());
}

void DataWindow::setStuffData(QModelIndex index)
{
    QSqlRecord record = database->getRecord(index);
    ui->imageLineEdit->setText(record.value("image").toString());
    ui->imageLineEdit->setReadOnly(true);
    QPixmap image( "assembly_line/" + record.value("pid").toString() + "/" + record.value("image").toString() );
    if( image.isNull() ) {
        image.load("noimage.jpg");
    }
    image = image.scaled(200,ui->pictureView->height());
    ui->pictureView->setPixmap(image);

    ui->sidLineEdit->setText(record.value("sid").toString());
    ui->sidLineEdit->setReadOnly(true);
    ui->pidComboBox->setModel(product);
    ui->pidComboBox->setEditText(record.value("pid").toString());
    ui->productNameLineEdit->setText(database->getProductName(record.value("pid").toString()));
    ui->productNameLineEdit->setReadOnly(true);

    ui->stuffProductTime->setDateTime(record.value("product_time").toDateTime());

    if( record.value("status").toInt() )
    {
        ui->statusPushButton->setText(QStringLiteral("良好"));
        ui->statusPushButton->setStyleSheet("background-color: rgb(0, 255, 0); font-weight: bold;");
    } else {
        ui->statusPushButton->setText(QStringLiteral("缺陷"));
        ui->statusPushButton->setStyleSheet("background-color: rgb(255, 0, 0); font-weight: bold;");
    }
}

void DataWindow::on_imageChoser_clicked()
{
    QString filter("assembly_line/" + ui->pidComboBox->currentText());
    QString path(QFileDialog::getOpenFileName(this,QStringLiteral("選擇圖片"),filter,tr("Images (*.png *.bmp *.jpg)")));
    if( !path.isNull()) {
        QUrl url(path);
        ui->imageLineEdit->setText(url.fileName());
    }
}

void DataWindow::on_statusPushButton_clicked()
{
    if( database->isConnect() ) {
        if( ui->statusPushButton->text() == QStringLiteral("良好") )
            defectWindow->setStatus(1,nullptr);
        else
            defectWindow->setStatus(0,database->getProductError(ui->comboBox->currentText()));
        defectWindow->exec();
    } else
        QMessageBox::critical(this,"Fatal Error","Databases doesn't connect!");

}

QStringListModel* DataWindow::getProductIds()
{
    return product;
}

QString DataWindow::getProductName( QString pid )
{
    return database->getProductName(pid);
}

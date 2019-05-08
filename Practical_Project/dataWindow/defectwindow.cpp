#include "defectwindow.h"

DefectWindow::DefectWindow( QWidget* parent )
    :QDialog(parent)
{
    setWindowTitle("Select defect detail");
    setGeometry( parent->width()/2 + parent->x(),
                 parent->height()/2 + parent->y(),
                 600, 600 );
    radioButtonLayout = new QHBoxLayout();
    pushButtonLayout = new QHBoxLayout();
    vLayout = new QVBoxLayout( this );

    goodRadioButton = new QRadioButton( "Good", this );
    defectRadioButton = new QRadioButton( "Defect", this );
    buttonGroup = new QButtonGroup( this );
    buttonGroup->addButton(goodRadioButton);
    buttonGroup->addButton(defectRadioButton);

    tableView = new QTableView( this );
    submitButton = new QPushButton( "Submit", this );
    cancelButton =  new QPushButton( "Cancel", this );

    radioButtonLayout->addWidget( goodRadioButton );
    radioButtonLayout->addWidget( defectRadioButton );
    pushButtonLayout->addWidget(submitButton);
    pushButtonLayout->addWidget(cancelButton);

    vLayout->addLayout(radioButtonLayout);
    vLayout->addWidget(tableView);
    vLayout->addLayout(pushButtonLayout);
}

void DefectWindow::setStatus(int status, QSqlQueryModel *model )
{
    if( status ) {
        goodRadioButton->setChecked(true);
        tableView->setModel(nullptr);
    } else {
        defectRadioButton->setChecked(true);
        tableView->setModel(model);
    }
}



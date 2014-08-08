#include "dialogdepartmentboss.h"
#include "ui_dialogdepartmentboss.h"

DialogDepartmentboss::DialogDepartmentboss(QWidget *parent, QList<Socio *> partners) :
    QDialog(parent),
    ui(new Ui::DialogDepartmentboss)
{
    ui->setupUi(this);

    //cargamos los jefes de departamentos del fichero partners.ptr
    QString filein;
    int npartners=partners.size();
    int ndb=-1;
    for (int i=0; i<npartners;i++){
        if(partners[i]->getDepartmentBoss() == '1'){
            ndb ++;
            ui->partnerview->setRowCount(ndb+1);
            QTableWidgetItem * item = new QTableWidgetItem(partners[i]->getName());
            QTableWidgetItem * item_ = new QTableWidgetItem(partners[i]->getPhone());
            QTableWidgetItem * item__ = new QTableWidgetItem(partners[i]->getDepartment());

            ui->partnerview->setItem(ndb, 0, item);
            ui->partnerview->setItem(ndb, 1, item_);
            ui->partnerview->setItem(ndb, 2, item__);
        }
    }
}

DialogDepartmentboss::~DialogDepartmentboss()
{
    delete ui;
}

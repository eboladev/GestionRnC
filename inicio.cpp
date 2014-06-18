#include "inicio.h"
#include "ui_inicio.h"

Inicio::Inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Inicio){
    ui->setupUi(this);
    npartners_ = -1;

}

Inicio::~Inicio()
{
    delete ui;
    if(events_)
        delete events_;
}

void Inicio::on_btnaddpartner_clicked()
{
    Dialog_newpartner * new_partner=new Dialog_newpartner (this);
    connect(new_partner, SIGNAL(new_partner(Socio*)), this, SLOT(addingpartner(Socio*)));
    new_partner->exec();
}

void Inicio::addingpartner(Socio *nuevo_socio){
    partners_.append(nuevo_socio);
    npartners_++;
//    info.append();
  //  info.append(nuevo_socio->getName());
    //info.append(nuevo_socio->getWork());
    //ui->partnerview->addItems(info);
    ui->partnerview->setRowCount(npartners_+1);
    QTableWidgetItem * item = new QTableWidgetItem(nuevo_socio->getWork());
    if(item->text() == "AUX")
        item->setBackgroundColor(QColor(255,175,0));//ponemos de color naranja los AUX
    else if(item->text() == "WBR")
        item->setBackgroundColor(QColor(128,255,0));//ponemos de color naranja los AUX
    else if(item->text() == "MIXER")
        item->setBackgroundColor(QColor(0,179,255));//ponemos de color naranja los AUX
    QTableWidgetItem * item_ = new QTableWidgetItem(nuevo_socio->getName());
    QTableWidgetItem * item__ = new QTableWidgetItem(nuevo_socio->getAKA());

    ui->partnerview->setItem(npartners_, 0, item);
    ui->partnerview->setItem(npartners_, 2, item_);
    ui->partnerview->setItem(npartners_, 1, item__);

}

void Inicio::on_btndelpartner_clicked()
{
    int row= ui->partnerview->currentRow();
    if(npartners_>=row && !partners_.isEmpty()){
        if(QMessageBox::warning(this, "¿Está seguro?", "Está seguro que quiere elminar el siguiente socio:\n"
                                +partners_[row]->getName(),QMessageBox::Ok,QMessageBox::Cancel) == QMessageBox::Ok){
            ui->partnerview->setItem(row, 0, NULL);
            ui->partnerview->setItem(row, 1, NULL);
            ui->partnerview->setItem(row, 2, NULL);
            ui->partnerview->removeRow(row);
            delete partners_[row];
            npartners_ --;
        }
    }
}

void Inicio::on_btnmodpartner_clicked()
{
    int row = ui->partnerview->currentRow();
    //partners_[row]
    ui->partnerview->setItem(row, 0, NULL);
    ui->partnerview->setItem(row, 1, NULL);
    ui->partnerview->setItem(row, 2, NULL);
    Dialog_newpartner * new_partner=new Dialog_newpartner (this);
    connect(new_partner, SIGNAL(new_partner(Socio*)), this, SLOT(addingpartner(Socio*)));
    new_partner->exec();
}

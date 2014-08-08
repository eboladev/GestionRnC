#include "dialogsearchpartner.h"
#include "ui_dialogsearchpartner.h"

DialogSearchPartner::DialogSearchPartner(QWidget *parent, QList<Socio*> partners) :
    QDialog(parent),
    ui(new Ui::DialogSearchPartner)
{
    ui->setupUi(this);
    partners_+= partners;
}

DialogSearchPartner::~DialogSearchPartner()
{
    delete ui;
}

void DialogSearchPartner::on_btnsearch_clicked()
{
    QString dnisearching = ui->dni_to_search->text();
    int npartners = partners_.count();
    bool found =false;
    int i=0;
    while(!found){
        if(i >npartners){
            QMessageBox::information(this,"Error","No se ha encontrado socio con dni\n"+dnisearching);
            return;
        }
        else{
            if(partners_[i]->getDNI()==dnisearching)
                found = true;
            else if(partners_[i]->getDNI()!=dnisearching){
                found = false;
                i++;
            }
        }
    }
    ui->textname->setText(ui->textname->text()+" "+partners_[i]->getName());
    ui->texaka->setText(ui->texaka->text()+" "+partners_[i]->getAKA());
    ui->textname->setText(ui->textname->text()+" "+partners_[i]->getName());
    ui->textname->setText(ui->textname->text()+" "+partners_[i]->getName());
    ui->textname->setText(ui->textname->text()+" "+partners_[i]->getName());
    ui->textname->setText(ui->textname->text()+" "+partners_[i]->getName());
    ui->textname->setText(ui->textname->text()+" "+partners_[i]->getName());
    ui->textname->setText(ui->textname->text()+" "+partners_[i]->getName());
    ui->textname->setText(ui->textname->text()+" "+partners_[i]->getName());
    ui->textname->setText(ui->textname->text()+" "+partners_[i]->getName());
}

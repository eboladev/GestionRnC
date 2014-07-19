#include "inicio.h"
#include "ui_inicio.h"

Inicio::Inicio(QWidget *parent) :
    QMainWindow(parent),
    partners_file_(NULL),
    ui(new Ui::Inicio){
    ui->setupUi(this);
    npartners_ = -1;

    /*//buscamos los partners en el sistema para añadirlos
    partners_file_ = new QFile ("partners.ptr",this);
    if(partners_file_->open(1,QIODevice::Text|QIODevice::ReadOnly)){
        if(partners_file_->isReadable()){
            //se crea el socio y se ponen los datos correspondientes
            while(partners_file_->atEnd()){
                Socio newp;
                //se lee la línea
                QString atribute;
                char *c;
                while (true){///leemos el NAME del socio
                    partners_file_->getChar(c);
                    if (*c != ':')
                        atribute.append(c);
                    else
                        break;
                }
                newp.setName(atribute);

                atribute.clear();
                while (true){///leemos el AKA del socio
                    partners_file_->getChar(c);
                    if (*c != ':')
                        atribute.append(c);
                    else
                        break;
                }
                newp.setAKA(atribute);

                atribute.clear();
                while (true){///leemos el DNI del socio
                    partners_file_->getChar(c);
                    if (*c != ':')
                        atribute.append(c);
                    else
                        break;
                }
                newp.setDNI(atribute);

                atribute.clear();
                while (true){///leemos el WORK del socio
                    partners_file_->getChar(c);
                    if (*c != ':')
                        atribute.append(c);
                    else
                        break;
                }
                newp.setWork(atribute);
            }
        }
    }
    else{///error abriendo fichero
        QMessageBox::warning(this,"Error", "Se ha producido un error al abrir el fichero de socios\n"
                             +partners_file_->errorString()
                             +"\n*Pruebe a borrarlo y crear otro, aveces funciona",QMessageBox::Ok);
    }*/
}

Inicio::~Inicio(){
    delete ui;
    if(events_)
        delete events_;
    if(partners_file_)
        delete partners_file_;
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
    //info.append();
    //info.append(nuevo_socio->getName());
    //info.append(nuevo_socio->getWork());
    //ui->partnerview->addItems(info);
    ui->partnerview->setRowCount(npartners_+1);
    QTableWidgetItem * item = new QTableWidgetItem(nuevo_socio->getWork());
    if(item->text() == "AUX")
        item->setBackgroundColor(QColor(255,175,0));//ponemos de color naranja los AUX
    else if(item->text() == "WBR")
        item->setBackgroundColor(QColor(128,255,0));//ponemos de color  los WBR
    else if(item->text() == "MIXER")
        item->setBackgroundColor(QColor(0,179,255));//ponemos de color  los MIXER
    QTableWidgetItem * item_ = new QTableWidgetItem(nuevo_socio->getName());
    QTableWidgetItem * item__ = new QTableWidgetItem(nuevo_socio->getAKA());

    ui->partnerview->setItem(npartners_, 0, item);
    ui->partnerview->setItem(npartners_, 2, item_);
    ui->partnerview->setItem(npartners_, 1, item__);

    //Una vez creado en el programa, lo guardamos al fichero de socios "partner.ptr"
    QString filein;
    if(partners_file_)
        delete partners_file_;
    partners_file_ = new QFile("partners.ptr",this);
    if(partners_file_->open(QIODevice::WriteOnly)){
        filein = nuevo_socio->getName()+':'
                +nuevo_socio->getAKA()+':'
                +nuevo_socio->getDNI()+':'
                +nuevo_socio->getWork();
        QByteArray bytestowrite= filein.toUtf8();
        int bytes = partners_file_->write(bytestowrite);
        if (bytes <= 0){
            QMessageBox::warning(this,"Error", "Se ha producido un error al abrir el fichero de socios\n"
                                 +partners_file_->errorString()
                                 +"\n*El nuevo socio no se ha guardado",QMessageBox::Ok);
        }
        partners_file_->close();
    }
    else{
        QMessageBox::warning(this,"Error", "Se ha producido un error al abrir el fichero de socios\n"
                             +partners_file_->errorString()
                             +"\n*El nuevo socio no se ha guardado",QMessageBox::Ok);
    }
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

void Inicio::on_btnsearchpartner_clicked()
{

}

void Inicio::on_btnviewboss_clicked()
{

}

#include "inicio.h"
#include "ui_inicio.h"

Inicio::Inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Inicio){
    ui->setupUi(this);
    npartners_ = -1;

    //buscamos los partners en el sistema para añadirlos
    partners_file_ = new QFile ("partners.ptr",this);
    if(partners_file_->open(QIODevice::ReadOnly)){
        //se crea el socio y se ponen los datos correspondientes
        while(!partners_file_->atEnd()){
            Socio *newp = new Socio;
            //se lee la línea
            QString line;
            QString atribute;
            line =partners_file_->readLine();
            ///segun formato extraemos los diferentes campos del partner
            atribute = line.section(":",0,0);//NAME
            newp->setName(atribute);
            atribute = line.section(":",1,1);//AKA
            newp->setAKA(atribute);
            atribute = line.section(":",2,2);//DNI
            newp->setDNI(atribute);
            atribute = line.section(":",3,3);//WORK
            newp->setWork(atribute);
            atribute = line.section(":",4,4);//CONTACT
            newp->setPhone(atribute);
            atribute = line.section(":",5,5);//DEPARTMENT
            newp->setDepartment(atribute);
            atribute = line.section(":",6,6);//GROUP
            newp->setGroup(atribute);
            addingpartner(newp);
        }
    }
    partners_file_->close();
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
    partners_.last()->setIDpartner(npartners_);

    ui->partnerview->setRowCount(npartners_+1);
    //QTableWidgetItem * item = new QTableWidgetItem(npartners_);
    QTableWidgetItem * item_ = new QTableWidgetItem(nuevo_socio->getWork());
    QTableWidgetItem * item__ = new QTableWidgetItem(nuevo_socio->getName());
    QTableWidgetItem * item___= new QTableWidgetItem(nuevo_socio->getPhone());

    //ui->partnerview->setItem(npartners_, 0, item);
    ui->partnerview->setItem(npartners_, 0, item__);
    ui->partnerview->setItem(npartners_, 1, item___);
    ui->partnerview->setItem(npartners_, 3, item_);

    //Una vez creado en el programa, lo guardamos al fichero de socios "partner.ptr"
    QString filein;
    if(partners_file_->open(QIODevice::ReadWrite)){
        partners_file_->readAll();
        if(npartners_>=1)
            filein += '\n';
        filein += nuevo_socio->getName()+':'
                +nuevo_socio->getAKA()+':'
                +nuevo_socio->getDNI()+':'
                +nuevo_socio->getWork();
        QByteArray bytestowrite= filein.toUtf8();
        int bytes = partners_file_->write(bytestowrite);
        partners_file_->close();
    }
}

void Inicio::on_btndelpartner_clicked()
{
    int row= ui->partnerview->currentRow();
    QString DNItodel;
    QString newtext;
    if(npartners_>=row && !partners_.isEmpty()){
        DNItodel= partners_[row]->getDNI();
        if(QMessageBox::warning(this, "¿Está seguro?", "Está seguro que quiere elminar el siguiente socio:\n"
                                +partners_[row]->getName(),QMessageBox::Ok,QMessageBox::Cancel) == QMessageBox::Ok){
            ui->partnerview->setItem(row, 0, NULL);
            ui->partnerview->setItem(row, 1, NULL);
            ui->partnerview->setItem(row, 2, NULL);
            ui->partnerview->removeRow(row);
            delete partners_[row];
            npartners_ --;
            //ahora hay que quitarlo del fichero partners.ptr
            partners_file_->open(QIODevice::ReadWrite);
            while (!partners_file_->atEnd()){
                QString line = partners_file_->readLine();
                if(line.section(":",2,2).compare(DNItodel))
                    newtext += line;
            }
            partners_file_->flush();
            partners_file_->write(newtext.toUtf8());
            partners_file_->close();
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

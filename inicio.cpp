#include "inicio.h"
#include "ui_inicio.h"

Inicio::Inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Inicio){
    ui->setupUi(this);
    npartners_ = -1;

    ui->totaltext->setText("" +  char(cuenta_.getTotal()));

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
            atribute = line.section(":",7,7);//MAIL
            newp->setMail(atribute);
            atribute = line.section(":",8,8);//DEPARTMENTBOSS
            newp->setDepartmentBoss(atribute.toInt());

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
    QTableWidgetItem * item = new QTableWidgetItem(nuevo_socio->getDepartment());
    QTableWidgetItem * item_ = new QTableWidgetItem(nuevo_socio->getWork());
    QTableWidgetItem * item__ = new QTableWidgetItem(nuevo_socio->getName());
    QTableWidgetItem * item___= new QTableWidgetItem(nuevo_socio->getPhone());

    ui->partnerview->setItem(npartners_, 0, item__);
    ui->partnerview->setItem(npartners_, 1, item___);
    ui->partnerview->setItem(npartners_, 2, item);
    ui->partnerview->setItem(npartners_, 3, item_);

    //Una vez creado en el programa, lo guardamos al fichero de socios "partner.ptr"
    QString filein;
    if(partners_file_->open(QIODevice::ReadWrite)){
        partners_file_->readAll();
        filein += nuevo_socio->getName()+':'
                +nuevo_socio->getAKA()+':'
                +nuevo_socio->getDNI()+':'
                +nuevo_socio->getWork()+':'
                +nuevo_socio->getPhone()+':'
                +nuevo_socio->getDepartment()+':'
                +nuevo_socio->getGroup()+':'
                +nuevo_socio->getMail()+':'
                +nuevo_socio->getDepartmentBoss();
        filein += '\n';
        partners_file_->write(filein.toUtf8());
        partners_file_->close();
    }
}

void Inicio::on_btndelpartner_clicked()
{
    int row= ui->partnerview->currentRow();
    QString DNItodel;
    if((npartners_>=row) && (!partners_.isEmpty())){
        DNItodel= partners_[row]->getDNI();
        if(QMessageBox::warning(this, "¿Está seguro?", "Está seguro que quiere elminar el siguiente socio:\n"
                                +partners_[row]->getName(),QMessageBox::Ok,QMessageBox::Cancel) == QMessageBox::Ok){
            ui->partnerview->setItem(row, 0, NULL);
            ui->partnerview->setItem(row, 1, NULL);
            ui->partnerview->setItem(row, 2, NULL);
            ui->partnerview->setItem(row, 3, NULL);
            ui->partnerview->removeRow(row);
            partners_.removeAt(row);
            npartners_ --;

            //ahora hay que quitarlo del fichero partners.ptr
            int i= npartners_;
            QString filein("");
            while (i >= 0){//generamos el texto con los nuevos socios para luego escribirlo
                filein += partners_[i]->getName()+':'
                        +partners_[i]->getAKA()+':'
                        +partners_[i]->getDNI()+':'
                        +partners_[i]->getWork()+':'
                        +partners_[i]->getPhone()+':'
                        +partners_[i]->getDepartment()+':'
                        +partners_[i]->getGroup()+':'
                        +partners_[i]->getMail()+':';
                        +partners_[i]->getDepartmentBoss();
                filein +='\n';
                i--;
            }
            partners_file_->remove();
            partners_file_->open(QIODevice::ReadWrite);
            partners_file_->write(filein.toUtf8());
            partners_file_->close();
        }
    }
}

void Inicio::on_btnsearchpartner_clicked(){
    DialogSearchPartner *dialog= new DialogSearchPartner(this, partners_);
    dialog->exec();
}

void Inicio::on_btnviewboss_clicked(){
    DialogDepartmentboss *dialog= new DialogDepartmentboss(this, partners_);
    dialog->exec();
}

void Inicio::on_btnextract_clicked()
{

    double amounttodraw = ui->amounttext->text().toDouble();
    cuenta_.draw(amounttodraw);
    double total = cuenta_.getTotal();
    ui->totaltext->clear();
    ui->totaltext->setText(""+char(total));
}

void Inicio::on_btningress_clicked()
{
    double amounttoingress = ui->amounttext->text().toDouble();
    cuenta_.ingress(amounttoingress);
    double total = cuenta_.getTotal();
    ui->totaltext->clear();
    ui->totaltext->setText(""+char(total));
}

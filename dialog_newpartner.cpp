#include "dialog_newpartner.h"
#include "ui_dialog_newpartner.h"

Dialog_newpartner::Dialog_newpartner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_newpartner)
{
    ui->setupUi(this);
}

Dialog_newpartner::~Dialog_newpartner()
{
    delete ui;
}

void Dialog_newpartner::on_buttonBox_accepted()
{
    //Primero comprobamos cierta veracidad en los campos para que los valores no sean erróneos
    QString dni = ui->dnitext->text();
    QString phone = ui->phonetext->text();
    bool errores=false;
    if(ui->nametext->text().isEmpty()){
        QMessageBox::information(this,"Error","No puede dejar el campo Nombre en blanco.");errores = true;return;}
    if(dni.isEmpty()){
        QMessageBox::information(this,"Error","No puede dejar el campo DNI en blanco");errores = true;return;}
    else if(dni.size()!=9){
        QMessageBox::information(this,"Error","El campo DNI debe tener 9 dígitos");errores = true;return;}
    if(ui->worktext->text().isEmpty()){
        QMessageBox::information(this,"Error","No puede dejar el campo Ocupación en blanco");errores = true;return;}
    else if((ui->worktext->text() != "AUX") &&
            (ui->worktext->text() != "WBR") &&
            (ui->worktext->text() != "MIXER")){
        QMessageBox::information(this,"Error","El campo Ocupación debe tener uno de estos valores:\nAUX\tWBR\tMIXER");errores = true;}
    if(ui->departmentext->text().isEmpty()){
        QMessageBox::information(this,"Error","No puede dejar el campo Departamento en blanco");errores = true;return;}
    else if((ui->departmentext->text() != "Administracion") &&
            (ui->departmentext->text() != "Audio") &&
            (ui->departmentext->text() != "Imagen")){
        QMessageBox::information(this,"Error","El campo Ocupación debe tener uno de estos valores:\nAdministracion\tAudio\tImagen");errores = true;}
    ////SI NO HAY ERRORES EN LOS DATOS INTRODUCIDOS, LOS GUARDAMOS COMO UN NUEVO SOCIO
    if (!errores){
        //guardamos el nuevo socio en la base de datos
        Socio *partner = new Socio;
        //partner->setAge(ui->);
        partner->setDNI(ui->dnitext->text());
        partner->setAKA(ui->akatext->text());
        partner->setName(ui->nametext->text());
        partner->setWork(ui->worktext->text());
        partner->setDepartment(ui->departmentext->text());
        partner->setPhone(ui->phonetext->text());
        partner->setMail(ui->mailtext->text());
        partner->setDepartmentBoss(ui->checkdepartmentboss->isChecked());

        emit new_partner(partner);
    }
}

//Socio* Dialog_newpartner::new_partner(Socio* partner){
//    return partner;
//}

#include "socio.h"

Socio::Socio():
    debts_(NULL){
}
QString Socio::getName(){
    return name_;
}
QString Socio::getAKA(){
    return aka_;
}
QString Socio::getDNI(){
    return dni_;
}
QString Socio::getWork(){
    return work_;
}
Deuda * Socio::getAllDebts(){
    return debts_;
}

void Socio::setAKA(QString aka){
    aka_=aka;
}

void Socio::setDNI(QString dni){
    dni_=dni;
}

void Socio::setName(QString name){
    name_=name;
}

void Socio::setWork(QString work){
    work_=work;
}

void Socio::setIDpartner(short int id){
    idpartner_ = id;
}

quint32 Socio::getIDpartner(){
    return idpartner_;
}

void Socio::setDepartment(QString department){
    department_ = department;
}

QString Socio::getDepartment(){
    return department_;
}


void Socio::setPhone(QString phone){
    phone_=phone;
}

QString Socio::getPhone(){
    return phone_;
}

void Socio::setGroup(QString group){
    group_ = group;
}

QString Socio::getGroup(){
    return group_;
}

void Socio::setMail(QString mail){
    mail_ = mail;
}

QString Socio::getMail(){
    return mail_;
}

void Socio::setDepartmentBoss(int isboss){
    if(isboss == 1)
        departmentboss_= true;
    else
        departmentboss_ = false;
}

char Socio::getDepartmentBoss(){
    if(departmentboss_==true)
        return '1';
    else
        return '0';
}

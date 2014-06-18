#include "socio.h"

Socio::Socio():
    debts_(NULL){
}

quint32 Socio::getAge(){
    return age_;
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

void Socio::setAge(quint32 age){
    age_=age;
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

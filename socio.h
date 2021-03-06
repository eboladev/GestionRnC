#ifndef SOCIO_H
#define SOCIO_H
#include <QString>
#include <QDate>
#include "deuda.h"

/*Clase para almacenar cada uno de los socios
 * guarda su información de su nombre, edad, dni,
 * aka, tiempo de ingreso en la asoc. deudas con la asoc.
 * funcion que cumple dentro de la misma
 *
*/

class Socio
{
public:
    Socio();
    //setters y getters
    void setName(QString);
    QString getName();
    void setAKA(QString);
    QString getAKA();
    void setDNI(QString);
    QString getDNI();
    void setWork(QString);
    QString getWork();
    void setDebt();
    Deuda* getAllDebts();
    void setIDpartner(short int);
    quint32 getIDpartner();
    void setDepartment(QString);
    QString getDepartment();
    void setPhone(QString);
    QString getPhone();
    void setGroup(QString);
    QString getGroup();
    void setMail(QString);
    QString getMail();
    void setDepartmentBoss(int);
    char getDepartmentBoss();

private:
    quint32 idpartner_;//identificador que irá en orden ascendente para los partners
    QString department_;//indica al departamento al que pertenece
    QString name_;      //nombre
    QString aka_;       //aka (apodo)
    QString dni_;       //DNI
    Deuda *debts_;      //Deudas
    QString work_;      //Desempeño en la asoc.
    QString group_;     //Grupo (en otro caso → '-')
    QString phone_;     //número de telefono movil
    QString mail_;      //correo electrónico
    QString address_;   //dirección de residencia
    QString password_;  //contraseña de acceso al sistema
    bool departmentboss_;//true si el socio es jefe del departamento al que pertenece
};

#endif // SOCIO_H

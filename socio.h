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
    void setAge(quint32);
    quint32 getAge();
    void setAKA(QString);
    QString getAKA();
    void setDNI(QString);
    QString getDNI();
    void setWork(QString);
    QString getWork();
    void setDebt();
    Deuda* getAllDebts();

private:
    QString name_;      //nombre
    QString aka_;       //aka (apodo)
    quint32 age_;       //edad
    QString dni_;       //DNI
    QDate time_income;  //Tiempo de llegada
    Deuda *debts_;      //Deudas
    QString work_;      //Desempeño en la asoc.
    QString group_;     //Grupo (en otro caso → '-')
    QString phone_;     //número de telefono movil
    QString mail_;      //correo electrónico
    QString address_;   //dirección de residencia
};

#endif // SOCIO_H

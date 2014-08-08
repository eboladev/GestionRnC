#ifndef INICIO_H
#define INICIO_H

#include <QMainWindow>
#include "socio.h"
#include "cuenta.h"
#include "evento.h"
#include "deuda.h"
#include <QFile>
#include "dialog_newpartner.h"
#include "dialogdepartmentboss.h"
#include "dialogsearchpartner.h"


namespace Ui {
class Inicio;
}

class Inicio : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = 0);
    ~Inicio();

private slots:
    void on_btnaddpartner_clicked();

    void addingpartner(Socio *);

    void on_btndelpartner_clicked();

    void on_btnsearchpartner_clicked();

    void on_btnviewboss_clicked();

    void on_btnextract_clicked();

    void on_btningress_clicked();

private:
    Ui::Inicio *ui;
    QList<Socio *> partners_;
    Cuenta cuenta_;
    quint32 npartners_;
    Evento *events_;

    QFile *partners_file_;
    QFile *count_file_; //fichero de cuentas
    Deuda *debts_;
};

#endif // INICIO_H

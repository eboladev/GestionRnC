#ifndef INICIO_H
#define INICIO_H

#include <QMainWindow>
#include "socio.h"
#include "evento.h"
#include "deuda.h"
#include <QFile>
#include "dialog_newpartner.h"
#include <QTextStream>


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

    void on_btnmodpartner_clicked();

    void on_btnsearchpartner_clicked();

    void on_btnviewboss_clicked();

private:
    Ui::Inicio *ui;
    QList<Socio *> partners_;
    quint32 npartners_;
    Evento *events_;
    QFile *partners_file_;
    Deuda *debts_;
};

#endif // INICIO_H

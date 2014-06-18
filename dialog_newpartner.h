#ifndef DIALOG_NEWPARTNER_H
#define DIALOG_NEWPARTNER_H

#include <QDialog>
#include <QMessageBox>
#include "socio.h"

namespace Ui {
class Dialog_newpartner;
}

class Dialog_newpartner : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_newpartner(QWidget *parent = 0);
    ~Dialog_newpartner();

private slots:
    void on_buttonBox_accepted();

signals:
    Socio* new_partner(Socio*);

private:
    Ui::Dialog_newpartner *ui;
};

#endif // DIALOG_NEWPARTNER_H

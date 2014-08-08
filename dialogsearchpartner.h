#ifndef DIALOGSEARCHPARTNER_H
#define DIALOGSEARCHPARTNER_H

#include <QDialog>
#include "socio.h"
#include <QMessageBox>

namespace Ui {
class DialogSearchPartner;
}

class DialogSearchPartner : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSearchPartner(QWidget *, QList<Socio *>);
    ~DialogSearchPartner();

private slots:
    void on_btnsearch_clicked();

private:
    Ui::DialogSearchPartner *ui;
    QList<Socio*> partners_;
};

#endif // DIALOGSEARCHPARTNER_H

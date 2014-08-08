#ifndef DIALOGDEPARTMENTBOSS_H
#define DIALOGDEPARTMENTBOSS_H

#include <QDialog>
#include <QFile>
#include "socio.h"

namespace Ui {
class DialogDepartmentboss;
}

class DialogDepartmentboss : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDepartmentboss(QWidget*, QList<Socio *> );
    ~DialogDepartmentboss();

private:
    Ui::DialogDepartmentboss *ui;
};

#endif // DIALOGDEPARTMENTBOSS_H

#ifndef EVENTO_H
#define EVENTO_H

#include <QObject>
#include <QDate>
#include <QTime>

class Evento : public QObject
{
    Q_OBJECT
public:
    explicit Evento(QObject *parent = 0);
    void setDate(QDate);
    void setTime(QTime);
    void setGroups(QString);
    void setContact(QString);
    void setPlace(QString);

signals:

public slots:

private:
    QDate date_;
    QTime time_;
    QString groups_;
    QString place_;
    QString contact_;

};

#endif // EVENTO_H

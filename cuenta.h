#ifndef CUENTA_H
#define CUENTA_H

class Cuenta
{
public:
    Cuenta();
    double getTotal();
    void draw(double );
    void ingress(double);
private:
    double total_;
};

#endif // CUENTA_H

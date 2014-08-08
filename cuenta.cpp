#include "cuenta.h"

Cuenta::Cuenta(){
    total_=0;
}
double Cuenta::getTotal(){
    return total_;
}

void Cuenta::draw(double amount){
    total_ = total_ - amount;
}

void Cuenta::ingress(double amount){
    total_ = total_ + amount;
}

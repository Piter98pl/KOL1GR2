#ifndef OPERATORY_H
#define OPERATORY_H

#include "litera.h"
#include <iostream>
#include <fstream>


// deklaracje operatorow, ktore nalezy zdefiniowac w operatory.cpp

bool operator>(const Litera& a, const Litera& b);
bool operator<(const Litera& a, const Litera& b);
std::ostream& operator<<(std::ostream& str, const Litera& a);
std::istream& operator>>(std::istream& str, Litera& a);

#endif
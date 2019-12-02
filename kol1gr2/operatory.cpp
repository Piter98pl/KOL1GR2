#include "litera.h"

using namespace std;

// tu napisac definicje operatorow deklarowanych w operatory.h

ostream& operator<<(ostream& str, const Litera& a) {
    return str << (a.ptr ? a.ptr : "pusty");
}

istream& operator>>(istream& str, Litera& a) {
    string tmp;
    getline(str,tmp);
    delete [] a.ptr;
    a.len = tmp.size();
    if (a.len>0) {
        a.ptr = new char[a.len+1];
        strcpy(a.ptr,tmp.c_str()); 
    } else {
        a.ptr = nullptr;
    }
    return str;
}

bool operator>(const Litera& a, const Litera& b) {
    TString tmp{a}; 
    tmp.insert(tmp.size(),b);
    return tmp; 
}

bool operator<(TString& a, const TString& b) {
    return a = a + b;
}
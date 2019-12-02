#include "litera.h"
#include<stdexcept>
#include <iostream>

using namespace std;

// tu prosze zdefiniowac wszystkie skladowe zadeklarowane w klasie Litera
Litera::Litera(const char arg) {
    if ( arg != nullptr) {
        len = strlen(arg);
        ptr = new char[len + 1];
        strcpy(ptr, arg);

    }
    #ifdef DEBUG
    cout << "Litera c-tor" << len << " - " << (ptr ? ptr : "pusty") << endl;
    #endif
}

Litera::~Litera(){
     #ifdef DEBUG
        cout << "Litera d-tor " << len << " - " << (ptr?ptr:"pusty") << endl;
    #endif
    delete [] ptr;

}

Litera::Litera(const Litera& arg) : len(arg.len) {
     if (len>0) {
        ptr = new char[len+1];
        strcpy(ptr,arg.ptr);
    }
    #ifdef DEBUG
        cout << "Litera cc-tor " << len << " - " << (ptr?ptr:"pusty") << endl;
    #endif
}

Litera& Litera::operator=(const Litera& arg){
     if ( this != &arg ) { 
        delete [] ptr;
        ptr = nullptr;
        len = arg.len;
        if (len>0) {
            ptr = new char[len+1];
            strcpy(ptr,arg.ptr);
}
     }
     #ifdef DEBUG
     cout <<"Litera operator kopiujący="<<len<<"-"<<ptr?ptr:"pusty")<<endl;
     #endif
     return *this;
}

Litera::Litera(Litera&& arg) : ptr(arg.ptr), len(arg.len) {
    arg.ptr = nullptr;
    arg.len = 0;
    #ifdef DEBUG
        cout << "Litera mvc-tor " << len << " - " << (ptr?ptr:"pusty") << endl;
    #endif
}

Litera& Litera::operator=(Litera&& arg) {
    if ( this != &arg ) {
        delete [] ptr;
        ptr = arg.ptr;
        len = arg.len;
        arg.ptr = nullptr;
        arg.len = 0;
    }
    #ifdef DEBUG
        cout << "Litera operator przenoszący= " << len << " - " << (ptr?ptr:"pusty") << endl;
    #endif    
    return *this;
}
char& Litera::operator[](size_t n) {
    if (!ptr) throw "obiekt jest pusty";
    if ( n < len ) return ptr[n];
    throw out_of_range("W klasie Litera argument operatora[] jest poza zakresem");
}
char* Litera::insert(size_t pos, const char* c) {
    if (pos <= len) {
        size_t oldlen = len;
        len = len + strlen(c);
        char* tmp = new char[len+1];
        strcpy(tmp,ptr); 
        for (size_t i=pos; i<pos+strlen(c); ++i) {
            tmp[i] = c[i-pos];
        }
        for (size_t i=pos; i<oldlen; ++i) {
            tmp[i+strlen(c)] = ptr[i];
        }
        tmp[len] = '\0';
        delete [] ptr;
        ptr = tmp;
        return ptr+pos;
    } else {
        throw out_of_range("Błędny argument");
    }
    return ptr;
}

char* Litera::insert(size_t pos, char c) {
    return insert(pos, string({c}).c_str());
}

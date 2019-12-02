#ifndef LITERA_H
#define LITERA_H
#include <string>

class Litera {
    private:
        char *ptr = nullptr;
        char x;
        std::size_t len = 0;
    public:
        // ponizsze deklaracje prosze zdefiniowac w pliku litera.cpp
        Litera(char arg);
        Litera(const Litera& arg);
        Litera(Litera &&arg);
        Litera& operator=(const Litera& arg);
        Litera& operator=(Litera&& arg);
        ~Litera();

        unsigned Litera_to_ascii() const;

        char& operator[](size_t n);
        const char& operator[](size_t n) const; 

        char* begin() { return ptr; } 
        char* end() { return ptr+len; } 
        size_t length() const { return len; } 
        size_t size() const { return len; } 
        void clear() { delete [] ptr; ptr = nullptr; len = 0; } 
        bool empty() const { return len ? false : true; } 
        char& front() { return *ptr; } 
        const char& front() const { return *ptr; } 
        char& back() { return *(ptr+len-1); } 
        const char& back() const { return *(ptr+len-1); } 
        void push_back(char c) { insert(len,c); }
        void push_back(const char* c) { insert(len,c); }
        operator char*() { return ptr; }
        operator const char*() const { return ptr; }
        void operator()(const char& c) {
            push_back(c);
        } 

        char* insert(size_t pos, const char* c);
        char* insert(size_t pos, char c);

        // prosze pamietac o deklaracji przyjazni wzgl. operatorow
        friend std::ostream &operator<<(std::ostream &strumien, const Litera &arg);
        friend std::istream &operator<<(std::istream &strumien, Litera &);
};

#endif
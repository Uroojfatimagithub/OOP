Create a class Integer to simulate the integer data type in C++. The class will have
one integer data member. Provide constructors and get()/set() methods. Overload the
following relational operators.
<, >, ==, !=, +, - ,*
Overload each of these using class member function .and verify the results
Print your name, reg,no, section, semester in main using cout statements.
Program:
// ooplabfeet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Integer {
private:
    int value;
    
public:
    Integer() {
        value = 0;
    }
    
    Integer(int val) {
        value = val;
    }
    
    int get() {
        return value;
    }
    
    void set(int val) {
        value = val;
    }
    
    bool operator<(const Integer& other) const {
        return value < other.value;
    }
    
    bool operator>(const Integer& other) const {
        return value > other.value;
    }
    
    bool operator==(const Integer& other) const {
        return value == other.value;
    }
    
    bool operator!=(const Integer& other) const {
        return value != other.value;
    }
    
    Integer operator+(const Integer& other) const {
        return Integer(value + other.value);
    }
    
    Integer operator-(const Integer& other) const {
        return Integer(value - other.value);
    }
    
    Integer operator*(const Integer& other) const {
        return Integer(value * other.value);
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Integer a(5);
    Integer b(10);
    
    cout <<" 5 < 10 : True : "<< (a < b) << endl; // prints 1 (true)
    cout <<" 5 > 10 : False : "<< (a > b) << endl; // prints 0 (false)
    cout <<" 5 == 10 : False : "<< (a == b) << endl; // prints 0 (false)
    cout <<" 5 != 10 : True : "<< (a != b) << endl; // prints 1 (true)
    
    Integer c = a + b;
    cout <<" 5 + 10 : "<< c.get() << endl; // prints 15
    
    Integer d = b - a;
    cout <<" 10 - 5 : "<<d.get() << endl; // prints 5
    
    Integer e = a * b;
    cout <<" 5 * 10 : "<<e.get() << endl; // prints 50

    system("pause");
	return 0;
}


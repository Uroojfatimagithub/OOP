#include <iostream>
using namespace std;
class Complex {
	private:
    double real;
    double imaginary;
public:
    Complex(double r= 0.0, double im= 0.0) {
        real= r;
        imaginary= im;
    }

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imaginary+ c.imaginary);
    }

    void display() const {
        cout<<real<< " + " << imaginary<< "i" <<endl;
    }
};

int main() {
    Complex c1(2.0, 3.0);
    Complex c2(4.0, -5.0);

    Complex sum = c1 + c2;

    cout << "c1 = ";
    c1.display();
    cout << "c2 = ";
    c2.display();
    cout << "sum = ";
    sum.display();

    return 0;
}


#include <iostream>
using namespace std;
class MyClass {
private:
    static int count;
public:
    MyClass() {
        ++count;
    }

    static int getCount() {
        return count;
    }
};

int MyClass::count= 0;

int main() {
    MyClass c1;
    MyClass c2;
    MyClass c3;

    cout << "Number of objects created: " << MyClass::getCount() <<endl;

    return 0;
}


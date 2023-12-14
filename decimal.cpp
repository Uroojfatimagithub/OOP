#include <iostream>
#include <string>
using namespace std;
class DecimalNumber {
	private:
    string number;
public:
    DecimalNumber(const string& s) : number(s) {}

    string get_reverse() const {
        string reversed_number;
        for (int i = number.length() - 1; i >= 0; i--) {
            reversed_number += number[i];
        }
        return reversed_number;
    }
};

int main() {
    cout << "Enter a decimal number: ";
    string decimal_number;
    cin >> decimal_number;
    DecimalNumber number(decimal_number);
    string reversed_number = number.get_reverse();
	cout << "The decimal number in reverse order is: " << reversed_number <<endl;
    return 0;
}


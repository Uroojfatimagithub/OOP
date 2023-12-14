#include <iostream>
#include <string>

using namespace std;

class Train {
	private:
    int number;
    string name;
    string source;
    string destination;
    string journeydate;
    int capacity;
public:
    Train() : number(0), capacity(0) {}
    Train(int num, const string& n, const string& s,
          const string& d, const string& j,
          int c) : number(num), name(n), source(s),
                          destination(d), journeydate(j),
                          capacity(c) {}

    void input_data() {
        cout << "Enter train number: ";
        cin >> number;
        cout << "Enter train name: ";
        getline(cin, name);
        cout << "Enter source: ";
        getline(cin, source);
        cout << "Enter destination: ";
        getline(cin, destination);
        cout << "Enter journey date: ";
        getline(cin, journeydate);
        cout << "Enter capacity: ";
        cin >> capacity;
    }

    void display_data() const {
        cout << "Train number: " << number << endl;
        cout << "Train name: " << name << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Journey date: " << journeydate << endl;
        cout << "Capacity: " << capacity << endl;
    }
};

int main() {
    Train t;
    t.input_data();
    cout << "\nTrain details:\n";
    t.display_data();
    return 0;
}


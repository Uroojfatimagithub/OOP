#include <iostream>
#include <string>
using namespace std;

class IDString {
public:
    string ID;
    string field1;
    string field2;
    string field3;
    
    IDString() {
        ID = "";
    }
    
    IDString(string id) {
        ID = id;
    }

    void id_display()
    {
    	cout<<"the entered id is: "<<ID<<endl;
	}
    
    void separateFields() {
        field1 = ID.substr(0, 5);
        field2 = ID.substr(6, 7);
        field3 = ID.substr(12,1);
    }
    
    void displayFields() {
        cout << "Field 1: " << field1 << endl;
        cout << "Field 2: " << field2 << endl;
        cout << "Field 3: " << field3 << endl;
    }
};

int main() {
    IDString idString("37203_7846830_4");
    idString.id_display();
    idString.separateFields();
    idString.displayFields();
    
    return 0;
}



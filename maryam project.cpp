#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Base class for Person
class Person {
protected:
    string name;
    int age;
public:
    Person() {}
    Person(const string& _name, int _age) : name(_name), age(_age) {}
    virtual void display() const = 0; // Pure virtual function
    virtual void saveToFile(ofstream& file) const = 0; // Pure virtual function
};

// Derived class for Doctor
class Doctor : public Person {
private:
    string specialization;
public:
    Doctor() {}
    Doctor(const string& _name, int _age, const string& _specialization)
        : Person(_name, _age), specialization(_specialization) {}

    void display() const {
        cout << "Doctor Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Specialization: " << specialization << endl;
    }

    void saveToFile(ofstream& file) const {
        file << "Doctor Name: " << name << endl;
        file << "Age: " << age << endl;
        file << "Specialization: " << specialization << endl;
        file << "--------------\n";
    }
};

// Derived class for Patient
class Patient : public Person {
private:
    string disease;
public:
    Patient() {}
    Patient(const string& _name, int _age, const string& _disease)
        : Person(_name, _age), disease(_disease) {}

    void display() const {
        cout << "Patient Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Disease: " << disease << endl;
    }

    void saveToFile(ofstream& file) const {
        file << "Patient Name: " << name << endl;
        file << "Age: " << age << endl;
        file << "Disease: " << disease << endl;
        file << "--------------\n";
    }
};

// Function to write a person's details to a file
void writeToFile(const Person& person) {
    ofstream file("hospital.txt", ios::app);
    if (file.is_open()) {
        person.display(); // Display the person's details on the console
        person.saveToFile(file); // Write the person's details to the file
        file.close();
        cout << "Details written to file successfully!" << endl;
    } else {
        cout << "Error opening the file!" << endl;
    }
}

// Function to read persons' details from a file
void readFromFile() {
    ifstream file("hospital.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error opening the file!" << endl;
    }
}

// Function to display menu and get user's choice
int getMenuChoice() {
    int choice;
    cout << "\n--- Hospital Management System ---" << endl;
    cout << "1. Add a Doctor" << endl;
    cout << "2. Add a Patient" << endl;
    cout << "3. Display All Details" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // Ignore the newline character
    return choice;
}

int main() {
    vector<Person*> persons;
    int choice;
    string name, specialization, disease;
    int age;

    cout << "Hospital Management System" << endl;
    cout << "--------------------------" << endl;

    do {
        choice = getMenuChoice();

        switch (choice) {
            case 1:
                cout << "Enter doctor's name: ";
                getline(cin, name);

                cout << "Enter doctor's age: ";
                cin >> age;
                cin.ignore(); // Ignore the newline character

                cout << "Enter doctor's specialization: ";
                getline(cin, specialization);

                persons.push_back(new Doctor(name, age, specialization));
                cout << "Doctor added successfully!" << endl;
                break;

            case 2:
                cout << "Enter patient's name: ";
                getline(cin, name);

                cout << "Enter patient's age: ";
                cin >> age;
                cin.ignore(); // Ignore the newline character

                cout << "Enter patient's disease: ";
                getline(cin, disease);

                persons.push_back(new Patient(name, age, disease));
                cout << "Patient added successfully!" << endl;
                break;

            case 3:
                cout << "\n--- All Details ---" << endl;
                for (size_t i = 0; i < persons.size(); ++i) {
                    persons[i]->display();
                    cout << "--------------" << endl;
                }
                break;

            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    // Write all persons' details to a file
    ofstream file("hospital.txt");
    if (file.is_open()) {
        for (size_t i = 0; i < persons.size(); ++i) {
            persons[i]->saveToFile(file);
        }
        file.close();
    } else {
        cout << "Error opening the file!" << endl;
    }

    // Free memory for the created persons
    for (size_t i = 0; i < persons.size(); ++i) {
        delete persons[i];
    }

    // Read and display persons' details from the file
    cout << "\n--- Details Read from File ---" << endl;
    readFromFile();

    return 0;
}


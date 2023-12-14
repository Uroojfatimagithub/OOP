#include <iostream>
#include <string>
using namespace std;
class Faculty {
protected:
string name;
int ID;
public:
virtual int salary() = 0;
};
class PermanentFaculty : public Faculty {
int year_of_service, basic_pay;
public:
void setBasicPay(int bp) {
basic_pay = bp;
}
int salary() {
return (basic_pay + (10 * basic_pay) + (25 * basic_pay));
}
};
class VisitingFaculty : public Faculty {
int hourly_rate, no_of_hours_taught;
public:
void setValues(int hr, int no_ht) {
hourly_rate = hr;
no_of_hours_taught = no_ht;
}
int salary() {
return (hourly_rate * no_of_hours_taught);
}
};
class ContractualFaculty : public Faculty {
int no_of_days, per_day_salary;
public:
void setValues(int days, int per_day_sal) {
no_of_days = days;
per_day_salary = per_day_sal;
}
int salary() {
return (no_of_days * per_day_salary);
}
};
int main()
{
cout << "Name: UROOJ FATIMA" << endl;
cout << "Reg No: 2022-BSE-074" << endl;
cout << "Section: B" << endl;
cout << "Semester: II" << endl;
int choice;
cout << "Enter faculty type:\n1. Permanent Faculty\n2. Visiting Faculty\n3.ContractualFaculty\n";
cin >> choice;
Faculty* facultyPtr;
if (choice == 1) {
PermanentFaculty* pf = new PermanentFaculty();
int basicPay;
cout << "Enter basic pay: ";
cin >> basicPay;
pf->setBasicPay(basicPay);
facultyPtr = pf;
}
else if (choice == 2) {
VisitingFaculty* vf = new VisitingFaculty();
int hourlyRate, noOfHoursTaught;
cout << "Enter hourly rate: ";
cin >> hourlyRate;
cout << "Enter number of hours taught: ";
cin >> noOfHoursTaught;
vf->setValues(hourlyRate, noOfHoursTaught);
facultyPtr = vf;
}
else if (choice == 3) {
ContractualFaculty* cf = new ContractualFaculty();
int noOfDays, perDaySalary;
cout << "Enter number of days: ";
cin >> noOfDays;
cout << "Enter per day salary: ";
cin >> perDaySalary;
cf->setValues(noOfDays, perDaySalary);
facultyPtr = cf;
}
else {
cout << "Invalid choice. Exiting the program." << endl;
return 0;
}
int salary = facultyPtr->salary();
cout << "Salary: " << salary << endl;
delete facultyPtr;
return 0;
}


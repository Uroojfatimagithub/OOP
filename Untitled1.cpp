#include<iostream>
#include<string>
using namespace std;
class faculty {
protected:
string name;
int ID;
public:
virtual int salary() = 0;
};
class P_F : public faculty {
int year_of_service, basic_pay;
public:
void setb_p(int bp)
{
basic_pay = bp;
}
int salary() {
return (basic_pay + (10 * basic_pay) + (25 * basic_pay));
}
};
class v_f : public faculty {
int h_r, no_of_h_taught;
public:
void set_values(int hr, int no_ht) {
h_r = hr;
no_of_h_taught = no_ht;
}
int salary() {
return (h_r * no_of_h_taught);
}
};
class c_f : public faculty {
int no_of_days, per_day_salary;
public:
void set_values(int days, int per_day_sal) {
no_of_days = days;
per_day_salary = per_day_sal;
}
int salary()
{
return (no_of_days * per_day_salary);
}
};
int main()
{
P_F pf;
v_f vf;
c_f cf;
pf.setb_p(3900); // Setting basic pay for P_F object
vf.set_values(15, 80); // Setting hourly rate and number of hours taught for v_f object
cf.set_values(30, 500); // Setting number of days and per day salary for c_f object
faculty* f1, * f2, * f3;
f1 = &pf;
f2 = &vf;
f3 = &cf;
int salary1 = f1->salary(); // Calculating salary for f1
int salary2 = f2->salary(); // Calculating salary for f2
int salary3 = f3->salary(); // Calculating salary for f3
cout << "Salary for f1: " << salary1 << endl;
cout << "Salary for f2: " << salary2 << endl;
cout << "Salary for f3: " << salary3 << endl;
cout << "Name: UROOJ FATIMA" << endl;
cout << "Reg No: 2022-BSE-074" << endl;
cout << "Section: B" << endl;
cout << "Semester: II" << endl;
return 0;
}

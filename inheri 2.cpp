#include<iostream>
using namespace std;
class person
{
	protected:
		string name;
		string adress;
		int contact;
		public:
			person():name(),adress(),contact(0)
			{    }
			   person(int n,int a,int c):name(),adress(),contact(c)
			   {    }
			void input()
			{
			cin>>name>>adress>>contact;
			}
			void display()
			{
				cout<<name<<adress<<contact;
			}
};
class student:public person
{
	int sem;
	float cgpa;
	string dep;
	public:
		student():person(),sem(0),cgpa(0.0),dep()
		{   }
		student(string nn,string aa,int cc,int s,float c,string d):person(nn,aa,cc),sem(s),cgpa(c),dep(d)
		{   }
		void input()
		{
			person::input();
			cin>>sem>>cgpa>>dep;
		}
		void display()
		{
			person::display();
			cout<<sem<<cgpa<<dep;
		}
};
class faculty:public person
{
	string dep;
	float exp;
	public:
		faculty():person(),dep(),exp(0.0)
		{	}
		faculty(string nnn,string aaa,int ccc.string d,float e):person(nnn,aaa,ccc),dep(d),exp(e)
		{   }
		void input()
		{
			person::input();
			cin>>dep>>exp;
		}
		void display()
		{
			person::display();
			cout<<dep<<exp;
		}
};
class staff:public person
{  };
int main()
{
	student s;
	s.input();
	faculty f;
	f.input();
	staff ss;
	ss.input();
	s.display();
	f.display();
	ss.display();
	return 0;
}

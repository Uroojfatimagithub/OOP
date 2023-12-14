// overloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Time 
{
private:
	int hours;
	int minute;
public:

Time (): hours(0),minute(0)
	   {  }

Time ( int h,int m) : hours(h),minute(m)
	   {  }

Time operator ++ ( ) 
{
	if (minute == 59)
		{minute=0;
		++hours;}
	else 
		++minute;
		return Time(hours,minute);
}
Time operator++( int ) //postfix
{   
	Time t(hours,minute);
 if (minute == 59)
	{
		minute=0;
		hours++;}

	else 
		minute++;
		return t; 
} 
void Display()
	   {  
		   cout<<hours << ":" <<minute << "  "<<endl;
	   }
};
int _tmain(int argc, _TCHAR* argv[])
{
		    Time t1(5,30),t2(2,59),t3,t4;;
		    t3=++t1;
		    t4=t2++;
		    cout<<"Time 1: "<<endl;
			t1.Display();
		    cout<<"Time 2 : "<<endl;
			t2.Display();
	        cout<<"Time 3:"<<endl;
			t3.Display();
			cout<<"Time 4:"<<endl;
			t4.Display();
		    system("pause");
		    return 0;
}

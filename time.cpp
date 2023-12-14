// pp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Time {
  private:
    int hour;
    int minute;
    int second;

  public:
    Time(int h, int m, int s) {
      hour = h;
      minute = m;
      second = s;
    }

    void setHour(int h) {
      hour = h;
    }
    int getHour() {
      return hour;
    }

    void setMinute(int m) {
      minute = m;
    }
    int getMinute() {
      return minute;
    }

    void setSecond(int s) {
      second = s;
    }
    int getSecond() {
      return second;
    }

    void display() {
      cout << hour << ":" << minute << ":" << second << endl;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	 
	Time *ct,*ft;
	ct = new Time(9, 7, 8);
	ft = new Time(13, 5, 6);
	ct->display();
	ft->display();
cout << "the  estimated number of hours in the departure of your flight is " << endl;
cout << ft->getHour() - ct->getHour() << endl;
	system("pause");
	return 0;
}

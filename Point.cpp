Task #02
// kkkk.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Point
{
protected:
	double x;
	double y;
	public:
        Point()
		{ }
		Point(double a,double b)
		{ 
			x=a;
			y=b;
		}
		double getx()
		{
		    return x;
		}
		double gety()
		{
			return y;
		}
		void set_values(double c,double d)
		{
			x=c;
			y=d;
		}
		void display()
		{
		     cout << "Point (" << x << ", " << y << ")";
		}
};
class Circle : public Point {
public:
    double radius;
public:
	Circle():radius(0.0)
	{ 
	}
	Circle(double r):radius(r)
	{  }
	double get_radius()
	{
		return radius;
	}
	void set_radius(float g)
	{
		radius=g;
	}
	double Area_circle()
	{
		return 3.14*radius*radius;
	}
	double circumference_circle()
	{
		return 2*3.14*radius;
	}
};
class cylinder:public Circle
{
  private:
	  double height;
 public:
	 cylinder(double r,double h):Circle(r),height(h)
	 {  }
	 double get_height()
	 {
		 return height;
	 }
	 void set_height(double t)
	 {
		 height=t;
	 }
	 double Area_cylinder()
	 {
		 return 2*Area_circle()+2*3.14*radius*height;
	 }
	 double Volume_cylinder()
	 {
		 return 3.14*radius*radius*height;
	 }
};
int _tmain(int argc, _TCHAR* argv[])
{

	cylinder c1(5.6,7.8);
	cout<<"volume of cylinder:"<<c1.Volume_cylinder()<<endl;
	cout<<"area  of cylinder:"<<c1.Area_cylinder()<<endl;
	cout<<"MY NAME IS UROOJ FATIMA"<<endl;
	cout<<"my section is 2_B"<<endl;
	cout<<"my roll no is BSE_2022_074"<<endl;
	system("pause");
	return 0;
}

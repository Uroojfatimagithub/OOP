TASK #01
Create a class Point with two data members x, y. Provide appropriate constructors,
get, set and display methods.
Create a class Triangle with three Points as its data members. Provide appropriate constructors for this class and a display method which calls the display methods of the three Points.
In the main function, declare three points and pass them to the constructor of the class Triangle. Call the display method of Triangle to verify the coordinates of the triangle.
Print your name, reg,no, section, semester in main using cout statements.
Program:
Task #01
// llll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Point
{
private:
	int x;
	int y;
public:
	Point()
	{}
	Point(int one,int two):x(one),y(two)
	{}
	void setx(int a)
	{
		x=a;
	}
	void sety(int b)
	{
		y=b;
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
	void display()
	{
		cout<<"("<<x<<","<<y<<")"<<endl;
	}
};
	class Triangle
	{
	private:
		Point p1;
		Point p2;
		Point p3;
	public:
		Triangle()
		{ }
		Triangle(Point pa,Point pb,Point pc):p1(pa),p2(pb),p3(pc)
		{ }
		void display()
		{
			p1.display();
			p2.display();
			p3.display();
		}
	};
int _tmain(int argc, _TCHAR* argv[])
{
	Point s(6,9);
	Point s1(8,9);
	Point s2(6,7);
     Triangle t1(s,s1,s2);
	 t1.display();
	 cout<<"MY NAME IS UROOJ"<<endl;
	 cout<<"MY REGISTRATION NO(BSE_2022_074)"<<endl;
	 cout<<"SECTION(B)"<<endl;
	 cout<<"SEMESTER 2ND"<<endl;
	system("pause");
	return 0;
}

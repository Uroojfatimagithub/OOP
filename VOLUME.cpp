//Write a program with a function volume() which accepts three sides of a cube and returns its volume. Provide a default value of 1 for all the three sides of a cube. Call this function with zero, one, two and three arguments and display the volume returned in the main().
Code:
#include<iostream>
using namespace std;
int volume(int a=1,int b=1,int c=1)
{
	return (a*b*c);
}
int main()
{
	cout<<volume()<<endl;
	cout<<volume(1)<<endl;
	cout<<volume(1,1)<<endl;
	cout<<volume(1,1,1)<<endl;
}

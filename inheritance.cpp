#include<iostream>
using namespace std;
class counter
{
	protected:
		int count;
		public:
		counter():count(0)
		{ }
		counter(int c):count(c)
		{  }
		counter operator++()
		{
			return counter(++count);
		}
		void display()
		{
			cout<<count<<endl;
		}
};
class counter2:public counter
{
	counter operator--()
	{
		return counter(--count);
	}
};
int main()
{
	counter2 c1,c2;
	c2=++c1;
	c2=++c1;
	c2=--c1;
	c2.display();
	return 0;
}

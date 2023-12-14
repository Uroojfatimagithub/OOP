#include<iostream>
#include<string>
using namespace std;
class Roman
{
	private:
	string roman_num;
	int decimal;
	public:
	Roman()
	{
		roman_num=" ";
		decimal=0;
	}
	void input()
	{
		cout<<"enter roman number:\n";
		getline(cin,roman_num);
	}
	void converter()
	{
		string str;
		int x=roman_num.length();
		for(int i=0;i<x;i++)
		{
			if(roman_num[i]=='M')
			decimal=decimal+1000;
			else if(roman_num[i]=='D')
			decimal=decimal+500;
			else if(roman_num[i]=='C')
			decimal=decimal+100;
			else if(roman_num[i]=='L')
			decimal=decimal+50;
			else if(roman_num[i]=='X')
			decimal=decimal+10;
			else if(roman_num[i]=='V')
			decimal=decimal+5;
			else if(roman_num[i]=='I')
			decimal=decimal+1;
		}
		}	
		void display()
		{
			cout<<"decimal number is\n";
			cout<<decimal;
		}
};
int main()
{
	Roman R1;
	R1.input();
	R1.converter();
	R1.display();
}


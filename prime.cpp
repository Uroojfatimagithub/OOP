#include<iostream>
using namespace std;
bool isprime(int x);
int main()
{
	int x;
	cout<<"enter a number";
	cin>>x;
	bool res=isprime(x);
      cout<<res;
}
bool isprime(int x)
{
	if(x==0||x==1)
	return false;
	for(int i=2;i<=x/2;i++)
	  if(x%i==0)
	  { 
	    return false;
	  }
	  else
	  return true;
}

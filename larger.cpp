.   int larger(int,int);
int main()
{
int x=10,y=5;
int m = larger(x,y);
cout<<m<<endl;
 return 0;
}
int larger(int a,int b)
{
if (a>b)
return a;
else
return b;
}

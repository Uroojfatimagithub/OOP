#include<iostream>
using namespace std;
struct point
{
	int x;
	int y;
};
void getinput(point &p1)
{
	cout<<"Enter x and y coordinates of points"<<endl;
	cin>>p1.x;
	cout<<endl;
	cin>>p1.y;
}
point addpoint(point pa,point pb)
{
	point temp;
	temp.x=pa.x+pb.x;
	temp.y=pa.y+pb.y;
	return temp;
}
int main()
{
	point pa,pb;
	getinput(pa);
	getinput(pb);
	point res=addpoint(pa,pb);
cout << "The sum of (" << pa.x << ", " << pa.y << ") and (" << pb.x << ", " << pb.y << ") is: (" << res.x << ", " << res.y << ")\n";
 return 0;
}

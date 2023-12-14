#include <iostream>
#include <string>
using namespace std;
int main()

{   
int vol=0;
int space=0;
int upcs=0;
	string text;
	cout<<"enter a paragraph"<<endl;
getline(cin,text);
for(int i = 0; i < text.length(); ++i)
    {
        if(text[i]=='a' || text[i]=='e' || text[i]=='i' ||
           text[i]=='o' || text[i]=='u' || text[i]=='A' ||
           text[i]=='E' || text[i]=='I' || text[i]=='O' ||
           text[i]=='U')
        {
            ++vol;
        }
		else if (text[i]==' ')
        {
            ++space;
        }
		 else if(text[i]>='A'&& text[i]<='Z')
        {
            ++upcs;
        }
}

cout<<"the summary of the entered paragraph"<<endl;
cout << "Vowels: " << vol << endl;
    cout << "uppercase: " << upcs << endl;
    cout << "White spaces: " << space << endl;

	system ("pause");
	return 0;
}


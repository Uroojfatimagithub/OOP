Exercise 1
Write a program which prompts user to enter a string of text. Once entered, you need to present a
summary of the text in the following manner.
Total number of vowels in the text.
Total number of spaces in the text.
Total number of upper case characters in the text.
Program:
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])

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

#include <iostream>
using namespace std;
void love_me()
{
	char c;
	cout << endl << "Do you love me, answer y or n?: ";
	c = ' ';
	while(c!='y' && c!='n') {
		cin >> c;
		if(c!='n' && c!='y')
			cout <<  endl << "Invalid reply, try again: ";
	}
	if(c=='n') {
		cout << endl << "I hate you ";
		love_me(); // recursion at work
	}
	cout << endl << "I love you too!";
}
int main() {
    love_me();
}

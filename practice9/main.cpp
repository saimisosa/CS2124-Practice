#include <iostream>
#include <string>
using namespace std;

string vowelReplace(string fullname){
    for (int i = 0; i < fullname.length(); i++){
        if (fullname[i] == 'A' || fullname[i] == 'E' || fullname[i] == 'I' || fullname[i] == 'O' || fullname[i] == 'U'){
            fullname[i] = 'Z';
        }
        else if (fullname[i] == 'a' || fullname[i] == 'e' || fullname[i] == 'i' || fullname[i] == 'o' || fullname[i] == 'u'){
            fullname[i] = 'z';
        }
    }
    cout << "Letters replaced: " << fullname << endl;
}



int main() {
    // part 1
    string firstname, lastname, fullname;
    cout << "What is your first name? " << endl;
    cin >> firstname;

    cout << "What is your last name? " << endl;
    cin >> lastname;

    fullname = firstname + ' ' + lastname;

    cout << "Your full name is: " << fullname << endl;

    // part 3
    cout << "Words reversed: ";
    for (int k = fullname.length()-1; k > -1; k--){
        cout << fullname[k];
    }
    cout << endl;

    // part 2
    vowelReplace(fullname);


}

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;

    string line;
    string word;
    char letter;

    ifstream song;
    song.open("mariahcarey.txt");

    if (!song) {
        cerr << "Could not open the file.\n";
        exit(1);
    }

    while(getline(song, line)) {
        lineCount++;
    }

    song.close();
    song.open("mariahcarey.txt");

    while(song >> word){
        wordCount++;
    }

    song.close();
    song.open("mariahcarey.txt");

    while(song >> letter){
        charCount++;
    }

    cout << "The number of lines in this text are: " << lineCount << endl;
    cout << "The number of words in this text are: " << wordCount << endl;
    cout << "The number of characters in this text are: " << charCount << endl;


}

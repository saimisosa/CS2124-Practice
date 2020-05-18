#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int countEven(const int* array, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (*array % 2 == 0) {
            count++;
        }
        array++;
    }
    return count;
}

double* maximum(double* num, int size) {
    if (size == 0) {
        return nullptr;
    } else {
        double *tempMax;
        double *ptr;
        tempMax = num;
        ptr = num + 1;

        for (int i = 0; i < (size-1); i++) {
            if (*ptr > *tempMax) {
                tempMax = ptr;
            }
            ptr++;
        }
        return tempMax;
    }
}

int myStrLen(const char* str) {
    int length = 0;
    while (*str != NULL){
        length++;
        str++;
    }
    return length;
}

bool contains1(const char* str, const char val){ // using pointers
    while (*str != NULL){
        if (*str == val){
            return true;
        }
        else {
            str++;
        }
    }
    return false;
}

bool contains2(const string word, const char letter){ // using just a string
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == letter){
            return true;
        }
    }
    return false;
}

void revString(char* numPtr) {
    char *begin;
    char *end;
    begin = numPtr;
    end = numPtr + (strlen(numPtr) - 1);

    while (begin < end) {
        char temp = *begin;
        *begin = *end;
        *end = temp;

        begin++;
        end--;
    }
}

void isPalindrome(char *letter){
    char *charPtr;
    char *rev;

    charPtr = letter;

    while (*charPtr != NULL) {
        ++charPtr; // traverses through the entire str, removing the char(s) before it
    }
    --charPtr; // repositions charPtr to point to the end of the string (ie. last char)

    for (rev = letter; charPtr >= rev;) {
        if (*charPtr == *rev) { // if the letters are the same
            --charPtr; // move the end
            rev++; // move forward
        } else {
            break; // stops the program the moment a char doesn't match
        }
    }

    if (rev > charPtr)
        cout << "String is Palindrome" << endl;
    else
        cout << "String is not a Palindrome" << endl;
}

void rotate1(int* valOne, int* valTwo, int* valThree) { // by pointer
    int swapVar = *valOne;
    *valOne = *valTwo;
    *valTwo = *valThree;
    *valThree = swapVar;
}

void rotate2(int& valOne, int& valTwo, int& valThree) { // by reference
    int shiftVar = valOne;
    valOne = valTwo;
    valTwo = valThree;
    valThree = shiftVar;
}

int digits1(char* element) { // using pointers
    int digitCount = 0;
    int size = 0;
    while (*element != NULL){
        if (isdigit(*element)){
            digitCount++;
            size++;
            element++;
        } else {
            size++;
            break;
        }
    }
    if (digitCount == size){
        return 1;
    } else {
        return 0;
    }
}

int digits2(const string& word){ // using string
    int digitCount = 0;
    for (int i = 0; i < word.size(); i++) {
        if (isdigit(word[i])){
            digitCount++;
        } else {
            break;
        }
    }
    if (digitCount == word.size()){
        return 1;
    }
    return 0;
}

int equals(int* firstStr, int* secondStr) { // assumed same size ONLY
    while (*firstStr != NULL && *secondStr != NULL){
        if (*firstStr != *secondStr){
            return 0;
        }
        firstStr++;
        secondStr++;
    }
    return 1;
}


int main() {
    //number 5
    char sample[6] = "abcde";
    char* aPtr;

    for (int i = 4; i > -1 ; i--) {
        aPtr = (sample + i);
        cout << *aPtr;
    }
    cout << endl;

    //number 6
    int numArray[4] = {5, 2, 8, 3};
    int even = countEven(numArray, 4);
    cout << "There are " << even << " even numbers." << endl;

    int test[7] = {5, 2, 8, 3, 12, 14, 15};
    int evenNum = countEven(test, 7);
    cout << "There are " << evenNum << " even numbers." << endl;

    //test 7
    double numbers[4] = {3.14, 9.29, 0.1, 46.2};
    double *mPtr;
    mPtr = maximum(numbers, 4);
    // check if nullptr and cout something stating that before printing
    if (mPtr == nullptr) {
        cout << "There's nothing in this array..." << endl;
    } else {
        cout << "The max is " << *mPtr << endl;
    }

    //test 8
    char anotherList[10] = "12345";
    int len = myStrLen(anotherList);
    cout << "The length of " << anotherList << " is " << len << endl;

    //test 9
    char valList[10] = "abcdce";
    bool doesContain1 = contains1(valList, 'c'); // should point to 'c' in s1
    if (doesContain1) {
        cout << "Element exists." << endl;
    } else {
        cout << "Element doesn't exist." << endl;
    }

    string fruit = "apple";
    bool doesContain2 = contains2(fruit, 'c');
    if (doesContain2) {
        cout << "Element exists." << endl;
    } else {
        cout << "Element doesn't exist." << endl;
    }

    //test 10
    char testD[10] = "abcde";
    cout << "Original string: " << testD << endl;
    revString(testD);  // call the function
    cout << "String reversed: " << testD << endl;
    cout << endl;

    //test 11
    char name[1000];
    cout << "Input string to check if its a palindrome. " << endl;
    cin >> name;
    isPalindrome(name);
    cout << endl;

    //test 12 - rotating by passing in pointer or reference
    int firstVal = 1, secondVal = 2, thirdVal = 3;
    cout << "Before shift, a, b, c is: " << firstVal << " " << secondVal << " " << thirdVal << endl;
    rotate1(&firstVal, &secondVal, &thirdVal);
    cout << "After shift, a, b, c is: " << firstVal << " " << secondVal << " " << thirdVal << endl;

    int fourthVal = 9, fifthVal = 1, sixthVal = 2;
    cout << "Before shift, a, b, c is: " << fourthVal << " " << fifthVal << " " << sixthVal << endl;
    rotate2(fourthVal, fifthVal, sixthVal);
    cout << "After shift, a, b, c is: " << fourthVal << " " << fifthVal << " " << sixthVal << endl;

    //test 13
    char valid[10] = "93270923";
    // change the cout
    cout << "Returns 1 if the whole string is numbers. Returns 0 if not: "<< digits1(valid) << endl;

    char another[10] = "sj2709";
    cout << "Returns 1 if the whole string is numbers. Returns 0 if not: "<< digits1(another) << endl;

    string testString = "11606021";
    cout << "Returns 1 if the whole string is numbers. Returns 0 if not: "<< digits2(testString) << endl;

    string invalidString = "036yrn12";
    cout << "Returns 1 if the whole string is numbers. Returns 0 if not: "<< digits2(invalidString) << endl;

    string anotherString = "sj2709";
    cout << digits2(anotherString) << endl;

    //test 14

    int listOne[5] = {1,2,3,4,5};
    int listTwo[5] = {1,2,3,4,5};

    cout << "1 (True) or 0 (False): " << equals(listOne, listTwo) << endl;

    int listThree[6] = {1,2,3,4,5,6};
    int listFour[6] = {9,8,7,6,5,4};
    cout << "1 (True) or 0 (False): " << equals(listThree, listFour) << endl;

    int listFive[6] = {1,2,3,4,5,6};
    int listSix[6] = {6,5,4,3,2,1};
    cout << "1 (True) or 0 (False): " << equals(listFive, listSix) << endl;
}

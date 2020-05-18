#include <iostream>
using namespace std;

void rotate1(int* valOne, int* valTwo, int* valThree){
    int swapVar = *valOne;
    *valOne = *valTwo;
    *valTwo = *valThree;
    *valThree = swapVar;
}

void rotate2(int& valOne, int& valTwo, int& valThree){
    int shiftVar = valOne;
    valOne = valTwo;
    valTwo = valThree;
    valThree = shiftVar;
}


int main() {
  int firstVal = 1, secondVal = 2, thirdVal = 3;
  cout << "Before shift, a, b, c is: " << firstVal << " " << secondVal << " " << thirdVal << endl;
  rotate1(&firstVal, &secondVal, &thirdVal);
  cout << "After shift, a, b, c is: " << firstVal << " " << secondVal << " " << thirdVal << endl;

  int fourthVal = 9, fifthVal = 1, sixthVal = 2;
  cout << "Before shift, a, b, c is: " << fourthVal << " " << fifthVal << " " << sixthVal << endl;
  rotate2(fourthVal, fifthVal, sixthVal);
  cout << "After shift, a, b, c is: " << fourthVal << " " << fifthVal << " " << sixthVal << endl;

}

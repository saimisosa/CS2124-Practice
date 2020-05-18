#include <iostream>
using namespace std;

class Complex {
private:
    int real = 0;
    int imag = 0;
public:
    Complex(int real, int imag) : real(real), imag(imag) {}

    int getReal() const {
        return real;
    }

    int getImag() const {
        return imag;
    }

};

void addComplexNums(Complex& one, Complex& two){
    cout << "The sum of these numbers are: " << one.getReal() + two.getReal() << " + " << one.getImag() + two.getImag() << "i" << endl;
}

int main() {
    int realOne = 0;
    int imagOne = 0;
    int realTwo = 0;
    int imagTwo = 0;

    cout << "Enter the real and imaginary parts of one complex number: " << endl;
    cin >> realOne >> imagOne;

    cout << "Enter the real and imaginary parts of a second complex number: " << endl;
    cin >> realTwo >> imagTwo;

    Complex onePair = {realOne, imagOne};
    Complex twoPair = {realTwo, imagTwo};
    addComplexNums(onePair, twoPair);

}

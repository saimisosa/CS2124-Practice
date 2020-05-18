#include <iostream>
#include <cmath>
using namespace std;

//DEMONSTRATE USE OF THE COPY CONSTRUCTOR

// keeping the struct Point
struct Point {
    double x;
    double y;
};

void showPoint(Point test){
    cout << "(" << test.x << "," << test.y << ")";
}

double pointDist(Point one, Point two){
    double distance = 0.0;

    double xDist = one.x - two.x;
    double yDist = one.y - two.y;
    distance = pow(pow(xDist, 2) + pow(yDist, 2), .5);
    return distance;

}

bool pointEq(Point one, Point two){
    double xDiff = abs(one.x - two.x);
    double yDiff = abs(one.y - two.y);
    return xDiff < 0.000001 && yDiff < 0.000001;
}

//redoing the rectangle struct as a class, with copy control

class Rectangle {
private:
    Point upperRight;
    Point lowerLeft;
public:
    // constructor
    Rectangle(Point upperRight, Point lowerLeft) : upperRight(upperRight), lowerLeft(lowerLeft) {}
    // copy constructor
    Rectangle(const Rectangle& rhs) {
        upperRight = rhs.upperRight;
        lowerLeft = rhs.lowerLeft;
    }

    void showPoints(){
        cout << "The points are ";
        showPoint(lowerLeft);
        cout << " and ";
        showPoint(upperRight);
        cout << endl;
    }
};

int main() {
    Point firstPair = {2,3};
    Point secondPair = {7,10};
    Rectangle sample(firstPair, secondPair);
    cout << "-- Rectangle one --" << endl;
    sample.showPoints();

    Rectangle test = sample;
    cout << "-- Rectangle two --" << endl;
    test.showPoints();

    cout << endl;





}

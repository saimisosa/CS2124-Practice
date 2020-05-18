#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

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

struct Rectangle{
    Point upperRight;
    Point lowerLeft;
};

double recArea(Rectangle rectangle){
    double oneX = rectangle.lowerLeft.x;
    double oneY = rectangle.lowerLeft.y;
    double twoX = rectangle.upperRight.x;
    double twoY = rectangle.upperRight.y;

    double xLength = abs(oneX - twoX);
    double yLength = abs(oneY - twoY);
    return xLength * yLength;
}

double recArea2(Rectangle* rectangle){
    double oneX = rectangle->lowerLeft.x;
    double oneY = rectangle->lowerLeft.y;
    double twoX = rectangle->upperRight.x;
    double twoY = rectangle->upperRight.y;

    double xLength = abs(oneX - twoX);
    double yLength = abs(oneY - twoY);
    return xLength * yLength;
}

bool isWithin(Rectangle rectangle, Point point){
    double oneX = rectangle.lowerLeft.x;
    double oneY = rectangle.lowerLeft.y;
    double twoX = rectangle.upperRight.x;
    double twoY = rectangle.upperRight.y;

    if (oneX < twoX && oneY < twoY){
        return (point.x > oneX && point.x < twoX && point.y > oneY && point.y < twoY);
    } else if (oneX > twoX && oneY > twoY){
        return (point.x < oneX && point.x > twoX && point.y < oneY && point.y > twoY);
    } else if (oneX < twoX && oneY > twoY){
        return (point.x > oneX && point.x < twoX && point.y > twoY && point.y < oneY);
    } else if (oneX > twoX && oneY < twoY){
        return (point.x < oneX && point.x > twoX && point.y > oneY && point.y < twoY);
    } else {
        return false;
    }
}

bool isOverlap(Rectangle rect1, Rectangle rect2){
    return (isWithin(rect1, rect2.upperRight) && isWithin(rect1, rect2.lowerLeft));
}



int main() {
    Point zero = {1,2};
    cout << "(x,y) = ";
    showPoint(zero);
    cout << endl;

    Point one = {1,1};
    Point two = {2,2};
    cout << "Distance: " << pointDist(one, two) << endl;

    cout << endl;

    Point three = {1.0000000000002, 2.000000004};
    Point four = {1.0000000000001, 2.000000003};
    cout << "A) " << boolalpha << pointEq(three, four) << endl;

    Point five = {1.005, 2.08};
    Point six = {1.09, 2};
    cout << "B) " << boolalpha << pointEq(five, six) << endl;

    Point seven = {-99, 200};
    Point eight = {99, -200};
    cout << "C) " << boolalpha << pointEq(seven, eight) << endl;
    cout << endl;

    Rectangle rect1 = {4,8,0,0};
    cout << "The area of rectangle 1 is: " << recArea(rect1) << endl;

    Rectangle rect2 = {4,8,1,1};
    cout << "The area of rectangle 2 is: " << recArea(rect2) << endl;

    Rectangle rect3 = {5,8,-3,-8};
    cout << "The area of rectangle 3 is: " << recArea(rect3) << endl;

    cout << endl;

    Rectangle rect4 = {4,9,0,0};
    Point nine = {2,3};
    cout << boolalpha << isWithin(rect4, nine) << endl;

    Rectangle rect5 = {4,9,0,0};
    Point ten = {-1,-1};
    cout << boolalpha << isWithin(rect5, ten) << endl;

    Rectangle rect6 = {4,9,0,0};
    Point eleven = {0,3};
    cout << boolalpha << isWithin(rect6, eleven) << endl;

    Rectangle rect7 = {5,5,0,0};
    Rectangle rect8 = {4,4,1,1};
    cout << boolalpha << isOverlap(rect7, rect8) << endl;
    cout << endl;

    //Practice with checking the largest distance between points
    vector<Point> points;
    Point try1 = {};
    Point try2 = {};
    double maxDist = 0;

    Point a = {1,2};
    Point b = {11,20};
    Point c = {8,-3};
    Point d = {7,-10};
    Point e = {0,0};
    Point f = {12,12};
    Point g = {-100,-100};

    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    points.push_back(d);
    points.push_back(e);
    points.push_back(f);
    points.push_back(g);

    for (int i = 0; i < points.size() ; i++) {
        for (int j = i + 1 ; j < points.size() ; j++) {
            double dist = pointDist(points[i], points[j]);
            if (dist > maxDist){
                maxDist = dist;
                try1 = points[i];
                try2 = points[j];
            }
        }
    }
    cout << "Points ";
    showPoint(try1);
    cout << " and ";
    showPoint(try2);
    cout << " are the furthest apart, as they have a max distance of " << maxDist <<  "." << endl;

    //Practice with pointers
    Rectangle hello = {2,1,0,0};
    Rectangle* rectangleP = &hello;

    double area = recArea(*rectangleP);
    double area2 = recArea2(rectangleP);
    cout << endl;
    cout << "Area of rectangle hello is " << area << endl;
    cout << "Area of rectangle hello is " << area2 << endl;

    Rectangle bye = {5,5,8,8};
    Rectangle* rectangleO = &bye;
    cout << "The points in rectangleO are ";
    showPoint(rectangleO->lowerLeft);
    cout << " and ";
    showPoint(rectangleO->upperRight);
    cout << endl;

    return 0;

}


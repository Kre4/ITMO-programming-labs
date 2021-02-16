#include <iostream>
#include "geometry/point.h"
#include "geometry/BrokenLine.h"
#include "geometry/Chain.h"
#include "geometry/Polygon.h"
#include "geometry/Triangle.h"
int main() {
    //Point
    std::cout << "Point test\n";
    Point point(1, 2);
    std::cout << point.GetX() << "\n";
    point.SetCord(-9, 5);
    std::cout << point.GetX() << "\n";
    Point point1(5, 6);
    point = point1;
    std::cout << point.GetX() << "\n";
    //Broken Line
    std::cout << "Broken Line test\n";
    BrokenLine brokenLine(2);
    brokenLine.SetPoint(0, point);
    brokenLine.SetPoint(1, point1);
    std::cout << brokenLine[0].GetX() << "\n";
    //Chain
    std::cout << "Chain test\n";
    Chain chain(brokenLine);
    std::cout << chain.GetPoints()[0].GetX() << "\n";
    //Polygon
    Point p(0, 0);
    Point p1(1, 0);
    Point p2(2, 1);
    Point p3(2, 4); // change y to -1 for checking
    brokenLine.SetSize(4);
    brokenLine[0] = p;
    brokenLine[1] = p1;
    brokenLine[2] = p2;
    brokenLine[3] = p3;
    std::cout << "Polygon\n";
    chain.Set(brokenLine);
    Polygon polygon(chain);
    std::cout << polygon.GetPoints().Size() << "\n";
    //Triangle
    std::cout<< "Triangle test\n";
    brokenLine.SetSize(3);
    Triangle triangle(brokenLine);
    std::cout<<triangle.Square()<<" "<<triangle.Perim();
    return 0;
}

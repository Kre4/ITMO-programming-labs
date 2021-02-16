#include <iostream>
#include "geometry/point.h"
#include "geometry/BrokenLine.h"
int main() {
    //Point
    std::cout<<"Point test\n";
    Point point(1,2);
    std::cout<<point.GetX()<<"\n";
    point.SetCord(-9,5);
    std::cout<<point.GetX()<<"\n";
    Point point1(5,6);
    point = point1;
    std::cout<<point.GetX()<<"\n";
    //Broken Line
    std::cout<<"Broken Line test\n";
    BrokenLine brokenLine(2);
    brokenLine.SetPoint(0,point);
    brokenLine.SetPoint(1,point1);
    std::cout<<brokenLine[0].GetX();
    //Chain
    return 0;
}

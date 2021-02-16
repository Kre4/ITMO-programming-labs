#include <iostream>
#include "geometry.h"
class lol{
private:
    int x;
public:
    explicit lol(int x){
        this->x=x;
    }

};
int main() {
    Point point(1,2);

    Point point1(5,6);
    point.SetCord(5,5);
    point = point1;
    std::cout<<point.GetX()<<"\n";
    //BrokenLine brokenLine(3, 1.0,1.0,2.0,2.0,3.0,3.0);
    BrokenLine brokenLine(1,3.0,2.0);
    BrokenLine bl();
    return 0;
}

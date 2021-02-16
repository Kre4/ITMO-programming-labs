#ifndef CODE_TRIANGLE_H
#define CODE_TRIANGLE_H

#include "Polygon.h"

class Triangle: public Polygon{
public:
    explicit Triangle(const BrokenLine &br) : Polygon(br) {
        brokenLine = br;
        if (brokenLine.Size()!=3){
            brokenLine = nullptr;
        }
    }
    explicit Triangle(Chain &chain1) : Polygon(chain1) {
        Triangle tr(chain1.GetPoints());
        *this = tr;
    }
    Triangle& operator=(const Triangle&tr){
        brokenLine = tr.brokenLine;
        return *this;
    }
};
#endif //CODE_TRIANGLE_H

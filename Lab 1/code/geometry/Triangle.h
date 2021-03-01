#ifndef CODE_TRIANGLE_H
#define CODE_TRIANGLE_H

#include "Polygon.h"

class Triangle : public Polygon {
private:
    void check() const{
        if (brokenLine.Size() != 3){
            throw triangle_exception();
        }
    }
public:
    explicit Triangle(const BrokenLine &br) : Polygon(br) {
        check();
    }

    explicit Triangle(const Chain &chain1) : Polygon(chain1) {
        check();
    }

    Triangle(const Triangle &triangle) : Polygon(triangle) {
        check();
    }

    Triangle &operator=(const Triangle &tr) {
        if (this == &tr)
            return *this;
        brokenLine = tr.brokenLine;
        return *this;
    }
};

#endif //CODE_TRIANGLE_H

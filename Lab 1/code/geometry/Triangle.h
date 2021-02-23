#ifndef CODE_TRIANGLE_H
#define CODE_TRIANGLE_H

#include "Polygon.h"

class Triangle : public Polygon {
public:
    explicit Triangle(const BrokenLine &br) : Polygon(br) {
        if (brokenLine.Size() != 3) {
            brokenLine.SetNull();
        }
    }

    explicit Triangle(const Chain &chain1) : Polygon(chain1) {
        if (brokenLine.Size() != 3) {
            brokenLine.SetNull();
        }
    }

    Triangle(const Triangle &triangle) : Polygon(triangle) {
        brokenLine = triangle.brokenLine;
    }

    Triangle &operator=(const Triangle &tr) {
        if (this == &tr)
            return *this;
        brokenLine = tr.brokenLine;
        return *this;
    }
};

#endif //CODE_TRIANGLE_H

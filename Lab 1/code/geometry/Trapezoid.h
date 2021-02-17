#ifndef CODE_TRAPEZOID_H
#define CODE_TRAPEZOID_H

#include "Polygon.h"

class Trapezoid : public Polygon {
public:
    Trapezoid(const BrokenLine &bl) : Polygon(bl) {
        brokenLine = bl;
        if (brokenLine.Size() != 4) {
            brokenLine = nullptr;
            return;
        }
        bool isTrapezoid = false;
        for (int i = 0; i < brokenLine.Size() && !isTrapezoid; i++) {
            float x1 = brokenLine[i].GetY() - brokenLine[i + 1].GetY();
            float y1 = brokenLine[i + 1].GetX() - brokenLine[i].GetX();
            float x2 = brokenLine[i + 2].GetY() - brokenLine[i + 3].GetY();
            float y2 = brokenLine[i + 3].GetX() - brokenLine[i + 2].GetX();
            if (x1 / y1 == x2 / y2) {
                isTrapezoid = true;
            }
        }
        if (!isTrapezoid)
            brokenLine = nullptr;

    }

    Trapezoid(Chain &chain) : Polygon(chain) {
        Trapezoid trapezoid(chain.GetPoints());
        *this = chain;
    }

    Trapezoid &operator=(const Trapezoid &trapezoid) {
        brokenLine = trapezoid.brokenLine;
        return *this;
    }

    Trapezoid(const Trapezoid &trapezoid) : Polygon(trapezoid) {
        brokenLine = brokenLine;
    }

};

#endif //CODE_TRAPEZOID_H

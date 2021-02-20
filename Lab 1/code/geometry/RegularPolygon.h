#ifndef CODE_REGULARPOLYGON_H
#define CODE_REGULARPOLYGON_H

#include "Polygon.h"

class RegularPolygon : public Polygon {
public:
    RegularPolygon(const BrokenLine &bl) : Polygon(bl) {
        brokenLine = bl;
        for (int i = 0; i < brokenLine.Size(); i++) {
            if (len(brokenLine[i], brokenLine[i + 1]) == len(brokenLine[i + 1], brokenLine[i + 2])) {
            } else {
                brokenLine = nullptr;
                return;
            }
        }
    }

    RegularPolygon(Chain &chain) : Polygon(chain) {
        RegularPolygon regularPolygon(chain.GetPoints());
        *this = regularPolygon;
    }

    RegularPolygon(const RegularPolygon &regularPolygon) : Polygon(regularPolygon) {
        brokenLine = regularPolygon.brokenLine;
    }

    RegularPolygon &operator=(const RegularPolygon &regularPolygon) {
        brokenLine = regularPolygon.brokenLine;
        return *this;
    }
};

#endif //CODE_REGULARPOLYGON_H

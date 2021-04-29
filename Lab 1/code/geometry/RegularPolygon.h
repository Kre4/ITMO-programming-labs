#ifndef CODE_REGULARPOLYGON_H
#define CODE_REGULARPOLYGON_H

#include "Polygon.h"

class RegularPolygon : public Polygon {
private:
    void check() const {
        for (int i = 0; i < brokenLine.Size(); i++) {
            if (len(brokenLine[i], brokenLine[i + 1]) == len(brokenLine[i + 1], brokenLine[i + 2])) {
            } else {
                throw regular_polygon_exception();
            }
        }

    }

public:
    explicit RegularPolygon(const BrokenLine &bl) : Polygon(bl) {
        check();
    }

    explicit RegularPolygon(const Chain &chain) : Polygon(chain) {
        check();
    }

    explicit RegularPolygon(const RegularPolygon &regularPolygon) : Polygon(regularPolygon) {

    }

    RegularPolygon &operator=(const RegularPolygon &regularPolygon) {
        if (this == &regularPolygon)
            return *this;
        brokenLine = regularPolygon.brokenLine;
        return *this;
    }
};

#endif //CODE_REGULARPOLYGON_H

#ifndef CODE_POLYGON_H
#define CODE_POLYGON_H

#include "Chain.h"
#include "math.h"

class Polygon : public Chain {
protected:
    float S = -1;
    float P = -1;

    float len(Point &p1, Point &p2) {
        return sqrt(float(pow(p1.GetX() - p2.GetX(), 2) + pow(p1.GetY() - p2.GetY(), 2)));
    }

public:
    explicit Polygon(const BrokenLine &br) {
        brokenLine = br;
        if (brokenLine.Size() < 3)
            brokenLine = nullptr;
        for (int i = 0; i < brokenLine.Size() - 1; i++) {
            float x = brokenLine[i].GetY() - brokenLine[i + 1].GetY();
            float y = brokenLine[i + 1].GetX() - brokenLine[i].GetX();
            float c = brokenLine[i].GetX() * brokenLine[i + 1].GetY() - brokenLine[i + 1].GetX() * brokenLine[i].GetY();
            float znak = 0;
            int counter = 0;
            for (int j = 0; j < brokenLine.Size(); j++) {
                if (j != i && j != i + 1) {
                    float value = x * brokenLine[j].GetX() + y * brokenLine[j].GetY() + c;
                    if (counter == 0) {
                        znak = value / std::abs(value);
                        counter++;
                    } else {
                        if (value / std::abs(value) != znak) {
                            brokenLine = nullptr;
                            return;
                        }
                    }
                }
            }
        }
    }

    explicit Polygon(Chain &chain) {
        brokenLine = chain.GetPoints();
        Polygon p(brokenLine);
        *this = p;
    }

    Polygon(const Polygon &polygon) {
        brokenLine = polygon.brokenLine;
    }

    Polygon &operator=(const Polygon &polygon) {
        brokenLine = polygon.brokenLine;
        return *this;
    }

    float Square() {
        if (S == -1) {
            float tmp = 0;
            for (int i = 0; i < brokenLine.Size() - 1; i++) {
                tmp += brokenLine[i].GetX() * brokenLine[i + 1].GetY();
                tmp -= brokenLine[i + 1].GetX() * brokenLine[i].GetY();
            }
            tmp += brokenLine[brokenLine.Size() - 1].GetX() * brokenLine[0].GetY() -
                   brokenLine[0].GetX() * brokenLine[brokenLine.Size() - 1].GetY();
            S = abs(tmp) / 2;
        }
        return S;
    }

    float Perim() {
        if (P == -1) {
            float tmp = 0;
            for (int i = 0; i < brokenLine.Size(); i++) {
                if (i == brokenLine.Size() - 1) {
                    tmp += len(brokenLine[0], brokenLine[i]);
                } else
                    tmp += len(brokenLine[i], brokenLine[i + 1]);
            }
            P = tmp;
        }
    return P;
    }

};


#endif //CODE_POLYGON_H

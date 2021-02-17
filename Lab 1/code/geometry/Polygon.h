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

    float angle(Point &p1, Point &p2, Point &p3) {
        float A1 = p1.GetY() - p2.GetY();
        float B1 = p2.GetX() - p1.GetX();
        float A2 = p2.GetY() - p3.GetY();
        float B2 = p3.GetX() - p2.GetX();;
        return acos((A1 * A2 + B1 * B2) / (sqrt(A1 * A1 + B1 * B1) * sqrt(A2 * A2 + B2 * B2))) * 180 / M_PI;
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
            for (int i = 0; i < brokenLine.Size(); i++) {
                tmp += brokenLine[i].GetX() * brokenLine[i + 1].GetY();
                tmp -= brokenLine[i + 1].GetX() * brokenLine[i].GetY();
            }
            //tmp += brokenLine[brokenLine.Size() - 1].GetX() * brokenLine[0].GetY() -
            //     brokenLine[0].GetX() * brokenLine[brokenLine.Size() - 1].GetY();

            S = tmp / 2;
        }
        return S;
    }

    float Perim() {
        if (P == -1){
            float tmp = 0;
            for (int i = 0; i < brokenLine.Size(); i++) {
                //if (i == brokenLine.Size() - 1) {
                //    tmp += len(brokenLine[0], brokenLine[i]);
                //} else
                tmp += len(brokenLine[i], brokenLine[i + 1]);
            }
            P = tmp;
        }
        return P;
    }

};


#endif //CODE_POLYGON_H

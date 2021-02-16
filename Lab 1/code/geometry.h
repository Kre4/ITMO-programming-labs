#ifndef CODE_GEOMETRY_H
#define CODE_GEOMETRY_H

#include <vector>
#include <stdarg.h>

class Point {
private:
    float x, y;
public:
    Point() {
        x = 0;
        y = 0;
    };

    Point(float x, float y) {
        this->x = x;
        this->y = y;
    }


    void SetCord(float x, float y) {
        this->x = x;
        this->y = y;
    }

    float GetX() {
        return x;
    }

    float GetY() {
        return y;
    }

    void SetX(float x) {
        this->x = x;
    }

    void SetY(float y) {
        this->y = y;
    }

    Point &operator=(Point p) {
        SetCord(p.GetX(), p.GetY());
        return *this;
    }

    Point(const Point &p) {
        this->x = p.x;
        this->y = p.y;
    }
};


class BrokenLine {
private:
    std::vector<Point> points;

public:

     BrokenLine(long long n,...) {
        points.resize(n);
        va_list args;
        va_start(args, n);

        for (int i = 0; i < n; i++) {

            points[i].SetX(va_arg(args, double ));
           points[i].SetY(va_arg(args, double ));

        }
        va_end(args);
    }

    BrokenLine(const BrokenLine &BL) {
         this->points.resize(BL.points.size());
         for (int i=0;i<points.size();i++){
             points[i] = BL.points[i];
         }
    }
    BrokenLine &operator=(const BrokenLine& bl) {
        this->points.resize(bl.points.size());
        for (int i=0;i<points.size();i++){
            points[i] = bl.points[i];
        }
        return *this;
    }


};

#endif //CODE_GEOMETRY_H

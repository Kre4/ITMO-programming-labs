#ifndef CODE_BROKENLINE_H
#define CODE_BROKENLINE_H

#include "point.h"
#include <iostream>

class BrokenLine {
private:
    std::size_t N;
    Point *points;
public:

    explicit BrokenLine(std::size_t n = 0) :
            N(n) {
        if (N == 0)
            points = nullptr;
        else
            points = new Point[N];
    }

    BrokenLine(std::size_t n, Point *array) {
        N = n;
        points = new Point[N];
        for (int i = 0; i < N; i++) {
            points[i] = array[i];
        }
    }

    BrokenLine(const BrokenLine &bl) :
            N(bl.N) {
        points = new Point[N];
        for (int i = 0; i < N; i++) {
            points[i] = bl.points[i];
        }
    }

    BrokenLine &operator=(const BrokenLine &bl) {
        N = bl.N;
        points = new Point[N];
        for (int i = 0; i < N; i++) {
            points[i] = bl.points[i];
        }
        return *this;
    }

    BrokenLine &operator=(const std::nullptr_t aNullptr) {
        N = 0;
        points = nullptr;
        return *this;
    }

    Point &operator[](const int index) {
        return points[index];
    }

    void SetPoint(int index, const Point &point) {
        if (index >= N)
            throw std::out_of_range("Incorrect index");
        points[index] = point;
    }

    void SetSize(int n) {
        Point *tmp = new Point[N];
        for (int i = 0; i < N; i++)
            tmp[i] = points[i];
        N = n;
        points = new Point[N];
        for (int i = 0; i < N; i++)
            points[i] = tmp[i];
        delete[] tmp;
    }

    int Size() {
        return N;
    }


    ~BrokenLine() {
        delete[] points;
    }

};

#endif //CODE_BROKENLINE_H

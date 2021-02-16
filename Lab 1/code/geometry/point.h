#ifndef CODE_POINT_H
#define CODE_POINT_H

class Point {
private:
    float x, y;
public:


    Point(float x = 0, float y = 0) :
            x(x), y(y) {}


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


    Point &operator=(Point p) {
        SetCord(p.GetX(), p.GetY());
        return *this;
    }

    Point(const Point &p) :
            x(p.x), y(p.y) {}

};

#endif //CODE_POINT_H

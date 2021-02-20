#ifndef CODE_POINT_H
#define CODE_POINT_H

class Point {
private:
    float x, y;
public:


    Point(float x = 0, float y = 0) :
            x(x), y(y) {}




    float GetX() const {
        return x;
    }

    float GetY() const {
        return y;
    }

    float SetX(float x){
        this->x = x;
    }
    float SetY(float y){
        this->y = y;
    }
    Point &operator=(const Point& p) {
        //SetCord(p.GetX(), p.GetY());
        SetX(p.GetX());
        SetY(p.GetY());
        return *this;
    }

    Point(const Point &p) :
            x(p.x), y(p.y) {}

};

#endif //CODE_POINT_H

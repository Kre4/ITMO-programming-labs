#ifndef CODE_MINI_CUBE_H
#define CODE_MINI_CUBE_H

#include <cstdio>
#include <vector>
#include <iostream>
#include <windows.h>

#define WHITE 0
#define BLUE 1
#define RED 2
#define YELLOW 3
#define ORANGE 4
#define GREEN 5
class mini_cube {
public:
    // 0 верхняя   1 нижняя
    // 4 передняя  5 задняя
    // 2 левая     3 правая
    std::vector<unsigned short> color;

    mini_cube() {
        color.assign(6, 0);
    }
    void setColor(int i, unsigned short color)
    {
        this->color[i] = color;
    }

    void out(int i){
        switch (color[i]) {
            case WHITE: SetColor(15,0); break;
            case BLUE:SetColor(1,0); break;
            case RED: SetColor(4,0); break;
            case YELLOW:SetColor(14,0); break;
            case ORANGE:SetColor(6, 0); break;
            case GREEN:SetColor(10,0); break;
        }
        std::cout<<color[i]<<" ";
    }
    //Z
    void rotateX0Y() {
        auto tmp = color[5];
        color[5] = color[3];
        color[3] = color[4];
        color[4] = color[2];
        color[2] = tmp;
    }
    //Y
    void rotateX0Z() {
        auto tmp = color[2];
        color[2] = color[1];
        color[1] = color[3];
        color[3] = color[0];
        color[0] = tmp;
    }
    //X
    void rotateY0Z() {
        auto tmp = color[0];
        color[0] = color[4];
        color[4] = color[1];
        color[1] = color[5];
        color[5] = tmp;
    }

private:
    void SetColor(int text, int bg){
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
    }

};


#endif //CODE_MINI_CUBE_H

#ifndef CODE_RUBIK_H
#define CODE_RUBIK_H

#include "mini_cube.h"
#include <iostream>

#define WHITE 0
#define BLUE 1
#define RED 2
#define YELLOW 3
#define ORANGE 4
#define GREEN 5

class rubik {
    std::vector<std::vector<std::vector<mini_cube>>> a;
    std::vector<unsigned short> color;

    std::vector<int> rotate;
public:
    int current;

    rubik() {
        a.assign(3, std::vector<std::vector<mini_cube>>(3, std::vector<mini_cube>(3)));
        clear();
    }


    void clear(std::vector<unsigned int> color = {}) {

        current = -1;

        int i, j, k;
//        for (i = 0; i < 6; i++)
//            this->color[i] = color[i];

        // upper
        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                a[i][j][2].setColor(0, BLUE);

        // lower
        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                a[i][j][0].setColor(1, GREEN);


        // left
        for (i = 0; i < 3; i++)
            for (k = 0; k < 3; k++)
                a[0][k][i].setColor(2, YELLOW);

        // right
        for (i = 0; i < 3; i++)
            for (k = 0; k < 3; k++)
                a[2][k][i].setColor(3, WHITE);
        // front
        for (k = 0; k < 3; k++)
            for (j = 0; j < 3; j++)
                a[j][0][k].setColor(4, ORANGE);

        // back
        for (k = 0; k < 3; k++)
            for (j = 0; j < 3; j++)
                a[j][2][k].setColor(5, RED);


    }

    // 0 верхняя   1 нижняя
    // 4 передняя  5 задняя
    // 2 левая     3 правая
    void rotate_90_degree(short int side, short int direction) {
        if (direction == -1)
            direction = 3;

        for (; direction > 0; --direction) {
            // upper and lower
            if (side == 0 || side == 1) {
                int k = (side == 1) ? (0) : 2;
                for (int i = 0; i < 3; ++i)
                    for (int j = 0; j < 3; ++j)
                        a[i][j][k].rotateX0Y();
                for (int i = 0; i < 3; ++i)
                    for (int j = i; j < 3; ++j)
                        std::swap(a[i][j][k], a[j][i][k]);
                for (int i = 0; i < 3; ++i)
                    std::swap(a[i][0][k], a[i][2][k]);
            }
            // right and left
            if (side == 2 || side == 3) {
                int i = (side == 2) ? (0) : (2);
                for (int j = 0; j < 3; ++j)
                    for (int k = 0; k < 3; ++k)
                        a[i][j][k].rotateY0Z();
                for (int j = 0; j < 3; ++j)
                    for (int k = j; k < 3; ++k)
                        std::swap(a[i][k][k], a[i][j][k]);
                for (int j = 0; j < 3; ++j)
                    std::swap(a[i][j][0], a[i][j][2]);
            }
            //front and back
            if (side == 4 || side == 5) {
                int j = (side == 4) ? (0) : (2);
                for (int i = 0; i < 3; ++i)
                    for (int k = 0; k < 3; ++k)
                        a[i][j][k].rotateX0Z();
                for (int i = 0; i < 3; ++i)
                    for (int k = 0; k < 3; ++k)
                        std::swap(a[i][j][k], a[k][j][i]);
                for (int k = 0; k < 3; ++k)
                    std::swap(a[0][j][k], a[2][j][k]);
            }
        }

    }

    void out() {
        //upper
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 3; ++i)
                std::cout << "  ";
            for (int i = 0; i < 3; ++i)
                a[j][i][2].out(0);


            for (int i = 0; i < 3; ++i)
                std::cout << "  ";
            std::cout << "\n";
        }
        //left - front - right
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 3; ++i)
                a[0][i][2 - j].out(2);
            for (int i = 0; i < 3; ++i)
                a[i][0][2 - j].out(4);
            for (int i = 0; i < 3; ++i)
                a[2][i][2 - j].out(3);
            std::cout << "\n";
        }
        //lower
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 3; ++i)
                std::cout << "  ";
            for (int i = 0; i < 3; ++i)
                a[j][i][0].out(1);
            for (int i = 0; i < 3; ++i)
                std::cout << "  ";
            std::cout << "\n";

        }
        //back
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 3; ++i)
                std::cout << "  ";
            for (int i = 0; i < 3; ++i)
                a[i][2][j].out(5);
            for (int i = 0; i < 3; ++i)
                std::cout << "  ";
            std::cout << "\n";
        }

    }

};

#endif //CODE_RUBIK_H

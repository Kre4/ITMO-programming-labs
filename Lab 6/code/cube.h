#ifndef CODE_CUBE_H
#define CODE_CUBE_H

#include "side.h"
#include <iostream>

/*
  WHITE = 1,
    BLUE = 2,
    RED = 3,
    YELLOW = 4,
    ORANGE = 5,
    GREEN = 6
 */
class cube {
public:
    side upper_side;
    side lower_side;
    side right_side;
    side left_side;
    side front_side;
    side back_side;
public:
    cube() : upper_side(WHITE), lower_side(BLUE), right_side(RED), left_side(YELLOW), front_side(ORANGE),
             back_side(GREEN) {}

    void out() {
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 3; ++i)
                std::cout << "  ";
            for (int i = 0; i < 3; ++i)
                std::cout << upper_side[j][i]<<" ";
            for (int i = 0; i < 3; ++i)
                std::cout << "  ";
            std::cout<<"\n";
        }
        for (int j=0;j<3;++j){
            for (int i=0;i<3;++i)
                std::cout<<left_side[j][i]<<" ";
            for (int i=0;i<3;++i)
                std::cout<<front_side[j][i]<<" ";
            for (int i=0;i<3;++i)
                std::cout<< right_side[j][i]<<" ";
            std::cout<<"\n";
        }

        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 3; ++i)
                std::cout << "  ";
            for (int i = 0; i < 3; ++i)
                std::cout << lower_side[j][i]<<" ";
            for (int i = 0; i < 3; ++i)
                std::cout << "  ";
            std::cout<<"\n";
        }
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 3; ++i)
                std::cout << "  ";
            for (int i = 0; i < 3; ++i)
                std::cout << back_side[j][i]<<" ";
            for (int i = 0; i < 3; ++i)
                std::cout << "  ";
            std::cout<<"\n";
        }
    }
    void turn_90_degree_minus(side& sd){
        for (int i=0;i<3;++i)
            for(int j=i;j<3;++j)
                std::swap(sd[i][j],sd[j][i]);
        std::swap(sd[0], sd[2]);

    }

};

#endif //CODE_CUBE_H

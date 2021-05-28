#ifndef CODE_CUBE_H
#define CODE_CUBE_H

#include "side.h"

/*
  WHITE = 1,
    BLUE = 2,
    RED = 3,
    YELLOW = 4,
    ORANGE = 5,
    GREEN = 6
 */
class cube {
private:
    side upper_side;
    side lower_side;
    side right_side;
    side left_side;
    side front_side;
    side back_side;
public:
    cube() : upper_side(WHITE), lower_side(BLUE), right_side(RED), left_side(YELLOW), front_side(ORANGE),
             back_side(GREEN) {}
};

#endif //CODE_CUBE_H

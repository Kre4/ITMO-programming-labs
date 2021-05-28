#ifndef CODE_SIDE_H
#define CODE_SIDE_H
#include <vector>
#include <stdio.h>
enum color{
    WHITE = 1,
    BLUE = 2,
    RED = 3,
    YELLOW = 4,
    ORANGE = 5,
    GREEN = 6
};
class side{
public:
    std::vector<std::vector<color>> colors;
    side(color C){
        colors.assign(3,std::vector<color>(3,C));
    }
};
#endif //CODE_SIDE_H

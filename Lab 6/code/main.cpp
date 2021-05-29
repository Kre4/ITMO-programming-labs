#include <iostream>
#include "cube.h"
#include <vector>
int main(){
    cube rubik;
    rubik.turn_90_degree_minus(rubik.front_side);
    rubik.out();

    return 0;
}
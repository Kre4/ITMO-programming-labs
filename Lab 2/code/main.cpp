#include <iostream>
#include "Polynomial.h"
int main() {
    Polynomial p1(2, 1.0, 0.0, 2.0);
    Polynomial p2(3, 0.0, 1.0, 5.0, 2.0);
    std::cout<<p2[3]<<"\n";
    p1-=p2;
    //std::cout<<p1[3]<<" "<<p2[3]<<"\n";
    for (int i=0;i<4;i++){
        std::cout<<p1[i]<<" ";
    }
    return 0;
}
#include <iostream>
#include "Polynomial_vector.h"

int main() {
    polynomial_v p1(2, {1.0, 0.0, 2.0});
    polynomial_v p2(3, {0.0, 1.0, 5.0, 2.0});
    polynomial_v p3;
    p1/=3;
    std::cout << p1.Size() << "\n";



    //std::cout<<p1<<"\n";
    for (int i = 0; i < p1.Size() + 1; i++) {
        std::cout << p1[i] << " ";
    }
    //std::cout<<p1<<"\n";
    //Polynomial ppp(2, {1,2, 3});
    //std::cin>>ppp;
    //std::cout<<ppp;
    return 0;
}

#include <iostream>
#include <vector>
#include "stlupgrade.h"
#include <algorithm>

//a = четное
bool rule(int a) {
    return !(a % 2);
}

bool comparator(int a, int b) {
    return a <= b;
}

int main() {

    std::vector<int> vec = {};

    //std::cout << *vec.begin() << " " << *(vec.end() - 1) << "\n";
    //std::cout << *std::find_if_not(vec.begin(), vec.end(), rule) << "\n";
    std::cout << stl::is_palindrome(vec.begin(), vec.end(), rule);
    return 0;
}

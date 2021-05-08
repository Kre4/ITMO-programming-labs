#include <iostream>
#include <vector>
#include "cb_iterator.h"
#include "circular_buffer.h"
#include <algorithm>
#include <list>
using namespace cbuf;
#define endl std::cout<<"\n"
int main() {

    ring<int> ring({1,2,5,4});
    ring.pop_back();
    ring.pop_back();
    std::cout<<"Begin/back/end\n"<<*ring.begin()<< " "<<*ring.back()<<" "<<*ring.end()<<"\n";
    endl;
    for (int i = 0; i < ring.size(); ++i) {
        std::cout << ring[i] << " ";
    }
    endl;

    //ring.resize(3);
    std::cout<<"Begin/back/end\n"<<*ring.begin()<< " "<<*ring.back()<<" "<<*ring.end()<<"\n";
    endl;
    for (int i = 0; i < ring.size(); ++i) {
        std::cout << ring[i] << " ";
    }
    endl;
//    ring.push_back(10);
//    for (int i = 0; i < 4; ++i) {
//        std::cout << ring.data_[i] << " ";
//    }
    endl;
//    std::sort(ring.begin(), ring.end());
//
//
//    std::cout<<"\n"<<*ring.begin()<< " "<<*ring.back()<<"\n";
//    endl;
//    for (int i = 0; i < 5; ++i) {
//        std::cout << ring.data_[i] << " ";
//    }

    std::cout<<"Size: "<<ring.size()<<"\nCapacity: "<<ring.capacity();

    return 0;
}

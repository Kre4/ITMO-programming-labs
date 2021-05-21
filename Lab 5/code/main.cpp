#include <iostream>
#include <vector>
#include "cb_iterator.h"
#include "circular_buffer.h"
#include <algorithm>
#include <list>
using namespace cbuf;
#define endl std::cout<<"\n"
int main() {

    ring<int> ring(3);
    ring.push_back(1);
    ring.push_back(3);
    ring.push_back(2);
    ring.push_back(228);
    std::cout<<"Begin/back/end\n"<<*ring.begin()<< " "<<ring.back()<<" "<<*ring.end()<<"\n";
    endl;
    for (int i = 0; i < ring.size(); ++i) {
        std::cout << ring[i] << " ";
    }
    endl;
    auto a = ring.begin();
    auto b = ring.end();
    auto c = ring.data_+ring.capacity_;
    int aa = 1;
    ring.resize(4);
    //std::sort(ring.begin(), ring.end());
    //ring.resize(3);
   // std::cout<<"Begin/back/end\n"<<*ring.begin()<< " "<<ring.back()<<" "<<*ring.end()<<"\n";
    endl;
    for (int i = 0; i < ring.capacity_; ++i) {
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

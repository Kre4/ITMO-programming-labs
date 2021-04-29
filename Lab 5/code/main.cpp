#include <iostream>
#include <vector>
#include "cb_iterator.h"
#include "circular_buffer.h"
#include <algorithm>
using namespace cbuf;
int main() {

    int *jopa = new int[10];
    *jopa = 5;
    *(jopa+5) = 2;
    random_access_iterator<int> iter(jopa);
    iter[5] = 3;
    iter+=4;
    iter++;
    ring<int> ring({1,5,4,2});
    std::sort(ring.begin(), ring.end());
    for (int i=0;i<4;++i){
        std::cout<<ring.data_[i]<<" ";
    }
        //std::cout<<"\n"<<*ring.begin()<< " "<<*ring.end()<<"\n";

    return 0;
}

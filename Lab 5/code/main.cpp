#include <iostream>
#include <vector>
#include "cb_iterator.h"
#include "circular_buffer.h"
#include <algorithm>
#include <list>
#include <string>

#define endl std::cout<<"\n"
class dumbInt{
public:

    std::string a = "not constructed";
    dumbInt(int a_){
        a = std::to_string(a_);
    }
    dumbInt(){
        a = "not constructed";
    }

    ~dumbInt(){
        a = "destroyed";
    }
    friend std::ostream& operator<<(std::ostream& out, dumbInt& item);
};

std::ostream &operator<<(std::ostream &out, dumbInt &item) {
    out<<item.a;
    return out;
}

int main() {

    cbuf::ring<int> ring(3);
//    ring.push_front(1);
//
//   // ring.push_front(228);
//    ring.pop_back();
    ring.push_back(1);
    ring.push_back(2);
    ring.push_back(3);
    ring.push_back(228);

    std::cout<<"Begin/back/end\n"<<*ring.begin()<< " "<<ring.back()<<" "<<*ring.end()<<"\n";
    endl;
    for (int i = 0; i < ring.size(); ++i) {
        std::cout << ring[i] << " ";
    }
    endl;





    std::cout<<"Size: "<<ring.size()<<"\nCapacity: "<<ring.capacity();

    return 0;
}

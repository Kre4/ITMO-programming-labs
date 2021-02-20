#ifndef CODE_CHAIN_H
#define CODE_CHAIN_H

#include "BrokenLine.h"

class Chain {
protected:
    BrokenLine brokenLine;
public:
    Chain() = default;

    Chain(const BrokenLine& bl) :
            brokenLine(bl) {}

    BrokenLine GetPoints() {

        return brokenLine;
    }

    Chain(const Chain &chain) :
            brokenLine(chain.brokenLine) {}

    Chain &operator=(const Chain &chain) {
        brokenLine = chain.brokenLine;
        return *this;
    }


    Chain &operator=(const BrokenLine &bl) {
        brokenLine = bl;
        return *this;
    }


    Point& operator[](int index) const{
        return brokenLine[index%brokenLine.Size()];
    }

    int Size() const{
        return brokenLine.Size();
    }

    void SetNull(){
        brokenLine.SetNull();
    }

    void Set(BrokenLine &br) {
        brokenLine = br;
    }

};

#endif //CODE_CHAIN_H

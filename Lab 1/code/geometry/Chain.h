#ifndef CODE_CHAIN_H
#define CODE_CHAIN_H

#include "BrokenLine.h"

class Chain {
protected:
    BrokenLine brokenLine;
public:
    Chain() = default;

    Chain(BrokenLine bl) :
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

    Chain &operator=(const std::nullptr_t aNullptr) {
        brokenLine = nullptr;
        return *this;
    }

    int Size() {
        return brokenLine.Size();
    }

    void Set(BrokenLine br) {
        brokenLine = br;
    }

};

#endif //CODE_CHAIN_H

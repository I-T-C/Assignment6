//
// Created by Imran Thompson on 14.5.18.
//

#ifndef COPYCONTROL_DYNAMICSTACKITERATOR_H
#define COPYCONTROL_DYNAMICSTACKITERATOR_H

#include "DynamicStack.h"

template <class T>
class DynamicStackIterator {
private:
    DynamicStack<T> fStack;

public:
    DynamicStackIterator(const DynamicStack<T>& aStack)
    {
        fStack = aStack;
    }

    const T& operator*() const
    {
        return fStack.top();
    }

    DynamicStackIterator& operator++()
    {
        fStack.pop();
        return *this;
    }

    DynamicStackIterator operator++(int)
    {
        DynamicStackIterator<T> temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const DynamicStackIterator& aOtherIter) const
    {
        return fStack.size() == aOtherIter.fStack.size();
    }

    bool operator!=(const DynamicStackIterator& aOtherIter) const
    {
        return !(*this == aOtherIter);
    }

    DynamicStackIterator end() const   // new iterator (after last increment)
    {
        return DynamicStackIterator(DynamicStack<T>());
    }
};


#endif //COPYCONTROL_DYNAMICSTACKITERATOR_H

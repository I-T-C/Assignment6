//
// Created by Imran Thompson on 13.5.18.
//

#ifndef COPYCONTROL_DYNAMICSTACK_H
#define COPYCONTROL_DYNAMICSTACK_H

#include "List.h"
#include <stdexcept>

template <class T>
class DynamicStack {
private:
    List<T> fElements;
    int fLimit = 10;

public:
    bool isEmpty() const
    {
        return fElements.isEmpty();
    }

    int size() const
    {
        return fElements.size();
    }

    void push( const T& aItem)
    {
        if(size() >= fLimit)
            throw std::overflow_error("Stack is full");
        else
            fElements.push_front(aItem);
    }


    void pop()
    {
        if(isEmpty())
            throw std::underflow_error("Stack is empty");
        else
            fElements.remove(fElements[0]);
    }

    const T& top() const
    {
        return fElements[0];
    }
};

#endif //COPYCONTROL_DYNAMICSTACK_H








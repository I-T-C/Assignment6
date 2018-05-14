//
// Created by Imran Thompson on 14.5.18.
//

#ifndef COPYCONTROL_DYNAMICQUEUE_H
#define COPYCONTROL_DYNAMICQUEUE_H

#include "List.h"
#include <stdexcept>

template <class T>
class DynamicQueue {
private:
    List<T> fElements;

public:
    bool isEmpty() const
    {
        return fElements.isEmpty();
    }

    int size() const
    {
        return fElements.size();
    }

    void enqueue(const T& aElement)
    {
        fElements.push_back(aElement);
    }

    void dequeue()
    {
        if(isEmpty())
            throw std::underflow_error("Queue is empty");

        else
            fElements.remove(fElements[0]);
    }

    const T& top() const
    {
        if(isEmpty())
            throw std::underflow_error("Queue is empty");

        else
            return fElements[0];
    }
};

#endif //COPYCONTROL_DYNAMICQUEUE_H

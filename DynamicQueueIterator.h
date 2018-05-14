//
// Created by Imran Thompson on 13.5.18.
//

#ifndef COPYCONTROL_DYNAMICQUEUEITERATOR_H
#define COPYCONTROL_DYNAMICQUEUEITERATOR_H

#include "DynamicQueue.h"

template<class T>
class DynamicQueueIterator
{
private:
    DynamicQueue<T> fQueue;

public:
    DynamicQueueIterator(const DynamicQueue<T>& aQueue)
    {
        fQueue = aQueue;
    }

    const T& operator*()
    {
        return fQueue.top();
    }

    DynamicQueueIterator& operator++()
    {
        fQueue.dequeue();
        return *this;
    }

    DynamicQueueIterator operator++(int)
    {
        DynamicQueueIterator temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const DynamicQueueIterator& aOtherIter) const
    {
        return fQueue.size() == aOtherIter.fQueue.size();
    }

    bool operator!=(const DynamicQueueIterator& aOtherIter) const
    {
        return !(*this == aOtherIter);
    }

    DynamicQueueIterator end() const
    {
        return DynamicQueueIterator(DynamicQueue<T>());
    }

};
#endif //COPYCONTROL_DYNAMICQUEUEITERATOR_H

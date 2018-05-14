//
// Created by Imran Thompson on 11.5.18.
//

#ifndef COPYCONTROL_DOUBLYLINKEDNODEITERATOR_H
#define COPYCONTROL_DOUBLYLINKEDNODEITERATOR_H

#include "DoublyLinkedNode.h"

template <class T>
class DoublyLinkedNodeIterator {
private:
    enum IteratorStates { BEFORE, DATA , AFTER };

    IteratorStates fState;

    typedef DoublyLinkedNode<T> Node;

    const Node* fLeftmost;
    const Node* fRightmost;
    const Node* fCurrent;

public:
    typedef DoublyLinkedNodeIterator<T> Iterator;

    DoublyLinkedNodeIterator( const Node& aList );

    const T& operator*() const;	// dereference
    Iterator& operator++();				// prefix increment
    Iterator operator++(int);			// postfix increment
    Iterator& operator--();				// prefix decrement
    Iterator operator--(int);			// postfix decrement

    bool operator==( const Iterator& aOtherIter ) const;
    bool operator!=( const Iterator& aOtherIter ) const;

    Iterator begin() const;
    Iterator end() const;
    Iterator rbegin() const;
    Iterator rend() const;
};

template<class T>
DoublyLinkedNodeIterator<T>::DoublyLinkedNodeIterator( const Node& aList )
{
    // set leftmost element
    fLeftmost = &aList;

    while ( &fLeftmost->getPrevious() != &Node::NIL )
    {
        fLeftmost = &fLeftmost->getPrevious();
    }

    // set current to first
    fCurrent = fLeftmost;

    if ( fCurrent != &Node::NIL )
        fState = DATA;
    else
        fState = AFTER;

    // set rightmost element
    fRightmost = &aList;

    while ( &fRightmost->getNext() != &Node::NIL )
    {
        fRightmost = &fRightmost->getNext();
    }
}

template<class T>
const T& DoublyLinkedNodeIterator<T>::operator*() const
{
    return fCurrent->getValue();
}

template<class T>
DoublyLinkedNodeIterator<T>& DoublyLinkedNodeIterator<T>::operator++()
{
    switch ( fState )
    {
        case BEFORE:
            fCurrent = fLeftmost;
            if ( fCurrent == &Node::NIL )
            {
                fState = AFTER;
            }
            else
            {
                fState = DATA;
            }
            break;
        case DATA:
            fCurrent = &fCurrent->getNext();
            if ( fCurrent == &Node::NIL )
            {
                fState = AFTER;
            }
            break;
        default: ;
    }

    return *this;
}

template<class T>
DoublyLinkedNodeIterator<T> DoublyLinkedNodeIterator<T>::operator++(int)
{
    Iterator temp = *this;

    ++(*this);

    return temp;
}

template<class T>
DoublyLinkedNodeIterator<T>& DoublyLinkedNodeIterator<T>::operator--()
{
    switch ( fState )															// 2
    {
        case AFTER:																	// 1
            fCurrent = fRightmost;													// 1
            if ( fCurrent == &Node::NIL )											// 2
            {
                fState = BEFORE;
            }
            else
            {
                fState = DATA;														// 2
            }
            break;
        case DATA:																	// 1
            fCurrent = &fCurrent->getPrevious();									// 2
            if ( fCurrent == &Node::NIL )											// 2
            {
                fState = BEFORE;													// 1
            }
            break;
        default: ;
    }

    return *this;																// 1/15
}

template<class T>
DoublyLinkedNodeIterator<T> DoublyLinkedNodeIterator<T>::operator--(int)
{
    Iterator temp = *this;														// 2

    --(*this);																	// 2

    return temp;																// 1/5
}

template<class T>
bool DoublyLinkedNodeIterator<T>::operator==( const Iterator& aOtherIter ) const
{
    return fLeftmost == aOtherIter.fLeftmost &&
           fRightmost == aOtherIter.fRightmost &&
           fCurrent == aOtherIter.fCurrent &&
           fState == aOtherIter.fState;
}

template<class T>
bool DoublyLinkedNodeIterator<T>::operator!=( const Iterator& aOtherIter ) const
{
    return !(*this == aOtherIter);
}

template<class T>
DoublyLinkedNodeIterator<T> DoublyLinkedNodeIterator<T>::begin() const
{
    return ++(rend());
}

template<class T>
DoublyLinkedNodeIterator<T> DoublyLinkedNodeIterator<T>::end() const
{
    Iterator temp = *this;

    temp.fCurrent = &Node::NIL;
    temp.fState = AFTER;

    return temp;
}

template<class T>
DoublyLinkedNodeIterator<T> DoublyLinkedNodeIterator<T>::rbegin() const
{
    return --(end());
}

template<class T>
DoublyLinkedNodeIterator<T> DoublyLinkedNodeIterator<T>::rend() const
{
    Iterator temp = *this;

    temp.fCurrent = &Node::NIL;
    temp.fState = BEFORE;

    return temp;
}

#endif //COPYCONTROL_DOUBLYLINKEDNODEITERATOR_H

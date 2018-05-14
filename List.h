//
// Created by Imran Thompson on 11.5.18.
//

#ifndef COPYCONTROL_LIST_H
#define COPYCONTROL_LIST_H

#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"

#include <stdexcept>

template <class T>
class List {
private:
    // auxiliary definition to simplify node usage
    typedef DoublyLinkedNode<T> Node;

    Node* fTop;		// the first element in the list
    Node* fLast;	// the last element in the list
    int fCount;		// number of elements in the list

    void init()
    {
        fTop = &Node::NIL;
        fLast = &Node::NIL;
        fCount = 0;
    }

public:
    // auxiliary definition to simplify iterator usage
    typedef DoublyLinkedNodeIterator<T> Iterator;

    List();							// default constructor - creates empty list
    ~List();						// destructor - frees all nodes

    List(const List& aOtherList);   // copy contructor
    List& operator=(const List& aOtherList); // assignment operator

    bool isEmpty() const;	// Is list empty?
    int size() const;		// list size

    void push_front( const T& aElement );	// adds a node initialized with aElement at front
    void push_back( const T& aElement );	// adds a node initialized with aElement at back

    void remove( const T& aElement );	// remove node that matches aElement from list

    const T& operator[]( unsigned int aIndex ) const;	// list indexer

    Iterator getIterator() const;	// return an iterator for the nodes of the list
};

template<class T>
List<T>::List()
{
    init();
}

template<class T>
List<T>::List(const List& aOtherList)
{
    init();

    for(int i = 0; i < aOtherList.fCount; i++)
    {
        push_back(aOtherList[i]);
    }

}

template<class T>
List<T>::~List()
{
    while ( fTop != &Node::NIL )
    {
        Node* temp = (Node *)&fTop->getNext();  // get next node (to become top)
        fTop->remove();                         // move first node
        delete fTop;							// free node memory
        fTop = temp;							// make temp the new top
    }
}

template<class T>
bool List<T>::isEmpty() const
{
    return fTop == &Node::NIL;
}

template<class T>
int List<T>::size() const
{
    return fCount;
}

template<class T>
void List<T>::push_front( const T &aElement )
{
    Node* lNewElement = new Node( aElement );	// create a new node

    if ( fTop == &Node::NIL )					// Is this the first node?
    {
        fTop = lNewElement;						// make lNewNode first node
        fLast = lNewElement;					// make lNewNode last node as well
    }
    else
    {
        fTop->prepend( *lNewElement );          // make lNewElement previous of top
        fTop = lNewElement;						// make lNewNode first node
    }

    fCount++;									// increment count
}


template<class T>
void List<T>::push_back(const T& aElement)
{
    Node* lNewElement = new Node(aElement);

    if(fTop == &Node::NIL)
    {
        fTop = lNewElement;
        fLast = lNewElement;
    }
    else
    {
        fLast->append(*lNewElement);
        fLast = lNewElement;
    }

    fCount++;

}

template<class T>
DoublyLinkedNodeIterator<T> List<T>::getIterator() const
{
    return Iterator(*fTop);
}

template<class T>
void List<T>::remove(const T& aElement)
{
    Node* lNode = fTop;                     // start from the top

    while(lNode != &Node::NIL)              // are there still nodes available
    {
        if(lNode->getValue() == aElement)   // have we found the node
            break;                          // stop the search
        lNode = (Node*)&lNode->getNext();   // move to the next node
    }

    // At this point we have either reached the end or found the node.
    if(lNode != &Node::NIL)
    {
        if(lNode == fTop)                       // was it the top node?
        {
            fTop = (Node*)&lNode->getNext();    // set top to the next node
        }
        if(lNode == fLast)                      // was it the last node?
        {
            fLast = (Node*)&lNode->getPrevious(); // set last to previous node
        }

        lNode->remove();                        // isolate node
        delete lNode;                           // release nodes memory
        fCount--;                               // decrement count

    }
}
template<class T>
List<T>& List<T>::operator=(const List& aOtherList)
{
    if (&aOtherList != this)
    {
        // delete this list
        while (fTop != &Node::NIL)
        {
            Node* temp = (Node *)&fTop->getNext();  // get next node (to become top)
            fTop->remove();                         // move first node
            delete fTop;							// free node memory
            fTop = temp;							// make temp the new top
        }

        // initialize this list
        fTop = &Node::NIL;					// initialize top
        fLast = &Node::NIL;					// initialize last
        fCount = 0;							// initialize count

        // copy aOtherList
        for (Iterator iter = aOtherList.getIterator(); iter != iter.end(); iter++)
            push_back(*iter);
    }

    return *this;
}


template <class T>
const T& List<T>::operator[](unsigned int aIndex) const
{
    if(aIndex < fCount)
    {
        Node* lNode = fTop;

        while(aIndex)
        {
            aIndex--;
            lNode = (Node*)&lNode->getNext();
        }

        return lNode->getValue();
    }
    else
    {
        throw std::range_error("Index out of range");
    }

}

#endif //COPYCONTROL_LIST_H

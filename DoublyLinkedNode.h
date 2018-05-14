//
// Created by Imran Thompson on 11.5.18.
//

#ifndef COPYCONTROL_DOUBLYLINKEDNODE_H
#define COPYCONTROL_DOUBLYLINKEDNODE_H

template <class T>
class DoublyLinkedNode {
public:
    typedef DoublyLinkedNode<T> Node;	// nominal equivalence

private:
    T fValue;           // actual data
    Node* fNext;        // forward pointer to next element
    Node* fPrevious;    // backward pointer to previous element

    void init()
    {
        fValue = T();
        fNext = &NIL;
        fPrevious = &NIL;
    }

    // private default constructor for sentinel
    DoublyLinkedNode()
    {
        init();
    }

public:
    static Node NIL;                            // sentinel declaration

    DoublyLinkedNode( const T& aValue ); // constructor (unlinked node)

    void prepend( Node& aNode );                // aNode becomes previous node of this
    void append( Node& aNode );                 // aNode becomes next node of this
    void remove();                              // this node is removed

    // getter functions
    const T& getValue() const;           // return constant reference to datum
    const Node& getNext() const;                // return constant reference to next node
    const Node& getPrevious() const;            // return constant reference to previous node
};

// sentinel implementation
template<class T>
DoublyLinkedNode<T> DoublyLinkedNode<T>::NIL;

template<class T>
DoublyLinkedNode<T>::DoublyLinkedNode( const T& aValue )
{
    init();
    fValue = aValue;
}

template<class T>
void DoublyLinkedNode<T>::prepend( Node& aNode )
{
    aNode.fNext = this;                     // make this the forward pointer of aNode

    if ( fPrevious != &NIL )                // make this's backward pointer aNode's
    {                                       // backward pointer and make previous'
        aNode.fPrevious = fPrevious;        // forward pointer aNode
        fPrevious->fNext = &aNode;
    }

    fPrevious = &aNode;                     // this' backward pointer becomes aNode
}

template<class T>
void DoublyLinkedNode<T>::append( Node& aNode )
{
    aNode.fPrevious = this;

    if ( fNext != &NIL )
    {
        aNode.fNext = fNext;
        fNext->fPrevious = &aNode;
    }

    fNext = &aNode;
}

template<class T>
void DoublyLinkedNode<T>::remove()
{
    if ( fPrevious != &NIL )
    {
        fPrevious->fNext = fNext;
    }

    if ( fNext != &NIL )
    {
        fNext->fPrevious = fPrevious;
    }

    fPrevious = &NIL;
    fNext = &NIL;
}

template<class T>
const T& DoublyLinkedNode<T>::getValue() const
{
    return fValue;
}

template<class T>
const DoublyLinkedNode<T>& DoublyLinkedNode<T>::getNext() const
{
    return *fNext;
}

template<class T>
const DoublyLinkedNode<T>& DoublyLinkedNode<T>::getPrevious() const
{
    return *fPrevious;
}

#endif //COPYCONTROL_DOUBLYLINKEDNODE_H

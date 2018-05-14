#include <iostream>
#include <string>

#include "List.h"

#include "DynamicStack.h"
#include "DynamicStackIterator.h"

#include "DynamicQueue.h"
#include "DynamicQueueIterator.h"

using namespace std;

void testCopyConstructor()
{
    string s1( "AAAA" );
    string s2( "BBBB" );
    string s3( "CCCC" );
    string s4( "DDDD" );
    string s5( "EEEE" );

    List<string> lList;

    lList.push_front( s4 );
    lList.push_front( s3 );
    lList.push_front( s2 );

    List<string> copy( lList );

    // iterate from the top
    cout << "A - Top to bottom: " << copy.size() << " elements" << endl;
    for ( List<string>::Iterator iter = copy.getIterator();
            iter != iter.end(); iter++ )
        cout << "A list element: " << *iter << endl;

    // override list
    lList = copy;

    lList.push_front( s1 );
    lList.push_back( s5 );

    // iterate from the top
    cout << "B – Bottom to top: " << lList.size() << " elements" << endl;
    for ( List<string>::Iterator iter = lList.getIterator().rbegin();
            iter != iter.rend(); iter-- )
        cout << "A list element: " << *iter << endl;
}

void testStack()
{
    DynamicStack<string> lStack;

    lStack.push("AAAA");
    lStack.push("BBBB");
    lStack.push("CCCC");
    lStack.push("DDDD");

    cout << "top: " << lStack.top() << endl;
    lStack.pop();
    cout << "top: " << lStack.top() << endl;
    lStack.pop();
//
    cout << "top: " << lStack.top() << endl;
    cout << "size: " << lStack.size() << endl;
    cout << "is empty: " << (lStack.isEmpty() ? "T" : "F") << endl;

    lStack.pop();
    cout << "top: " << lStack.top() << endl;

    lStack.pop();
    cout << "is empty: " << (lStack.isEmpty() ? "T" : "F") << endl;
}

void testStackIterator()
{
    DynamicStack<string> lStack;

    string s1("One");
    string s2("Two");
    string s3("Three");
    string s4("Four");
    string s5("Five");
    string s6("Six");

    lStack.push(s1);
    lStack.push(s2);
    lStack.push(s3);
    lStack.push(s4);
    lStack.push(s5);
    lStack.push(s6);

    cout << "Traverse elements" << endl;

    for (DynamicStackIterator<string> iter = DynamicStackIterator<string>(lStack);
            iter != iter.end(); iter++)
        cout << "value: " << *iter << endl;
}

void testQueue()
{
    DynamicQueue<int> lQueue;

    lQueue.enqueue(1);
    lQueue.enqueue(2);
    lQueue.enqueue(3);
    lQueue.enqueue(4);
    lQueue.enqueue(5);
    lQueue.enqueue(6);

    cout << "Queue elements:" << endl;

    for(; !lQueue.isEmpty(); lQueue.dequeue())
        cout << "value: " << lQueue.top() << endl;
}

void testQueueIterator()
{
    DynamicQueue<string> lQueue;

    string s1("One");
    string s2("Two");
    string s3("Three");
    string s4("Four");
    string s5("Five");
    string s6("Six");

    lQueue.enqueue(s1);
    lQueue.enqueue(s2);
    lQueue.enqueue(s3);
    lQueue.enqueue(s4);
    lQueue.enqueue(s5);
    lQueue.enqueue(s6);

    cout << "Traverse queue elements" << endl;

    for(DynamicQueueIterator<string> iter = DynamicQueueIterator<string>(lQueue);
            iter != iter.end(); iter++)
        cout << "value: " << *iter++ << endl;
}

int main()
{
    testCopyConstructor();
    testStack();
    testStackIterator();
    testQueue();
    testQueueIterator();
    return 0;
}

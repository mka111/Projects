//
//  dlinkedlist.h
//  Assignment2
//
//  Created by manpreet kaur on 2016-01-26.
//  Copyright © 2016 manpreet kaur. All rights reserved.
//

#ifndef dlinkedlist_h
#define dlinkedlist_h


#include <cstdlib>
#include <stdexcept>
#include <string>

using namespace std;

// template class for doubly-linked list node
template <class T>
class Node
{
public:
    T data;
    //string data;
    Node<T>* prev;
    Node<T>* next;
    
    // default constructor
    
    Node(T value)
    {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

// DLinkedList class definition
template <class T>
class DLinkedList
{
private:
    // DLinkedList private members
    int size; // number of items stored in list
    Node<T>* front; // references to the front
    Node<T>* back;  //  and back of the list
    
    // helper function for deep copy
    // Used by copy constructor and operator=
    void CopyList(const DLinkedList& ll);
    
    // helper function for deep delete
    // Used by destructor and copy/assignment
    void DeleteList();
    
public:
    // default constructor
    DLinkedList();
    
    // copy constructor, performs deep copy of list elements
    DLinkedList(const DLinkedList& ll);
    
    // destructor
    ~DLinkedList();
    
    // MUTATORS
    
    // Inserts an item at the front of the list
    // POST:  List contains item at position 0
    // PARAM: item = item to be inserted
    void InsertFront(T item);
    
    // Inserts an item at the back of the list
    // POST:  List contains item at back
    // PARAM: item = item to be inserted
    void InsertBack(T item);
    
    // Inserts an item in position p (0-indexed)
    // Throws exception for invalid index
    // PRE:   0 <= p <= size
    // POST:  List contains item at position p
    // PARAM: item = item to be inserted, p = position where item will be inserted
    void InsertAt(T item, int p);
    
    // Removes and returns an item from position p (0-indexed)
    // Throws exception if list is empty or index invalid
    // PRE:   0 <= p < size
    // POST:  Item is removed from list
    // PARAM: p = position from where item will be removed
    T RemoveAt(int p);
    
    // Removes duplicates from the list, preserving existing order of remaining items.
    // The first occurrence of any duplicate (relative to the front of the list)
    //   is the one which remains.
    // We have not yet learned about efficiency so you may implement this in any way
    //   as long as the resulting list satisfies the requirement above.
    // PRE:
    // POST:  List contains no duplicates, front and back point to the appropriate nodes
    // PARAM:
    void RemoveDuplicates();
    void cool();
    
    // ACCESSORS
    
    // Returns size of list
    int Size() const;
    
    // Returns whether the list is empty
    bool IsEmpty() const;
    
    // Returns existence of item
    bool Contains(T item) const;
    
    // Returns item at index (0-indexed)
    // Throws exception for invalid index
    T ElementAt(int p) const;
    
    // OVERLOADED OPERATORS
    
    // overloaded assignment operator
    // must work in the following cases:
    // list2 = list1 -> general case
    // list2 = list2 -> should do nothing
    DLinkedList& operator=(const DLinkedList& ll);
};

#endif /* dlinkedlist_h */

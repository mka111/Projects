//
//  slinkedlist.cpp
//  assign5
//
//  Created by manpreet kaur on 2016-04-02.
//  Copyright © 2016 manpreet kaur. All rights reserved.
//

#include "slinkedlist.h"
#include<iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;


template<class T>
SLinkedList<T>::SLinkedList()
{
    size = 0;
    front = NULL;
    back= NULL;
}

template<class T>
void SLinkedList<T>::CopyList(const SLinkedList<T>& ll)
{
    size=ll.size;
    if(ll.IsEmpty()) //if the list to be copied is empty, intializing front and back with null.
    {
        front=NULL;
        back=NULL;
        return;
    }
    front=new Node<T>(ll.front->data); //making a new front with same data as of the front of list to be copied.
    back=front;
    Node<T>* temp;
    temp=ll.front->next; //temp pointer for the next of the front.
    
    for(int i=1; i<size; i++)
    {
        back->next= new Node<T>(temp->data);
        back=back->next;
        temp=temp->next; //going to the next position of the list.
    }
    
}

template<class T>
void SLinkedList<T>::DeleteList() //helper function for destructor
{
    if(IsEmpty()==false)
    {
    Node<T>* temp=front;
    while(temp!=NULL)
    {
        temp=front->next;
        delete front;
        front=temp;
    }
    front=NULL;
    back=NULL;
    size=0;
    }
}

template<class T>
SLinkedList<T>::SLinkedList(const SLinkedList<T>& ll)
{
    CopyList(ll);
}

template<class T>
SLinkedList<T>::~SLinkedList<T>()
{
    DeleteList();
}

template<class T>
void SLinkedList<T>::InsertFront(T item)
{
    Node<T>* temp= new Node<T>(item);
    temp->next=front;
    front= temp;
    if(size==0)
    {
        back=front;
    }
    size+=1;
}


template<class T>
void SLinkedList<T>::InsertBack(T item)
{
    Node<T>* temp= new Node<T>(item);
    if(back!=NULL)
    {
        back->next=temp;
        
    }
    back=temp;
    if(size==0)
    {
        front=back;
    }
    size+=1;
}

template<class T>
bool SLinkedList<T>::Remove(T item)
{
    Node<T>* temp=front;
    Node<T>* temp2;
    if(IsEmpty()==true)
    {
        return false;
    }
    if(temp->data==item) //checking if the front contains the data to be removed
    {
        delete temp;
        front=front->next;
        size-=1;
        return true;
    }
    
    for(int i=0; i<size-1; i++)
    {
        
        if(temp->next->data==item)
        {
            temp2=temp->next;
            temp->next=temp->next->next;
            delete temp2;
            if(temp->next == NULL)
            {
                back=temp;
            }
            size-=1;
            return true;
        }
        temp=temp->next;
    }
    
    return false;
}

template<class T>
void SLinkedList<T>::RemoveAll()
{
    DeleteList();
}

template<class T>
bool SLinkedList<T>::IsEmpty()const
{
        if(size==0)
    {
        return true;
    }
    return false;
}

template<class T>
int SLinkedList<T>::Size() const
{
    return size;
}

template<class T>
bool SLinkedList<T>::Contains(T item) const
{
    if(IsEmpty()==true)
    {
        return false;
    }
    Node<T>* temp=front;
    while(temp!=NULL)
    {
        if(temp->data == item)
        {
            return true;
        }
        temp=temp->next;
        
    }
    return false;
    
}

template<class T>
T* SLinkedList<T>::Retrieve(T item)
{
    T* value = NULL;
    Node<T>* temp = front;
    while(temp!=NULL)
    {
        if(temp->data == item)
        {
            value = &(temp->data);
            break; //breaking the loop if we found the item
        }
        temp=temp->next;
        
    }
    
    return value;
    
    
}

template<class T>
vector<T> SLinkedList<T>::Dump() const
{
    vector<T> list;
    
    Node<T>* temp = front;
    for(int i=0; i<size; i++)
    {
        list.push_back(temp->data); //calling push_back
        temp=temp->next;
    }
    return list;
}

template<class T>
SLinkedList<T>& SLinkedList<T>::operator=(const SLinkedList<T>& ll)
{
    if(this!=&ll)/*if we are not trying to copy the same list to it, then just first delete that list, and make an another list which is copy of the given list.*/
    {
        DeleteList();
        CopyList(ll);
    }
    return *this;
}



































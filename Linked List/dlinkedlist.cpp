//
//  dlinkedlist.cpp
//  Assignment2
//
//  Created by manpreet kaur on 2016-01-26.
//  Copyright © 2016 manpreet kaur. All rights reserved.
//


#include "dlinkedlist.h"
#include <iostream>
#include<stdexcept>
using namespace std;
template<class T>
DLinkedList<T>::DLinkedList()
{
    size=0;
    front=NULL;
    back=NULL;
    
}


template<class T>
void DLinkedList<T>::CopyList(const DLinkedList<T>& ll)
{
    size=ll.size;
    if(ll.IsEmpty())
    {
        front=NULL;
        back=NULL;
        return;
    }
    front=new Node<T>(ll.front->data);
    back=front;
    Node<T>* temp;
    Node<T>* temp2;

    temp=ll.front->next;
    
    for(int i=1; i<size; i++)
    {
        back->next= new Node<T>(temp->data);
        temp2=back;
        back=back->next;
        back->prev=temp2;
        temp=temp->next;
    }
    
}
template<class T>
void DLinkedList<T>::DeleteList()
{
    Node<T>* temp=front;
    while(temp!=NULL)
    {
        temp=front->next;
        delete front;
        if(temp!=NULL)
        {
            temp->prev=NULL;;
        }
        front=temp;
    }
    front=NULL;
    back=NULL;
    size=0;
}

template<class T>
DLinkedList<T>::DLinkedList(const DLinkedList<T>& ll)
{
    CopyList(ll);
}

template<class T>
DLinkedList<T>::~DLinkedList<T>()
{
    DeleteList();
}

template<class T>
void DLinkedList<T>::InsertFront(T item)
{
    Node<T>* temp= new Node<T>(item);
    temp->next=front;
    if(front!=NULL)
    {
        front->prev= temp;
    }
    front= temp;
    if(size==0)
    {
        back=front;
    }
    size+=1;
}

template<class T>
void DLinkedList<T>::InsertBack(T item)
{
    Node<T>* temp= new Node<T>(item);
    if(back!=NULL)
    {
        back->next=temp;
        
    }
    temp->prev=back;
    back=temp;
    if(size==0)
    {
        front=back;
    }
    size+=1;
    
}


template<class T>
void DLinkedList<T>::InsertAt(T item, int p)
{
    //check valid index, exception
    
    if((p>=0)&&(p<=size))
    {
        Node<T>* temp =new Node<T>(item);
        if(size==0)
        {
            front=temp;
            back=front;
        }
        else
        {
            Node<T>* temp2 = front;
            int i=0;
            while((i<size)&&(p!=size))
            {
                if(p==i)//make cases for indivial when 0 and last and in general.
                {
                    temp->next=temp2;
                    temp->prev=temp2->prev;//if(p==0)and (p!=0) and (p==size-1)
                    temp2->prev=temp;
                    if(p!=0)
                    {
                        temp->prev->next=temp;
                    }
                    if(p==0)
                    {
                        front=temp;
                    }
                    break;
                }
                else
                {
                    temp2=temp2->next;
                }
                i++;
            }
            if(p==size)
            {
                temp->prev=back;
                back->next=temp;
                back=temp;
            }
        }
        size=size+1;
    }
    else
    {
        throw std::out_of_range("DLinkedList<T>::InsertAt(T item, int p) – index out of range");
    }
}

template<class T>
T DLinkedList<T>::RemoveAt(int p)
{
    if((size!=0)&&(p>=0)&&(p<size))
    {
        Node<T>* temp = front;
        int i=0;
        T store;
        while(i<size)
        {
            if(p==i)
            {
                store=temp->data;
                if(p==0)
                {
                    front=temp->next;
                    front->prev=NULL;
                }
                if(p==(size-1))
                {
                    back=temp->prev;
                    back->next=NULL;
                }
                if((p!=0)&&(p!=(size-1)))
                {
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                }
                delete temp;
                break;
            }
            i++;
            temp=temp->next;
        }
        temp=NULL;
        size=size-1;
        return store;
    }
    else
    {
        throw std::out_of_range("DLinkedList<T>::RemoveAt(int p) – index out of range");
    }
}

template<class T>
T DLinkedList<T>::ElementAt(int p)const
{
    T store;
    if((p>=0)&&(p<size))
    {
        Node<T>*temp=front;
        int i=0;
        
        while(i<size)
        {
            if(p==i)
            {
                store= temp->data;
            }
            i++;
            temp=temp->next;
        }
    }
    else
    {
        throw std::out_of_range("DLinkedList<T>::ElementAt(int p) – index out of range");
    }
    return store;
}

template<class T>
void DLinkedList<T>::RemoveDuplicates()
{
    int i=0;
    Node<T>*temp=front;
    Node<T>*temp2;
    T store;
    int j;
    for(i=0; i<size; i++)
    {
        store= temp->data;
        temp2=temp->next;
        j=i+1;
        while(j<size)
        {
            if(store==temp2->data)
            {
                store=RemoveAt(j);
            }
            else
            {
                j++;
            }
            temp2=temp2->next;
        }
        temp=temp->next;
    }
}

template<class T>
int DLinkedList<T>::Size()const
{
    return size;
}

template<class T>
bool DLinkedList<T>::IsEmpty()const
{
    if((front==NULL)&&(back==NULL))
    {
        return true;
    }
    return false;
}

template<class T>
bool DLinkedList<T>::Contains(T item)const
{
    int i=0;
    Node<T>*temp=front;
    while(i<size)
    {
        if(item==temp->data)
        {
            return true;
        }
        i++;
        temp=temp->next;
    }
    return false;
}

template<class T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList<T>& ll)
{
    if(this!=&ll)
    {
        DeleteList();
        CopyList(ll);
    }
    return *this;
}

template<class T>
void DLinkedList<T>::cool()
{
    if((front!=NULL)&&(back!=NULL))
    {
        cout<<"\nfront is "<<front->data;
        cout<<"\nback is "<<back->data;
    }
    
}













    
























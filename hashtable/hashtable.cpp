//
//  hashtable.cpp
//  assign5
//
//  Created by manpreet kaur on 2016-04-02.
//  Copyright © 2016 manpreet kaur. All rights reserved.
//

#include <cstdlib>
#include <math.h> // needed for Hash function
#include <string>
#include <vector>
#include "slinkedlist.h"
#include "useraccount.h"
#include<iostream>
using namespace std;

HashTable::HashTable() //default constructor
{
    maxsize=101;
    table = new SLinkedList<UserAccount>[maxsize]; //array of singly linked list
    size=0;
    
    
}

int HashTable::Hash(string input) const
{
    int asc;
    int n=input.length();
    int value=0;
    int k=n;
    
    for(int i=0;i<n;i++)
    {
        asc=input[i]-96;
        value=value+(asc* pow(32, k-1)); //Horner's method
        value=value%maxsize;
        k--;
        
    }
    
    return value;
}

bool HashTable::IsPrime(int n)const
{
    int prime=0;
    for(int i=2;i<=n/2;++i) //if the number is divisble by any number till its half, then its not prime.
    {
        if(n%i==0)
        {
            prime=1;
            break; //break out ofloop when we found a number divisible to it.
        }
    }
    if (prime==0)
        return true;
    
    return false;
}

int HashTable::SmallestPrime(int n)const
{
    int i=n+1;
    
    int number;
    
    while(i<(n+1)*10) //checking till next number is prime    {
        if(IsPrime(i)==true)
        {
            number=i;
            break;
        }
        i++;
    }
    return number;
}

bool HashTable::Resize(int n)
{
    if((n<maxsize)||(n<0))
    {
        return false;
    }
    SLinkedList<UserAccount>* oldtable =table; //pointer for the original table
    SLinkedList<UserAccount>* newtable; //pointer for a newtable
    int oldmaxsize=maxsize; //storing current maxsize in variable oldmaxsize
    maxsize=SmallestPrime(n); //changing the maxxsize as smallest prime numberlarger than n.
    newtable=new SLinkedList<UserAccount>[maxsize];
    SLinkedList<UserAccount> accnt;
    vector<UserAccount> vec; /*defining a vector to store all the contents of the hashtable by calling Dump 
                              function*/
    for(int i=0; i<oldmaxsize; i++)
    {
        if(oldtable[i].IsEmpty()==false)
        {
            vec=oldtable[i].Dump(); //storing the contents of each singly linked list in the vector.
            int index2;
            UserAccount ua; //creating an object of UserAccount class to re-hash all the contents in new size table
            for(int j=0; j<vec.size();j++)
            {
                index2=Hash(vec[j].GetUsername()); /*finding appropriate index in the new table by calling Hash 
                                                    function*/
                ua.SetUsername(vec[j].GetUsername()); //setting the same username and level at the index
                ua.SetUserLevel(vec[j].GetUserLevel());
                newtable[index2].InsertBack(ua); /*inserting back the UserAccount with username and userlevel at appropriate index in the newtable and then deleting the existing table and assigning the newtable as the HashTable.*/
            }
        }
    }
    delete[] oldtable;
    table=newtable;
    return true;
    
}

// parameterized constructor
HashTable::HashTable(int n)
{
    maxsize=SmallestPrime(2*n);
    size=0;
    table= new SLinkedList<UserAccount>[maxsize];
    //table[maxsize];

}

// copy constructor
HashTable::HashTable(const HashTable& sourceht)
{
    size= sourceht.size; /
    maxsize = sourceht.maxsize;
    table =new SLinkedList<UserAccount>[maxsize];
    SLinkedList<UserAccount>* temp;
    for(int i=0; i<maxsize; i++)
    {
        temp=&sourceht.table[i];
        table[i]=*new SLinkedList<UserAccount>(*temp);
        
    }
}

HashTable::~HashTable()
{
    for(int i=0; i<maxsize; i++)
    {
        table[i].~SLinkedList(); //deleting each singly list at any index by simply calling destructor of list.
    }
    
}

double HashTable::LoadFactor() const
{
        return double(size)/double(maxsize);
}

// Insertion
bool HashTable::Insert(UserAccount acct)
{
    int index, index1;
    index=Hash(acct.GetUsername()); //getting appropriate index for the username to be inserted
    if(table[index].Contains(acct)==true) /*if that usernanme already exists, then returning false, and then not 
                                           inserting it.*/
    {
        return false;
    }
    if(LoadFactor()< (2.0/3.0))
    {
        table[index].InsertBack(acct);//if the loadfactor <2/3, then simply inserting the UserAccount
    }
    else
    {
        Resize(SmallestPrime(2*maxsize));
        index1=Hash(acct.GetUsername()); //after resizing,inserting at a  different index.
        table[index1].InsertBack(acct);
        
    }
    size+=1;
    
    return true;
    
}

// Removal
bool HashTable::Remove(UserAccount acct)
{
    int index;
    index=Hash(acct.GetUsername());
    if(table[index].Remove(acct)==true)
    {
        size-=1;
        return true;
    }

    return false;
    
}

// Search
// Returns true if item exists, false otherwise
bool HashTable::Search(UserAccount acct) const
{
    int index;
    index=Hash(acct.GetUsername());
    if(table[index].Contains(acct)==true)
    {
        return true;
    }
    return false;

    
}

// Retrieval
UserAccount* HashTable::Retrieve(UserAccount acct)
{
    UserAccount* accnt;
    int index;
    index=Hash(acct.GetUsername());
    accnt=table[index].Retrieve(acct);
    return accnt;
}

int HashTable::Size() const
{
    return size;
}

int HashTable::MaxSize() const
{
    return maxsize;
}
int HashTable::Numberofitems(int index)
{
    return table[index].Size();
    
}
HashTable& HashTable::operator=(const HashTable& sourceht)
{
    if(this!=&sourceht)
    {
        for(int i=0; i<maxsize; i++)
        {
            table[i].~SLinkedList();
        }
        size= sourceht.size;
        maxsize = sourceht.maxsize;
        table =new SLinkedList<UserAccount>[maxsize];
        SLinkedList<UserAccount>* temp;
        for(int i=0; i<maxsize; i++)
        {
            temp=&sourceht.table[i];
            table[i]=*new SLinkedList<UserAccount>(*temp);
            
        }

    }
    return *this;
}






















































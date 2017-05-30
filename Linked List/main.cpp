//
//  main.cpp
//  Assignment2
//
//  Created by manpreet kaur on 2016-01-26.
//  Copyright © 2016 manpreet kaur. All rights reserved.
//

#include <cstdlib>
#include <iostream>
using namespace std;
#include <string>
#include <stdexcept>
#include "dlinkedlist.h"
#include "dlinkedlist.cpp"
#include"ccqueue.h"
#include "ccqueue.cpp"


// forward function declarations
void LLTest();
//void CCQTest();

// program entry point
int main()
{
    cout << "Entering DLinkedList test function... " << endl;
    LLTest();
    cout << "... DLinkedList test function complete!\n" << endl;
    
    cout << "Entering CCQueue test function... " << endl;
    //CCQTest();
    cout << "... CCQueue test function complete!\n" << endl;
    
    system("pause");
    return 0;
}

void LLTest()
{
    // default constructor, InsertFront, InsertBack, ElementAt
    cout<<"hello";
    DLinkedList<int> lla;
    
    int size=lla.Size();
    int value;
    cout<<"\nBEfore\n";
    lla.InsertAt(400, 0);
    lla.InsertBack(40);
    try {
        lla.InsertAt(400, 4);
    
    } catch (exception f) {
        cout<< f.what() << endl;
    }
    try
    {
        cout<<lla.RemoveAt(12345);
    }
    catch (exception e)
    {
        cout << "Exception in RemoveAt(): " << endl;
    }

    try {
        cout<<lla.ElementAt(98);
        
        
            
        }
    catch (std::out_of_range f) {
        cout<<"exception in element at"<<f.what();
    }

    
    
    //lla.InsertFront(30);
    //lla.InsertAt(30, 3);
    //lla.InsertAt(30, 0);
    //lla.InsertAt(400, 3);
    //lla.InsertAt(30, 4);
    //lla.InsertBack(400);
    //lla.InsertFront(40);
    //lla.InsertAt(400,3);
    
    
    //for(int i=0; i<lla.Size(); i++)
    //{
    //   cout << "lla contains at  "<<i<<" " << lla.ElementAt(i) << " at index 0." << endl;
    //}
    //lla.cool();
    cout<<"\nAFTER\n";
    lla.RemoveDuplicates();
    DLinkedList<int> llb;
    llb=llb;
    
    
    
   
    
        for(int i=0; i<lla.Size(); i++)
    {
        cout << "lla contains at  "<<i<<" " << lla.ElementAt(i) << " at index 0." << endl;
    }
    //lla.cool();
    if(lla.Contains(400)==true)
    {
        cout<<"yes";
    }
    
    for(int i=0; i<llb.Size(); i++)
    {
        cout << "llb contains at  "<<i<<" " << llb.ElementAt(i) << " at index 0." << endl;
    }
    //llb.cool();
    if (llb.IsEmpty())
    cout << "llb is empty." << endl;
    else
        cout << "llb is not empty." << endl;
    if (lla.IsEmpty())
    cout << "lla is empty." << endl;
    else
        cout << "lla is not empty." << endl;
    
    if (llb.Contains(40))
        cout << "10 found in llc." << endl;
    else
        cout << "10 not found in llc." << endl;
    
    

    

    


    
    
    // copy constructor, InsertAt, RemoveAt (with exception)
    //DLinkedList<int> llb(lla);
    //llb.InsertAt(7, 1);
    /*try
    {
        int temp = llb.RemoveAt(12345);
    }
    catch (exception e)
    {
        cout << "Exception in RemoveAt(): " << e.what() << endl;
    }
    
    // assignment operator, IsEmpty, Size, RemoveDuplicates, Contains
    DLinkedList<int> llc;
    if (llc.IsEmpty())
        cout << "llc is empty." << endl;
    else
        cout << "llc is not empty." << endl;
    llc = lla;
    llc.InsertBack(13);
    llc.InsertBack(13);
    llc.InsertBack(13);
    cout << "llc contains " << llc.Size() << " items." << endl;
    llc.RemoveDuplicates();
    if (llc.Contains(10))
        cout << "10 found in llc." << endl;
    else
        cout << "10 not found in llc." << endl;
    if (llc.Contains(13))
        cout << "13 found in llc." << endl;
    else
        cout << "13 not found in llc." << endl;*/
}

void CCQTest()
{
    CCQueue ccq;
    ccq.Add("Alrikr", "Video card smoked");
    ccq.Add("Bjornstjerne", "Received wrong colour cable");
    ccq.Add("Cyprianus", "Motherboard DOA");
    ccq.Add("Dietrich", "Order not received");
    ccq.Add("Elisaeus", "Only 931GB on 1TB hard drive");
    cout << "Size of ticket queue: " << ccq.Size() << endl;
    //ccq.Service();
    //ccq.MoveUp(3);
    //ccq.MoveUp(2);
    //ccq.MoveDown(2);
    cout << ccq.PrintStatus() << endl;
}
//
//  ccqueue.cpp
//  Assignment2
//
//  Created by manpreet kaur on 2016-01-30.
//  Copyright © 2016 manpreet kaur. All rights reserved.
//

#include <stdio.h>
//
//  ccqueue.h
//  Assignment2
//
//  Created by manpreet kaur on 2016-01-26.
//  Copyright © 2016 manpreet kaur. All rights reserved.



#include <sstream>
#include <string>

#include "dlinkedlist.h"
#include "ticket.h"
#include "ccqueue.h"

CCQueue::CCQueue()
{
    maxticketid=0;
    Ticket t;
    tickets.InsertFront(t);
    
}
bool CCQueue::Add(string customer, string complaint)
{
    if((customer!="")&&(complaint!=""))
    {
        Ticket t1(maxticketid+1,customer,complaint);
        tickets.InsertBack(t1);
        maxticketid++;
        return true;
    }
    return false;
}

Ticket CCQueue::Service()
{
    if(tickets.IsEmpty()==false)
    {
        return tickets.RemoveAt(0);
        
    }
    else
    {
        throw std::out_of_range("CCQueue::Service()-index out of range");
    }
}
bool CCQueue::MoveUp(int index)
{
    if((index>0)&&(index<tickets.Size()))
    {
        Ticket t(tickets.ElementAt(index).GetID(),tickets.ElementAt(index).GetCustomer(),tickets.ElementAt(index).GetComplaint());
        tickets.InsertAt(t,index-1);
        tickets.RemoveAt(index+1);
        return true;
    }
    return false;
}
bool CCQueue::MoveDown(int index)
{
    if((index>=0)&&(index<tickets.Size()-1))
    {
        Ticket t(tickets.ElementAt(index+1).GetID(),tickets.ElementAt(index+1).GetCustomer(),tickets.ElementAt(index+1).GetComplaint());
        tickets.InsertAt(t,index);
        tickets.RemoveAt(index+2);
        return true;
    }
    return false;
}
int CCQueue::Size()const
{
    return tickets.Size();
}
























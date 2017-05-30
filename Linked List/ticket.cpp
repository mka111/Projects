//
//  ticket.cpp
//  Assignment2
//
//  Created by manpreet kaur on 2016-01-26.
//  Copyright © 2016 manpreet kaur. All rights reserved.
//

#include <stdio.h>
#include "ticket.h"


// default constructor
Ticket::Ticket()
{
    ticketid = 0;
    customername = "Cornelius";
    complaint = "Star Wars Darth Vader waffle maker does not produce accurate waffle likeness of Darth Vader";
}

// parameterized constructor
Ticket::Ticket(unsigned int tid, string cname, string cplnt)
{
    ticketid = tid;
    if (cname == "")
        customername = "Cornelius";
    else
        customername = cname;
    if (cplnt == "")
        complaint = "Star Wars Darth Vader waffle maker does not produce accurate waffle likeness of Darth Vader";
    else
        complaint = cplnt;
}

// MUTATORS

// ACCESSORS
unsigned int Ticket::GetID() const
{
    return ticketid;
}

string Ticket::GetCustomer() const
{
    return customername;
}

string Ticket::GetComplaint() const
{
    return complaint;
}

// overloaded operators
// equality returns true if either ticketid matches,
//   or customername and complaint match
bool Ticket::operator==(const Ticket& tick) const
{
    if (ticketid == tick.ticketid || (customername == tick.customername && complaint == tick.complaint) )
        return true;
    else
        return false;
}

bool Ticket::operator!=(const Ticket& tick) const
{
    return !(*this == tick);
}

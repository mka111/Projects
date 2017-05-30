//
//  ticket.h
//  Assignment2
//
//  Created by manpreet kaur on 2016-01-26.
//  Copyright © 2016 manpreet kaur. All rights reserved.
//

#ifndef ticket_h
#define ticket_h

#include <string>

using namespace std;

class Ticket
{
private:
    unsigned int ticketid;
    string customername;
    string complaint;
    
public:
    // default constructor
    Ticket();
    
    // parameterized constructor
    Ticket(unsigned int tid, string cname, string cplnt);
    
    // MUTATORS
    
    // ACCESSORS
    unsigned int GetID() const;
    string GetCustomer() const;
    string GetComplaint() const;
    
    // overloaded operators
    // equality returns true if either ticketid matches,
    //   or customername and complaint match
    bool operator==(const Ticket& tick) const;
    bool operator!=(const Ticket& tick) const;
};


#endif /* ticket_h */

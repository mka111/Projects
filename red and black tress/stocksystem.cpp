//
//  stocksystem.cpp
//  Assignment4
//
//  Created by manpreet kaur on 2016-03-17.
//  Copyright © 2016 manpreet kaur. All rights reserved.
//

#include "stocksystem.h"
#include<iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
using namespace std;


StockSystem::StockSystem()
{
    balance=100000.00;
}
double StockSystem::GetBalance()
{
    return balance;
}
bool StockSystem::StockNewItem(StockItem item)
{
    if(records.Insert(item)==true)
    {
        return true;
    }
    return false;
}

bool StockSystem::EditStockItemDescription(int itemsku, string desc)
{
    StockItem t2(itemsku, "hello", 19.8);// making a t2 object of Stockitem with same itemsku.
    StockItem* p;
    p=records.Retrieve(t2); /*it will give the pointer to stockitem having itemsku as SKU regardless of any description or
                             price.*/
    if(p!=NULL)
    {
        p->SetDescription(desc); //changing the description of that specific node.
        return true;
    }
    
    
    
    return false;
}

bool StockSystem::EditStockItemPrice(int itemsku, double retailprice)
{
    StockItem t2(itemsku, "hello", 19.9); // making a t2 object of Stockitem with same itemsku.
    StockItem* p;
    p=records.Retrieve(t2); /*it will give the pointer to stockitem having itemsku as SKU regardless of any description or
                             price.*/

    if(p!=NULL && retailprice>0)
    {
        p->SetPrice(retailprice); //changing the price of that specific node.

        return true;
    }
    return false;
}

bool StockSystem::Restock(int itemsku, int quantity, double unitprice)
{
    StockItem t2(itemsku, "hello", 19.9); // making a t2 object of Stockitem with same itemsku.

    StockItem* p;
    p=records.Retrieve(t2);  /*it will give the pointer to stockitem having itemsku as SKU regardless of any description or
                              price.*/
    if((p!=NULL)&&(balance>=quantity*unitprice) && quantity>0 && unitprice>0)
    {
        p->SetPrice(unitprice); //setting different unitprice
        p->SetStock(quantity); //and changing the no. ofitems in stock
        balance-=quantity*unitprice; //as we purchase, balance will be decreased.
        
        return true;
    }
    return false;
}

bool StockSystem::Sell(int itemsku, int quantity)
{
    StockItem t2(itemsku, "hello", 19.9); // making a t2 object of Stockitem with same itemsku.

    StockItem* p;
    p=records.Retrieve(t2); /*it will give the pointer to stockitem having itemsku as SKU regardless of any description or
                             price.*/
    if((p!=NULL)&&(p->GetStock()!=0) && (quantity>0)) //if stock is not empty
    {
        if((p->GetStock())>=quantity) //if stock is more than quantity needed,
        {
            p->SetStock((p->GetStock())-quantity);
            balance+=quantity*(p->GetPrice());
        }
        else if(p->GetStock()< quantity) /*if stock is more than quantity needed, sell the stock available and set
                                          number of items in stock as 0.*/
        {
            p->SetStock(0);
            balance+=(p->GetStock())*(p->GetPrice()); //as we sell, balance will be increased.
        }
        return true;
    }
    return false;

}



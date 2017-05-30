//
//  main.cpp
//  assignment1
//
//  Created by manpreet kaur on 2016-01-18.
//  Copyright © 2016 manpreet kaur. All rights reserved.
//

#include <iostream>
#include "cd.h"
#include "cdcatalogue.h"


CDCatalogue::CDCatalogue() //Default constructor
{
    maxsize=4;
    cds=new CD[maxsize];
    numcds=0;           //for an empty catalogue
}
void CDCatalogue::CopyArray(const CDCatalogue& cat)
{
    maxsize=cat.maxsize;
    numcds=cat.numcds;
    
    cds= new CD[maxsize]; //creating a new dynamic array since it's a deep copy
    for(int i=0; i<numcds; i++)
    {
        cds[i]=cat.cds[i];
    }
}

CDCatalogue::CDCatalogue(const CDCatalogue& cat) //Copy constructor
{
    CopyArray(cat); //calling the helper method for copy constructor
}

CDCatalogue::~CDCatalogue() //destructor
{
    delete[] cds;
}

bool CDCatalogue::Insert(CD disc)
{
    
    if(Find(disc)==-1)      //inserting disc only if it doesn't exist in the catalogue already
    {
        if(numcds==maxsize) //if array is already filled then creating a new dynamic array with more space to insert disc
        {
            CD* array=cds;
            maxsize=2*maxsize;
            cds=new CD[maxsize];
            
            for(int i=0; i<numcds; i++) //filling in the same contents of old array into new array
            {
                cds[i]=array[i];
            }
            delete[] array;  //deallocating the memory of old array.
        }
        cds[numcds]=disc;
        numcds+=1;
        return true;
    }
    return false;

}

int CDCatalogue::Find(CD disc)const
{
    int i=0;
    while((i<numcds)&&(disc.GetArtist()!="/0")&&(disc.GetArtist()!="/0"))
    {
        if(cds[i]==disc)
        {
            return i;
        }
        i++;
    }
    return -1;
}

bool CDCatalogue::Remove(CD disc)
{
    int i;
    i=Find(disc);    //finding the index of disc in the array
    if(i!=-1)       //if there is a valid index for disc in the array,then removing the disc from the array.
    {
        cds[i]=cds[numcds-1];
        numcds-=1;
        return true;
    }
    return false;
}
int CDCatalogue::Count()const
{
    return numcds;
}

bool CDCatalogue::Boycott(string dontlikeanymore)
{
    int i=0;
    
    int remove=0;           // variable to keep track if  atleast one cd is removed.
    while((i<numcds)&&(dontlikeanymore!="/0"))
    {
        if(cds[i].GetArtist()==dontlikeanymore)
        {
            cds[i]=cds[numcds-1];
            remove=1;
            numcds-=1;       //each time a cd is removed, numcds will be decremented.
        }
        else
        {
            i++;
        }
    }
    if(remove==0)    /*if the value of remove remains the same,then it means
                       no cd with the given name of artist is removed*/
    {
        return false;
    }
    return true;
}

CDCatalogue CDCatalogue::Join(const CDCatalogue& cat) const
{
    CDCatalogue cat2;
    int i=0;
    int j=0;
    cat2.maxsize=cat.maxsize+this->maxsize;
    CD* array=cat2.cds;  //deallocating the old memory stored by cat2.cds, and allocating new memory space for cds.
    delete[] array;
    cat2.cds=new CD[cat2.maxsize];
    
    
    for(i=0;i<this->numcds;i++)
    {
        cat2.cds[i]=this->cds[i];   //first copying all the contents of this into cat2 array.
    }
    for(j=0;j<cat.numcds;j++)
    {
        if(Find(cat.cds[j])==-1)     /*checking if a cd of cat does not exist in
                                     collection of cds in "this catalogue", then copying that cd into cat2 array*/
        {
            cat2.cds[i]=cat.cds[j];  /*This way all the cds in "this catalogue" and "cat catalogue" are stored
                                      in "cat2 catalogue" with only one copy of the similiar cds in both*/
            i++;
        }
    }
    
    cat2.numcds=i;  //updating number of cds in cat2 catalogue.
    
    return cat2;
    
}


CDCatalogue CDCatalogue::Common(const CDCatalogue& cat) const
{
    
    CDCatalogue cat2;
    int i=0;
    int j=0;
    int k=0;
    cat2.maxsize=cat.maxsize+this->maxsize;
    CD* array=cat2.cds; //deallocating the old memory stored by cat2.cds, and allocating new memory space for cds.
    delete[] array;
    
    cat2.cds=new CD[cat2.maxsize];
    while(i<cat.numcds)
    {
        for(j=0;j<this->numcds;j++)
        {
            if(this->cds[j]==cat.cds[i])   /*if a cd in "this" matches with any cd
                                          in cat, then copying that cd into cat2 array*/
               {
                   cat2.cds[k]=cat.cds[i];
                   k++;
               }
        }
        i++;
    }
    cat2.numcds=k; //updating number of cds in cat2 catalogue.
    return cat2;
}

CDCatalogue CDCatalogue::Split(const CDCatalogue& cat) const
{
    CDCatalogue cat2;
    int i=0;
    int j=0;
    int k=0;
    int same=0;
    cat2.maxsize=cat.maxsize+this->maxsize;
    CD* array=cat2.cds;    //deallocating the old memory stored by cat2.cds, and allocating new memory space for cds.
    delete[] array;
    
    cat2.cds=new CD[cat2.maxsize];
    while(i<this->numcds)
    {
        j=0;              //assigning the index j as 0 to check the array again from the beginning for a different cd.
        while(j<cat.numcds)
        {
            if(this->cds[i]==cat.cds[j])
            {
                same=1;  //changing the value of "same" if a cd in "this catalogue" is same as in cat catalogue.
            }
            j++;
        }
        if(same==0)     /*if the value of "same" is still 0, i.e. if a cd is does not
                        exist in cat cataolgue then copying that cd to cat2 catalogue.*/
        {
            cat2.cds[k]=this->cds[i];
            k++;
        }
        else
        {
            same=0;    /*setting the value of "same" as 0, to check the similarity
                       for an another cd of "this catalogue" in cat catalogue*/
        }
        i++;
    }
    
    cat2.numcds=k;    //updating number of cds in cat2 catalogue.
    return cat2;
}


























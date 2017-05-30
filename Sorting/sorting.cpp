//
//  sorting.cpp
//  Assignment3
//
//  Created by manpreet kaur on 2016-02-20.
//  Copyright © 2016 manpreet kaur. All rights reserved.
//
#include<cstdlib>

//Selection Sort
//source consulted from Geoffrey Tien lecture notes.
template <class T>
int SelectionSort(T arr[], int n)
{
    int j;
    int count = 0; // counter for barometer operations
    for(int i=0; i<n-1; i++)
    {
        int small=i;
        for( j=i+1; j<n; j++)
        {
            count++;
            if(arr[j]<arr[small])
            {
                
                small=j;
            }
        }
        if(j>=n)
        {
            count++;
        }
        T temp=arr[i];
        arr[i]=arr[small];
        arr[small]=temp;
    }
    
    return count;
}

// Quicksort
// source consulted from codershub.com
template <class T>
int Quicksort(T arr[], int n)
{
    int count = 0;
    QuicksortHelper(arr, 0, n-1, count);
    return count;
}

template <class T>
void QuicksortHelper(T arr[], int low, int high, int& counter)
{
    if (low < high)
    {
        int p = QSPartition(arr, low, high,counter);         QuicksortHelper(arr, low, p - 1, counter);
        QuicksortHelper(arr, p + 1, high, counter);
    }
}




template <class T>
void swap(T* a, T* b)
{
    T t = *a;
    *a = *b;
    *b = t;
}


template <class T>
int QSPartition(T arr[], int low, int high, int& counter)
{
    
    int pivotindex = high;
    int j;
    T pivotindexvalue=arr[high];    // pivot
    int i = (low - 1);
    for (j = low; j <= high- 1; j++)
    {
        counter++;
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivotindexvalue)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);  // Swap current element with index
        }
    }
    if(j>high-1)
    {
        counter++;
    }
    swap(&arr[i + 1], &arr[high]);
    pivotindex= i + 1;
    
    
    return pivotindex;
}

// Randomized Quicksort
// source consulted from codershub.com



template <class T>
int RQuicksort(T arr[], int n)
{
    int count = 0;
    RQuicksortHelper(arr, 0, n-1, count);
    return count;
    
    
    
}

template <class T>
void RQuicksortHelper(T arr[], int low, int high, int& counter)
{
    if (low < high)
    {
        int p = RQSPartition(arr, low, high,counter);        RQuicksortHelper(arr, low, p - 1, counter);
        RQuicksortHelper(arr, p + 1, high, counter);
    }

    
    
}

template <class T>
int RQSPartition(T arr[], int low, int high, int& counter)
{
    
    int i= low+rand()%(high-low+1);
    
    swap(&arr[i], &arr[high]);
    return QSPartition(arr, low, high, counter);

    
   
}

// Mergesort
// source consulted from geeksquiz.com
template <class T>
int Mergesort(T arr[], int n)
{
    int count = 0;
    MergesortHelper(arr, 0, n-1, n, count);
    
    return count;
}

template <class T>
void MergesortHelper(T arr[], int low, int high, int n, int& counter)
{
    if(low<high)
    {
        int mid=low+(high-low)/2;
        MergesortHelper(arr, low, mid, n, counter);
        MergesortHelper(arr, mid+1, high, n, counter);
        Merge(arr, low, mid, high, n, counter);

        
    }
    
}


template <class T>
void Merge(T arr[], int low, int mid, int high, int n, int& counter)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 =  high - mid;

    
    // creating temp arrays
    T* L= new T[n1];
    T* R= new T[n2];
    
    // Copy data to temp arrays L[] and R[]
    for(i = 0; i < n1; i++)
    {
        

        L[i] = arr[low + i];
    }
    for(j = 0; j < n2; j++)
    {
        
        R[j] = arr[mid + 1+ j];
    }
    
    /* Merge the the arrays back into arr*/
    i = 0;
    j = 0;
    k = low;
    
    while (i < n1 && j < n2)
    {
        counter++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            
            
        }
        else
        {
            arr[k] = R[j];
            j++;
            
        }
        k++;
    }
    
    while (i < n1)
    {
        counter++;
        arr[k] = L[i];
        i++;
        k++;
    }
    
    
    while (j < n2)
    {
        counter++;
        arr[k] = R[j];
        j++;
        k++;

    }
    

    
    
}

// Shell Sort
// source consulted from geeksquiz.com
template <class T>
int ShellSort(T arr[], int n)
{
    int count = 0;
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            //count++;
            T temp = arr[i];
            int j;
            for (j = i; ((j >= gap)&& (arr[j - gap] > temp)); j -= gap)
            {
                arr[j] = arr[j - gap];
                count++;
                
            }
            if((j<gap)||(arr[j-gap]<=temp))
            {
              count++;
            }
            arr[j] = temp;
        }
        
    }
    
    return count;
}

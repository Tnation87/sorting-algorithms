//
//  main.cpp
//  assign 1
//
//  Created by toka magdy ragab  on 3/27/18.
//  Copyright © 2018 toka magdy ragab . All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <math.h>

using namespace std;

void SelectionSort(int a[], int n)
{
    chrono::system_clock::time_point start = chrono::system_clock::now();
    for (int i = 0, min, tmp,j; i < n; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
    chrono::system_clock::time_point stop = chrono::system_clock::now();
    cout << "selection sort took ";
    cout << chrono::duration_cast<chrono::seconds>(stop - start).count() << " s" << endl;
}

void InsertionSort(int a[],int n)
{
    chrono::system_clock::time_point start = chrono::system_clock::now();
    for (int i = 1,temp,j; i < n; i++)
    {
        temp = a[i];
        for (j = i; j > 0 && temp < a[j-1]; j--)
            a[j] = a[j-1];
        a[j] = temp;
    }
    chrono::system_clock::time_point stop = chrono::system_clock::now();
    cout << "insertion sort took ";
    cout << chrono::duration_cast<chrono::seconds>(stop - start).count() << " s" << endl;
}

void BubbleSort(int a[], int n)
{
    chrono::system_clock::time_point start = chrono::system_clock::now();
    for (int i = 0; i < n; i++)
    {
        int temp;
        for (int j = n-1; j > 0; j--)
        {
            if(a[j] < a[j-1])
            {
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
    chrono::system_clock::time_point stop = chrono::system_clock::now();
    cout << "bubble sort took ";
    cout << chrono::duration_cast<chrono::seconds>(stop - start).count() << " s" << endl;
}

void MER(int a[], int l, int r, int m)
{
    int  i ,j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[i+l];
    for (j = 0; j < n2; j++)
        R[j] = a[m+j+1];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
            
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l+r) / 2;
        MergeSort(a,l,m);
        MergeSort(a,m+1,r);
        MER(a,l,r,m);
    }
}

using namespace std;

int main(int argc, const char * argv[]) {
    int arr[100000];
    int totaltime;
    
    //cout << "unsorted array: ";
    for(int i = 0; i < 100000; i++)
    {
        arr[i] = (rand() % 100000);
    //    cout << arr[i] << "  ";
    }
    //cout << endl << "array sorted using selection sort: ";
    SelectionSort(arr,100000);
    //for(int i = 0; i < 10; i++)
    //    cout << arr[i] << "  ";
    //cout << endl;
    
    
    //cout << "unsorted array: ";
    for(int i = 0; i < 100000; i++)
    {
        arr[i] = (rand() % 100000);
    //  cout << arr[i] << "  ";
    }
    //cout << endl << "array sorted using insertion sort: ";
    InsertionSort(arr,100000);
    //for(int i = 0; i < 100000; i++)
    //   cout << arr[i] << "  ";
    //cout << endl;
    
    
    //cout << "unsorted array: ";
    for(int i = 0; i < 100000; i++)
    {
        arr[i] = rand() % 100000;
        //cout << arr[i] << "  ";
    }
    //cout << endl << "array sorted using bubble sort: ";
    BubbleSort(arr,100000);
    //for(int i = 0; i < 100000; i++)
        //cout << arr[i] << "  ";
    //cout << endl;
    
    
    //cout << "unsorted array: ";
    for(int i = 0; i < 100000; i++)
    {
      arr[i] = rand() % 100000;
    //   cout << arr[i] << "  ";
    }
    //cout << endl << "array sorted using merge sort: ";
    chrono::system_clock::time_point start = chrono::system_clock::now();
    MergeSort(arr,0,100000);
    chrono::system_clock::time_point stop = chrono::system_clock::now();
    totaltime = static_cast<int>(chrono::duration_cast<chrono::microseconds>(stop - start).count());
    cout << "merge sort took " << totaltime << " micro s" << endl;
    //for(int i = 0; i < 10; i++)
    //   cout << arr[i] << "  ";
    //cout << endl;
    
    return 0;
}

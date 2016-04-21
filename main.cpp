//

//  main.cpp

//  Homework 5 2.0

//

//  Created by Carlee Bettler on 4/18/16.

//  Copyright (c) 2016 Carlee Bettler. All rights reserved.

//


#include <iostream>

#include <stack>

#include <fstream>

#include <vector>

#include <cstring>

#include <fstream>

#include <string>

#include <sstream>


using namespace std;


//NAMES OF FILES TO READ IN

//RANDOM: /Users/carleebettler/Documents/Comp 271/Unit 3/random.txt

//REVERSED: /Users/carleebettler/Documents/Comp 271/Unit 3/Reversed2.txt

//NEARLY SORTED: /Users/carleebettler/Documents/Comp 271/Unit 3/NearlySorted.txt

//FEW UNIQUE: /Users/carleebettler/Documents/Comp 271/Unit 3/FewUnique.txt


////MY SAMPLE: /Users/carleebettler/Documents/Comp 271/Unit 3/mySample.txt


int swapGlobal = 0;

int compareGlobal = 0;

int swapGlobal2 = 0;

int compareGlobal2 = 0;

void bubblesort(int A[], int n);

void merge2(int A[], int low, int high, int mid);

void MergeSortCont(int A[], int low, int high);

void InsertionSort(int A[], int n);

void shell_sort (int A[], int n);

int partition(int a[], int left, int right, int pivotIndex); void quicksort(int a[], int left, int right);


int main() {
    
    string file1name;
    stack<string> s;
    string line, line2;
    int sampleNum;
    int i;
    
    
    //The code below reads in a file based on the name the user enters (you must reenter the name for every different file). It then pushes the contents of this file, deliminated by a space, into a stack
    
    
    cout<<"Please enter name of file: " <<endl;
    
    
    getline(cin, file1name);
    
    
    ifstream file1(file1name);
    
    
    while(!file1.is_open()){
        
        cout << "Not able to open file. Please enter another file name: "<< endl;
        
        getline(cin, file1name);
        
        file1.open(file1name);
        
    }
    
    
    if (file1.is_open())
        
    {
        while(!file1.eof())
            
        {
            
            getline (file1,line);
            
            istringstream ss(line);
            
            while(getline(ss, line2, ' ')) {
                
                s.push(line2);
                
            }
            
        }
        
    }
    
    
    
    file1.clear();
    
    file1.close();
    
    
    cout<<s.size()<<endl;
    //For testing purposes
    
    
    int Array1[s.size()];
    
    int Array1B[s.size()];
    
    //Declaring my arrays for the data from my files
    
    
    for(i = 0; i < 10000; i++) {
        
        sampleNum = atoi(s.top().c_str());
        
        Array1[i] = sampleNum;
        
        s.pop();
        
    }
    
    
    
    for(i = 0; i < 10000; i++) {
        
        Array1B[9999-i] = Array1[i];
        
    }
    
    
    
    cout<<Array1[0]<<endl;
    
    cout<< Array1B[0]<<endl;
    //^Testing purposes, assure arrays read in correctly
    
    //I push the contents of my stack onto Array1, and then I push them onto a second array called Array1B in the reverse order so the order in the array matches the order of the data in the file. I realize now that this is not the most effient way, but hey, I'm pretty sure it works, and it is already emmeshed in my code
    
    
    
    
    //Arrays for testing purposes
    
    int Array3[5] = {5,4,3,2,1};
    
    int Array2[6] = {1,1,27,8,2,5};
    
    int Array4[10] = {1,13,4,6,4,33,5,25,7,1};
    
    int Array5[5] = {9,2,4,8,1};
    
    
    //To run my funtions, I would uncomment the specific function I wanted to test before I ran, that way I didn't need to worry about overwriting arrays or using already organized arrays.
    
    
    //BUBBLESORT TESTING
    //bubblesort(Array1B, 10000);
    
    
    
    //MERGE SORT TESTING
    /*cout<<"MERGE SORT"<<endl;
    
    MergeSortCont(Array1B, 0, 10000);
    
    for(int k = 0; k< 10000; k++){
     
     cout<<Array1B[k]<<endl;
     
     }
    
    cout<<"COMPARE VALUES:"<<compareGlobal<<endl;
    
    cout<<"SWAP VALUES:"<<swapGlobal<<endl;
    
    */
    
    
    
    //SHELL SORT TESTING
    //shell_sort(Array1B, 10000);
    
    
    //INSERTION SORT
    InsertionSort(Array1B, 10000);
    
    
    //QUICK SORT
    /*cout<<"QUICK SORT"<<endl;
    quicksort(Array1B, 0, 10000);
    //partition(Array1B, 0, 10000, 5000);
    
    
    for(int l = 0; l< 10000; l++){
     
     cout<<Array1B[l]<<endl;
     
     }
    
    cout<<"COMPARE VALUES:"<<compareGlobal2<<endl;
    
    cout<<"SWAP VALUES:"<<swapGlobal2<<endl;*/
    
    return 0;
    
}

//For all my functions below, I used code from the book, except for quicksort, which I found online. I incremented swap (my term for exchange) whenever an element in the array that was passed in was changed (i.e. A[num] = num2),and I incremented compare whenever an element in the array that was passed in was compared to something else with a greater than/less than sign (i.e. A[num] > num2).

//Additionally, for all non recursive functions (i.e. all but merge and quick sort) in the body of these functions I had them print out the contents of the file they sorted for testing purposes, and I also had them cout the compare and swap values. For my recursive functions I did this in main. Additionally, for my recursive functions I used global instead of local variables, because returning an int would have messed up their functionality, and couting and int in the body of the recursive function gives me a huge list of numbers.


//BUBBLE SORT:

void bubblesort(int A[], int n)

//n = # of elements you are sorting

{
    
    cout<<"BUBBLE SORT"<<endl;
    
    int compare = 0;
    
    int swap = 0;
    
    int i,j,temp;
    
    for(i=1; i<n; i++)
        
    {
        
        for(j=0; j<n-1; j++)
            
        {
            compare++;
            
            if(A[j]>A[j+1])
                
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                swap++;
            }
            
        }
        
    }
    
    
    for(int k = 0; k< n; k++){
        cout<<A[k]<<endl;
    }
    
    cout<<"COMPARE VALUES:"<<compare<<endl;
    cout<<"SWAP VALUES:"<<swap<<endl;
    
}


//MERGE SORT
void merge2(int A[], int low, int high, int mid)

{
    
    int compare = 0;
    
    int swap = 0;
    
    int i,j,k,C[high];
    
    i=low;      //index for first part
    
    j=mid+1;    //index for second part
    
    k=0;        //index for array C
    
    
    
    while((i<=mid) && (j<=high)) {
        
        if(A[i]<A[j]){
            
            C[k]=A[i++];
            
            compareGlobal++;
            
        }
        
        else {
            
            C[k]=A[j++];
            
            compareGlobal++;
            
        }
        
        k++;
        
    }
    
    while(i<=mid)
        
        C[k++]=A[i++];
    
    while(j<=high)
        
        C[k++]=A[j++];
    
    for(i=low, j=0; i<=high; i++,j++){
        
        A[i]=C[j];
        
        swapGlobal++;
        
    }
    
}


void MergeSortCont(int A[], int low, int high) {
    
    int mid;
    
    if(low  < high){
        
        mid = (low + high)/2;
        
        MergeSortCont(A, low, mid);
        
        MergeSortCont(A, mid+1, high);
        
        merge2(A, low, high, mid);
        
    }
    
}



//INSERTION SORT

void InsertionSort(int A[], int n) {
    
    cout<<"\nINSERTION SORT"<<endl;
    
    int i, j, element;
    
    int compare = 0;
    
    int swap = 0;
    
    for(i = 1; i < n; i++) {
        
        element = A[i];
        
        j = i;
        
        while((j>0) && (A[j-1] > element)){
            
            A[j] = A[j - 1];
            compare++;
            j = j - 1;
            //Note: I'm aware this code does technically change an element in the array I passed in, but it does so to in effect iterate through an array. Therefore I don't increment swap until A[j] is set to element
            
        }
        
        swap++;
        A[j] = element;
        
    }
    
    for(int k = 0; k< n; k++){
        cout<<A[k]<<endl;
        
    }
    
    cout<<"COMPARE VALUES:"<<compare<<endl;
    cout<<"SWAP VALUES:"<<swap<<endl;
    
}

//SHELL SORT

void shell_sort (int A[], int n) {
    
    cout<<"\nSHELL SORT"<<endl;
    
    int compare = 0;
    
    int swap = 0;
    
    int temp, gap, i;
    
    int swapped;
    
    gap = n/2;
    
    do {
        
        do {
            
            swapped = 0;
            
            for(i = 0; i < n - gap; i++) {
                
                compare++;
                
                if(A[i] > A[i + gap]) {
                    
                    temp = A[i];
                    
                    A[i] = A[i + gap];
                    
                    A[i + gap] = temp;
                    
                    swapped = 1;
                    
                    swap++;
                    
                }
                
            }
            
        } while(swapped == 1);
        
    } while((gap = gap/2) >= 1);
    
    
    for(int k = 0; k< n; k++){
        
        cout<<A[k]<<endl;
        
    }
    
    cout<<"COMPARE VALUES:"<<compare<<endl;
    cout<<"SWAP VALUES:"<<swap<<endl;
    
}



//QUICK SORT

int partition(int a[], int left, int right, int pivotIndex)
//for pivot, just chose the middle

{
    int pivot = a[pivotIndex];
    do
    {
        while (a[left] < pivot) {
            left++;
            compareGlobal2++;
            
        }
        
        while (a[right] > pivot) {
            
            right--;
            compareGlobal2++;
            
        }
        
        if (left < right && a[left] != a[right])
        {
            swap(a[left], a[right]);
            swapGlobal2++;
        }
        
        else
            
        {
            return right;
            
        }
        
    }
    
    while (left < right);
    
    return right;
}


void quicksort(int a[], int left, int right)
//Note: I'm aware there is a slight issue with quicksort, based on the numbers it returns (it doesnt' quite go to 10,000, but it is in order)
//but I'm not sure what exactly. 

{
    if (left < right)
        
    {
        int pivot = (left + right) / 2; // middle
        int pivotNew = partition(a, left, right, pivot);
        quicksort(a, left, pivotNew - 1);
        quicksort(a, pivotNew + 1, right);
    }
    
}


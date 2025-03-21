#include<iostream>
#include<cmath>

void partition_1(double A[],int start,int mid,int end){
    int i=0;
    int loc=0;
    double pivot=A[mid];
    while(i<end-start+1){
        if(A[start+i]<pivot){
            loc++;
        }
                                          //now the place where the pivot stays is--start+loc
    }

}

void partition_2(double A[], int start, int mid, int end){

}

void swap(double A, int a,int b){
    double x=A[a];
    A[a]=A[b];
}
  
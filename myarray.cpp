#include<iostream>
template <class T>
class yourarray{
   private:
     int* yaray;
     int size;
     int len;

   public:
     yourarray(int length){
        int* yaray=new T[length];
        size=0;
        len=length;
     }

     int length(){
         return size;
     }

     T lastelt(){
        if(size>0){
        return yaray[size-1]}
        else{
            throw std::out_of_range("the array is empty");
        }
     }

     T firstelt(){
        if(size>0){
            return yaray[0]}
            else{
                throw std::out_of_range("the array is empty");
            }       
     }

     void append(T x){
        if(size<len){
            yaray[size]=x;
        }
        else{
            throw std::out_of_range("the array is full") ;
        }
     }

     T removelast(){
        if(size==0){
            throw std::out_of_range("the array is empty");
        }
        else{
            size--;

            return yaray[size+1] ;
        } 
     }
};
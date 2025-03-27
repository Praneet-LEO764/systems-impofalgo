#include<iostream>
template <class T>
class yourarray{
   private:   //if one is sane...this is not required
     T* yaray;
     int size;
     int len;

   public:
     yourarray(int length){
        yaray=new T[length];
        size=0;
        len=length;
     }

     int length(){
         return size;
     }

     T lastelt(){
        if(size>0){
        return yaray[size-1];}
        else{
            throw std::out_of_range("the array is empty");
        }
     }

     T firstelt(){
        if(size>0){
            return yaray[0];}
            else{
                throw std::out_of_range("the array is empty");
            }       
     }

     void append(T x){
        if(size<len){
            yaray[size]=x;
            size++;
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

            return yaray[size] ;
        } 
     }

     T elementat(int i){
        if(i<size){
        return yaray[i];}
        else{
            throw std::out_of_range("seriously?");
        }
     }   
     void replace(int i, T x){
        if(i<size){
            yaray[i]=x;
        }
        else{
                throw std::out_of_range("seriously?");
            }
     }
     void insert(int i, T x){
        if(i<=size&&size<len){
            
            for(int x=size-1;x>=i;x--){

                
                yaray[x+1]=yaray[x];}
            yaray[i]=x;
            size++;}

        else{
                throw std::out_of_range("can't do..sorry");
            }
     
    }

    void display(){
        for(int i=0;i<size;i++){
            std::cout<<yaray[i]<<"->";
        }
    }
    void remove(int i){
        if(i>size-1|| i<0){
            throw std::out_of_range("there is nothing to remove");
        }
        else{

            if(i==size-1){
                size--;
            }
            else{
            size--;
           for(int k=i;k<size;k++){
            
            yaray[k]=yaray[k+1];
           }
        }
    }
}


};

int main(){
    yourarray<int> ar(4);
    ar.append(4);
    ar.append(562356356);
    ar.append(0);
    ar.append(235);
    ar.removelast();
    ar.insert(1,9876543);

    ar.remove(2);
    ar.display();
    return 0;
}
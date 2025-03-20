#include<iostream>
template <class T>
class vector{
    private:
      T* arr=nullptr;
      int size=0;
      int capacity;
    public:
      vector(){
        capacity=1;
        arr=new T[1];
      }
    
    void updatecapacity(int cap){
        if (size>cap){
            std::cout<<"this won't be permitted, you have more element";}
        else{
            T* newarr=new T[cap];
            capacity=cap;
            for(int i=0;i<size;i++){
                newarr[i]=arr[i];
            }
            delete[] arr;
            arr=newarr;
            
        }

        
    } 
    void append(T x){
        if (size<capacity){
           arr[size]=x;
           size++;
        }
        else{
            updatecapacity(2*size);
            arr[size]=x;
            size++;
        }
    }
    T removelast(){
        T ret=arr[size-1];
        size--;
        if(size<=capacity/4){
            updatecapacity(capacity/2);
        }
        return ret;
    }
    T& operator[](int index) {
        return arr[index];
    } 
};

int main(){
   vector<int> myvec;
   myvec.append(0);
   myvec.append(1);
   myvec.append(2);
   myvec.append(3);
   myvec.append(4);
   myvec.append(5);
   myvec.append(6);
   myvec.append(7);
   myvec.append(9);
   myvec.append(9);
   myvec.append(10);
  
   
   std::cout<< myvec[8];
   return 0;
}
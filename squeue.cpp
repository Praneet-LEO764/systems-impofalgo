#include <iostream>
template <class T>
class stack{
  private:
    int len;
    
    T* stk;
  public:
  int size;
    stack(int length){
        len=length;
        size=0;
        stk = new T[len];

    }
    void enqueue(T x){
         if(size>=len){
            throw std::out_of_range("stack's full");

         }
         else{
            stk[size]=x;
            size++;
         }
    }
    T dequeue(){
        if(size==0){
            throw std::out_of_range("stack's empty");

        }
        else{
            size--;
            return stk[size];
        }
    }

    void print(){
        for(int i=0;i<size;i++){
            std::cout<<stk[i]<<"\n";
        }
    }
};


/*we now implement queue using stack class that we just created...we call such an implementation of queues as squeue*/

template <class T>
class squeue{
    private:
    int len;
    int size;
    stack<T> first;
     stack<T> second;
    public:
    squeue(int length) : first(length), second(length) {
        len = length;
        size = 0;
    }
    
     

     void enqueue(T x){
        if(size>=len){
            throw std::out_of_range("the queue is full");
        }
        else{
            first.enqueue(x);
            size++;
        }
     }

     T dequeue() {
        if (size == 0) {
            throw std::out_of_range("the queue is empty");
        }
        
        if (second.size == 0) {
            while (first.size > 0) {
                second.enqueue(first.dequeue());
            }
        }
    
        T value = second.dequeue();
        size--;
        return value;
    }
     
     
};

int main(){

    squeue<int> queue(5);
    queue.enqueue(23);
    queue.enqueue(34);
    queue.enqueue(45);
    queue.enqueue(56);
    queue.enqueue(67);
    std::cout<<queue.dequeue();
    std::cout<<queue.dequeue();
    std::cout<<queue.dequeue();
    std::cout<<queue.dequeue();
    std::cout<<queue.dequeue();
    
    
    return 0;
}
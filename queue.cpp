#include <iostream>
template <class T>
class Node {            //Note::its a different node when compared to the node we constructed for simple linked list.
    public:
        T data;
        Node<T>* next;
        Node<T>* prev;
    
        Node(T value) {
            data = value;
            next = nullptr;
            prev=nullptr;
        }
    };

template <class T>
class CDLL{                              //CDLL stands for circular double linked list-This is tailored for the problem of circular implementation of queue(cqueue)
    public:
        Node<T>* head;
        
        
        Node<T>* tail;
        CDLL(){
            head=nullptr;
            tail=nullptr;
            
        }
        void append(T x){
            Node<T>* naya = new Node<T>(x);
            if(head==nullptr){
                head=naya;
                tail=naya;
            }
            else{
                naya->prev=tail;
                tail->next=naya;
                tail=tail->next ;
                            }
                        }
};

template <class T>
class cqueue {
   private:
      
      T* head;
      T* tail;
      CDLL<T> queue;
      
   public:
      cqueue(int size){
        
        
        for(int i=0;i<size+1;i++){
         queue.append(T{});
        }
        queue.tail->next=queue.head;
        queue.head->prev=queue.tail;
        queue.head=queue.tail;
        
        head=queue.head;
        tail=queue.tail;
      }

      void enqueue(T x){
         if (head==tail){
            head=head->next;
            head->data=x;
            tail=head->next; //tail is always at the next empty node           

         }
         else if (tail->next==head){
            std::cout<<"The queue is full"<<'\n';
           
         }
         else{
            tail->data=x;
            tail=tail->next;
           
           
         }
      }

      T dequeue(){
        if (head==tail){
            throw std::out_of_range("Queue is empty");
        }
        else{
            
            head=head->next;
            return head->prev->data;
            
        }
      }


};
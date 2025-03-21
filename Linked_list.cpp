#include <iostream>
template <class T>
class Node {
    public:
        T data;
        Node<T>* next;
    
        Node(T value) {
            data = value;
            next = nullptr;
        }
    };

template <class T>
class Linked_list{
    public:
        Node<T>* head;
        
        
        Node<T>* tail;
        Linked_list(){
            head=nullptr;
            tail=nullptr;
            
        }
        void append(T x){
            Node<T>* naya = new Node(x);
            if(head==nullptr){
                head=naya;
                tail=naya;
            }
            else{
                tail->next=naya;
                tail=tail->next;   //correctly updated the tail
            }
        }
        void display(){
            Node<T>* current =head;
            while(current!=nullptr){
                std::cout<<current->data<<"\n";
                current=current->next;
            }
        }
        void remove(T x){//calling this function leads to deletion of the first instance of an item x (of tpe T) from the linked list.
            
            if (head->data==x){
                Node<T>* temp=head->next;
                if (tail==head){
                   tail=tail->next;
                   delete head;
                   head=temp;
                }
                else{delete head;
                head=temp;}
            }
            else{
                Node<T>* current =head->next;
                Node<T>* pre =head;
                while(current!=nullptr && current->data!= x){
                    current=current->next;
                    pre=pre->next;
                 }
                if (current!=nullptr){
                    if(current==tail){
                        tail=pre;
                    }
                    pre->next=current->next;
                    delete current;
            }
        }

        }
        void removefirst(){
            if (head!=nullptr){
                Node<T>* temp=head->next;
                if(head==tail){
                  tail=head->next;  
                }
                delete head;
                head=temp;
            }
            else{
                std::cout<<"The list is empty....are you sure u are using it on the correct list?"
            }

        }
        void removelast(){
            if(head==nulptr){
                std::cout<<"there is nothing to remove"
            }
            else{
                Node<T>* pre=head;
                Node<T>* current= head->next;
            }
            while(current->next!=nullptr){
                current=current->next;
                pre=pre->next;
            }
            tail=pre;
            pre->next=current->next;
            delete current;
        }
};

int main() {
    Linked_list<int> myList;

    myList.append(11234);
    myList.append(201325);
    myList.append(540);

    
    myList.removelast();

    myList.display();
    return 0;
}
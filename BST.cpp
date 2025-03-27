#include<iostream>
//Implemented by keeping things simple and not using any private thingy
template <class T>
class node{
    public:
      node<T>* parent;
      node<T>* left;
      node<T>* right;
      T data;
      
      node(T x){
        parent=nullptr;
        left=nullptr;
        right=nullptr;
        data=x;
      }
}; 
//----------------------------------------------------------------------------------------------------------------------------------------------------
template<class T>     
class BST{
  private:
    int size;
  public:
    node<T>* head;


    BST(){
        head=nullptr;
    }
    
    //----------------------------------------------------------------------------------------------------------------------------------------------------
    node<T>* just_less(node<T>* x){
       node<T>* current=head;
       node<T>* result=nullptr;
       while(current!=nullptr){
          if(current->data>x->data){
         
           current=current->left;
         
       }
          else{
            result=current;
            current=current->right;
          }

        
    }
    return result;
       
    }
    //----------------------------------------------------------------------------------------------------------------------------------------------------
    node<T>* just_more(node<T>* x){
        node<T>* current=head;
        node<T>* result=nullptr;
        while(current!=nullptr){
           if(current->data<x->data){
          
            current=current->right;
          
        }
           else{
             result=current;
             current=current->left;
           }
 
         
     }
     return result;
        
     }
     //----------------------------------------------------------------------------------------------------------------------------------------------------
    node<T>* highest(){
        node<T>* current=head;
        while(current->right!=nullptr){
            current=current->right;
        }
        return current;
    }
    //----------------------------------------------------------------------------------------------------------------------------------------------------
    node<T>* lowest(){
        node<T>* current=head;
        while(current->left!=nullptr){
            current=current->left;
        }
        return current;
    }
    //----------------------------------------------------------------------------------------------------------------------------------------------------
    bool exists(T x){
        node<T>* current=head;
        bool value=false;
        while(current!=nullptr && !value){
            if (current->data>x){
                 current=current->left;
            }
            else if(current->data<x){
                current=current->right;
            }
            else{
                value=true;
            }
        }
        return value;
    }
    //----------------------------------------------------------------------------------------------------------------------------------------------------
    void append(T x){
        node<T>* n=new node(x);
        if(head==nullptr){
           head=n;
        }
        
        else{
            node<T>* lower=just_less(n);
            node<T>* upper=just_more(n);
            if(lower!=nullptr&& upper!=nullptr){
                if (lower->right==upper){
                    n->right=lower->right;
                    lower->right=n;
                }
                else{
                    n->left=upper->left;
    
                    upper->left=n;
                }
            }

            else if(lower==nullptr){
                node<T>* position=lowest();
                position->left=n;

            }
            else if(upper ==nullptr){
                node<T>* position=highest();
                position->right=n;
            }
            
        }
    }
    // ----------------------------------------------------------------------------------------------------------------------------------------------
    
    void del(T x) {
        node<T>* current = head;
        node<T>* parent = nullptr;
    
        // Find the node to delete and its parent
        while (current != nullptr && current->data != x) {
            parent = current;
            if (x < current->data)
                current = current->left;
            else
                current = current->right;
        }
    
        if (current == nullptr) return;  // Node not found
    
        // Case 1: Node has no children
        if (current->left == nullptr && current->right == nullptr) {
            if (parent == nullptr) head = nullptr; // Deleting root node
            else if (parent->left == current) parent->left = nullptr;
            else parent->right = nullptr;
            delete current;
        }
        
        // Case 2: Node has one child
        else if (current->left == nullptr || current->right == nullptr) {
            node<T>* child = (current->left) ? current->left : current->right;
            if (parent == nullptr) head = child; // Deleting root node
            else if (parent->left == current) parent->left = child;
            else parent->right = child;
            delete current;
        }
    
        // Case 3: Node has two children
        else {
            node<T>* successor = current->right;
            node<T>* successorParent = current;
            while (successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }
    
            current->data = successor->data; // Copy successor data
            if (successorParent->left == successor)
                successorParent->left = successor->right;
            else
                successorParent->right = successor->right;
    
            delete successor;
        }
    }
    
};

int main(){
    BST<int> x;
    x.append(1);
    x.append(0);
    x.append(2);
    x.append(3);
    x.del(2);
    x.append(123);
    x.append(5432);
    x.append(1234);
    x.append(2);
    x.del(1);

    
    std::cout<<x.head->data;
    return 0;
}
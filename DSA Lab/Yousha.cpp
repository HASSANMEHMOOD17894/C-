// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int Data){
        this->data=Data;
        this->next=nullptr;
    }
};
class linklist{
     private:
    Node*head;
    
   public:
   
    linklist(){
      head=nullptr;
  }  
  void insertatbegin(int newdata){
      Node* newnode= new Node(newdata);
     newnode->next=head;
      head=newnode;
      
  } 
  void insertatend(int newdata){
      Node*newnode=new Node(newdata);
     
      if(head==nullptr){
          head=newnode;
      }else{
           Node*current=head;
          while(current->next!=nullptr){
              current=current->next;
          }
          current->next=newnode;
      }
      
  }
  void insertatspecific(int n,int newdata){
      int count=0;
      Node* current= head;
      Node* newnode=new Node(newdata);
      if(n==0){
          newnode->next=head;
          head=newnode;
          return;
      }
      while(current!=nullptr){
           Node*newnode=new Node(newdata);
          if(count==n-1){
              newnode->next=current->next;
              current->next=newnode;
          }
          if(count==n){
             
              newnode->next=current;
              
              
          }
          count++;
      }
  }
  void print(){
      Node*current=head;
      while(current!=nullptr){
          cout<<current->data<<"->";
          current=current->next;
      }
      cout<<"Null"<<endl;
  }
  
  
};

int main() {
     linklist list;
    // list.insertatbegin(1);
    // list.insertatbegin(2);
    // list.insertatbegin(3);
    // list.print();
    // list.insertatend(4);
    // list.insertatend(2);
    // list.insertatend(1);
    // list.print();
    int n;
    int choice;
    do{
        
    cout<<"enter choice:"<<endl;
    cin>>choice;
    
    switch(choice){
        case 1:
        
         
         cout<<"enter the value:";
         cin>>n;
         list.insertatbegin(n);
         list.print();
         break;
        case 2:
         
         
         cout<<"enter the value:";
         cin>>n;
         list.insertatend(n);
         list.print();
         break;
        case 3:
         
         int val;
         cout<<"enter the position:";
         cin>>n;
         cout<<"enter the value:"<<endl;
         cin>>val;
          list.insertatspecific(n,val);
        list.print();
         break;
        case 4:
        
        
         cout<<"enter the value:";
         cin>>n;
        //  list.deleteatbegin(n);
         break;
        case 5:
         list.print();
         break;
         case 6:
         cout<<"Exit";
         break;
         default:
         cout<<"invalid input:"<<endl;
         break;
    }
    }while(choice!=6);

    return 0;
}

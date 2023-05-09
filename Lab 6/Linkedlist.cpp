#include <iostream>
#include <chrono>
using namespace std;

struct Node {
   int data;
   struct Node *next;
};
struct Node* top = NULL;
void push(int val) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = val;
   newnode->next = top;
   top = newnode;
}
void pop() {
   if(top==NULL)
   cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<< top->data <<endl;
      top = top->next;
   }
}
void display() {
   struct Node* ptr;
   if(top==NULL)
   cout<<"stack is empty";
   else {
      ptr = top;
      cout<<"Stack elements are: ";
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   cout<<endl;
}

int main (){
    int arr[20]={23,5,6,80,12,45,67,100,21,34,67,54,65,20,53,85,96,92,16,83};
    for (int i=0;i<20;i++){
        auto start = chrono::high_resolution_clock::now();
        push(arr[i]);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast <chrono::nanoseconds>(end - start);
        cout<<"run time for push an element " <<duration.count()<<" nanosecond "<<endl;
        
    }
    cout<<endl;
    
    for (int i=0;i<5;i++){
        auto start = chrono::high_resolution_clock::now();
        display();
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast <chrono::nanoseconds>(end - start);
        cout<<"run time for display an element " <<duration.count()<<" nanosecond "<<endl;
        
    }
    cout<<endl;
    for (int i=0;i<10;i++){
        auto start = chrono::high_resolution_clock::now();
        pop();
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast <chrono::nanoseconds>(end - start);
        cout<<"run time for pop an element " <<duration.count()<<" nanosecond "<<endl;
        
    }
}
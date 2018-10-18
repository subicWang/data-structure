#include<iostream>
using namespace std;

class Stack{
public:
  enum {MaxStack=5};
  Stack(){init();}
  void init(){top=-1;}
  bool isFull(){return top>=MaxStack-1;}
  bool isEmpty(){return top<0;}
  void push(int n){
    if(isFull()){
      errMsg("Full stack, Can't push!");
      return;
    }
    arr[++top]=n;
  }
  int pop(){
    if(isEmpty()){
      errMsg("Empty stack, Poping dummy values!");
      return dummy_val;
    }
    return arr[top--];
  }
  void dump(){
    cout<<"Stack contents, top to bottom:\n";
    for(int i=top; i>=0; i--)
      cout<<arr[i]<<'\t';
  }
private:
  void errMsg(const char* msg) const{
    cerr<<"\n***Stack operation failure:"<<msg<<"\n";
  }
  int top;
  int arr[MaxStack];
  int dummy_val;
};

#include<iostream>
#include<stack>
#define GET_ARRAY_LENGTH(array,len){len=sizeof(array)/sizeof(array[0]);}
using namespace std;
class Solution{
public:
  void push(int node){
    stack1.push(node);
  }
  int pop(){
    if(stack2.empty()){
      while(!stack1.empty()){
        stack2.push(stack1.top());
        stack1.pop();
      }
    }
    int a = stack2.top();
    stack2.pop();
    return a;
  }
private:
  stack<int> stack1;
  stack<int> stack2;
};
int main(int argc, char const *argv[]) {
  Solution s;
  int a[]={1,2,3,4,5};
  int b[]={6,7,8,9,10};
  int len;
  GET_ARRAY_LENGTH(a,len);
  for(int i=0; i<len; i++){
    s.push(a[i]);
  }
  for(int i=0; i<len-1; i++){
    cout<<s.pop();
  }
  for(int i=0; i<len; i++){
    s.push(b[i]);
  }
  for(int i=0; i<len-1; i++){
    cout<<s.pop();
  }
  return 0;
}

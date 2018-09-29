#include<iostream>
using namespace std;

void swap1(int a, int b){
  int tmp;
  tmp=a; a=b; b=tmp;
}
void swap2(int *a, int *b){   //接收的参数a是地址，应当传入地址
  int tmp;
  tmp=*a;*a=*b;*b=tmp;
}
void swap3(int &a, int &b){  // 对a的引用操作
  int tmp;
  tmp=a; a=b; b=tmp;
}
// void swap4(int *&a, int *&b){
//   int tmp;
//   tmp = *a;*a = *b;*b = tmp;
// }
void f(int &refa){
  refa=100;
}
void test(int *&p){
  int a=1;
  p = &a;
  cout<<*p<<endl;
}
int main(int argc, char const *argv[]) {
  int a[1][2] = {1,2};
  int **p;
  *p =  &a[0][0];
  // cout<<a<<endl;
  cout<<*p<<endl;
  return 0;
}

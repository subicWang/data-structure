#include<iostream>
using namespace std;
//输入一个整数，输出二进制含1的个数
// 考虑复数的情况，不能简单的右移后与1与。而是应该减一后与原整数与运算，会将该整数的最右边的1变为0.
int numberOf1(int n){
  int count=0;
  while(n){
      count++;
      n = (n-1)&n;
  }
  return count;
}
int main(int argc, char const *argv[]) {
  int n;
  int count=0;
  cin>>n;
  count = numberOf1(n);
  cout<<n<<"二进制含1的个数为:"<<count<<endl;
  return 0;
}

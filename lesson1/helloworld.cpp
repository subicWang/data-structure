#include<iostream>
using namespace std;
int f(int x, int i=0){
  i++;
  if(x<=3){
    return i;
  }
  return f(x-2)+f(x-4)+1;
}
// 两个非负数之间的最大公约数
long long gcd(long long x, long long y){
  if (y==0){
    return x;
  }
  else{
    std::cout << x <<" "<< y << '\n';
    return gcd(y, x%y);
  }
}
int main(int argc, char const *argv[]){
  int res = f(8);
  std::cout <<res<< '\n';
  return 0;
}

#include<iostream>
#include<math.h>
using namespace std;

int main(int argc, char const *argv[]) {
  long long h=0;
  cin>>h;
  long long x= floor(sqrt(1+4*h)/2 -0.5);
  cout<<x;
  return 0;
}

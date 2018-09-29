#include <iostream>
using namespace std;
void Hanoi(int n, char x, char y, char z, int &num){
  if (n==1) num++;
  else{
    num++;
    Hanoi(n-1, x, z, y, num);
    Hanoi(n-1, y, x, z, num);
  }
}
int main(int argc, char const *argv[]) {
  int num=0;
  Hanoi(5, 'x', 'y', 'z', num);
  printf("%d\n", num);
  return 0;
}

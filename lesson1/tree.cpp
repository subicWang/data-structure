#include<iostream>
# define GET_ARRAY_LENGHT(array,len){len=sizeof(array)/sizeof(array[0]);}
using namespace std;
int main(int argc, char const *argv[]) {
  char acX[]="abcdefg";
  char acY[]={'a','b','c','d','e','f','g'};
  int len1, len2;
  GET_ARRAY_LENGHT(acX,len1);
  GET_ARRAY_LENGHT(acY,len2);
  cout<<len1<<endl;
  cout<<len2<<endl;
  return 0;
}

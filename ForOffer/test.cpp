#include<stdio.h>
#include<typeinfo>
#include<iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  std::string str1("trend");
  std::string str2("micro");
  std::string& strs = str1;
  std::string* ptrs = &str1;
  cout<<strs<<endl;
  strs = str2;
  ptrs = &str2;
  cout<<strs<<endl;
  cout<<*ptrs<<endl;
  return 0;
}

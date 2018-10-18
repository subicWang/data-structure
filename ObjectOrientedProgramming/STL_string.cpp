#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void printChar(char c){
  cout<<c;
}
int main(int argc, char const *argv[]) {
  string s="pele, the greatest ever";
  string::size_type where;
  cout<<"s:           "<<s<<endl;
  cout<<"s in reverse:";
  for_each(s.rbegin(), s.rend(), printChar);
  cout<<endl;
  where=s.find('a');
  cout<<"'a' is the "<<where<<"th char in "<<s<<endl;
  random_shuffle(s.begin(), s.end());
  cout<<"s after random shuffle: "<<s<<endl;
  sort(s.begin(), s.end());
  cout<<"s sorted in ascending order: "<<s<<endl;
  return 0;



  
}

#include<iostream>
#include<set>
#include<string>
using namespace std;
int main(int argc, char const *argv[]) {
  string s;
  set<string> Stuff;
  while(cin>>s){
    Stuff.insert(s);
  }
  cout<<Stuff.size();
  return 0;
}

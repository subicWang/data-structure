#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int N=0, ai=0, SUMA=0, MEANA, count=0;
  vector<int> a;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>ai;
    a.push_back(ai);
    SUMA+=ai;
  }
  MEANA = SUMA/N;
  if(SUMA%N!=0) return -1;
  for(vector<int>::iterator it=a.begin(); it<a.end();it++){
    if(abs(*it-MEANA)%2!=0) return -1;
    if(*it>MEANA) count+=(*it-MEANA)/2;
    }
  cout<<count;
  return 0;
}

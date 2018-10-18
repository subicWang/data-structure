#include<iostream>
#include<string>
using namespace std;

string LeftRotating(string s, int k){
  if(k<0) return NULL;
  if(k==0) return s;
  int L = s.size();
  if(k>L) k=k%L;
  //思路1： 分别用两个字符串存起来，然后，颠倒顺序
  // string s1="";
  // string s2="";
  // for(int i=0;i<s.size();i++){
  //   if(i<k) s1.push_back(s[i]);
  //   else s2.push_back(s[i]);
  // }
  // return s2+s1;
  // 思路2： 利用string带的算法函数
  // substr: 取串的某一部分
  // erase: 去除串的某一部分
//   string sTemp="";
//   sTemp = s.substr(0,k);
//   s.erase(0, k);
//   s += sTemp;
//   return s;
  // 思路3：比较讨巧
  s+=s;
  return s.substr(k,L);
}

int main(int argc, char const *argv[]) {
  string s="";
  int k=0;
  cin>>s;
  cin>>k;
  cout<<LeftRotating(s,k);
  return 0;
}

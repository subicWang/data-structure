#include<iostream>
using namespace std;
//����һ����������������ƺ�1�ĸ���
// ���Ǹ�������������ܼ򵥵����ƺ���1�롣����Ӧ�ü�һ����ԭ���������㣬�Ὣ�����������ұߵ�1��Ϊ0.
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
  cout<<n<<"�����ƺ�1�ĸ���Ϊ:"<<count<<endl;
  return 0;
}

#include<iostream>
using namespace std;
bool g_invalidinput = false;
int findTheGreatestSumOfSubArray(int* pData, int nLength){
  if(pData==NULL||nLength==0){
    g_invalidinput=true;
    return 0;
  }
  g_invalidinput = false;
  int curSum=0;
  int greatestSum=0;
  for(int i=0;i<nLength;i++){
    if(curSum<0){
      curSum = pData[i];
    }
    else{
      curSum += pData[i];
    }
    if(curSum>greatestSum){
      greatestSum = curSum;
    }

  }
  return greatestSum;
}
int f(int x) {
    int s=0;
    while(--x >0)   s+=f(x);
    return max(s,1);
}
int main(int argc, char const *argv[]) {
  int a = f(7);
  cout<<a;
  return 0;
}

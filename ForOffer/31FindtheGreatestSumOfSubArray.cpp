#include<iostream>
#define GET_ARRAY_LEN(array, len){len=sizeof(array)/sizeof(array[0]);}
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

int main(int argc, char const *argv[]) {
  int numbers[]={5,2,1,-4,3,-6,3,9,2,-11,3};
  int len = sizeof(numbers)/sizeof(numbers[0]);
  int sum = findTheGreatestSumOfSubArray(numbers, len);
  cout<<sum;
  return 0;
}

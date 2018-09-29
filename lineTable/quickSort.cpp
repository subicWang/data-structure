#include<iostream>
using namespace std;
#define GET_ARRAY_LENGTH(array,len){len=sizeof(array)/sizeof(array[0]);}
void QuickSort(int array[], int start, int end){
  if(start>=end) return;
  int Pivot = array[start];
  int left=start, right=end;
  while(left<right){
    while(array[right]>Pivot && left<right)
      right--;
    array[left]=array[right];
    while(array[left]<=Pivot && left<right)
      left++;
    array[right]=array[left];
  }
  array[left]=Pivot;
  QuickSort(array,start,left-1);
  QuickSort(array,left+1,end);
}
int main(int argc, char const *argv[]) {
  int array[]={1,3,2,4,5,2,4,67};
  int len;
  GET_ARRAY_LENGTH(array, len);
  int start=0;
  int end=len-1;
  QuickSort(array,start,end);
  for(int i=0;i<len;i++){
    cout<<array[i]<<"\t";
  }
  cout<<"\n";
  return 0;
}

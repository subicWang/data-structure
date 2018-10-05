#include<iostream>
using namespace std;
#define GET_ARRAY_LEN(array,len){len=sizeof(array)/sizeof(array[0]);}
bool g_bInputInvalid = false;
bool checkInvalidArray(int* numbers, int length){
  g_bInputInvalid = false;
  if(numbers==NULL||length==0){
    g_bInputInvalid = true;
  }
  return g_bInputInvalid;
}
bool CheckMoreThanHalf(int* numbers, int length, int number){
  int times=0;
  for(int i=0;i<length;i++){
    if(numbers[i]==number){
      times++;
    }
  }
  bool isMoreThanHalf=true;
  if(times*2<length){
    isMoreThanHalf=false;
    g_bInputInvalid=true;
  }
  return isMoreThanHalf;
}
void printArray(int*numbers, int length){
  for(int i=0;i<length;i++){
    cout<<numbers[i]<<",";
  }
}
int transform(int* numbers, int start, int end){
  int Pivot=numbers[start];
  while(start<end){
    while(start<end&&numbers[end]>Pivot){
      end--;
    }
    numbers[start]=numbers[end];
    while(start<end&&numbers[start]<=Pivot){
      start++;
    }
    numbers[end]=numbers[start];
  }
  numbers[start]=Pivot;
  return start;
}
void quickSort(int* numbers, int length, int start, int end){
  if(start==end){
    return;
  }
  int index=transform(numbers, start, end);
  if(index<end){
    quickSort(numbers, length, index+1, end);
  }
  if(index>start){
    quickSort(numbers, length, start, index-1);
  }
}
int moreThanHalfNum(int* numbers, int length){
  if(checkInvalidArray(numbers, length)){
    return 0;
  }
  int middle = length>>1;
  cout<<"middle "<<middle<<endl;
  int start = 0;
  int end = length-1;
  int index = 0;
  while(index!=middle){
      index=transform(numbers, start, end);
      if(index>middle){
        end=index-1;
      }
      else{
        start=index+1;
      }
  }
  int result=numbers[middle];
  if(!CheckMoreThanHalf(numbers,length,result)){
    result=0;
  }
  return result;
}
int moreThanHalfNum2(int* numbers, int length){
  if(checkInvalidArray(numbers, length)){
    return 0;
  }
  int result=0;
  int times=0;
  for(int i=1;i<length;i++){
    if(times==0){
      result=numbers[i];
      times+=1;
    }
    else if(numbers[i]==numbers[i-1])
      times++;
    else
      times--;
  }
  cout<<"times"<<times<<endl;
  if(times>=1 and CheckMoreThanHalf(numbers, length, result)){
    return result;
  }else{
    return 0;
  }
}
int main(int argc, char const *argv[]) {
  int numbers[]={1,2,3,4,2,1,1,1,1,1,1};
  int len;
  GET_ARRAY_LEN(numbers, len);
  // quickSort(numbers, len,0,len-1);
  // int val=moreThanHalfNum(numbers, len);
  int val=moreThanHalfNum2(numbers, len);
  cout<<"该数组中超过一半的数为："<<val<<endl;
  printArray(numbers, len);
  return 0;
}

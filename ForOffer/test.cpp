#include<iostream>
#include<vector>
using namespace std;

int inversePairsCore(int* &copy, int* &data, int start, int end){
  if(start==end){
    copy[start]=data[start];
    return 0;
  }
  int length=(end-start)/2;
  int left = inversePairsCore(copy, data, start, start+length);
  int right = inversePairsCore(copy, data, start+length+1, end);
  int i=start+length;
  int j=end;
  int indexcopy=end;
  long long count=0;
  while(i>=start&&j>=start+length+1)
     {
        if(data[i]>data[j])
           {
             copy[indexcopy--]=data[i--];
             count+=j-start-length;          //count=count+j-(start+length+1)+1;
           }
        else
           {
             copy[indexcopy--]=data[j--];
           }
     }
  for(;i>=start;--i)
      copy[indexcopy--]=data[i];
  for(;j>=start+length+1;--j)
      copy[indexcopy--]=data[j];
  for(int ii=start; ii<=end; ii++)
      data[ii] = copy[ii];
  return left+right+count;
}
int inversePairs(int* data, int length){
  if(data==NULL||length<0){
    return 0;
  }
  int* copy = new int[length];
  for(int i=0;i<length;i++){
    copy[i]=data[i];
  }
  int count=inversePairsCore(copy, data, 0, length-1);
  delete[] copy;
  return count%1000000007;
}
int main(int argc, char const *argv[]) {
  int data[4]={7,5,6,4};
  int len = sizeof(data)/sizeof(data[0]);
  int count = inversePairs(data, len);
  cout<<count;
  return 0;
}

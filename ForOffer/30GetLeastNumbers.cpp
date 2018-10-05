#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
#define GET_ARRAY_LEN(array,len){len=sizeof(array)/sizeof(array[0]);}
/*找出数组中最小的K个数*/
// 在可以改变原有数组顺序的前提下，可以通过寻找第K大的数。然后将该数前面的数返回。
bool g_bInputInvalid = false;
bool checkInvalidArray(int* numbers, int length){
  g_bInputInvalid = false;
  if(numbers==NULL||length<=0)
    g_bInputInvalid = true;
  return g_bInputInvalid;
}
int partition(int* numbers, int start, int end){
  int Pivot=numbers[start];
  while(start<end){
    while(start<end && numbers[end]>=Pivot)
      end--;
    numbers[start]=numbers[end];
    while (start<end && numbers[start]<Pivot)
      start++;
    numbers[end]=numbers[start];
  }
  numbers[start]=Pivot;
  return start;
}
void getLeastNumbers(int* numbers, int* result, int length, int K){
  if(numbers==NULL||result==NULL||K>length||length<=0||K<=0)
    return ;
  int start=0;
  int end=length-1;
  int index=0;
  while(index!=K-1){
    index = partition(numbers, start, end);
    if(index>K-1)
      end = index-1;
    else
      start = index+1;
  }
  for(int i=0;i<K;i++){
    result[i] = numbers[i];
  }
}
void printArray(int* array, int length){
  for(int i=0;i<length;i++){
    cout<<array[i]<<",";
  }
}
class GetLeastNumbersbyHeap{
public:
  void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
      cout<<v[i]<<",";
    }
  }
  vector<int> getLeastNumbersByHeap(vector<int> input, int k){
    int len=input.size();
    if(len<k||len<=0)
      return vector<int>();
    vector<int> res(input.begin(),input.begin()+k);
    //建立K个元素的最大堆，然后每个元素和其比较，重建堆，时间复杂度为O(nlog(K))
    make_heap(res.begin(), res.end());
    for(int i=k;i<len;i++){
      if(input[i]<res[0]){ //如果新元素比堆顶元素小
        //pop_heap 删除堆顶，即把对顶放到最后，并重建堆
        pop_heap(res.begin(), res.end());
        //pop_back 删除最后一个元素，即之前的堆顶元素
        res.pop_back();
        res.push_back(input[i]);
        push_heap(res.begin(),res.end());
      }
    }
    return res;
  }
};
// 如果不可以改变数组
int main(int argc, char const *argv[]) {
  int numbers[]={5,2,1,4,3,6,3,2,11,3,52,9};
  int len;
  int K=5;
  GET_ARRAY_LEN(numbers, len);
  /********利用STL容器构建最大堆的方法******************/
  // GetLeastNumbersbyHeap Solution;
  // vector<int> input;
  // vector<int> res;
  // for(int i=0;i<len;i++){
  //   input.push_back(numbers[i]);
  // }
  // Solution.printVector(input);
  // res = Solution.getLeastNumbersByHeap(input, K);
  // cout<<endl;
  // Solution.printVector(res);

  /********利用快排思想，寻找第K大的数，然后输出K前面的数******************/
  // int* result=numbers;
  // GET_ARRAY_LEN(numbers, len);
  // getLeastNumbers(numbers, result, len, K);
  // printArray(result, K);
  // cout<<endl;
  // printArray(numbers, len);
  return 0;
}

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
#define GET_ARRAY_LEN(array,len){len=sizeof(array)/sizeof(array[0]);}
/*�ҳ���������С��K����*/
// �ڿ��Ըı�ԭ������˳���ǰ���£�����ͨ��Ѱ�ҵ�K�������Ȼ�󽫸���ǰ��������ء�
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
    //����K��Ԫ�ص����ѣ�Ȼ��ÿ��Ԫ�غ���Ƚϣ��ؽ��ѣ�ʱ�临�Ӷ�ΪO(nlog(K))
    make_heap(res.begin(), res.end());
    for(int i=k;i<len;i++){
      if(input[i]<res[0]){ //�����Ԫ�رȶѶ�Ԫ��С
        //pop_heap ɾ���Ѷ������ѶԶ��ŵ���󣬲��ؽ���
        pop_heap(res.begin(), res.end());
        //pop_back ɾ�����һ��Ԫ�أ���֮ǰ�ĶѶ�Ԫ��
        res.pop_back();
        res.push_back(input[i]);
        push_heap(res.begin(),res.end());
      }
    }
    return res;
  }
};
// ��������Ըı�����
int main(int argc, char const *argv[]) {
  int numbers[]={5,2,1,4,3,6,3,2,11,3,52,9};
  int len;
  int K=5;
  GET_ARRAY_LEN(numbers, len);
  /********����STL�����������ѵķ���******************/
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

  /********���ÿ���˼�룬Ѱ�ҵ�K�������Ȼ�����Kǰ�����******************/
  // int* result=numbers;
  // GET_ARRAY_LEN(numbers, len);
  // getLeastNumbers(numbers, result, len, K);
  // printArray(result, K);
  // cout<<endl;
  // printArray(numbers, len);
  return 0;
}

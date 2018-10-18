// #include<iostream>
// #include<set>
// #include<vector>
// #include<algorithm>
// using namespace std;
// //step1.寻找数列中的正序对
// int getOrderPairs(vector<int> arr, int n, int Cur_value, int pos){
//   int NumOrder=0;
//   for(int i=pos;i<n;++i){
//     if(!arr[i])  continue;
//     if(arr[i]>Cur_value)
//       NumOrder++;
//   }
//   return NumOrder;
// }
// int getOrderPairsAll(vector<int> arr, int n){
//   int NumOrder=0;
//   for(int i=0;i<n;i++){
//     if(!arr[i])  continue;
//     NumOrder+=getOrderPairs(arr, n, arr[i], i);
//   }
//   return NumOrder;
// }
// void PrintVector(std::vector<int> v){
//   cout<<"\nVector:";
//   for(std::vector<int>::iterator vi=v.begin();vi<v.end();vi++){
//     cout<<*vi;
//   }
// }
// int main(int argc, char const *argv[]) {
//   int n,k,ans=0;
//   cin>>n;
//   cin>>k;
//   vector<int> V;
//   vector<int> Vmissing;
//   vector<int> Pos;
//   for(int i=0;i<n;i++){ // 输入数据
//     int vi;
//     cin>>vi;
//     V.push_back(vi);
//     if(!vi) Pos.push_back(i);
//   }
//   vector<int> Vcopy=V;
//   PrintVector(V);
//   for(int i=1;i<n+1;i++){ //寻找缺失值
//     if(find(V.begin(), V.end(), i)==V.end())
//       Vmissing.push_back(i);
//   }
//   PrintVector(Vmissing);
//   int numbase = getOrderPairsAll(V, n);
//   cout<<"\n"<<"numbase"<<numbase;
//   int numMissing=0;
//   do{
//     for(int i=0;i<Pos.size();i++){
//       Vcopy[Pos[i]]=Vmissing[i];
//     }
//     numMissing = getOrderPairsAll(Vcopy, n);
//     PrintVector(Vcopy);
//     if(numMissing==k) ans++;
//   }while(next_permutation(Vmissing.begin(), Vmissing.end()));
//   cout<<ans;
//   return 0;
// }
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
//step1.寻找数列中的正序对
int getOrderPairs(vector<int> arr, int n, int Cur_value, int pos){
  int NumOrder=0;
  for(int i=pos;i<n;++i){
    if(!arr[i])  continue;
    if(arr[i]>Cur_value)
      NumOrder++;
  }
  return NumOrder;
}
int getOrderPairsAll(vector<int> arr, int n){
  int NumOrder=0;
  for(int i=0;i<n;i++){
    if(!arr[i])  continue;
    NumOrder+=getOrderPairs(arr, n, arr[i], i);
  }
  return NumOrder;
}
int getOrderPairsMissing(vector<int> V,vector<int> Vmissing, vector<int> Pos){
  int NumOrder=0;
  int Vsize=V.size();
  int Vmissingsize = Vmissing.size();
  for(int i=0;i<Vmissingsize;i++){
    NumOrder+=getOrderPairs(V, Vsize, Vmissing[i], Pos[i]);
  }
  return NumOrder;
}
int main(int argc, char const *argv[]) {
  int n,k,ans=0;
  cin>>n;
  cin>>k;
  vector<int> V;
  vector<int> Vmissing;
  vector<int> Pos;
  for(int i=0;i<n;i++){ // 输入数据
    int vi;
    cin>>vi;
    V.push_back(vi);
    if(!vi) Pos.push_back(i);
  }
  vector<int> Vcopy=V;
  for(int i=1;i<n+1;i++){ //寻找缺失值
    if(find(V.begin(), V.end(), i)==V.end())
      Vmissing.push_back(i);
  }
  int numbase = getOrderPairsAll(V, n);
  int numMissing=0;
  int nMissingSize = Vmissing.size();
  // cout<<"numbase"<<numbase<<'\n';
  do{
    int numMissbase = getOrderPairsAll(Vmissing, nMissingSize);
    for(int i=0;i<nMissingSize;i++){
         Vcopy[Pos[i]]=Vmissing[i];
       }
    numMissing = getOrderPairsMissing(Vcopy,Vmissing,Pos);
    // cout<<"numMissing:"<<numMissing<<" numMissbase:"<<numMissbase<<'\n';
    if(nMissingSize==n){
      if(numMissing+numbase==k) ans++;
    }else{
      if(numMissing+numbase+numMissbase==k) ans++;
    }
  }while(next_permutation(Vmissing.begin(), Vmissing.end()));
  cout<<ans;
  return 0;
}

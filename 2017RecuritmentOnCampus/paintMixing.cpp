#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
const int N=30;
void getBinaryMat(const set<int> &s, vector<vector<int>> &bMat){
  if(s.empty()) return;
  for(set<int>::iterator it=s.begin();it!=s.end();it++){
    vector<int> v(N);
    int flag=1;
    for(int i=0;i<N;i++){
      v[i] = (*it)&flag;
      flag<<=1;
    }
    bMat.push_back(v);
  }
}
int getNumOfLeastColors(set<int>& colorSet){
  if(colorSet.empty()) return -1;
  vector<vector<int>> bMat;
  getBinaryMat(colorSet, bMat);
  const int Row=bMat.size();
  int r=0,c=0;
  for(;c<N&&r<Row;c++,r++){
    int i=0;
    for(i=r; i<Row; i++){
      if(bMat[i][c]!=0)
        break;
    }
    if(Row==i) //此时说明，该列没有1，下一次循环r不用加1，所以在这里先减一
      --r;
    else{
      swap(bMat[r],bMat[i]);
      for(int k=i+1;k<Row;k++){
        if(bMat[k][c]!=0){
          for(int j=c;j<N;j++)
            bMat[k][j]=bMat[k][j]^bMat[r][j];
        }
      }
    }
  }
  return r;
}
int main(int argc, char const *argv[]) {
  int n=0;
  cin>>n;
  set<int> x;
  int color;
  for(int i=0;i<n;i++){
    cin>>color;
    x.insert(color);
  }
int res=getNumOfLeastColors(x);
cout<<res;
return 0;
}

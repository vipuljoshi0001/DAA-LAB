#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
 int t; cin>>t;
 while(t--){
  int n; cin>>n;
  vector<int> arr(n);

  for(int i=0;i<n;i++) cin>>arr[i];

  int k; cin>>k;

  unordered_map<int,int> freq;

  for(int x:arr) freq[x]++;

  long long count=0;

  for(auto &p:freq){
   int num=p.first;
   int f=p.second;

   if(k==0){
    count+=(long long)f*(f-1)/2;
   }
   else if(freq.find(num+k)!=freq.end()){
    count+=(long long)f*freq[num+k];
   }
  }

  if(k!=0) count/=2;

  cout<<count<<endl;
 }
 return 0;
}

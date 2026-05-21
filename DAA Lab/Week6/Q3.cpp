#include<iostream>
#include<vector>
#include<functional>
using namespace std;

bool hasCycle(vector<vector<int>>& adj,int v){
 vector<int> color(v,0);

 function<bool(int)> dfs=[&](int u){
  color[u]=1;

  for(int j=0;j<v;j++){
   if(adj[u][j]==1){
    if(color[j]==1) return true;

    if(color[j]==0){
     if(dfs(j)) return true;
    }
   }
  }

  color[u]=2;

  return false;
 };

 for(int i=0;i<v;i++){
  if(color[i]==0){
   if(dfs(i)) return true;
  }
 }

 return false;
}

int main(){
 int v; cin>>v;

 vector<vector<int>> adj(v,vector<int>(v));

 for(int i=0;i<v;i++){
  for(int j=0;j<v;j++){
   cin>>adj[i][j];
  }
 }

 if(hasCycle(adj,v)){
  cout<<"Yes Cycle Exists"<<endl;
 }
 else{
  cout<<"No Cycle Exists"<<endl;
 }

 return 0;
}

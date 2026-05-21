#include<iostream>
#include<vector>
using namespace std;

bool dfs(int src,int dest,vector<vector<int>>& adj,vector<bool>& visited){
 visited[src]=true;

 if(src==dest) return true;

 for(int i=0;i<adj[src].size();i++){
  if(adj[src][i]==1 && !visited[i]){
   if(dfs(i,dest,adj,visited)) return true;
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

 int src,dest;
 cin>>src>>dest;

 vector<bool> visited(v,false);

 if(dfs(src,dest,adj,visited)){
  cout<<"Yes Path Exists"<<endl;
 }
 else{
  cout<<"No Such Path Exists"<<endl;
 }

 return 0;
}

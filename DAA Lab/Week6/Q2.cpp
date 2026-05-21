#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isBipartite(vector<vector<int>>& adj,int v){
 vector<int> color(v,-1);

 for(int i=0;i<v;i++){
  if(color[i]==-1){
   queue<int> q;
   q.push(i);
   color[i]=0;

   while(!q.empty()){
    int u=q.front();
    q.pop();

    for(int j=0;j<v;j++){
     if(adj[u][j]==1){
      if(color[j]==-1){
       color[j]=1-color[u];
       q.push(j);
      }
      else if(color[j]==color[u]){
       return false;
      }
     }
    }
   }
  }
 }

 return true;
}

int main(){
 int v; cin>>v;

 vector<vector<int>> adj(v,vector<int>(v));

 for(int i=0;i<v;i++){
  for(int j=0;j<v;j++){
   cin>>adj[i][j];
  }
 }

 if(isBipartite(adj,v)){
  cout<<"Yes Bipartite"<<endl;
 }
 else{
  cout<<"Not Bipartite"<<endl;
 }

 return 0;
}

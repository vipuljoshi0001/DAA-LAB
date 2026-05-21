#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge{
 int src,dest,weight;

 bool operator<(const Edge& other) const{
  return weight<other.weight;
 }
};

class DSU{
public:
 vector<int> parent,rankv;

 DSU(int n){
  parent.resize(n);
  rankv.resize(n,0);

  for(int i=0;i<n;i++) parent[i]=i;
 }

 int find(int x){
  if(parent[x]!=x){
   parent[x]=find(parent[x]);
  }

  return parent[x];
 }

 bool unite(int x,int y){
  int px=find(x);
  int py=find(y);

  if(px==py) return false;

  if(rankv[px]<rankv[py]){
   parent[px]=py;
  }
  else if(rankv[px]>rankv[py]){
   parent[py]=px;
  }
  else{
   parent[py]=px;
   rankv[px]++;
  }

  return true;
 }
};

int main(){
 int v; cin>>v;

 vector<Edge> edges;

 for(int i=0;i<v;i++){
  for(int j=0;j<v;j++){
   int weight;
   cin>>weight;

   if(weight!=0 && i<j){
    edges.push_back({i,j,weight});
   }
  }
 }

 sort(edges.begin(),edges.end());

 DSU dsu(v);

 long long totalCost=0;
 int edgesAdded=0;

 for(const Edge& e:edges){
  if(dsu.unite(e.src,e.dest)){
   totalCost+=e.weight;
   edgesAdded++;

   if(edgesAdded==v-1) break;
  }
 }

 cout<<totalCost<<endl;

 return 0;
}

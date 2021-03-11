#include<bits/stdc++.h>
using namespace std;
int n,q;
long long m;
vector<int>adj[100001];
int u[100001],v[100001],w[100001];
bool tree;
int cc;
int par[100001];
int find(int x){
  if(par[x]!=x) par[x]=find(par[x]);
  return par[x];
}
void join(int x,int y){
  x=find(x);y=find(y);
  cc-=(x!=y);
  par[x]=y;
}
int main(){
  ios::sync_with_stdio(false);
  cin >> n >> m >> q;
  tree=m==n-1;cc=n;
  for(int i=1; i<=n ;i++){
    par[i]=i;
  }
  for(int i=1; i<=q ;i++){
    cin >> u[i] >> v[i] >> w[i];
    if(w[i]==0) join(u[i],v[i]);
    tree&=(w[i]!=1);
  }
  for(int i=1; i<=q ;i++){
    if(!w[i]) continue;
    if(find(u[i])==find(v[i])) return cout << "No\n",0;
  }
  if(tree) return cout << "Yes\n",0;
  if(cc<=2) return cout << "No\n",0;
  if(m>=n && m<=n+1LL*cc*(cc-3)/2) cout << "Yes\n";
  else cout << "No\n";
}

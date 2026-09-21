#include<bits/stdc++.h>

using namespace std;

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

using Graph=vector<vector<int>>;

// based on:
// https://kopricky.github.io/code/GraphDecomposition/centroid_decomposition.html
struct CentDec{
  int V;
  vector<bool> used;
  vector<int> sz, par;
  CentDec(const Graph &G){ init(G); }

  void calcSize(int u,int p,const Graph &G){
    sz[u] = 1;
    for(int v : G[u]){
      if(!used[v] && v != p){
        calcSize(v,u,G);
        sz[u] += sz[v];
      }
    }
  }

  void cdBuild(int u,int p,const Graph &G){
    calcSize(u,-1,G);
    int tot = sz[u];
    bool ok = false;
    int pp = -1;
    while(!ok){
      ok = true;
      for(int v : G[u]){
        if(!used[v] && v != pp && 2*sz[v] > tot){
          pp = u, u = v, ok = false;
          break;
        }
      }
    }
    par[u] = p;
    used[u] = true;
    for(int v : G[u]){
      if(!used[v]){
        cdBuild(v,u,G);
      }
    }
  }

  void init(const Graph &G){
    V=G.size();
    used.resize(V);
    sz.resize(V);
    par.resize(V);
    for(int i=0;i<V;i++){
      used[i]=false;
      sz[i]=0;
      par[i]=-1;
    }
    cdBuild(0,-1,G);
  }
};

// based on:
// https://algo-logic.info/lca/
struct LCA {
  vector<vector<int>> parent;
  vector<int> dist;
  LCA(const Graph &G, int root = 0) { init(G, root); }

  void init(const Graph &G, int root = 0) {
    int V = G.size();
    int K = 1;
    while ((1 << K) < V) K++;
    parent.assign(K, vector<int>(V, -1));
    dist.assign(V, -1);
    dfs(G, root, -1, 0);
    for (int k = 0; k + 1 < K; k++) {
      for (int v = 0; v < V; v++) {
        if (parent[k][v] < 0) {
          parent[k + 1][v] = -1;
        } else {
          parent[k + 1][v] = parent[k][parent[k][v]];
        }
      }
    }
  }

  void dfs(const Graph &G, int v, int p, int d) {
    parent[0][v] = p;
    dist[v] = d;
    for (auto e : G[v]) {
      if (e != p) dfs(G, e, v, d + 1);
    }
  }

  int query(int u, int v) {
    if (dist[u] < dist[v]) swap(u, v);
    int K = parent.size();
    for (int k = 0; k < K; k++) {
      if ((dist[u] - dist[v]) >> k & 1) {
        u = parent[k][u];
      }
    }
    if (u == v) return u;
    for (int k = K - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};

using ll=long long;
using weiGraph=vector<vector<pair<int,ll>>>;

vector<ll> d;
vector<int> exi;
vector<multiset<ll>> ms;

ll dist(int u,int v,LCA &lca){
  int l=lca.query(u,v);
  return d[u]+d[v]-2*d[l];
}

void toggle(int v,LCA &lca,CentDec &cd){
  int beg=v;
  exi[beg]^=1;
  while(v>=0){
    if(exi[beg]==1){
      // add
      ms[v].insert(dist(beg,v,lca));
    }
    else{
      // erase
      ms[v].erase(ms[v].find(dist(beg,v,lca)));
    }
    v=cd.par[v];
  }
}

ll ask(int v,LCA &lca,CentDec &cd){
  int beg=v;
  ll res=8e18;
  while(v>=0){
    if(!ms[v].empty()){
      res=min(res,dist(beg,v,lca)+(*ms[v].begin()));
    }
    v=cd.par[v];
  }
  return res;
}

int main(){

  double t0 = get_time_sec();
  
  int N,Q;
  cin >> N >> Q;
  ms.resize(N);
  Graph g(N);
  weiGraph wg(N);
  for(int i=1;i<N;i++){
    int A,B,C;
    cin >> A >> B >> C;
    A--; B--;
    g[A].push_back(B);
    g[B].push_back(A);
    wg[A].push_back({B,C});
    wg[B].push_back({A,C});
  }

  double t1 = get_time_sec();

  exi.resize(N);
  for(auto &nx : exi){nx=0;}

  {
    d.resize(N);
    for(auto &nx : d){nx=-1;}
    d[0]=0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
      int od=q.front(); q.pop();
      for(auto [v,w] : wg[od]){
        if(d[v]==-1){
          d[v]=d[od]+w;
          q.push(v);
        }
      }
    }
  }

  double t2 = get_time_sec();

  LCA lca(g,0);
  CentDec cd(g);

  double t3 = get_time_sec();

  toggle(0,lca,cd);
  while(Q--){
    int typ;
    cin >> typ;
    if(typ==1){
      int X;
      cin >> X;
      X--;
      toggle(X,lca,cd);
    }
    else{
      int V;
      ll T;
      cin >> V >> T;
      V--;
      if(ask(V,lca,cd)<=T){cout << "YES\n";}
      else{cout << "NO\n";}
    }
  }

  double t4 = get_time_sec();

  cerr << t1 - t0 << endl;
  cerr << t2 - t1 << endl;
  cerr << t3 - t2 << endl;
  cerr << t4 - t3 << endl;

  return 0;
}

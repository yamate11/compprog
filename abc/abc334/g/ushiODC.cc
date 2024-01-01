#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wreturn-type"
struct UnionFindUndo {
  vector< int > data;
  stack< pair< int, int > > history;

  UnionFindUndo(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    history.emplace(x, data[x]);
    history.emplace(y, data[y]);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return (find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }

  void undo() {
    data[history.top().first] = history.top().second;
    history.pop();
    data[history.top().first] = history.top().second;
    history.pop();
  }

  void snapshot() {
    while(history.size()) history.pop();
  }

  void rollback() {
    while(history.size()) undo();
  }
};


struct OfflineDynamicConnectivity {
  using edge = pair< int, int >;

  UnionFindUndo uf;
  int V, Q, segsz;
  vector< vector< edge > > seg;
  int comp;

  vector< pair< pair< int, int >, edge > > pend;
  map< edge, int > cnt, appear;

  OfflineDynamicConnectivity(int V, int Q) : uf(V), V(V), Q(Q), comp(V) {
    segsz = 1;
    while(segsz < Q) segsz <<= 1;
    seg.resize(2 * segsz - 1);
  }

  void insert(int idx, int s, int t) {
    auto e = minmax(s, t);
    if(cnt[e]++ == 0) appear[e] = idx;
  }

  void erase(int idx, int s, int t) {
    auto e = minmax(s, t);
    if(--cnt[e] == 0) pend.emplace_back(make_pair(appear[e], idx), e);
  }

  void add(int a, int b, const edge &e, int k, int l, int r) {
    if(r <= a || b <= l) return;
    if(a <= l && r <= b) {
      seg[k].emplace_back(e);
      return;
    }
    add(a, b, e, 2 * k + 1, l, (l + r) >> 1);
    add(a, b, e, 2 * k + 2, (l + r) >> 1, r);
  }

  void add(int a, int b, const edge &e) {
    add(a, b, e, 0, 0, segsz);
  }

  void build() {
    for(auto &p : cnt) {
      if(p.second > 0) pend.emplace_back(make_pair(appear[p.first], Q), p.first);
    }
    for(auto &s : pend) {
      add(s.first.first, s.first.second, s.second);
    }
  }

  void run(const function< void(int) > &f, int k = 0) {
    int add = 0;
    for(auto &e : seg[k]) {
      add += uf.unite(e.first, e.second);
    }
    comp -= add;
    if(k < segsz - 1) {
      run(f, 2 * k + 1);
      run(f, 2 * k + 2);
    } else if(k - (segsz - 1) < Q) {
      int query_index = k - (segsz - 1);
      f(query_index);
    }
    for(auto &e : seg[k]) {
      uf.undo();
    }
    comp += add;
  }
};
#pragma GCC diagnostic pop


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  vector mark(Q, pll(-1, -1));
  OfflineDynamicConnectivity odc(N, Q);
  REP(t, 0, Q) {
    ll tp, x, y; cin >> tp >> x >> y;
    if (tp == 1) {
      odc.insert(t, x, y);
    }else if (tp == 2) {
      odc.erase(t, x, y);
    }else if (tp == 3) {
      mark[t] = pll(x, y);
    }else assert(0);
  }
  odc.build();
  auto f = [&](int t) -> void {
    auto [x, y] = mark[t];
    if (x < 0) return;
    if (odc.uf.find(x) == odc.uf.find(y)) cout << 1 << "\n";
    else cout << 0 << "\n";
  };
  odc.run(f);
  

  return 0;
}


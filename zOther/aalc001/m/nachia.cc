#include <bits/stdc++.h>
#include <atcoder/segtree>
#include <atcoder/lazysegtree>
using namespace std;
using ll = long long;
const ll INF = 1ll << 60;
#define rep(i,n) for(ll i=0; i<ll(n); i++)
template <class A, class B> void chmax(A& l, const B& r){ if(l < r) l = r; }
template <class A, class B> void chmin(A& l, const B& r){ if(r < l) l = r; }

const ll mask = (1ll << 30) - 1;
ll nand(ll a, ll b){ return mask - (a & b); }

using S = array<ll, 2>;
S getS(ll v){
  S res;
  res[0] = nand(0, v);
  res[1] = nand(mask, v);
  return res;
}
S op(S l, S r){
  S res;
  rep(i,2) res[i] = ((mask - l[i]) & r[0]) | (l[i] & r[1]);
  return res;
}
S getE(){
  return { 0, mask };
}

void testcase(){
  ll N, Q; cin >> N >> Q;
  vector<ll> A(N); rep(i,N) cin >> A[i];
  vector<S> init(N);
  rep(i,N) init[i] = getS(A[i]);
  
  auto ds = atcoder::segtree<S, op, getE>(init);
  
  rep(qi,Q){
    ll ty; cin >> ty;
    if(ty == 1){
      ll p,x; cin >> p >> x; p--;
      A[p] = x;
      ds.set(p, getS(x));
    }
    if(ty == 2){
      ll l,r; cin >> l >> r; l--;
      auto f = ds.prod(l+1, r);
      ll start = A[l];
      ll ans = ((mask - start) & f[0]) | (start & f[1]);
      cout << ans << "\n";
    }
  }
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  testcase();
  return 0;
}

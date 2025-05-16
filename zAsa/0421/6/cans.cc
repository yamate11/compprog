#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll Q; cin >> Q;
  vector<pll> vec(Q, pll(0, -1LL));
  map<ll, ll> note;
  ll cur = -1;
  ll memp = 0;
  vector<ll> ans;
  REP(_q, 0, Q) {
    string op; cin >> op;
    if (op == "ADD") {
      ll x; cin >> x;
      vec[memp] = pll(x, cur);
      cur = memp;
      memp++;
    }else if (op == "DELETE") {
      if (cur >= 0) {
        cur = vec[cur].second;
      }
    }else if (op == "SAVE") {
      ll y; cin >> y;
      note[y] = cur;
    }else if (op == "LOAD") {
      ll z; cin >> z;
      auto it = note.find(z);
      if (it == note.end()) {
        cur = -1;
      }else {
        cur = it->second;
      }
    }else assert(0);
    
    if (cur == -1) ans.push_back(-1);
    else ans.push_back(vec[cur].first);
  }
  REPOUT(i, 0, ssize(ans), ans[i], " ");

  return 0;
}


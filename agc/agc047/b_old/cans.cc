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

template <typename T>
struct Trie {

  struct TrNode {
    vector<int> _next;
    int _parent;
    bool _exists;
    T _user;
    TrNode(int sz = 0, int _parent_ = -1) : _next(sz, -1), _parent(_parent_), _exists(false), _user() {}
  };

  char from;
  int br_size;
  vector<TrNode> nodes;

  Trie(char from_, char to_)
    : from(from_), br_size(to_ - from_ + 1), nodes(1, TrNode(br_size)) {}

  int _index(const string& s, bool create) {
    int idx = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      int c = s[i] - from;
      if (nodes[idx]._next[c] < 0) {
        if (not create) return -1;
        nodes[idx]._next[c] = nodes.size();
        nodes.emplace_back(br_size, idx);
        idx = nodes.size() - 1;
      }else {
	idx = nodes[idx]._next[c];
      }
    }
    return idx;
  }

  int insert(const string& s) {
    int idx = _index(s, true);
    nodes[idx]._exists = true;
    return idx;
  }

  bool erase(int idx) {
    bool ret = nodes[idx]._exists;
    nodes[idx]._exists = false;
    return ret;
  }

  bool erase(const string& s) {
    int idx = _index(s, false);
    if (idx < 0) return false;
    return erase(idx);
  }

  int index(const string& s) {
    int idx = _index(s, false);
    if (idx < 0 or not nodes[idx]._exists) return -1;
    return idx;
  }

  int parent(int idx) { return nodes[idx]._parent; }

  int child(int idx, char c) { return nodes[idx]._next[c - from]; }

  bool exists(int idx) { return nodes[idx]._exists; }

  T& user(int idx) { return nodes[idx]._user; }

};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, S, type=string) [QLqQueaJ]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [QLqQueaJ]

  Trie<vector<ll>> trie('a', 'z');
  REP(i, 0, N) {
    ll idx = trie.insert(S[i]);
    vector<ll> vec(26);
    REPrev(j, SIZE(S[i]) - 1, 0) {
      vec[S[i][j] - 'a'] = 1;
      idx = trie.parent(idx);
      auto& v = trie.user(idx);
      if (SIZE(v) == 0) v = vector<ll>(26);
      REP(k, 0, 26) v[k] += vec[k];
    }
  }
  ll ans = 0;
  REP(i, 0, N) {
    string t = S[i].substr(0, SIZE(S[i]) - 1);
    ll idx = trie._index(t, false);
    const auto& v = trie.user(idx);
    REP(j, 0, 26) ans += v[j];
    ans--;
  }
  cout << ans << endl;
  
  return 0;
}


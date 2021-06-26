#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(perm)

// ---- inserted library file perm.cc

template<typename T>
class IterPerm {
  int cand_size;
  int seq_size;
  T perm;
  vector<T> cands;
  vector<int> idx;
  
  void construct(const T& orig, int ss) {
    cand_size = orig.size();
    seq_size = ss;
    perm = T(orig.begin(), orig.begin() + seq_size);
    cands = vector<T>(seq_size);
    if (seq_size > 0) cands.at(0) = orig;
    idx = vector<int>(seq_size);
    init();
  }

  void init() {
    for (int i = 0; i < seq_size; i++) {
      perm.at(i) = cands.at(0).at(i);
      if (i > 0) {
	cands.at(i) = T(cands.at(0).begin() + i, cands.at(0).end());
      }
      idx.at(i) = 0;
    }
  }

  // IntPerm is implemented using IterPerm<vector<int>>, and
  // it needs a constructor without parameter.
  friend class IntPerm;
  IterPerm() {}

public:
  
  IterPerm(const T& orig, int ss) { construct(orig, ss); }
  IterPerm(const T& orig) { construct(orig, orig.size()); }
  
  const T& get() { return perm; }

  bool next() {
    int i = seq_size - 1;
    while (i >= 0 && ++idx.at(i) >= cand_size - i) i--;
    if (i < 0) {
      init();
      return false;
    }
    perm.at(i) = cands.at(i).at(idx.at(i));
    for (int k = i + 1; k < seq_size; k++) {
      for (int m = 0; m < cand_size - k; m++) {
	int shift = m < idx.at(k - 1) ? 0 : 1;
	cands.at(k).at(m) = cands.at(k - 1).at(m + shift);
      }
      idx.at(k) = 0;
      perm.at(k) = cands.at(k).at(0);
    }
    return true;
  }
};

class IntPerm {

  IterPerm<vector<int>> itp;

  void construct(int ns, int ss) {
    vector<int> vec(ns);
    iota(vec.begin(), vec.end(), 0);
    itp = IterPerm(vec, ss);
  }

public:

  IntPerm(int ns, int ss) { construct(ns, ss); }
  IntPerm(int ns) { construct(ns, ns); }
  const vector<int>& get() { return itp.get(); }
  bool next() { return itp.next(); }

};

template<typename T>
class IterComb {

  vector<T> orig;
  int c_size;
  vector<T> comb;
  vector<int> idx;

  void init() {
    for (int i = 0; i < c_size; i++) {
      idx.at(i) = i;
      comb.at(i) = orig.at(i);
    }
  }


public:

  IterComb() {}

  IterComb(vector<T> orig_, int c_size_)
    : orig(orig_), c_size(c_size_), comb(c_size), idx(c_size) { init(); }

  const vector<T>& get() { return comb; }

  bool next() {
    int n = orig.size();
    int i = c_size - 1;
    while (i >= 0 && ++idx.at(i) > n - (c_size - i)) i--;
    if (i < 0) {
      init();
      return false;
    }

    int k = idx.at(i);
    for ( ; i < c_size; i++, k++) {
      idx.at(i) = k;
      comb.at(i) = orig.at(k);
    }
    return true;

  }

};

class IntComb {
  
  IterComb<int> itc;

public:

  IntComb(int n, int r) {
    vector<int> seq(n);
    iota(seq.begin(), seq.end(), 0);
    itc = IterComb<int>(seq, r);
  }
  const vector<int>& get() { return itc.get(); }
  bool next() { return itc.next(); }
};

class DupIntPerm {
  int n;
  int r;
  vector<int> vec;

public:
  DupIntPerm(int n_, int r_) : n(n_), r(r_), vec(r) {}

  const vector<int>& get() { return vec; }

  bool next() {
    for (int i = r - 1; i >= 0; i--) {
      if (++vec[i] < n) return true;
      vec[i] = 0;
    }
    return false;
  }
};

// ---- end perm.cc

// @@ !! LIM -- end mark --

struct myexc : exception {};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, K; cin >> N >> M >> K;
  vector<vector<ll>> fwd(N + 1), bwd(N + 1);
  map<ll, set<ll>> ord;
  for (ll i = 0; i < M; i++) {
    ll a, b; cin >> a >> b;
    fwd[a].push_back(b);
    bwd[b].push_back(a);
    ord[a].insert(b);
  }
  auto chk_ord = [&](ll a, ll b) -> bool {
    auto it = ord.find(a);
    if (it == ord.end()) return false;
    if (it->second.find(b) == it->second.end()) return false;
    return true;
  };
  auto brute = [&](const auto& vec) -> vector<vector<ll>> {
    vector<vector<ll>> ret;
    ll sz = vec.size();
    IntPerm ip(sz);
    const vector<int>& v = ip.get();
    do {
      auto ok = [&]() -> bool {
        for (ll i = 0; i+1 < sz; i++) {
          for (ll j = i + 1; j < sz; j++) {
            ll x = vec[v[i]];
            ll y = vec[v[i + 1]];
            if (chk_ord(y, x)) return false;
          }
        }
        return true;
      };
      if (ok()) {
        vector<ll> cs(sz);
        for (ll i = 0; i < sz; i++) cs[i] = vec[v[i]];
        ret.push_back(move(cs));
      }
    }while (ip.next());
    return ret;
  };

  vector<ll> vec_rank(N + 1, -1);
  vector<vector<ll>> rev_rank(N + 10, vector<ll>());
  vector<bool> on_stack(N + 1);
  auto dfs2 = [&](auto rF, ll nd) -> ll {
    if (on_stack[nd]) throw myexc();
    if (vec_rank[nd] >= 0) return vec_rank[nd];
    on_stack[nd] = true;
    ll r = 0;
    for (auto cld: bwd[nd]) {
      ll cr = rF(rF, cld);
      r = max(r, cr + 1);
    }
    vec_rank[nd] = r;
    rev_rank[r].push_back(nd);
    on_stack[nd] = false;
    return r;
  };
  try {
    for (ll p = 1; p <= N; p++) {
      dfs2(dfs2, p);
    }
  }catch (const myexc& e) {
    cout << -1 << endl;
    return 0;
  }

  vector<vector<ll>> result(1);
  auto dup_result = [&](const auto& vvec) {
    ll orig_size = result.size();
    ll vv_size = vvec.size();
    auto phase1 = [&]() -> void {
      for (ll i = 1; i < vv_size; i++) {
        for (ll j = 0; j < orig_size; j++) {
          if (i * orig_size + j == K) return;
          result.push_back(result[j]);
        }
      }
    };
    auto phase2 = [&]() -> void {
      for (ll i = 0; i < vv_size; i++) {
        for (ll j = 0; j < orig_size; j++) {
          if (i * orig_size + j == K) return;
          for (ll x : vvec[i]) result[i * orig_size + j].push_back(x);
        }
      }
    };
    phase1();
    phase2();
  };

  auto from_rr = [&](ll st, ll p) -> vector<ll> {
    vector<ll> res;
    for (ll i = 0; i < p; i++) {
      for (ll x : rev_rank[st + i]) res.push_back(x);
    }
    return res;
  };

  auto genperm = [&](const auto& vec, ll n) -> vector<vector<ll>> {
    ll sz = vec.size();
    IntPerm ip(n);
    vector<vector<ll>> ret;
    const vector<int>& v = ip.get();
    do {
      vector<ll> w(sz);
      for (ll i = 0; i < sz; i++) {
        if (i < n) w[i] = vec[v[i]];
        else       w[i] = vec[i];
      }
      ret.push_back(move(w));
    }while (ip.next());
    return ret;
  };

  for (ll i = 0; true; i++) {
    ll rsz = result.size();
    ll n = rev_rank[i].size();
    if (n == 0) break;
    if (rsz == K || n == 1) {
      for (ll x : rev_rank[i]) {
        for (ll k = 0; k < rsz; k++) result[k].push_back(x);
      }
    }else if (n >= 3) {
      auto vvec = genperm(rev_rank[i], min(4LL, n));
      dup_result(vvec);
    }else { // n == 2
      if (rev_rank[i+1].size() != 2) {
        auto vvec = genperm(rev_rank[i], 2);
        dup_result(vvec);
      }else if (rev_rank[i+2].size() != 2) {
        vector<ll> w = from_rr(i, 2);
        auto vvec = brute(w);
        dup_result(vvec);
        i++;
      }else if (rev_rank[i+3].size() != 2) {
        vector<ll> w = from_rr(i, 3);
        auto vvec = brute(w);
        dup_result(vvec);
        i += 2;
      }else {
        auto vvec = genperm(rev_rank[i], 2);
        dup_result(vvec);
      }
    }
  }

  if ((ll)result.size() < K) {
    cout << -1 << endl;
  }else {
    for (const auto& v : result) {
      for (ll x : v) cout << x << " ";
      cout << "\n";
    }
  }
  
  

  return 0;
}


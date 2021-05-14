#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(f:>> perm)

// ---- inserted function f:>> from util.cc
template <typename T1, typename T2>
istream& operator>> (istream& is, pair<T1,T2>& p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T1, typename T2, typename T3>
istream& operator>> (istream& is, tuple<T1,T2,T3>& t) {
  is >> get<0>(t) >> get<1>(t) >> get<2>(t);
  return is;
}

template <typename T1, typename T2, typename T3, typename T4>
istream& operator>> (istream& is, tuple<T1,T2,T3,T4>& t) {
  is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t);
  return is;
}

template <typename T>
istream& operator>> (istream& is, vector<T>& v) {
  for (size_t i = 0; i < v.size(); i++) { is >> v[i]; }
  return is;
}

template <typename T>
vector<T> read_vector_n(istream& is, size_t n) {
  vector<T> ret(n);
  for (size_t i = 0; i < n; i++) {
    is >> ret[i];
  }
  return ret;
}

template <typename T>
vector<T> read_vector(istream& is) {
  size_t n; is >> n;
  return read_vector_n<T>(is, n);
}
// ---- end f:>>

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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N); cin >> A;
  auto rec = vector(200, vector<int>());
  
  auto show = [&](const vector<int>& xs) -> void {
    cout << xs.size();
    for (ll x : xs) cout << " " << x + 1;
    cout << endl;
  };

  for (ll i = 1; i <= N; i++) {

    IntComb ic(N, i);
    const vector<int>& v = ic.get();
    do {
      ll t = 0;
      for (ll j: v) {
        t += A[j];
      }
      ll m = t % 200;
      if (rec[m].size() == 0) {
        rec[m] = v;
      }else {
        cout << "Yes\n";
        show(v);
        show(rec[m]);
        return 0;
      }
    }while (ic.next());
  }
  cout << "No\n";

  return 0;
}


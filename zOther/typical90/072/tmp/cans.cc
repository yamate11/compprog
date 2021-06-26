#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(perm f:perfmeas)

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

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --

struct MyIntPerm {
  // Enumerate permutations of length seq_size from [0, cand_size).
  int cand_size;
  int seq_size;     

  struct Itr {
    bool fin;
    const MyIntPerm& mip;
    vector<int> perm;
    vector<int> head;
    vector<int> prv;
    vector<int> nxt;
    
    Itr(const MyIntPerm& mip_, bool finished = false)
      : fin(finished), mip(mip_) {
      if (!fin) {
        perm.resize(mip.seq_size);
        iota(perm.begin(), perm.end(), 0);
        head = perm;
        prv.resize(mip.cand_size);
        iota(prv.begin(), prv.end(), -1);
        nxt.resize(mip.cand_size);
        iota(nxt.begin(), nxt.end(), 1);
        nxt[mip.cand_size - 1] = -1;
      }
    }

    bool operator !=(const Itr& o) const {
      if (o.fin) return !fin;
      else if (fin) return true;
      return mip.cand_size == o.mip.cand_size
        && mip.seq_size == o.mip.seq_size
        && perm == o.perm;
    }

    const vector<int>& operator *() const { return perm; }

    void operator ++() {
      if (fin) return;
      int i = mip.seq_size - 1;
      if (nxt[perm[i]] >= 0) {
        perm[i] = nxt[perm[i]];
        return;
      }
      i--;
      int c;
      while (i >= 0) {
        c = perm[i];
        if (prv[c] >= 0) nxt[prv[c]] = c;
        if (nxt[c] >= 0) {
          prv[nxt[c]] = c;
          break;
        }
        i--;
      }
      if (i < 0) {
        fin = true;
        return;
      }
      c = nxt[c];
      nxt[prv[c]] = nxt[c];
      if (nxt[c] >= 0) prv[nxt[c]] = prv[c];
      perm[i] = c;
      int top = head[i];
      for (int j = i + 1; j < mip.seq_size; j++) {
        head[j] = top;
        perm[j] = top;
        top = nxt[top];
      }
    }
  };

  Itr begin() const { return Itr(*this); }
  Itr end() const { return Itr(*this, true); }
};


int xx;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int n = atoi(argv[1]);
  int r = atoi(argv[2]);

  vector<ll> vec(n);
  iota(vec.begin(), vec.end(), 0);

  double t1 = get_time_sec();
  MyIntPerm mip = {n, r};
  auto it = mip.begin();
  for (const auto& v : mip) {
    xx |= v[0];
  }
  double t2 = get_time_sec();
  IntPerm ip(n, r);
  const vector<int>& v = ip.get();
  do {
    xx |= v[0];
  }while (ip.next());
  double t3 = get_time_sec();
  do {
    xx |= vec[0];
  }while (next_permutation(vec.begin(), vec.end()));
  double t4 = get_time_sec();
  
  cout << t2 - t1 << endl;
  cout << t3 - t2 << endl;
  cout << t4 - t3 << endl;
  cout << xx << endl;

  return 0;
}


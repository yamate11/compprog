#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

template<typename T>
struct Board {
  int nR;
  int nC;
  T def;
  vector<T> brd;
  Board(int nr, int nc, T def_ = T(0)) :
    nR(nr), nC(nc), def(def_), brd(nR*nC, def_) {}
  int enc(int r, int c) const { 
    if (r < 0 || r >= nR || c < 0 || c >= nC) return -1;
    else                                      return r * nC + c;
  }
  pair<int, int> dec(int i) const { return make_pair(i / nC, i % nC); }
  const T& ati(int i) const { return i < 0 ? def : brd.at(i); }
  T& ati(int i) { return i < 0 ? def : brd.at(i); }
  const T& at(int r, int c) const {
    int i = enc(r, c);
    if (i < 0) return def;
    else       return brd.at(i);
  }
  T& at(int r, int c) {
    int i = enc(r, c);
    if (i < 0) return def;
    else       return brd.at(i);
  }
  int ishift(int i, int dr, int dc) const {
    pair<int, int> j = dec(i);
    return enc(j.first + dr, j.second + dc);
  }
  int ishift(int i, pair<int, int> p) const {
    return ishift(i, p.first, p.second);
  }
  int iS(int i) const {
    return (i < 0 || i + nC >= nR * nC) ? -1 : i + nC;
  }
  int iN(int i) const {
    return (i < 0 || i - nC < 0       ) ? -1 : i - nC;
  }
  int iE(int i) const {
    return (i < 0 || i % nC == nC - 1 ) ? -1 : i + 1;
  }
  int iW(int i) const {
    return (i < 0 || i % nC == 0      ) ? -1 : i - 1;
  }
  int iSE(int i) const { return iE(iS(i)); }
  int iSW(int i) const { return iW(iS(i)); }
  int iNE(int i) const { return iE(iN(i)); }
  int iNW(int i) const { return iW(iN(i)); }
  vector<int> viSN(int i) const { return vector<int> { iS(i), iN(i) }; }
  vector<int> viEW(int i) const { return vector<int> { iE(i), iW(i) }; }
  vector<int> vi4(int i) const {
    return vector<int> { iS(i), iN(i), iE(i), iW(i) }; 
  }
  vector<int> vidiagP(int i) const { return vector<int> { iNW(i), iSE(i) }; }
  vector<int> vidiagN(int i) const { return vector<int> { iSW(i), iNE(i) }; }
  vector<int> vidiag(int i) const {
    return vector<int> { iNW(i), iSE(i), iSW(i), iNE(i) }; 
  }
  vector<int> vi8(int i) const {
    return vector<int> { iS(i), iN(i), iE(i), iW(i),
	                 iNW(i), iSE(i), iSW(i), iNE(i) }; 
  }
  vector<T> tval(vector<int> is) const {
    vector<T> ret;
    for (int i : is) ret.push_back(ati(i));
    return ret;
  }
  vector<T> vtSN(int i) const { return tval(viSN(i)); }
  vector<T> vtEW(int i) const { return tval(viEW(i)); }
  vector<T> vt4(int i)  const { return tval(vi4(i)); }
  vector<T> vtdiagP(int i) const { return tval(vidiagP(i)); }
  vector<T> vtdiagN(int i) const { return tval(vidiagN(i)); }
  vector<T> vtdiag(int i) const { return tval(vidiag(i)); }
  vector<T> vt8(int i) const { return tval(vi8(i)); }
};

template<typename T>
ostream& operator <<(ostream& os, Board<T> brd) {
  for (int i = 0; i < brd.nR; i++) {
    for (int j = 0; j < brd.nC; j++) {
      if (j > 0) os << " ";
      os << brd.at(i, j);
    }
    os << "\n";
  }
  return os;
}



using Pair = pair<ll, ll>;
Pair mult(ll k, Pair p) { return make_pair(k * p.first, k * p.second); }

bool solve() {
  Board<char> brd(19, 19, '.');
  ll numP = 0;
  ll numO = 0;
  for (ll i = 0; i < 19; i++) {
    string s; cin >> s;
    for (ll j = 0; j < 19; j++) {
      brd.at(i, j) = s.at(j);
      if (s.at(j) == 'o') numP++;
      if (s.at(j) == 'x') numO++;
    }
  }

  auto seqlen = [&](ll i, char c, Pair d) -> ll {
    if (brd.ati(brd.ishift(i, mult(-1, d))) == c) return 0;
    ll m = 1;
    for ( ; brd.ati(brd.ishift(i, mult(m, d))) == c; m++);
    return m;
  };

  auto solve2 = [&](char p1, char p2) -> bool {
    set<ll> cand;
    for (ll i = 0; i < 19*19; i++) {
      if (brd.ati(i) == '.') continue;
      for (Pair d : vector<Pair> { {1,0}, {0,1}, {1,1}, {1,-1} }) {
	ll k = seqlen(i, brd.ati(i), d);
	if (brd.ati(i) == p2) {
	  if (k >= 5) return false;
	}else if (brd.ati(i) == p1) {
	  if (k >= 10) return false;
	  if (k >= 5) {
	    if (cand.empty() == 0) {
	      for (ll m = k - 5; m < 10 - k; m++) {
		cand.insert(brd.ishift(i, mult(m, d)));
	      }
	    }else {
	      set<ll> newCand;
	      for (ll m = k - 5; m < 10 - k; m++) {
		ll z = brd.ishift(i, mult(m, d));
		if (cand.find(z) != cand.end()) newCand.insert(z);
	      }
	      if (newCand.empty()) return false;
	      cand = move(newCand);
	    }
	  }
	}else assert(0);
      }
    }
    return true;
  };

  if (numP == numO) return solve2('x', 'o');
  else if (numP == numO + 1) return solve2('o', 'x');
  else return false;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}


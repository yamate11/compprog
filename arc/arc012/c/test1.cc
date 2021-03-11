#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

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
  const T& ati(int i) const { return brd.at(i); }
  T& ati(int i) { return brd.at(i); }
  const T& at(int r, int c) const {
    int i = enc(r, c);
    if (i == -1) return def;
    else         return brd.at(i);
  }
  T& at(int r, int c) {
    int i = enc(r, c);
    if (i == -1) return def;
    else         return brd.at(i);
  }
  int iS(int i) {
    return (i < 0 || i + nC >= nR * nC) ? -1 : i + nC;
  }
  int iN(int i) {
    return (i < 0 || i - nC < 0       ) ? -1 : i - nC;
  }
  int iE(int i) {
    return (i < 0 || i % nC == nC - 1 ) ? -1 : i + 1;
  }
  int iW(int i) {
    return (i < 0 || i % nC == 0      ) ? -1 : i - 1;
  }
  int iSE(int i) { return iE(iS(i)); }
  int iSW(int i) { return iW(iS(i)); }
  int iNE(int i) { return iE(iN(i)); }
  int iNW(int i) { return iW(iN(i)); }
  vector<int> viSN(int i) { return vector<int> { iS(i), iN(i) }; }
  vector<int> viEW(int i) { return vector<int> { iE(i), iW(i) }; }
  vector<int> vi4(int i) {
    return vector<int> { iS(i), iN(i), iE(i), iW(i) }; 
  }
  vector<int> vidiagP(int i) { return vector<int> { iNW(i), iSE(i) }; }
  vector<int> vidiagN(int i) { return vector<int> { iSW(i), iNE(i) }; }
  vector<int> vidiag(int i) {
    return vector<int> { iNW(i), iSE(i), iSW(i), iNE(i) }; 
  }
  vector<int> vi8(int i) {
    return vector<int> { iS(i), iN(i), iE(i), iW(i),
	                 iNW(i), iSE(i), iSW(i), iNE(i) }; 
  }
  vector<T> tval(vector<int> is) {
    vector<T> ret;
    for (int i : is) ret.push_back(ati(i));
    return ret;
  }
  vector<T> vtSN(int i) { return tval(viSN(i)); }
  vector<T> vtEW(int i) { return tval(viEW(i)); }
  vector<T> vt4(int i)  { return tval(vi4(i)); }
  vector<T> vtdiagP(int i) { return tval(vidiagP(i)); }
  vector<T> vtdiagN(int i) { return tval(vidiagN(i)); }
  vector<T> vtdiag(int i) { return tval(vidiag(i)); }
  vector<T> vt8(int i) { return tval(vi8(i)); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  Board<char> brd(10, 5, '.');
  brd.at(2, 2) = 'o';
  brd.at(2, 0) = 'o';
  ll cnt1 = 0;
  for (char t : brd.vt8(brd.enc(1,1))) cnt1 += t == 'o' ? 1 : 0;
  assert(cnt1 == 2);

  cout << "Test Done." << endl;
}

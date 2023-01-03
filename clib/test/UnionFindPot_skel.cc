#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(UnionFindPot debug)

template<typename T = int>
struct NaiveUnionFind {
  int size;
  vector<int> _leader;
  vector<T> _pot;
  vector<vector<int>> _member;

  NaiveUnionFind(int size_) : size(size_), _leader(size), _pot(size), _member(size) {
    for (int i = 0; i < size; i++) {
      _leader[i] = i;
      _pot[i] = 0;
      _member[i].push_back(i);
    }
  }
  int merge(int i, int j, const T& p = (T)0) {
    DLOGK("naive merge", i, j);
    int new_leader = _leader[j];
    int old_leader = _leader[i];
    if (new_leader == _leader[i]) {
      if (_pot[i] == _pot[j] + p) return new_leader;
      else return -1;
    }
    T pdiff = p + _pot[j] - _pot[i];
    for (int x : _member[old_leader]) {
      _leader[x] = new_leader;
      _member[new_leader].push_back(x);
      _pot[x] = _pot[x] + pdiff;
    }
    _member[old_leader].resize(0);
    DLOG("naive merge result");
    for (int x = 0; x < size; x++) {
      DLOGK(x, _leader[x], _pot[x], _member[x]);
    }
    return new_leader;
  }

  pair<int, T> pot(int i) { return {_leader[i], _pot[i]}; }

  int leader(int i) { return _leader[i]; }

  int groupSize(int i) { return _member[_leader[i]].size(); }

  const vector<int>& group(int i) { return _member[_leader[i]]; }

};

struct Fp2 {
  int v;
  Fp2(int v_ = 0) : v(v_) {}
  Fp2 operator +(const Fp2& o) const { return Fp2(v ^ o.v); }
  Fp2 operator -() const { return Fp2(v); }
  Fp2 operator -(const Fp2& o) const { return Fp2(v ^ o.v); }
  bool operator ==(const Fp2& o) const { return v == o.v; }
  bool operator !=(const Fp2& o) const { return v != o.v; }
};


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  {
    UnionFind uf1(6);
    assert(uf1.leader(0) != uf1.leader(5));
    assert(uf1.groupSize(5) == 1);
    uf1.merge(0, 5);
    assert(uf1.leader(0) == uf1.leader(5));
    assert(uf1.groupSize(5) == 2);
    assert(uf1.groupSize(0) == 2);
    uf1.merge(1, 3);
    uf1.merge(2, 5);
    assert(uf1.groupSize(2) == 3);
    assert(uf1.leader(0) == uf1.leader(2));
    assert(uf1.leader(1) == uf1.leader(3));
    assert(uf1.leader(4) != uf1.leader(0));
    assert(uf1.leader(0) != uf1.leader(1));

    assert(uf1.group(2) == vector<int>({0, 2, 5}));
    assert(uf1.group(3) == vector<int>({1, 3}));

  }

  {
    for (int _z = 0; _z < 10000; _z++) {
      DLOG("****");
      int n = randrange(1, 11);
      UnionFind uf(n);
      NaiveUnionFind nuf(n);
      for (int _rep = 0; _rep < 30; _rep++) {
        int a = randrange(0, n);
        int b = randrange(0, n);
        auto [la, pa] = uf.pot(a);
        auto [lb, pb] = uf.pot(b);
        auto [nla, npa] = nuf.pot(a);
        auto [nlb, npb] = nuf.pot(b);
        assert(la == uf.leader(a));
        assert(lb == uf.leader(b));
        DLOGK(a, b, la, lb, nla, nlb);
        assert ((la == lb) == (nla == nlb));
        if (la == lb) {
          DLOGKL("equiv", a, b, la, lb, pa, pb, npa, npb);
          assert(pa - pb == npa - npb);
        }else {
          int p = randrange(-10, 11);
          DLOGKL("merge", b, a, p);
          uf.merge(b, a, p);
          nuf.merge(b, a, p);
          DLOGK(nuf.pot(b), nuf.pot(a));
          DLOGKL("uf", uf._leader);
        }
        if (_rep == n) {
          for (int i = 0; i < n; i++) {
            assert(uf.groupSize(i) == nuf.groupSize(i));
            auto v1 = uf.group(i);
            auto v2 = nuf.group(i);
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            assert(v1 == v2);
          }
        }
      }
    }
  }


  {
    UnionFind uf(6);
    uf.merge(3, 1, 20);
    int ld = uf.merge(0, 1, -10);
    assert(ld >= 0);
    auto [ld3, p3] = uf.pot(3);
    auto [ld0, p0] = uf.pot(0);
    assert(ld3 == ld0 and p3 - p0 == 30);
    int rc = uf.merge(3, 0, 40);
    assert(rc == -1);
  }

  {
    UnionFind<Fp2> uf(6);
    uf.merge(4, 3, 1);
    uf.merge(3, 2, 1);
    int rc = uf.merge(4, 2, 0);
    assert(rc >= 0);
    assert(uf.leader(4) == uf.leader(2));
    auto [ld4, pot4] = uf.pot(4);
    auto [ld2, pot2] = uf.pot(2);
    assert(uf.leader(4) == ld4 and uf.leader(2) == ld2);
    assert(pot4 == pot2);
    assert(uf.groupSize(4) == 3);
    auto v = uf.group(3);
    sort(v.begin(), v.end());
    assert(v == (vector<int>{2, 3, 4}));
  }

  cout << "test done." << endl;
}

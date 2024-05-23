#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(UnionFind ftwo debug)

template<typename T = int>
struct NaiveUnionFind {
  int size;
  vector<int> _leader;
  vector<optional<T>> _pot;
  vector<vector<int>> _member;

  NaiveUnionFind(int size_) : size(size_), _leader(size), _pot(size), _member(size) {
    for (int i = 0; i < size; i++) {
      _leader[i] = i;
      _pot[i] = (T)0;
      _member[i].push_back(i);
    }
  }
  int merge(int i, int j, optional<T> p = nullopt) {
    DLOGK("naive merge", i, j, p);
    int new_leader = _leader[j];
    int old_leader = _leader[i];
    if (new_leader == old_leader and not _pot[i]) {
      if (not p or *_pot[i] != *_pot[j] + *p) {
        for (int x : _member[new_leader]) _pot[x] = nullopt;
      }
      return new_leader;
    }
    bool pot_consis = p and _pot[j] and _pot[i];
    T pdiff = pot_consis ? *p + *_pot[j] - *_pot[i] : (T)0;
    if (not pot_consis) {
      for (int x : _member[new_leader]) _pot[x] = nullopt;
    }
    for (int x : _member[old_leader]) {
      _leader[x] = new_leader;
      _member[new_leader].push_back(x);
      if (pot_consis) _pot[x] = *_pot[x] + pdiff;
      else _pot[x] = nullopt;
    }
    _member[old_leader].resize(0);
    DLOG("naive merge result");
    for (int x = 0; x < size; x++) {
      DLOGK(x, _leader[x], _pot[x], _member[x]);
    }
    return new_leader;
  }

  pair<int, optional<T>> leaderpot(int i) {
    return {_leader[i], _pot[i]};
  }

  int leader(int i) { return _leader[i]; }

  int groupSize(int i) { return _member[_leader[i]].size(); }

  int numGroups() {
    int ret = 0;
    for (int i = 0; i < size; i++) if (_leader[i] == i) ret++;
    return ret;
  }

  const vector<int>& group(int i) { return _member[_leader[i]]; }

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
    assert(uf1.group_size(5) == 1);
    uf1.merge(0, 5);
    assert(uf1.num_groups() == 5);
    assert(uf1.leader(0) == uf1.leader(5));
    assert(uf1.group_size(5) == 2);
    assert(uf1.group_size(0) == 2);
    uf1.merge(1, 3);
    uf1.merge(2, 5);
    assert(uf1.num_groups() == 3);
    assert(uf1.group_size(2) == 3);
    assert(uf1.leader(0) == uf1.leader(2));
    assert(uf1.leader(1) == uf1.leader(3));
    assert(uf1.leader(4) != uf1.leader(0));
    assert(uf1.leader(0) != uf1.leader(1));

    auto gi3 = uf1.group_info();
    assert(gi3.group(2) == vector<int>({0, 2, 5}));
    assert(gi3.group(3) == vector<int>({1, 3}));
  }

  {
    UnionFind<ll> uf(3);
    assert(*uf.pot(0) == 0 and *uf.pot(1) == 0 and *uf.pot(2) == 0);
    uf.merge(1, 0, 10);
    assert(uf.leader(0) == uf.leader(1) and *uf.pot(1) == *uf.pot(0) + 10);
    uf.merge(2, 1, 10);
    assert(uf.leader(1) == uf.leader(2) and *uf.pot(2) == *uf.pot(1) + 10);
    uf.merge(0, 2, 10);
    assert(uf.leader(2) == uf.leader(0) and not uf.pot(uf.leader(0)));
  }

  {
    for (int _z = 0; _z < 10000; _z++) {
      DLOG("****");
      int n = randrange(1, 11);
      UnionFind<ll> uf(n);
      NaiveUnionFind nuf(n);
      for (int _rep = 0; _rep < 30; _rep++) {
        int a = randrange(0, n);
        int b = randrange(0, n);
        int la = uf.leader(a);
        auto pa = uf.pot(a);
        int lb = uf.leader(b);
        auto pb = uf.pot(b);
        auto [nla, npa] = nuf.leaderpot(a);
        auto [nlb, npb] = nuf.leaderpot(b);
        assert(la == uf.leader(a));
        assert(lb == uf.leader(b));
        DLOGK(a, b, la, lb, nla, nlb);
        assert ((la == lb) == (nla == nlb));
        if (la == lb) {
          DLOGKL("equiv", a, b, la, lb, pa, pb, npa, npb);
          assert(pa and pb and npa and npb and *pa - *pb == *npa - *npb);
        }else {
          int p = randrange(-10, 11);
          DLOGKL("merge", b, a, p);
          int i = uf.merge(b, a, p);
          int j = nuf.merge(b, a, p);
          DLOGK(i, j, nuf.leaderpot(b), nuf.leaderpot(a));
          DLOGKL("uf", uf._leader);
          assert(uf.leader(j) == uf.leader(a) and uf.leader(j) == uf.leader(b));
          assert(nuf.leader(i) == nuf.leader(a) and nuf.leader(i) == nuf.leader(b));
          for (int k = 0; k < n; k++) {
            if (uf.leader(k) == i) {
              if (*nuf._pot[k] - *nuf._pot[i] != *uf.pot(k) - *uf.pot(i)) {
                DLOGK(k, i, *nuf._pot[k], *nuf._pot[i], *uf.pot(k), *uf.pot(i));
                assert(false);
              }
            }
          }
        }
        if (_rep == n) {
          for (int i = 0; i < n; i++) {
            assert(uf.num_groups() == nuf.numGroups());
            assert(uf.group_size(i) == nuf.groupSize(i));
            auto gi = uf.group_info();
            auto v1 = gi.group(i);
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
    UnionFind<ll> uf(6);
    uf.merge(3, 1, 20);
    int ld = uf.merge(0, 1, -10);
    assert(ld >= 0);
    int ld3 = uf.leader(3);
    auto p3 = uf.pot(3);
    int ld0 = uf.leader(0);
    auto p0 = uf.pot(0);
    assert(ld3 == ld0 and *p3 - *p0 == 30);
    uf.merge(3, 0, 40);
    assert(not uf.pot(0) and not uf.pot(3));
  }

  {
    UnionFind<ll> uf(13);
    uf.merge(0, 1, 3);
    uf.merge(1, 2, 1);
    uf.merge(4, 1, 2);
    uf.merge(3, 4, -4);
    int rc1 = uf.merge(2, 3, 1);
    assert(rc1 >= 0);
    uf.merge(5, 7, 0);
    uf.merge(9, 5, -2);
    uf.merge(7, 6, 3);
    int rc2 = uf.merge(9, 6, 1);
    assert(rc2 >= 0);
    uf.merge(8, 7, 1);
    uf.merge(10, 11, 2);
    uf.merge(10, 12, 3);
    int rc3 = uf.merge(12, 11, -1);
    assert(rc3 >= 0);
    assert(uf.leader(0) == uf.leader(1));
    assert(uf.leader(0) == uf.leader(2));
    assert(uf.leader(0) == uf.leader(3));
    assert(uf.leader(0) == uf.leader(4));
    assert(uf.leader(0) != uf.leader(5));
    assert(uf.leader(5) == uf.leader(6));
    assert(uf.leader(5) == uf.leader(7));
    assert(uf.leader(5) == uf.leader(8));
    assert(uf.leader(5) == uf.leader(9));
    assert(uf.leader(5) != uf.leader(10));
    assert(*uf.pot(0) - *uf.pot(3) == 5);
    assert(*uf.pot(8) - *uf.pot(6) == 4);
    assert(*uf.pot(4) - *uf.pot(0) == -1);
    auto gi = uf.group_info();
    vector<int> v1(gi.group(3));
    for (int i = 0; i < 13; i++) assert(uf.group_size(i) == (int)gi.group(i).size());
  }


  {
    UnionFind<Ftwo> uf(6);
    uf.merge(4, 3, 1);
    uf.merge(3, 2, 1);
    int rc = uf.merge(4, 2, 0);
    assert(rc >= 0);
    assert(uf.leader(4) == uf.leader(2));
    int ld4 = uf.leader(4);
    auto pot4 = uf.pot(4);
    int ld2 = uf.leader(2);
    auto pot2 = uf.pot(2);
    assert(uf.leader(4) == ld4 and uf.leader(2) == ld2);
    assert(pot4 == pot2);
    assert(uf.group_size(4) == 3);
    auto gi = uf.group_info();
    auto v = gi.group(3);
    sort(v.begin(), v.end());
    assert(v == (vector<int>{2, 3, 4}));
  }

  cout << "test done." << endl;
}

#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug matrix ftwo)

int main() {

  random_device rd;
  mt19937 rng(rd());

  {
    Ftwo zero(0);
    Ftwo one(1);

    assert(zero + zero == zero);
    assert(zero + one == one);
    assert(one + zero == one);
    assert(one + one == zero);
    assert(zero - zero == zero);
    assert(zero - one == one);
    assert(one - zero == one);
    assert(one - one == zero);
    assert(zero * zero == zero);
    assert(zero * one == zero);
    assert(one * zero == zero);
    assert(one * one == one);
    assert(zero / one == zero);
    assert(one / one == one);
  }

  if (1) {
    ll rep = 100;
    ll sz2 = 12;
    for (ll k = 0; k < rep; k++) {
      Matrix<Ftwo> mat1(sz2, sz2);
      uniform_int_distribution<ll> dist1(0, 1);
      while (true) {
        for (ll i = 0; i < sz2; i++) {
          for (ll j = 0; j < sz2; j++) {
            mat1.at(i, j) = dist1(rng);
          }
        }
        auto [rank, det] = mat1.self_sweepout();
        if ((ll)rank == sz2) break;
      }
      uniform_int_distribution<ll> dist2(3, sz2);
      ll sz1 = dist2(rng);
      DLOGK(sz1);
      vector<ll> seed(sz1);
      for (ll i = 0; i < sz1; i++) {
        ll e = 0;
        for (ll j = 0; j < sz2; j++) {
          if (mat1.at(i, j)) { e |= (1LL << j); }
        }
        seed[i] = e;
      }
      vector<ll> vs;
      for (ll m = 0; m < sz1; m++) {
        ll e = 0;
        for (ll j = 0; j < sz1; j++) {
          if (dist1(rng) == 0) { e ^= seed[j]; }
        }
        vs.push_back(e);
      }
      for (ll m = 0; m < sz1; m++) vs.push_back(seed[m]);
      auto basis = getF2Basis(vs);
      DLOGK(sz1);
      DLOGK(vs);
      DLOGK(basis);
      assert((ll)basis.size() == sz1);
      Matrix<Ftwo> mat2(sz1, sz2);
      for (ll i = 0; i < sz1; i++) {
        for (ll j = 0; j < sz2; j++) {
          mat2.at(i, j) = (((basis[i] >> j) & 1) != 0) ? 1 : 0;
        }
      }
      DLOGK(mat2);
      auto [rank2, det2] = mat2.self_sweepout();
      DLOGK(rank2);
      assert((ll)rank2 == sz1);
      Matrix<Ftwo> mat3(sz1 + 1, sz2);
      for (ll i = 0; i < sz1; i++) {
        for (ll j = 0; j < sz2; j++) {
          mat3.at(i, j) = mat1.at(i, j);
        }
      }
      for (ll m = 0; m < sz1; m++) {
        for (ll j = 0; j < sz2; j++) {
          mat3.at(sz1, j) = ((basis[m] >> j) != 0) ? 1 : 0;
        }
        DLOGK(mat3);
        auto [rank3, det3] = mat3.self_sweepout();
        DLOGK(rank3);
        assert((ll)rank3 == sz1);
      }
    }
  }

  cerr << "Test Done.\n";

}

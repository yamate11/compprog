#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(dynSegTree)

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    using DAT = ll;
    using OP = optional<ll>;
    const DAT unit_dat = LLONG_MAX;
    const OP unit_op = nullopt;
    auto xAdd = [](DAT x, DAT y) -> DAT { return min(x, y); };
    auto xComp = [](OP h, OP g) -> OP { return h.has_value() ? h : g; };
    auto xAppl = [](int k, OP f, DAT x) -> DAT { return f.value_or(x); };
    auto dst = make_dyn_seg_tree(0, 64, unit_dat, unit_op, xAdd, xComp, xAppl);

    dst.update(11, 12, 100);
    // dst.show_nodes();
    dst.update(20, 21, 200);
    // dst.show_nodes();
    assert(dst.query(0, 64) == 100);
    assert(dst.query(0, 15) == 100);
    assert(dst.query(15, 30) == 200);
    dst.update(30, 50, 500);
    assert(dst.query(40, 42) == 500);
  }

  random_device rand_dev;
  mt19937 rng(rand_dev());
  auto get_pqx = [&](ll sz) -> tuple<ll, ll, ll> {
    uniform_int_distribution<ll> dist1(0, sz);
    ll p, q;
    while (true) {
      p = dist1(rng);
      q = dist1(rng);
      if (p > q) swap(p, q);
      if (p < q) break;
    }
    uniform_int_distribution<ll> dist2(-1e9, 1e9);
    // uniform_int_distribution<ll> dist2(0, 5);
    ll x = dist2(rng);
    return {p, q, x};
  };

  ll rep1 = 500;
  ll rep2 = 500;

  auto run_test = [&](auto unit_dat, auto unit_op,
                      auto xAdd, auto xComp, auto xAppl) -> void {
    for (ll sz: vector<ll>({10, 1000})) {
      uniform_int_distribution<ll> dist(0, sz);
      vector<ll> cmp(sz);
      for (ll i = 0; i < rep1; i++) {
        // DLOG("---start");
        auto dst = make_dyn_seg_tree(0, sz, unit_dat, unit_op,
                                     xAdd, xComp, xAppl);
        for (ll j = 0; j < sz; j++) cmp[j] = unit_dat;
        for (ll j = 0; j < rep2; j++) {
          auto [p, q, x] = get_pqx(sz);
          dst.update(p, q, x);
          // DLOGK(p, q, x);
          for (ll k = p; k < q; k++) cmp[k] = xAppl(1, x, cmp[k]);
          auto [p2, q2, x2] = get_pqx(sz);
          ll y = dst.query(p2, q2);
          ll y_cmp = unit_dat;
          for (ll k = p2; k < q2; k++) y_cmp = xAdd(y_cmp, cmp[k]);
          // DLOGK(p2, q2, y, y_cmp);
          assert(y == y_cmp);
        }
      }
    }
  };

  {
    using DAT = ll;
    using OP = optional<ll>;
    const DAT unit_dat = LLONG_MAX;
    const OP unit_op = nullopt;
    auto xAdd = [](DAT x, DAT y) -> DAT { return min(x, y); };
    auto xComp = [](OP h, OP g) -> OP { return h.has_value() ? h : g; };
    auto xAppl = [](int k, OP f, DAT x) -> DAT { return f.value_or(x); };
    run_test(unit_dat, unit_op, xAdd, xComp, xAppl);
  }

  {
    using DAT = ll;
    using OP = ll;
    const DAT unit_dat = 0;
    const OP unit_op = 0;
    auto xAdd = [](DAT x, DAT y) -> DAT { return x + y; };
    auto xAppl = [](int k, OP f, DAT x) -> DAT { return k * f + x; };
    auto xComp = [](OP h, OP g) -> OP { return h + g; };
    run_test(unit_dat, unit_op, xAdd, xComp, xAppl);
  }

  {
    using DAT = ll;
    using OP = optional<ll>;
    const DAT unit_dat = 0;
    const OP unit_op = nullopt;
    auto xAdd = [](DAT x, DAT y) -> DAT { return x + y; };
    auto xAppl = [](int k, OP f, DAT x) -> DAT {
      return f.has_value() ? k * f.value() : x;
    };
    auto xComp = [](OP h, OP g) -> OP { return h.has_value() ? h : g; };
    run_test(unit_dat, unit_op, xAdd, xComp, xAppl);
  }


  return 0;
}


#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"
using pll = pair<ll, ll>;

// @@ !! LIM(mo)

random_device rd;
mt19937 rng(rd());
ll randrange(ll i, ll j) {
  uniform_int_distribution<ll> dist(i, j - 1);
  return dist(rng);
}

// For confirmation testing:
// - ABC 242G Range Pairing Query
  
void fromABC242G() {

  ll T = 100;
  REP(_t, 0, T) {
    ll N = randrange(50, 80);
    vector<ll> A(N);
    ll nc = randrange(1, N / 4);
    REP(j, 0, N) A[j] = randrange(0, nc);
    ll Q = randrange(50, 80);
    vector<pll> qs(Q);
    REP(j, 0, Q) {
      ll a = randrange(0, Q);
      ll b = randrange(a + 1, Q + 1);
      qs[j] = pll(a, b);
    }

    vector<ll> cnt(N);
    ll cans = 0;
    vector<ll> ans(Q);

    auto f_in  = [&](ll i) -> void { if (++cnt[A[i]] % 2 == 0) cans++; };
    auto f_out = [&](ll i) -> void { if (cnt[A[i]]-- % 2 == 0) cans--; };
    auto calc = [&](ll i) -> void { ans[i] = cans; };
    Mo mo(N);
    REP(i, 0, Q) mo.add_query(qs[i].first, qs[i].second);
    mo.run(f_in, f_out, calc);

    // naive
    REP(i, 0, Q) {
      auto [a, b] = qs[i];
      vector<ll> ncnt(N);
      REP(j, a, b) ncnt[A[j]]++;
      ll nans = 0;
      REP(k, 0, nc) nans += ncnt[k] / 2;
      assert(nans == ans[i]);
    }
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  

  cerr << "ok\n";
}

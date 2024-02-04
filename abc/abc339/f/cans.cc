#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#include <boost/multiprecision/cpp_int.hpp>           // 整数を使う時
using namespace boost::multiprecision;

// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(random)

// ---- inserted library file random.cc


struct Random {
  static random_device the_random_device;
  mt19937_64 rng;

  Random() : rng(the_random_device()) {}
  Random(unsigned seed) : rng(seed) {}
  
  ll range(ll i, ll j) {
    if (i >= j) {
      throw runtime_error("Random.range: invalid range");
    }
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  }

};

random_device Random::the_random_device;

// ---- end random.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);


  ll M;
  vector<cpp_int> Bv;
  vector<ll> Bn;
  {
    ll N; cin >> N;
    // @InpVec(N, A, type=cpp_int) [Y0ryPkG3]
    auto A = vector(N, cpp_int());
    for (int i = 0; i < N; i++) { cpp_int v; cin >> v; A[i] = v; }
    // @End [Y0ryPkG3]
    sort(ALL(A));
    REP(i, 0, N) {
      if (i == 0 or A[i - 1] != A[i]) {
        Bv.push_back(A[i]);
        Bn.push_back(1);
      }else {
        Bn.back()++;
      }
    }
    M = SIZE(Bv);
    assert(M == SIZE(Bn));
  }

  Random rand;
  ll nf = 20;
  vector Pr(nf, 0LL);
  vector F(nf, vector(M, ll()));
  vector<unordered_map<ll, vector<ll>>> revF(nf);
  REP(i, 0, nf) {
    Pr[i] = rand.range(1LL << 28, 1LL << 30);
    REP(j, 0, M) {
      ll x = (ll)(Bv[j] % Pr[i]);
      F[i][j] = x;
      revF[i][x].push_back(j);
    }
  }
  ll ans = 0;
  REP(i, 0, M) REP(j, 0, M) {
    ll r = (F[0][i] * F[0][j]) % Pr[0];
    auto it = revF[0].find(r);
    if (it == revF[0].end()) continue;
    auto cands = it->second;
    REP(k, 1, nf) {
      auto prev = move(cands);
      cands.clear();
      for (auto m : prev) {
        if ((F[k][i] * F[k][j]) % Pr[k] == F[k][m]) cands.push_back(m);
      }
      if (cands.empty()) break;
    }
    for (ll m : cands) ans += Bn[i] * Bn[j] * Bn[m];
  }
  cout << ans << endl;

  return 0;
}


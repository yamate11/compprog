#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, K; cin >> N >> M >> K;
  // @InpVec(N, A) [jMnugSHR]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [jMnugSHR]

  if (M == K) {
    vector<ll> ans;
    ll sum = 0;
    REP(i, 0, M) sum += A[i];
    ans.push_back(sum);
    REP(i, M, N) {
      sum += A[i] - A[i - M];
      ans.push_back(sum);
    }
    REPOUT(i, 0, ssize(ans), ans[i], " ");
    return 0;
  }else {
    vector<ll> ans;
    multiset<ll> lo;
    multiset<ll> hi;
    vector<ll> tmp;
    REP(i, 0, M) tmp.push_back(A[i]);
    sort(ALL(tmp));
    ll sum = 0;
    REP(i, 0, K) {
      lo.insert(tmp[i]);
      sum += tmp[i];
    }
    REP(i, K, M) hi.insert(tmp[i]);
    ans.push_back(sum);
    REP(i, M, N) {
      ll out = A[i - M];
      ll in = A[i];
      auto it = lo.find(out);
      if (it == lo.end()) {
        auto it_hi = hi.find(out);
        assert(it_hi != hi.end());
        hi.erase(it_hi);
        lo.insert(in);
        sum += in;
        auto it_lo = prev(lo.end());
        sum -= *it_lo;
        hi.insert(*it_lo);
        lo.erase(it_lo);
      }else {
        sum -= *it;
        lo.erase(it);
        hi.insert(in);
        auto it_hi = hi.begin();
        sum += *it_hi;
        lo.insert(*it_hi);
        hi.erase(it_hi);
      }
      ans.push_back(sum);
    }
    REPOUT(i, 0, ssize(ans), ans[i], " ");
    return 0;
    
  }

  return 0;
}


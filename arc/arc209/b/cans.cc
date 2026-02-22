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

// @@ !! LIM(sortedIndex)

// ---- inserted library file sortedIndex.cc

vector<int> sortedIndex(const auto& vec, auto comp) {
  vector<int> ret(vec.size());
  iota(ret.begin(), ret.end(), 0);
  sort(ret.begin(), ret.end(), [&vec, &comp](int i, int j) { return comp(vec[i], vec[j]); });
  return ret;
}

template<typename Collection>
vector<int> sortedIndex(const Collection& vec) { return sortedIndex(vec, less<typename Collection::value_type>()); }

// ---- end sortedIndex.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll sigma = 26;

  auto solve = [&]() -> void {
    string S; cin >> S;
    ll N = ssize(S);
    vector cnt(sigma, 0LL);
    for (char c : S) cnt[c - 'a']++;
    ll d0 = ranges::max_element(cnt) - cnt.begin();
    if (cnt[d0] <= (N + 1) / 2) {
      auto ord = sortedIndex(cnt, greater<ll>());
      ll p = 0;
      string ans(N, ' ');
      REP(ii, 0, sigma) {
        ll i = ord[ii];
        REP(j, 0, cnt[i]) {
          ans[p] = 'a' + i;
          if (p % 2 == 0) {
            if (p + 2 < N) p += 2;
            else p = 1;
          }else {
            p += 2;
          }
        }
      }
      cout << ans << "\n";
    }else if (cnt[d0] == N) {
      cout << S << "\n";
    }else {
      char c0 = 'a' + d0;
      string ans;
      string s_others;
      REP(d, 0, sigma) if (d != d0) s_others += string(cnt[d], (char)('a' + d));
      ll num_others = ssize(s_others);
      ll p = cnt[d0] / (num_others + 1);
      ll q = cnt[d0] % (num_others + 1);
      vector<ll> vec(num_others + 1, p);
      ll pe;
      if (p % 2 == 0) {
        REP(i, 0, q) vec[num_others - i] = p + 1;
        pe = num_others + 1 - q;
      }else {
        REP(i, 0, q) vec[i] = p + 1;
        pe = q;
      }
      ll ip = 0;
      if (pe % 2 != 0) {
        ans += string(vec[ip], c0);
        ip++;
        ans += s_others.back(); s_others.pop_back();
      }
      for (; ip < pe; ip += 2) {
        ans += string(vec[ip] + 1, c0);
        ans += s_others.back(); s_others.pop_back();
        ans += string(vec[ip + 1] - 1, c0);
        if (ip + 1 < num_others) {
          ans += s_others.back(); s_others.pop_back();
        }
      }
      for (; ip < num_others + 1; ip++) {
        ans += string(vec[ip], c0);
        if (ip < num_others) {
          ans += s_others.back(); s_others.pop_back();
        }
      }
      cout << ans << "\n";
    }
  };


  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}


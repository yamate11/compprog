#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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

  ll N; cin >> N;
  string T; cin >> T;

  auto check = [&](const string& S) -> bool {
    auto sub = [&](const string& A, const string& B) -> bool {
      ll n = SIZE(A);
      assert(SIZE(B) == n + 1);
      ll i = 0;
      while (i < n and A[i] == B[i]) i++;
      if (i == n) return true;
      while (i < n and A[i] == B[i + 1]) i++;
      return i == n;
    };

    ll szt = SIZE(T);
    ll szs = SIZE(S);

    if (szt == szs) {
      ll cnt = 0;
      REP(i, 0, szt) if (T[i] != S[i]) cnt++;
      return cnt <= 1;
    }else if (szs == szt + 1) return sub(T, S);
    else if (szs == szt - 1) return sub(S, T);
    else return false;

};

  auto ans = vector<ll>();
  REP(i, 0, N) {
    string S; cin >> S;
    if (check(S)) ans.push_back(i);
  }
  cout << SIZE(ans) << "\n";
  REPOUT(i, 0, SIZE(ans), ans[i] + 1, " ");

  return 0;
}


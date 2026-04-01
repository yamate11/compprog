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

  
  string S; getline(cin, S);
  ll N = ssize(S);
  ll i = 0;
  set<string> ss;
  for (; i < N; ) {
    if (i < N - 1 and S[i] == '@' and 'a' <= S[i + 1] and S[i + 1] <= 'z') {
      ll j = i + 2;
      for (; j < N and 'a' <= S[j] and S[j] <= 'z'; j++);
      ss.insert(S.substr(i + 1, j - (i + 1)));
      i = j;
    }else {
      i++;
    }
  }
  for (auto n : ss) cout << n << "\n";

  return 0;
}


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

  ll N; cin >> N;
  // @InpVec(N, S, type=string) [6lEXxeOX]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [6lEXxeOX]
  vector fwd(N, vector<ll>());
  vector nbwd(N, 0LL);
  REP(i, 0, N) {
    string s; cin >> s;
    REP(j, 0, N) {
      if (i == j) continue;
      if (S[i][j] == 'o') {
        fwd[i].push_back(j);
        nbwd[j]++;
      }else if (S[i][j] == 'x') {
        fwd[j].push_back(i);
        nbwd[i]++;
      }
    }
  }
  vector<ll> cands;
  REP(i, 0, N) if (nbwd[i] == 0) cands.push_back(i);
  vector<ll> rec;
  while (not cands.empty()) {
    ll x = cands.back(); cands.pop_back();
    rec.push_back(x);
    for (ll y : fwd[x]) {
      if (--nbwd[y] == 0) cands.push_back(y);
    }
  }
  if (ssize(rec) < N) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  vector<ll> revR(N);
  REP(i, 0, N) revR[rec[i]] = i;
  REP(i, 0, N) {
    string s(N, ' ');
    REP(j, 0, N) {
      if (i == j) s[j] = '-';
      else if (revR[i] < revR[j]) s[j] = 'o';
      else if (revR[i] > revR[j]) s[j] = 'x';
      else assert(0);
    }
    cout << s << "\n";
  }

  return 0;
}


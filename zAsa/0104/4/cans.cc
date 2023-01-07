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

  string def = "zrbcdwtjfqlvsxpmhkng";
  vector tr(26, -1LL);
  REP(i, 0, 20) tr[def[i] - 'a'] = i / 2; 
  ll N; cin >> N;
  vector<string> ans;
  REP(_i, 0, N) {
    string w; cin >> w;
    string a;
    REP(i, 0, SIZE(w)) {
      char z = w[i];
      ll d;
      if (0 <= z - 'a' and z - 'a' < 26) d = z - 'a';
      else if (0 <= z - 'A' and z - 'A' < 26) d = z - 'A';
      else continue;
      ll c = tr[d];
      if (c >= 0) a += (char)('0' + c);
    }
    if (SIZE(a) > 0) ans.push_back(a);
  }
  REPOUT(i, 0, SIZE(ans), ans[i], " ");

  return 0;
}


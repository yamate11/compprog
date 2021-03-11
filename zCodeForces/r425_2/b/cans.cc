#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string goods; cin >> goods;
  vector<bool> is_good(128);
  for (ll i = 0; i < (ll)goods.size(); i++) {
    is_good[goods[i]] = true;
  }

  string pattern; cin >> pattern;
  ll psz = pattern.size();
  ll stpos = -1;
  string lpat, rpat;
  for (ll i = 0; i < psz; i++) {
    if (pattern[i] == '*') {
      stpos = i;
      break;
    }
  }
  if (stpos >= 0) {
    lpat = pattern.substr(0, stpos);
    rpat = pattern.substr(stpos + 1);
  }else {
    lpat = pattern;
    rpat = "";
  }
  ll lpsz = lpat.size();
  ll rpsz = rpat.size();

  auto match =
    [&](string pat, string s) -> bool {
      assert(pat.size() == s.size());
      for (ll i = 0; i < (ll)pat.size(); i++) {
        if (pat[i] == s[i]) continue;
        if (pat[i] != '?') return false;
        if (!is_good[s[i]]) return false;
      }
      return true;
    };

  auto solve =
    [&]() -> bool {
      string s; cin >> s;
      ll insize = (ll)s.size() - (lpsz + rpsz);
      if (insize < 0) return false;
      if (stpos < 0 && ((ll)s.size() != lpsz)) return false;
      if (!match(lpat, s.substr(0, lpsz))) return false;
      if (stpos < 0) return true;
      if (!match(rpat, s.substr(s.size() - rpsz, rpsz))) return false;
      for (ll i = lpsz; i < (ll)s.size() - rpsz; i++) {
        if (is_good[s[i]]) return false;
      }
      return true;
    };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}


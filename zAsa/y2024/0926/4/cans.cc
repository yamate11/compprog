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

  string s; cin >> s;
  vector<ll> suit;
  vector<ll> num;
  vector<ll> pos;
  {
    ll i = 0;
    while (i < ssize(s)) {
      pos.push_back(i);
      if (s[i] == 'S') suit.push_back(0);
      else if (s[i] == 'H') suit.push_back(1);
      else if (s[i] == 'D') suit.push_back(2);
      else if (s[i] == 'C') suit.push_back(3);
      else assert(0);
      i++;
      if (s[i] == '1' and s[i + 1] == '0') {
        num.push_back(10);
        i+= 2;
      }else {
        if (s[i] == 'A') num.push_back(14);
        else if ('2' <= s[i] and s[i] <= '9') num.push_back(s[i] - '0');
        else if (s[i] == 'J') num.push_back(11);
        else if (s[i] == 'Q') num.push_back(12);
        else if (s[i] == 'K') num.push_back(13);
        i++;
      }
    }
    pos.push_back(i);
  }
  ll sz = ssize(suit);
  ll nmin = sz + 1;
  ll smin = -1;
  REP(i, 0, 4) {
    ll cnt = 0;
    REP(j, 0, sz) {
      if (suit[j] == i and num[j] >= 10) cnt++;
      if (cnt == 5) {
        if (j + 1 < nmin) {
          nmin = j + 1;
          smin = i;
        }
        break;
      }
    }
  }
  vector<string> ans;
  REP(j, 0, nmin) {
    if (not (suit[j] == smin and num[j] >= 10)) {
      ans.push_back(s.substr(pos[j], pos[j + 1] - pos[j]));
    }
  }
  if (ans.empty()) {
    cout << 0 << endl;
  }else {
    REPOUT(i, 0, ssize(ans), ans[i], "");
  }

  return 0;
}


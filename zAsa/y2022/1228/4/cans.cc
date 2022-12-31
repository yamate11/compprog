#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long;

#define EX_REP_LL(i, from, to) for (ll i = (from); i < (to); i++)
#define EXGEN(rep_part, cond, yes, no_behaviour) ([&]() { rep_part if (cond) return (yes); no_behaviour; }())
#define EXISTS_BASE(rep_part, cond) EXGEN(rep_part, cond, true, return false)
#define EXFIND_BASE(rep_part, cond, t) EXGEN(rep_part, cond, t, assert(0))
#define EXISTS(i, from, to, cond) EXISTS_BASE(EX_REP_LL(i, from, to), cond)
#define FORALL(i, from, to, cond) (not EXISTS(i, from, to, not (cond)))
#define EXFIND(i, from, to, cond) EXFIND_BASE(EX_REP_LL(i, from, to), cond, i)

int main() {
  string s; cin >> s;
  ll N = s.size();
  cout << EXFIND(i, 0, N,
          EXISTS(c, 0, 26,
          FORALL(j, 0, N - i,
          EXISTS(k, 0, i + 1, 
          s[j + k] == 'a' + c))))
       << endl;
  return 0;
}


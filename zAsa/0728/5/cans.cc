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
  string S; cin >> S;
  string que = "";
  for (ll i = 0; i < N; i++) {
    char c = S[i];
    char d = i + 1 < N ? S[i + 1] : ' ';
    if (que == "") {
      que = string(1, c);
    }else if (ssize(que) == 1) {
      if (que[0] == c) que = "";
      else que += c;
    }else if (ssize(que) == 2) {
      if (que[0] == c) que = string(1, que[1]);
      else if (que[1] == c) que = string(1, que[0]);
      else if (d == ' ') que += c;
      else {
        i++;
        if (c == d) ;
        else if (d == que[0]) que = string() + que[1] + c;
        else if (d == que[1]) que = string() + c + que[0];
        else assert(false);
      }
    }
  }
  cout << ssize(que) << "\n";

  return 0;
}


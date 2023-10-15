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
  string S; cin >> S;
  deque<char> deq;
  REP(i, 0, SIZE(S)) {
    if (deq.empty()) {
      deq.push_back(S[i]);
    }else {
      if (deq.back() == S[i]) deq.pop_back();
      else if (deq.front() == S[i]) deq.pop_front();
      else {
        auto nxt = [&]() -> char {
          ll j = i;
          while (j < N and S[i] == S[j]) j++;
          if (j == N) return -1;
          else return S[j];
        };
        char c = nxt();
        if (c == deq.back()) deq.push_front(S[i]);
        else deq.push_back(S[i]);
      }
    }
  }
  cout << deq.size() << endl;

  return 0;
}


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

struct Node {
  Node* prev;
  string s;
  Node() : prev(nullptr), s("") {}
};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  Node top;

  ll N, Q; cin >> N >> Q;
  Node* server = &top;
  vector<Node*> pc(N, &top);
  
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    ll p; cin >> p; p--;
    if (tp == 1) {
      pc[p] = server;
    }else if (tp == 2) {
      string s; cin >> s;
      Node* nn = new Node();
      nn->s = move(s);
      nn->prev = pc[p];
      pc[p] = nn;
    }else if (tp == 3) {
      server = pc[p];
    }else assert(0);
  }
  vector<string> vec;
  Node* n = server;
  while (true) {
    if (n == &top) break;
    vec.push_back(move(n->s));
    n = n->prev;
  }
  reverse(ALL(vec));
  REPOUT(i, 0, ssize(vec), vec[i], "");

  return 0;
}


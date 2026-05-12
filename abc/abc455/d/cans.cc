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
  Node* prev = nullptr;
  Node* next = nullptr;
};


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;

  vector<Node*> card(N);
  vector<Node*> pos(N);
  REP(i, 0, N) {
    card[i] = new Node;
    pos[i] = new Node;
    pos[i]->next = card[i];
    card[i]->prev = pos[i];
  }

  REP(_q, 0, Q) {
    ll c, p; cin >> c >> p; c--; p--;
    card[c]->prev->next = nullptr;
    card[c]->prev = card[p];
    card[p]->next = card[c];
  }
  vector<ll> ans(N);
  REP(i, 0, N) {
    ll cnt = 0;
    for (Node* p = pos[i]->next; p != nullptr; p = p->next) cnt++;
    ans[i] = cnt;
  }
  REPOUT(i, 0, N, ans[i], " ");

  return 0;
}


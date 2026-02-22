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

  ll N, Q; cin >> N >> Q;
  vector<ll> box_of_pegion(N);
  vector<ll> box_at_pos(N);
  vector<ll> pos_of_box(N);
  REP(i, 0, N) {
    box_of_pegion[i] = i;
    box_at_pos[i] = i;
    pos_of_box[i] = i;
  }
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll a, b; cin >> a >> b; a--; b--;
      box_of_pegion[a] = box_at_pos[b];
    }else if (tp == 2) {
      ll a, b; cin >> a >> b; a--; b--;
      ll aa = box_at_pos[a];
      ll bb = box_at_pos[b];
      swap(box_at_pos[a], box_at_pos[b]);
      swap(pos_of_box[aa], pos_of_box[bb]);
    }else if (tp == 3) {
      ll a; cin>> a; a--;
      cout << pos_of_box[box_of_pegion[a]] + 1 << "\n";
    }else assert(0);
  }

  return 0;
}


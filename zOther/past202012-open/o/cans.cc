#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  auto nbr = vector(N + 1, vector<ll>());
  auto busy_nbr = vector(N + 1, vector<ll>());
  for (ll i = 0; i < M; i++) {
    ll a, b; cin >> a >> b;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  ll thr = sqrt(M);
  vector<bool> busy(N + 1);
  for (ll i = 1; i <= N; i++) if ((ll)nbr[i].size() > thr) busy[i] = true;
  for (ll i = 1; i <= N; i++) {
    for (ll p : nbr[i]) if (busy[p]) busy_nbr[i].push_back(p);
  }
  ll Q; cin >> Q;
  vector<ll> read(N + 1);
  vector<ll> received(N + 1);
  vector<ll> sent(N + 1);
  for (; Q > 0; Q--) {
    ll t, x; cin >> t >> x;
    if (t == 1) {
      sent[x]++;
      for (ll p : busy_nbr[x]) received[p]++;
    }else if (t == 2) {
      ll allrcv = 0;
      if (busy[x]) {
        allrcv = received[x];
      }else {
        for (ll p : nbr[x]) {
          allrcv += sent[p];
        }
      }
      cout << allrcv - read[x] << endl;
      read[x] = allrcv;
    }
  }
  

  return 0;
}


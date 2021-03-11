#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> H(N);
  for (ll i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  using Tuple = tuple<ll, ll, ll>;
  vector<Tuple> sem;
  for (ll i = 0; i < N; i++) {
    ll m, s, e; cin >> m >> s >> e;
    sem.emplace_back(s, e, m);
  }
  sort(sem.begin(), sem.end());

  auto dotest = [&](ll x) -> ll {
    ll lastm = -1;
    ll seq = 0;
    ll t = 0;
    ll score = 0;
    for (ll i = 0; i < N; i++) {
      if (!((x >> i) & 1)) continue;
      ll s, e, m; tie(s, e, m) = sem.at(i);
      if (s < t) continue;
      if (lastm == m) {
	seq++;
	score += H.at(seq);
	t = e;
      }else {
	seq = 0;
	score += H.at(seq);
	lastm = m;
	t = e;
      }
    }
    return score;
  };

  ll ans = 0;
  for (ll x = 0; x < (1<<N); x++) {
    ans = max(ans, dotest(x));
  }
  cout << ans << endl;
  
}


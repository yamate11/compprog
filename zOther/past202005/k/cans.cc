#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  vector<ll> desk_bot(N+1), desk_top(N+1), cont_next(N+1), cont_prev(N+1);
  for (ll i = 1; i <= N; i++) {
    desk_bot.at(i) = i;
    desk_top.at(i) = i;
    cont_next.at(i) = 0;
    cont_prev.at(i) = 0;
  }
  for (ll q = 0; q < Q; q++) {
    ll f, t, x; cin >> f >> t >> x;
    ll pr = cont_prev.at(x);
    ll move_top = desk_top.at(f);
    ll old_to_top = desk_top.at(t);
    desk_top.at(f) = pr;
    if (x == desk_bot.at(f)) desk_bot.at(f) = 0;
    cont_next.at(pr) = 0;
    desk_top.at(t) = move_top;
    if (desk_bot.at(t) == 0) desk_bot.at(t) = x;
    cont_next.at(old_to_top) = x;
    cont_prev.at(x) = old_to_top;
  }
  
  vector<ll> ans(N+1);
  for (ll i = 1; i <= N; i++) {
    for (ll x = desk_bot.at(i); x > 0; x = cont_next.at(x)) {
      ans.at(x) = i;
    }
  }
  for (ll i = 1; i <= N; i++) cout << ans.at(i) << "\n";

  return 0;
}


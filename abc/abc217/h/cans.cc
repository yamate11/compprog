#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll minf = 0;
  priority_queue<ll, vector<ll>, greater<ll>> posf;
  priority_queue<ll> negf;
  ll shift = 0;
  auto push_pos = [&](ll x) -> void { if (x < shift) posf.push(x - shift); };
  auto push_neg = [&](ll x) -> void {                negf.push(x + shift); };
  auto top_pos = [&]() -> ll { return posf.top() + shift; };
  auto top_neg = [&]() -> ll { return negf.top() - shift; };
  auto pop_pos = [&]() -> void { if (posf.top() != 0) posf.pop(); };
  auto pop_neg = [&]() -> void { if (negf.top() != 0) negf.pop(); };
  posf.push(0);
  negf.push(0);
  for ( ; N > 0; N--) {
    ll t, d, x; cin >> t >> d >> x;
    shift = t;
    if (d == 0) {
      ll y = top_pos();
      if (x <= y) {
        push_neg(x);
      }else {
        minf += x - y;
        push_pos(x);
        pop_pos();
        push_neg(y);
      }
    }else if (d == 1) {
      ll y = top_neg();
      if (y <= x) {
        push_pos(x);
      }else {
        minf += y - x;
        push_neg(x);
        pop_neg();
        push_pos(y);
      }
    }
  }
  cout << minf << endl;

  return 0;
}


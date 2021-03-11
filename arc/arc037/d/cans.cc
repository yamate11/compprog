#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

constexpr ll MOD = ll(1e9) + 7;

ll add(ll x, ll y) { return (x + y) % MOD; }
ll sub(ll x, ll y) { return (MOD + x - y) % MOD; }
ll mul(ll x, ll y) { return (x * y) % MOD; }
ll sq(ll x) { return mul(x, x); }
ll tr(ll x) { return mul(x, sq(x)); }

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll L; cin >> L;
  vector<ll> p(L+1), q(L+1), r(L+1), s(L+1), u(L+1);
  p.at(0) = q.at(0) = u.at(0) = r.at(0) = s.at(0) = 1;
  for (ll i = 0; i < L; i++) {
    const ll pp = p.at(i);
    const ll qq = q.at(i);
    const ll rr = r.at(i);
    const ll ss = s.at(i);
    const ll uu = u.at(i);
    p.at(i+1) = add(mul(3, pp), tr(add(qq, uu)));
    q.at(i+1) = mul(qq, sub(sq(add(rr, ss)), sq(ss)));
    u.at(i+1) = add(sq(add(qq, uu)), mul(uu, sub(sq(add(rr, ss)), sq(ss))));
    r.at(i+1) = add(mul(rr, sub(sq(add(qq, uu)), sq(qq))), sq(add(rr, ss)));
    s.at(i+1) = mul(ss, sub(sq(add(qq, uu)), sq(qq)));
  }
  cout << p.at(L) << endl;

  return 0;
}


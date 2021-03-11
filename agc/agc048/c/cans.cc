#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

struct MyExc : exception {};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, L; cin >> N >> L;
  vector<ll> A(N + 2), B(N + 2);
  for (ll i = 1; i <= N; i++) cin >> A[i];
  for (ll i = 1; i <= N; i++) cin >> B[i];
  A[0] = B[0] = 0;
  A[N+1] = B[N+1] = L+1;

  auto func = [&](ll st, ll en, ll dir) -> ll {
    ll ret = 0;

    if (dir > 0) {

      if (B[en] + 1 != B[en + 1]) return -1;
      ll p = st;
      ll q = st;
      while (p <= en) {
	while (q <= en && B[p] != A[q] - (q - p)) q++;
	ret += q - p;
	while (p < q   && B[p] == A[q] - (q - p)) p++;
      }
      return ret;

    }else {

      if (B[st] - 1 != B[st - 1]) return -1;

      ll p = en;
      ll q = en;
      while (p >= st) {
	while (q >= st && B[p] != A[q] + (p - q)) q--;
	ret += p - q;
	while (q < p   && B[p] == A[q] + (p - q)) p--;
      }
      return ret;
    }
  };

  ll st = 0;
  ll ans = 0;
  ll dir = 0;
  try {
    for (ll i = 0; i < N + 2; i++) {
      if (A[i] == B[i]) {
	if (st < i) {
	  ans += func(st, i - 1, dir);
	}
	st = i + 1;
      }else if (i == st) {
	if (B[i] < A[i]) dir = -1;
	else             dir = 1;
      }else if (dir == 1 && B[i] < A[i]) {
	throw MyExc();
      }else if (dir == -1 && B[i] > A[i]) {
	ans += func(st, i - 1, dir);
	st = i;
	dir = 1;
      }
    }
    cout << ans << endl;
  }catch(const MyExc& e) {
    cout << -1 << endl;
  }

  return 0;
}


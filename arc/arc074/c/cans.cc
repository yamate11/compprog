#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

ll cmp3(ll P1, ll P2, ll Q1, ll Q2) {
  ll s1 = P1 * (Q1 + Q2);
  ll s2 = P2 * Q1;
  ll s3 = P2 * Q2;
  ll smax = max(s1, max(s2, s3));
  ll smin = min(s1, min(s2, s3));
  return smax - smin;
}

ll chk(ll c, ll P, ll Q) {
  c = min(c, cmp3(P/3, P - P/3, Q/2, Q - Q/2));
  c = min(c, cmp3(P/3 + 1, P - P/3 - 1, Q/2, Q - Q/2));
  return c;
}

ll solve() {
  ll H, W; cin >> H >> W;
  if (H % 3 == 0) return 0;
  if (W % 3 == 0) return 0;
  ll c = min(H, W);
  c = chk(c, H, W);
  c = chk(c, W, H);
  return c;
}


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}


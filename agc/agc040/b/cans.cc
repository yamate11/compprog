#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<int> L(N), R(N);
  for (int i = 0; i < N; i++) cin >> L.at(i) >> R.at(i);
  vector<int> ord(N);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(),
       [&](int x, int y) {
	 if (L.at(x) == L.at(y)) { return R.at(x) > R.at(y); }
	 return L.at(x) < L.at(y);
       });
  vector<int> vec(N);
  int iv = 0;
  vec.at(iv++) = 0;
  for (int i = 1; i < N; i++) {
    while (iv > 0 && R.at(ord.at(vec.at(iv-1))) >= R.at(ord.at(i))) {
      iv--;
    }
    vec.at(iv++) = i;
  }
  if (iv == 1) {
    int i0 = vec.at(0);
    int minLen = R.at(ord.at(i0)) - L.at(ord.at(i0)) + 1;
    int xmax = 0;
    for (int i = 0; i < N; i++) {
      if (i == i0) continue;
      xmax = max(xmax, R.at(ord.at(i)) - L.at(ord.at(i)) + 1);
    }
    cout << minLen + xmax << endl;
    return 0;
  }

  int xmax = 0;
  int xmaxArg = 0;
  for (int i = 0; i < N; i++) {
    int thisLen = R.at(i) - L.at(i) + 1;
    if (thisLen > xmax) {
      xmax = thisLen;
      xmaxArg = i;
    }
  }
  int rr0 = (int)(1e9) + 10;
  int ll0 = 0;
  for (int i = 0; i < N; i++) {
    if (i == xmaxArg) continue;
    rr0 = min(rr0, R.at(i));
    ll0 = max(ll0, L.at(i));
  }
  int zLen = max(0, rr0 - ll0 + 1);

  int ymax = 0;
  int rrr = R.at(ord.at(vec.at(0)));
  int lll = L.at(ord.at(vec.at(iv-1)));
  for (int i = 0; i < iv-1; i++) {
    int len1 = rrr - L.at(ord.at(vec.at(i))) + 1;
    int len2 = R.at(ord.at(vec.at(i+1))) - lll + 1;
    int thisLen = max(0, len1) + max(0, len2);
    ymax = max(ymax, thisLen);
  }
  cout << max(ymax, xmax + zLen) << endl;

  return 0;
}


#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

ll solve() {
  ll R, B, x, y; cin >> R >> B >> x >> y;
  if (x * B <= R) return B;
  if (y * R <= B) return R;
  double p = ((double)R * y - B) / ((double)x * y -1.0);
  ll pp0 = floor(p);
  ll pp1 = ceil(p);
  ll qq0 = (B - pp0) / y;
  ll qq1 = R - x * pp1;
  return max(pp0 + qq0, pp1 + qq1);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}


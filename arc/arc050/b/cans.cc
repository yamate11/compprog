#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

using namespace boost::multiprecision;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  cpp_int R, B; cin >> R >> B;
  cpp_int x, y; cin >> x >> y;
  
  cpp_int ans;
  cpp_int rR = x * B - R;
  cpp_int rB = y * R - B;
  cpp_int d = x * y - 1;
  if (rR <= 0)      ans = B;
  else if (rB <= 0) ans = R;
  else              ans = rR / d + rB / d;

  cout << ans << endl;

  return 0;
}


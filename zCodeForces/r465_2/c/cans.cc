#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll R, x1, y1, x2, y2; cin >> R >> x1 >> y1 >> x2 >> y2;
  ll dx = x2 - x1;
  ll dy = y2 - y1;
  if (R*R <= dx*dx + dy*dy) {
    cout << x1 << " " << y1 << " " << R << endl;
    return 0;
  }
  double x_ans, y_ans, r_ans;
  if (x1 == x2 && y1 == y2) {
    r_ans = R / 2.0;
    x_ans = x1 + r_ans;
    y_ans = y1;
  }else {
    double d = sqrt(dx * dx + dy * dy);
    double x3 = x1 - dx / d * R;
    double y3 = y1 - dy / d * R;
    x_ans = (x2 + x3) / 2.0;
    y_ans = (y2 + y3) / 2.0;
    r_ans = (d + R) / 2.0;
  }
  cout << x_ans << " " << y_ans << " " << r_ans << endl;


  return 0;
}


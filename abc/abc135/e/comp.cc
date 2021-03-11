#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> ans;
long long k, x, y;
bool swaped, x_fliped, y_fliped;
int type;
void out() {
  cout << ans.size() << endl;
  for (auto i : ans) cout << i.first << " " << i.second << '\n';
  exit(0);
}
void check_possibility() {
  if (k % 2 == 0 && (x + y) % 2 == 1) {
    cout << -1 << endl;
    exit(0);
  }
}
void restore() {
  if (swaped) for (auto& i : ans) swap(i.first, i.second);
  if (x_fliped) for (auto& i : ans) i.first *= -1;
  if (y_fliped) for (auto& i : ans) i.second *= -1;
}
void normalize() {
  if (x < 0) x *= -1, x_fliped = true;
  if (y < 0) y *= -1, y_fliped = true;
  if (x < y) swap(x, y), swaped = true;
}
long long get_steps() {
  if (k > x + y) {
    if ((x + y) % 2 == 0) {
      type = 1;
      return 2;
    } else {
      type = 3;
    }
  } else {
    long long res = (k + x + y - 1) / k;
    if ((k * res) % 2 != (x + y) % 2) res++;
    type = 1;
    return res;
  }
}
void build_1(long long steps) {
  long long extra = -(steps * k - x - y) / 2;
  //cerr << extra << endl;
  long long cur_x = 0, cur_y = 0;
  while (cur_y > extra) {
    long long dy = min(k, abs(extra - cur_y));
    long long dx = k - dy;
    cur_x += dx;
    cur_y -= dy;
    ans.emplace_back(cur_x, cur_y);
  }
  while (cur_x < x) {
    long long dx = min(k, abs(x - cur_x));
    long long dy = k - dx;
    cur_x += dx;
    cur_y += dy;
    ans.emplace_back(cur_x, cur_y);
  }
  while (cur_y < y) {
    long long dy = min(k, abs(y - cur_y));
    long long dx = k - dy;
    cur_x += dx;
    cur_y += dy;
    ans.emplace_back(cur_x, cur_y);
  }
}
void build_2() {
  ans.emplace_back(x, -(k - x));
  ans.emplace_back(x + (k + x - y) / 2, -(k - x) + k - (k + x - y) / 2);
  ans.emplace_back(x, y);
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> k >> x >> y;
  normalize();
  check_possibility();
  long long steps = get_steps();
  if (type == 1) build_1(steps);
  else build_2();
  //cerr << steps << " " << type << endl;
  restore();
  out();
  return 0;
}

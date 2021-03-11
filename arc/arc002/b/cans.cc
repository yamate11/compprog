#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

vector<ll> mday({0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});

ll lastDay(ll& y, ll& m) {
  if (m != 2) return mday.at(m);
  if (y % 400 == 0) return 29;
  if (y % 100 == 0) return 28;
  if (y % 4 == 0) return 29;
  return 28;
}

void next(ll& y, ll& m, ll& d) {
  if (d < lastDay(y, m)) {
    d++;
    return;
  }
  d = 1;
  if (m < 12) {
    m++;
    return;
  }
  m = 1;
  y++;
  return;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s; cin >> s;
  ll y = stoi(s.substr(0, 4));
  ll m = stoi(s.substr(5, 7));
  ll d = stoi(s.substr(8, 10));
  while (true) {
    if (y % (m*d) == 0) {
      cout << y
	   << '/'
	   << setw(2) << setfill('0') << m
	   << '/'
	   << setw(2) << setfill('0') << d << endl;
      return 0;
    }
    next(y, m, d);
  }

  return 0;
}


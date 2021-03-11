#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


long long iSqrt(long long x) {
  long t = sqrt((long double)x);
  if (t*t <= x && x < (t+1)*(t+1)) return t;
  long long p = t;
  long long w = 1;
  while (x < p*p) {
    p -= w;
    w *= 2;
  }
  long long q = t;
  w = 1;
  while (q*q <= x) {
    q += w;
    w *= 2;
  }
  while (q - p > 1) {
    long long mid = (p + q) / 2;
    if (mid*mid <= x) p = mid;
    else              q = mid;
  }
  return p;

}


int main() {
  cout << setprecision(20);


  ll x1 = 4e8+72813;
  ll x = x1*x1 - 10;
  ll y = iSqrt(x);
  cout << "iSqrt(" << x << ") = " << y << "\n";

}

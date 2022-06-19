#include <bits/stdc++.h>
using namespace std;

string S;

long long func(long long t, long long k) {
  if (k == 0 or t == 0) return S[k] - 'A' + t;
  return func(t - 1, k >> 1) + 1 + (k & 1);
}

int main() {
  cin >> S;
  long long Q; cin >> Q;
  while (--Q >= 0) {
    long long t, k; cin >> t >> k; k--;
    cout << (char)('A' + func(t, k) % 3) << "\n";
  }
  return 0;
}


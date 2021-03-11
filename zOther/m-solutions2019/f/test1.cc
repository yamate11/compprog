#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main() {
  int N = 2000;
  ll x = 0;
  ll y = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - i; j++) {
      for (int k = 0; k < N; k++) {
	x = 1 - x;
	y++;
      }
    }
  }
  cout << x << ", " << y << endl;
}

#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N);
  vector<ll> rank(N+1);
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a; a--;
    A.at(i) = a;
    rank.at(a) = i;
  }
  rank.at(N) = -1;
  vector<char> c(N);
  char cc = 'A';
  c.at(A.at(0)) = cc;
  for (ll i = 1; i < N; i++) {
    ll rPrev = rank.at(A.at(i-1) + 1);
    ll rCur = rank.at(A.at(i) + 1);
    if (rPrev < rCur) {
      c.at(A.at(i)) = cc;
    }else {
      if (cc == 'Z') {
	cout << -1 << endl;
	return 0;
      }
      c.at(A.at(i)) = ++cc;
    }
  }
  for (ll i = 0; i < N; i++) {
    cout << c.at(i);
  }
  cout << endl;

  return 0;
}


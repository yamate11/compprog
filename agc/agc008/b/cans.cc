#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, K; cin >> N >> K;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  
  ll c = 0;
  for (int i = 0; i < K; i++) c += A.at(i);
  ll p = 0;
  for (int i = K; i < N; i++) if (A.at(i) > 0) p += A.at(i);
  ll score = max(c, 0LL) + p;
  for (int i = 0; i + K < N; i++) {
    if (A.at(i) > 0) p += A.at(i);
    if (A.at(i+K) > 0) p -= A.at(i+K);
    c += A.at(i+K) - A.at(i);
    score = max(score, max(c, 0LL) + p);
  }
  cout << score << endl;

  return 0;
}


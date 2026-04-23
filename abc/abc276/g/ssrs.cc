#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
vector<int> c = {1, 2, 3, 2, 1};
int main(){
  int N, M;
  cin >> N >> M;
  int mx = N + M / 3;
  vector<long long> inv(mx + 1);
  inv[1] = 1;
  for (int i = 2; i <= mx; i++){
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
  }
  vector<long long> fact(mx + 1);
  vector<long long> finv(mx + 1);
  fact[0] = 1;
  finv[0] = 1;
  for (int i = 1; i <= mx; i++){
    fact[i] = fact[i - 1] * i % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
  vector<long long> f(N * 2 + 3, 0);
  for (int i = 0; i <= N - 1; i++){
    for (int j = 0; j < 5; j++){
      f[i + j + N - 1] += fact[N - 1] * finv[i] % MOD * finv[N - 1 - i] % MOD * c[j];
      f[i + j + N - 1] %= MOD;
    }
  }
  long long ans = 0;
  for (int i = 0; i * 3 <= M; i++){
    if (M - i * 3 <= N * 2 + 2){
      ans += f[M - i * 3] * fact[i + N] % MOD * finv[i] % MOD * finv[N] % MOD;
    }
  }
  ans %= MOD;
  cout << ans << endl;
}

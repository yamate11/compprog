#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpVec(M, C) [92E5S0fB]
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; C[i] = v; }
  // @End [92E5S0fB]

  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }

  auto func = [&]() -> double {
    ll k = 0;
    ll a = 0;
    if (N % 2 == 1) {

      while (a + C[k] <= N / 2) {
        a += C[k];
        k++;
      }
      ll pre = C[k] - (N / 2 - a);
      ll post = C[k] - pre - 1;
      ll median, thisCellVal;
      if (2 * (post + 1) < N) {
        median = k + 1;
        thisCellVal = pre * k + (post + 1) * (k + 1);
      }else {
        median = k;
        thisCellVal = (pre + post + 1) * k;
      }
      ll s = 0;
      REP(i, 0, M) {
        if (i == k) s += thisCellVal;
        else s += C[i] * i;
      }
      double mean = (double)s / N;
      return max(0.0, median - mean);

    }else {

      while (a + C[k] <= N / 2 - 1) {
        a += C[k];
        k++;
      }
      if (a + C[k] > N / 2) {
        ll pre = C[k] - (N / 2 - 1 - a);
        ll post = C[k] - pre - 1;
        ll median, thisCellVal;
        if (2 * (post + 1) < N) {
          median = k + 1;
          thisCellVal = pre * k + (post + 1) * (k + 1);
        }else {
          median = k;
          thisCellVal = (pre + post + 1) * k;
        }
        ll s = 0;
        REP(i, 0, M) {
          if (i == k) s += thisCellVal;
          else s += C[i] * i;
        }
        double mean = (double)s / N;
        return max(0.0, median - mean);

      }else {

        



      }




    }



    


  };

  double x1 = func();
  reverse(ALL(C));
  double x2 = func();
  cout << max(x1, x2) << endl;

  return 0;
}


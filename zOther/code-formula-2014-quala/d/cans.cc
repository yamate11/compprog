#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  string K; cin >> K;
  ll numNoRem = 36LL - (ll)K.size();
  vector<bool> rem(128);
  for (ll i = 0; i < (ll)K.size(); i++) rem.at(K.at(i)) = true;
  vector<bool> seen(128);
  ll fixed = 0;
  ll unc = 0;
  for (ll i = 0; i < (ll)S.size(); i++) {
    char c = S.at(i);
    if (rem.at(c) || seen.at(c)) fixed += 1;
    else {
      unc++;
      seen.at(c) = true;
    }
  }

  vector tbl(unc + 1, vector(numNoRem - unc + 1, -1.0));
  auto calc = [&](const auto& rF, ll len, ll nnr) -> double {
    double& val = tbl.at(len).at(nnr);
    if (val < 0) {
      if (len == 0) val = 0.0;
      else {

	double q1 = 0.0, q2 = 0.0, q3 = 0.0;
	double p1 = 1.0 / (len + nnr);
	ll e1 = 1;
	double r1 = rF(rF, len - 1, nnr);
	q1 = p1 * (e1 + r1);

	if (len > 1) {
	  double p2 = (len - 1.0) / (len + nnr);
	  ll e2 = 3;
	  double r2 = rF(rF, len - 1, nnr);
	  q2 = p2 * (e2 + r2);
	}
	if (nnr > 0) {
	  double p3 = double(nnr) / (len + nnr);
	  ll e3 = 2;
	  double r3 = rF(rF, len, nnr - 1);
	  q3 = p3 * (e3 + r3);
	}
	val = q1 + q2 + q3;
      }
    }
    return val;
  };

  cout << calc(calc, unc, numNoRem - unc) + fixed << endl;
  

  return 0;
}


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
  vector<string> S(N);
  for (ll i = 0; i < N; i++) cin >> S.at(i);
  sort(S.begin(), S.end(),
       [](string a, string b) -> bool {
	 string ra(a);
	 string rb(b);
	 reverse(ra.begin(), ra.end());
	 reverse(rb.begin(), rb.end());
	 return ra < rb;
       });
  for (string s : S) {
    cout << s << "\n";
  }

  return 0;
}


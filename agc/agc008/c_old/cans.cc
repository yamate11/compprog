#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll ai, ao, at, aj, al, as, az;
  cin >> ai >> ao >> at >> aj >> al >> as >> az;
  ll t = 0;
  t += (ai / 2) * 2;
  t += ao;
  t += (aj / 2) * 2;
  t += (al / 2) * 2;
  ll bi = ai % 2;
  ll bj = aj % 2;
  ll bl = al % 2;
  if (bi + bj + bl == 3) {
    t += 3;
  }else if ((bi == 1 && bj == 1 && al >= 2) ||
	    (bj == 1 && bl == 1 && ai >= 2) ||
	    (bl == 1 && bi == 1 && aj >= 2)) {
    t += 1;
  }


  cout << t << endl;

  return 0;
}


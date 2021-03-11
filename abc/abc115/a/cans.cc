#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

string solve() {
  int D; cin >> D;
  if (D == 25) return "Christmas";
  if (D == 24) return "Christmas Eve";
  if (D == 23) return "Christmas Eve Eve";
  if (D == 22) return "Christmas Eve Eve Eve";
  assert(false);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;
	   

  return 0;
}


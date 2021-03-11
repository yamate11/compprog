#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

string solve() {
  int N; cin >> N;
  int A, B; cin >> A >> B;
  if (A == B) {
    if (N % (A+1) == 0) return "Aoki";
    else return "Takahashi";
  }else if (A > B) {
    return "Takahashi";
  }else if (A < B) {
    if (N <= A) return "Takahashi";
    else return "Aoki";
  }else assert(false);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}


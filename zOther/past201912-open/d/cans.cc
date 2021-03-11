#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<int> a(N+1);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    a.at(x)++;
  }
  int dup = -1;
  int none = -1;
  for (int i = 1; i <= N; i++) {
    if (a.at(i) == 0) none = i;
    else if (a.at(i) == 2) dup = i;
  }
  if (dup < 0) {
    cout << "Correct" << endl;
  }else {
    cout << dup << " " << none << endl;
  }

  return 0;
}


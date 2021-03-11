#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main() {
  int N; cin >> N;
  priority_queue<int> que;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    que.push(x);
  }
  int s = 0;
  while (!que.empty()) {
    s += que.top();
    que.pop();
  }
  cout << N << " " << s << endl;
}


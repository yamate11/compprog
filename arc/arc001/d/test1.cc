#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

void foo(deque<ll> q, auto m) {
  m();
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  deque<ll> q;
  q.push_back(3);
  q.push_front(5);
  cout << q.front() << ", ";
  foo(q, &q.pop_front);
  // q.pop_front();
  cout << q.front() << endl;
  q.pop_back();
  return 0;
}

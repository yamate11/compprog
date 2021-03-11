#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DSTR(...) func({__VA_ARGS__})

void func(vector<string> ss) {
  for (string s : ss) {
    cerr << s << " ";
  }
  cerr << endl;
}

template <class Head>
void foo(Head&& head) {
  cerr << head << endl;
}

template <class Head, class... Tail>
void foo(Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  foo(forward<Tail>(tail)...);
}

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
  os << '[';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << ']';

  return os;
}

template <typename T, typename T2, typename T3>
vector<T> pqToVector(const priority_queue<T, T2, T3>& orig) {
  priority_queue<T, T2, T3> pq(orig);
  vector<T> ret;
  while (!pq.empty()) {
    T x = pq.top(); pq.pop();
    ret.push_back(x);
  }
  return ret;
}

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig) {
  priority_queue<T, T2, T3> pq(orig);
  bool first = true;
  os << '[';
  while (!pq.empty()) {
    T x = pq.top(); pq.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

int main() {
  string s1("hello");
  string s2("world");
  // DSTR(s1, s2, "there");
  foo(s1, s2, "there", make_pair(2, 5));
  foo(10);
  foo("Bye");
  ll x = 1L << 40;
  int y = 1 << 15;
  vector<vector<int>> v1({{2}, {5}});
  v1.push_back({8, -2, 7});
  v1.push_back({4, 0});
  foo(x, y, v1);
  int special = 4;
  auto comp = [&](int p, int q) -> bool {
    if (p != special && q == special) return true;
    if (p == special) return false;
    return p < q;
  };
  // priority_queue<int, vector<int>, greater<int>> pq;
  // priority_queue<int> pq;
  priority_queue<int, vector<int>, decltype(comp)> pq(comp);
  pq.push(4), pq.push(10), pq.push(1), pq.push(20), pq.push(35);
  // foo(pqToVector(pq));
  foo(pq);

  return 0;
}

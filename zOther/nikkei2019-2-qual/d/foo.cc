#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


typedef pair<ll,ll> Pair;

bool operator<(const Pair p1, const Pair p2) {
  if (p1.first < p2.first) return true;
  if (p1.first > p2.first) return false;
  return p1.second < p2.second;
}

int main(int argc, char *argv[]) {
  set<Pair> theS;
  // theS.emplace(1, 0);
  auto it = theS.lower_bound(0LL);
}

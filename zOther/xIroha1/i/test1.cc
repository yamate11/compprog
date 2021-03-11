#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DLOG(...)
#endif

int main() {
  vector<unordered_map<int, vector<int>>> vec;
  vec.resize(10);
  vec.at(0)[1].push_back(2);
  for (auto x: vec.at(0).at(1)) {
    cout << x << endl;
  }
}

#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


/*
template <class T>
auto atOne(vector<T>& collection) {
  auto it = collection.begin();
  advance(it, 1);
  return it;
}
*/

int main() {
  vector<int> v1 = {-99, 20, 1, 2, 3, 4, 5};
  sort(v1.begin()+1, v1.end());
  for (int i = 0; i < (int) v1.size(); i++) {
    cout << v1.at(i) << endl;
  }
}

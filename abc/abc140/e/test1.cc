#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main() {
  set<int> s({10, 12, 18, 20});
  int x = 17;

  for (auto it = s.lower_bound(x); it != s.end(); it++) cout << *it << endl;
  
  cout << "--\n";
  
  auto it0 = s.upper_bound(x);
  auto revit = reverse_iterator<set<int>::iterator>(it0);
  for (; revit != s.rend(); revit++) cout << *revit << endl;

  /*
  auto it = s.insert(15).first;
  auto revit = reverse_iterator<set<int>::iterator>(it);
  for (; revit != s.rend(); revit++) {
    cout << *revit << endl;
  }
  */
}

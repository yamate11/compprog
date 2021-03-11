#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


class Edge : public pair<int, int> {
public:
  Edge() : pair<int, int>() {}
  Edge(const int& x, const int& y) : pair<int, int>(x, y) {}
  Edge(istream& stream, int shift) {
    stream >> this->first >> this->second;
    this->first -= shift;
    this->second -= shift;
  }
};


int main() {
  Edge x(cin, 1);
  Edge y {4, 2};
  Edge z;
  z.first = 1000;
  z.second = 50;
  cout << x.second << " " << x.first << endl;
  cout << y.second << " " << y.first << endl;
  cout << z.second << " " << z.first << endl;
  return 0;
}

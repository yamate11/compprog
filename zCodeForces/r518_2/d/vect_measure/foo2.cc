#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using namespace std::chrono;

int main(int argc, char** argv) {
  for (int i = 1; i < 21; i++) {
    int size = 1 << i;
    vector<int> x(size);
    vector<vector<long long>> y(size);
    cout << i << " " << sizeof(x) << " " << sizeof(y) << endl;

  }
  
  return 0;
}

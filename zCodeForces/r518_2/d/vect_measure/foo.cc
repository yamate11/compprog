#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using namespace std::chrono;

int main(int argc, char** argv) {
  int size = stoi(argv[1]);
  int rep = 1 << 20;
  vector x(rep, vector<int>(size));
  cout << sizeof(x) << endl;
  string s; cin >> s;
  return 0;
}

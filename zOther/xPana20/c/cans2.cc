#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  cpp_int a, b, c; cin >> a >> b >> c;
  if (c < a + b) {
    cout << "No\n";
    return 0;
  }
  cpp_int x = (a + b) * c * 2 + a * b * 4;
  cpp_int y = c * c + (a + b) * (a + b);
  cout << (x < y ? "Yes\n" : "No\n");

  return 0;
}


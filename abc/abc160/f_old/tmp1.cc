#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

ll foo(auto f) {
  ll x = f(0, 2);
  return x;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto g = [](ll t, ll s) -> ll { return t+s; };
  cout << foo(g);

}

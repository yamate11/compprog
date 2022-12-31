#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

struct A {
  vector<ll> vec;
  A() : vec(10) { for (int i = 0; i < 10; i++) vec[i] = i; }
  ll& at(ll i) {
    cout << "func 1" << endl;
    return vec[i];
  }
  /*
  const ll& at(ll i) const {
    cout << "func 2" << endl;
    return vec[i];
  }
  */
};


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  const A a;
  // a.at(3) = 30;
  ll b = a.at(5);
  cout << a.at(3) << " " << b << endl;

}

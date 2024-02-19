#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(binsearch)

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    vector<ll> vec1 {1, 4, 9, 10, 15, 18, 20};
    ll sz1 = vec1.size();
    ll lim1;
    auto check1 = [&](ll z) { return vec1.at(z) < lim1; };
    lim1 = 10;
    assert(binsearch(check1, -1LL, sz1) == 2);
    lim1 = 0;
    assert(binsearch(check1, -1LL, sz1) == -1);
    lim1 = 100;
    assert(binsearch(check1, -1LL, sz1) == 6);

    vec1 = vector<ll>({20, 18, 15, 10, 9, 4, 1});
    lim1 = 10;
    assert(binsearch(check1, sz1, -1LL) == 4);
    lim1 = 0;
    assert(binsearch(check1, sz1, -1LL) == 7);
    lim1 = 100;
    assert(binsearch(check1, sz1, -1LL) == 0);

    // avoiding unnecessary overflow
    ll z0 = LLONG_MAX - 100;
    auto check2 = [&](ll x) -> bool { return x <= z0; };
    auto check3 = [&](ll x) -> bool { return x >= z0; };
    ll x0 = binsearch(check2, z0 - 50, z0 + 50);
    assert(x0 == z0);
    ll x1 = binsearch(check3, z0 + 50, z0 - 50);
    assert(x1 == z0);

  }
  {
    auto check = [&](double x) { return x * x < 2; };
    double x0 = binsearch(check, 1.0, 2.0, 1e-6);
    assert(abs(sqrt(2) - x0) < 1e-6);

    auto check2 = [&](double x) { return x * x > 2; };
    double x1 = binsearch(check2, 2.0, 1.0, 1e-6);
    assert(abs(sqrt(2) - x1) < 1e-6);

    // https://rsk0315.hatenablog.com/entry/2020/04/29/155009
    auto check3 = [&](long double x) { return x <= 1e17L; };
    long double x3 = binsearch(check3, 0.0L, 1e18L, 1e-9L);
    assert(abs(x3 - 1e17L) < 1e-9L);

  }

  {
    auto check = [&](long double x) { return x * x < 2; };
    long double x0 = binsearch(check, 1.0L, 2.0L, 1e-17L);
    assert(abs(sqrt(2.0L) - x0) < 1e-17L);
  }
  


  cerr << "ok.\n";

}

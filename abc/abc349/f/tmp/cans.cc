#include <bits/stdc++.h>
#include <cassert>
using namespace std;

// Prime numbers up to 100.
// Note that their product is larger than 2^64.
vector<int> primes({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
      47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97});

// Returns the maximum number of divisors of number s such that
// t * s <= n and all prime divisors of s are greater than or equal
// to primes[i]
int num_div(long long int n, long long int t, int i) {
  int p = primes[i];
  int ret = 1;
  int r = 1;
  long long int q = p;   // q = p ^ r
  while (t * q <= n) {
    ret = max(ret, (r + 1) * num_div(n, t * q, i + 1));
    q *= p;
    r++;
  }
  return ret;
}

// Returns 10^n
long long int pow10(int n) {
  long long int ret = 1;
  while (n-- > 0) ret *= 10;
  return ret;
}

int main(/* int argc, char *argv[] */) {
  for (int k = 1; k <= 18; k++) {
    cout << "10^" << k << " " << num_div(pow10(k), 1, 0) << endl;
  }
  return 0;
}

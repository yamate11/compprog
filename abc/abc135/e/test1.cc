#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
using vector3 = vector<vector2<T>>;
template <typename T>
using vector4 = vector<vector3<T>>;
template <typename T>
using vector5 = vector<vector4<T>>;

template <typename T>
vector2<T> init2(int n1, int n2) {
  return vector2<T>(n1, vector<T>(n2));
}

template <typename T>
vector3<T> init3(int n1, int n2, int n3) {
  return vector3<T>(n1, init2<T>(n2, n3));
}

template <typename T>
vector4<T> init4(int n1, int n2, int n3, int n4) {
  return vector4<T>(n1, init3<T>(n2, n3, n4));
}

template <typename T>
vector5<T> init5(int n1, int n2, int n3, int n4, int n5) {
  return vector5<T>(n1, init4<T>(n2, n3, n4, n5));
}


constexpr int n1 = 10;
constexpr int n2 = 10;
constexpr int n3 = 10;
constexpr int n4 = 10;
constexpr int n5 = 10;


int main() {

  int n = 40;
  vector5<int> v = init5<int>(n, n, n, n, n);
  v.at(n-1).at(n-1).at(n-1).at(n-1).at(n-1) = n;

}

#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

string toString(auto v) {
  stringstream ss;
  ss << "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin())  ss << ", ";
    // if the value_type is not printable, modify the following line.
    ss << *it;
    // e.g., if it is a pair, use "ss << pairToString(*it)"
  }
  ss << "]";
  return ss.str();
}

string pairToString(auto p) {
  stringstream ss;
  ss << "(" << p.first << ":" << p.second << ")";
  return ss.str();
}

#define DEBUG 1

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#if DEBUG
  #define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DCALL(func, ...)
#endif

int main() {
  vector<ll> v = {1, 2, 3};
  DLOG("v = %s", toString(v, idconv).c_str());

  return 0;
}

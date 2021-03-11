#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

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


// Returns a const char* representation of a container, such as a vector.
// Works for a container whose iterator has begin() and end()
string toString(auto v) {
  stringstream ss;
  ss << "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin())  ss << ", ";
    ss << *it;
  }
  ss << "]";
  return ss.str();
}

vector<ll> toVector(auto q)
{
  vector<ll> v;
  while (!q.empty()) {
    v.push_back(q.top());
    q.pop();
  }
  return v;
}


ll Q;
vector<ll> p;
priority_queue<ll> small;
priority_queue<ll, vector<ll>, greater<ll>> large;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> Q;

  ll minX;
  ll minF;
  ll numP = 0;
  for (ll i = 0; i < Q; i++) {
    ll t, a, b;
    cin >> t;
    if (t == 1) {
      cin >> a >> b;
      numP++;
      if (numP == 1) {
	small.push(a);
	minX = a;
	minF = b;
      }else if (numP % 2 == 0) {
	if (small.top() < a) {
	  large.push(a);
	  minF += abs(minX - a) + b;
	}else {
	  ll oldMinX = small.top();
	  large.push(oldMinX);
	  small.pop();
	  small.push(a);
	  minX = small.top();
	  minF += abs(oldMinX - a) + b;
	}
      }else if (numP % 2 == 1) {
	if (a < large.top()) {
	  small.push(a);
	  minX = small.top();
	  minF += abs(minX - a) + b;
	}else {
	  minX = large.top();
	  small.push(minX);
	  large.pop();
	  large.push(a);
	  minF += abs(minX - a) + b;
	}
      }
      DLOG("small: %s", toString(toVector(small)).c_str());
      DLOG("large: %s", toString(toVector(large)).c_str());
    }else {
      cout << minX << " " << minF << endl;
    }
  }

  return 0;
}


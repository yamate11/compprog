#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<ll> vll;

#define X first
#define Y second
#define mk make_pair
#define psh push_back
#define all(a) a.begin(), a.end()

const int MOD = (int)1e6 + 7;
const ll LINF = (ll)1e18 + 7;
const int INF = (int)1e9 + 7;
const double eps = 1e-7;
const int MAXN = (int)1e6 + 7;
const double pi = acos(-1);

int main(){
  //freopen("C:\\Programs\\input.txt", "r", stdin);
  //freopen("C:\\Programs\\output.txt", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    int k;
    cin >> k;
    set <int> se1, se2;
    int f = 1;
    for (int j = 0; j < k; j++){
      int a;
      cin >> a;
      if (a > 0){
	se1.insert(a);
	if (se2.find(a) != se2.end()) f = 0;
      }
      else{
	se2.insert(-a);
	if (se1.find(-a) != se1.end()) f = 0;
      }
    }
    if (f){
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}



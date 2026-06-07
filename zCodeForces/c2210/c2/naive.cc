#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector <int> primes;
	vector <bool> s(501, true);
	for(int i = 2; i <= 500; i++){
		if(s[i]){
			primes.push_back(i);
			if(i * i <= 500){
				for(int j = i * i; j <= 500; j += i){
					s[j] = false;
				}
			}
		}
	}
    
    int t = 1;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector <int> a(n);
        for(int i = 0; i < n; i++){
			cin >> a[i];
        }
        
        vector <int> b(n);
        for(int i = 0; i < n; i++){
			cin >> b[i];
        }
        
        vector <int> c(n - 1), g(n), k(n);
		for(int i = 0; i < n - 1; i++){
			c[i] = __gcd(a[i], a[i + 1]);
		}
		
		g[0] = c[0];
		g[n - 1] = c[n - 2];
		for(int i = 1; i < n - 1; i++){
			g[i] = c[i - 1] / __gcd(c[i - 1], c[i]) * c[i];
		}
		
		for(int i = 0; i < n; i++){
			k[i] = a[i] / g[i];
		}
		
		int ans = 0;
		int i = 0;
		while(i < n){
			if(k[i] > 1){
				if(b[i] >= g[i]){
					ans += 1;
				}
				
				i += 1;
				continue;
			}
			
			vector <int> d;
			if(k[i] == 1){
				int val = b[i] / g[i];
				if(val >= 2){
					vector <int> tmp;
					if(i > 0){
						tmp.push_back(g[i - 1] / c[i - 1]);
						if(k[i - 1] > 1 && b[i - 1] < g[i - 1]){
							tmp.push_back(k[i - 1]);
						}
					}
					
					if(i + 1 < n){
						tmp.push_back(g[i + 1] / c[i]);
						if(k[i + 1] > 1 && b[i + 1] < g[i + 1]){
							tmp.push_back(k[i + 1]);
						}
					}
					
					for(int p : primes){
						if(p > val){
							break;
						}
						
						bool mark = true;
						for(int x : tmp){
							if(x % p == 0){
								mark = false;
								break;
							}
						}
						
						if(mark){
							d.push_back(p);
							if(d.size() == 3){
								break;
							}
						}
					}
				}
			}
			
			if(d.empty()){
				i += 1;
				continue;
			}
			
			vector <pair <int, int>> prev;
			prev.push_back({0, 0});
			while(i < n && k[i] == 1){
				d.clear();
				int val = b[i] / g[i];
				if(val >= 2){
					vector <int> tmp;
					if(i > 0){
						tmp.push_back(g[i - 1] / c[i - 1]);
						if(k[i - 1] > 1 && b[i - 1] < g[i - 1]){
							tmp.push_back(k[i - 1]);
						}
					}
					
					if(i + 1 < n){
						tmp.push_back(g[i + 1] / c[i]);
						if(k[i + 1] > 1 && b[i + 1] < g[i + 1]){
							tmp.push_back(k[i + 1]);
						}
					}
					
					for(int p : primes){
						if(p > val){
							break;
						}
						
						bool mark = true;
						for(int x : tmp){
							if(x % p == 0){
								mark = false;
								break;
							}
						}
						
						if(mark){
							d.push_back(p);
							if(d.size() == 3){
								break;
							}
						}
					}
				}
				
				if(d.empty()){
					break;
				}
				
				int max_val = -(1LL << 60);
				for(auto x : prev){
					max_val = max(max_val, x.second);
				}
				
				vector <pair <int, int>> cur;
				cur.push_back({0, max_val});
				for(int p : d){
					int best = -(1LL << 60);
					for(auto x : prev){
						if(x.first != p){
							best = max(best, x.second + 1);
						}
					}
					
					cur.push_back({p, best});
				}
				
				prev.swap(cur);
				i += 1;
			}
 
			int max_val = -(1LL << 60);
			for(auto x : prev){
				max_val = max(max_val, x.second);
			}
			
			ans += max_val;
		}
		
		cout << ans << '\n';
    }
    
    return 0;
}

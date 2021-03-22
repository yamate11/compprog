#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))
#define F first
#define S second

int main(){
    FAST
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int dec = -1;
        int inc = -1;
        bool ok = 1;
        for(int i = 0; i < n - 1; i++){
            if(arr[i] > arr[i + 1]){
                if(dec == -1)dec = arr[i] - arr[i + 1];
                else{
                    if(arr[i] - arr[i + 1] != dec)ok = 0;
                }
            }
            else{
                if(inc == -1)inc = arr[i + 1] - arr[i];
                else{
                    if(arr[i + 1] - arr[i] != inc)ok = 0;
                }
            }
        }
        if(!ok){
            cout << -1 << endl;
        }
        else if(inc == -1 || dec == -1){
            cout << 0 << endl;
        }
        else{
            for(int i = 0; i < n; i++){
                if(arr[i] >= inc + dec){
                    ok = 0;
                }
            }
            if(!ok){
                cout << -1 << endl;
            }
            else{
                cout << inc + dec << " " << inc << endl;
            }
        }
    }
    return 0;
}

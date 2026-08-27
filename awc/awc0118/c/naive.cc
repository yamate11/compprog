#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,M; cin >> N >> M;
    string s; cin >> s;
    if(s.size() < 7){cout << "0\n"; return 0;}
    string a = "ATCODER";
    vector<int> OK;
    for(int i=0; i<=N-a.size(); i++) if(s.substr(i,a.size()) == a) OK.push_back(i);
 
    vector<pair<int,int>> V;
    int L = -1,R = -1;
    for(int i=0; i<OK.size(); i++){
        int pos = OK.at(i);
        if(L != -1){
            if(R == pos) R += 7;
            else V.push_back({L,R}),L = pos,R = pos+7;
        }
        else L = pos,R = pos+7;
    }
    if(L != -1) V.push_back({L,R});

    if(V.size() == 0){cout << "0\n"; return 0;}
    {
        auto [l0,r0] = V.at(0);
        if(l0 == 0 && r0 == N){
            if(M >= (N-7)/7) cout << N/7 << "\n";
            else cout << M << "\n";
            return 0;
        }
    }
    int answer = 0;
    vector<int> Len;
    for(auto [l,r] : V){
        if(l == 0 || r == N){
            int now = min(M,(r-l)/7);
            answer += now,M -= now;
        }
        else Len.push_back({(r-l)/7});
    }
    sort(Len.rbegin(),Len.rend());
    for(auto len : Len){
        if(M == 0) break;
        M--;
        int now = min(M,len);
        answer += now,M -= now;
    }
    cout << answer << endl;
}

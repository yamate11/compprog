#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#include<atcoder/maxflow>
using namespace atcoder;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N,A,B;
    cin>>N>>A>>B;
    mf_graph<ll> M(N*N+2);
    vector<string> S(N);
    vector<vector<ll>> D(N,vector<ll>(N,-1));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(D[i][j]!=-1)continue;
            D[i][j]=0;
            queue<array<ll,2>> Q;
            Q.push({i,j});
            while(!Q.empty()){
                auto [y,x]=Q.front();
                Q.pop();
                for(int t=0;t<2;t++){
                    for(ll ny:{y-B,y+B}){
                        for(ll nx:{x-A,x+A}){
                            if(ny<0||ny>=N)continue;
                            if(nx<0||nx>=N)continue;
                            assert(D[ny][nx]!=D[y][x]);
                            if(D[ny][nx]!=-1)continue;   
                            D[ny][nx]=1-D[y][x];
                            Q.push({ny,nx});
                        }
                    }
                    swap(A,B);
                }
                
            }
        }
    }
    ll st=N*N;
    ll gl=N*N+1;
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++)cout<<D[i][j];
    //     cout<<endl;
    // }
    vector<array<ll,2>> EG;
    for(int i=0;i<N;i++)cin>>S[i];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(S[i][j]=='.'){
                if(D[i][j]==0){
                    M.add_edge(st,i*N+j,1);
                    EG.push_back({st,i*N+j});
                    ll y=i,x=j;
                    // cout<<y<< " "<<x<<endl;
                    for(int t=0;t<2;t++){
                        for(ll ny:{y-B,y+B}){
                            for(ll nx:{x-A,x+A}){
                                
                                if(ny<0||ny>=N)continue;
                                if(nx<0||nx>=N)continue;
                                if(S[ny][nx]=='.'){
                                    M.add_edge(y*N+x,ny*N+nx,1);
                                    EG.push_back({y*N+x,ny*N+nx});
                                }
                            }
                        }
                        swap(A,B);
                    }
                }
                else{
                    M.add_edge(i*N+j,gl,1);
                    EG.push_back({i*N+j,gl});
                }
            }
        }
    }
    ll p=M.flow(st,gl);
    // cout<<p<<endl;
    auto NEG=M.edges();
    vector<vector<ll>> G(N*N);
    queue<ll> que;
    for(auto neg:NEG){
        if(neg.from==st){
            if(neg.flow==0){
                // cout<<" "<<neg.to<<endl;
                que.push(neg.to);
            }
            continue;
        }
        if(neg.to==gl)continue;
        if(neg.flow==1){
            G[neg.to].push_back(neg.from);
        }
        else{
            G[neg.from].push_back(neg.to);
        }
    }
    vector<bool> seen(N*N,0);
    while(!que.empty()){

        ll p=que.front();
        que.pop();
        if(seen[p])continue;
        seen[p]=1;
        for(auto v:G[p]){
            if(!seen[v])que.push(v);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(S[i][j]=='#')continue;
            if(seen[i*N+j]){
                if(D[i][j]==0){
                    S[i][j]='o';
                }
            }
            else{
                if(D[i][j]==1){
                    S[i][j]='o';
                }
            }
        }
        // cout<<S[i]<<"\n";
    }

    ll cnt_o = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (S[i][j] == 'o') cnt_o++;
      }
    }

    vector<pair<int, int>> dirs{{-A, -B}, {-B, -A}, {-A, B}, {-B, A}, {A, -B}, {B, -A}, {A, B}, {B, A}};
    vector<string> SA(N);
    for (int i = 0; i < N; i++) cin >> SA[i];
    ll cnt_t = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (SA[i][j] == 'o') {
          cnt_t++;
          for (auto [di, dj] : dirs) {
            ll i1 = i + di;
            ll j1 = j + dj;
            if (0 <= i1 and i1 < N and 0 <= j1 and j1 < N and SA[i1][j1] == 'o') {
              cout << "NG\n";
              return 0;
            }
          }
        }
      }
    }
    if (cnt_o != cnt_t) {
      cout << "NG\n";
      return 0;
    }
    cout << "OK\n";
}

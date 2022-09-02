#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<iomanip>
#include<numeric>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<random>
#include<bitset>
#include<cassert>
#include<complex>
#include<fstream>
#include<cstdlib>
#include<functional>
#include<array>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int dx[]={1,1,1,0,0,-1,-1,-1},dy[]={1,0,-1,1,-1,1,0,-1};
int t,n,m,col[50][50];
string s[50];
vector<pair<int,int>>vec[2500];
void dfs(int x,int y){
	vec[col[x][y]].push_back({x,y});
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(0<=nx&&nx<n&&0<=ny&&ny<m&&s[nx][ny]=='*'&&col[nx][ny]==-1){
			col[nx][ny]=col[x][y];
			dfs(nx,ny);
		}
	}
}
int main(){
	cin>>t;
	while(cin>>n>>m){
		for(int i=0;i<2500;i++)
			vec[i].clear();
		for(int i=0;i<n;i++)
			cin>>s[i];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				col[i][j]=-1;
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(s[i][j]=='*'&&col[i][j]==-1){
					col[i][j]=cnt;
					dfs(i,j);
					cnt++;
				}
			}
		}
		bool ng=0;
		for(int i=0;i<cnt;i++){
			if(vec[i].size()!=3){
				ng=1;
				break;
			}
			bool ok1=0,ok2=0;
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					if(vec[i][j].first+1==vec[i][k].first&&vec[i][j].second==vec[i][k].second)
						ok1=1;
					if(vec[i][j].first==vec[i][k].first&&vec[i][j].second+1==vec[i][k].second)
						ok2=1;
				}
			}
			if(ok1&&ok2)
				continue;
			ng=1;
			break;
		}
		cout<<(!ng?"YES":"NO")<<endl;
	}
}

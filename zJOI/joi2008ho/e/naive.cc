#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;

int w;
int h;

int W;
int H;
int n;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

vector<int> xs,ys,xe,ye;

vector<int> X,Y;

int imos[3000][3000];


int main()
{
  cin >> w >> h;

  cin >> n;
  xs.resize(n);
  ys.resize(n);
  xe.resize(n);
  ye.resize(n);
  for(int i = 0;i < n;i++)
    {
      int x1,y1,x2,y2;
      cin >> x1 >> y1 >> x2 >> y2;

      xs[i] = x1;
      ys[i] = y1;
      xe[i] = x2;
      ye[i] = y2;

      X.push_back(x1);
      X.push_back(x2);
      Y.push_back(y1);
      Y.push_back(y2);
    }
  X.push_back(0);
  Y.push_back(0);
  X.push_back(w);
  Y.push_back(h);
  sort(X.begin(),X.end());
  sort(Y.begin(),Y.end());

  X.erase(unique(X.begin(),X.end()),X.end());
  Y.erase(unique(Y.begin(),Y.end()),Y.end());



  W = X.size() - 2;
  H = Y.size() - 2;
  for(int i = 0;i < n;i++)
    {
      int x1 = lower_bound(X.begin(),X.end(),xs[i]) - X.begin();
      int x2 = lower_bound(X.begin(),X.end(),xe[i]) - X.begin();

      int y1 = lower_bound(Y.begin(),Y.end(),ys[i]) - Y.begin();
      int y2 = lower_bound(Y.begin(),Y.end(),ye[i]) - Y.begin();

      imos[x1][y1]++;
      imos[x2][y2]++;
      imos[x1][y2]--;
      imos[x2][y1]--;
    }

  for(int y = 0;y <= H;y++)
    for(int x = 1;x <= W;x++)
      imos[x][y] += imos[x - 1][y];
  for(int x = 0;x <= W;x++)
    for(int y = 1;y <= H;y++)
      imos[x][y] += imos[x][y - 1];

  int result = 0;
  for(int x = 0;x <= W;x++)
    {
      for(int y= 0;y <= H;y++)
	{
	  if(imos[x][y] == 0)
	    {
	      queue<P> q;
	      result++;
	      q.push(P(x,y));
	      while(!q.empty())
		{
		  int xi = q.front().first;
		  int yi = q.front().second;
		  q.pop();

		  if(imos[xi][yi] == 1) continue;
		  imos[xi][yi] = 1;

		  for(int i = 0;i < 4;i++)
		    {
		      int nx = xi + dx[i];
		      int ny = yi + dy[i];

		      if(0 <= nx && nx <= W && 0 <= ny && ny <= H && imos[nx][ny] == 0)
			{
			  q.push(P(nx,ny));
			}
		    }
		}
	    }
	}
    }

  cout << result << endl;
  return 0;
}

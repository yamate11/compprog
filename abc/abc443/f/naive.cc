#include <bits/stdc++.h>
using namespace std;
#define I return
#define love 0
#define Sasuke ;
#define forever ;
#define ios ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PII pair<int, int>
#define ll long long
#define le left
#define ri right

const int N = 3000010;
const int M = N * 10 + 5;

bool vis[N][10];
PII pre[N][10];
int dig[N][10];
int ans[M], cnt;

void cal(int r, int d)
{
    cnt = 0;
    while (r != -1)
    {
        ans[++cnt] = d;
        PII p = pre[r][d];
        r = p.first;
        d = p.second;
    }
    for (int i = cnt; i >= 1; i--)
        cout << ans[i];
    cout << '\n';
}

int main()
{
    ios int n;
    cin >> n;

    if (n % 10 == 0)
    {
        cout << -1;
        I love Sasuke forever
    }

    queue<PII> q;
    for (int i = 1; i <= 9; i++)
    {
        int r = i % n;
        vis[r][i] = 1;
        pre[r][i] = {-1, -1};
        dig[r][i] = i;
        q.push({r, i});
    }

    while (!q.empty())
    {
        auto [r, last] = q.front();
        q.pop();

        if (r == 0)
        {
            cal(r, last);
            I love Sasuke forever
        }

        for (int nd = last; nd <= 9; nd++)
        {
            int nr = (r * 10 + nd) % n;
            if (!vis[nr][nd])
            {
                vis[nr][nd] = 1;
                pre[nr][nd] = {r, last};
                dig[nr][nd] = nd;
                q.push({nr, nd});
            }
        }
    }

    cout << -1;
    I love Sasuke forever
}



#include <iostream>
#include <math.h>

using namespace std;

/*


*/

int main()
{
    freopen("LongestIncreasingSubsequence.in", "r", stdin);
    freopen("LongestIncreasingSubsequence.out", "w", stdout);
    int n;
    cin >> n;
    const int maxn = n + 1;
    int a[maxn];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int LIS[maxn];

    for (int i = 1; i <= n; ++i)
    {
        LIS[i] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        int ans = 1;
        for (int j = i; j >= 1; --j)
        {
            if (a[i] > a[j])
            {
                ans = max(ans, LIS[j] + 1);
            }
        }
        LIS[i] = ans;
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(LIS[i], ans);
        cout << LIS[i] << " ";
    }

    cout << "test git";
    cout << "hello world" << endl;
    cout << "test";

    cout << endl;
    cout << ans;
}
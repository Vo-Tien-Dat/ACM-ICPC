

#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e3;
vector<int> graph[maxn];
bool isChecked[maxn];

void DFS(int nodeFirst)
{
    isChecked[nodeFirst] = true;
    for (int i = 0; i < graph[nodeFirst].size(); ++i)
    {
        int nodeSecond = graph[nodeFirst][i];
        if (isChecked[nodeSecond] == false)
        {
            DFS(nodeSecond);
        }
    }
}

int main()
{

    freopen("DFS.in", "r", stdin);
    freopen("DFS.out", "w", stdout);
    int numberNodes, numberPaths;

    cin >> numberNodes >> numberPaths;
    for (int i = 1; i <= numberNodes; ++i)
    {
        isChecked[i] = false;
    }
    for (int i = 1; i <= numberPaths; ++i)
    {
        int first, second;
        cin >> first >> second;
        graph[first].push_back(second);
    }

    DFS(1);

    for (int i = 1; i <= numberNodes; ++i)
    {
        cout << isChecked[i] << endl;
    }
}
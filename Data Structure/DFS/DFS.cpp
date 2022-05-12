

#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e3;
vector<int> graph[maxn];
bool isChecked[maxn];

void DFS(int first)
{
    isChecked[first] = true;
    for (int i = 0; i < graph[first].size(); ++i)
    {
        int second = graph[first][i];
        if (isChecked[second] == false)
        {
            DFS(second);
        }
    }
}

int main()
{

    freopen("DFS.in", "r", stdin);
    freopen("DFS.out", "w", stdout);
    int nodes, paths;

    cin >> nodes >> paths;
    for (int i = 1; i <= nodes; ++i)
    {
        isChecked[i] = false;
    }
    for (int i = 1; i <= paths; ++i)
    {
        int first, second;
        cin >> first >> second;
        graph[first].push_back(second);
    }

    DFS(1);

    for (int i = 1; i <= nodes; ++i)
    {
        cout << isChecked[i] << endl;
    }
}
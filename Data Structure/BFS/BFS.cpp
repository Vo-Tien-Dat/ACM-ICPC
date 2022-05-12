#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

const int maxn = 1e3;
vector<int> graph[maxn];

bool isChecked[maxn];

void BFS(int nodeFirst)
{
    queue<int> queueNodes;
    queueNodes.push(nodeFirst);
    while (!queueNodes.empty())
    {
        int frontQueue = queueNodes.front();
        isChecked[frontQueue] = true;
        queueNodes.pop();
        for (int i = 0; i < graph[frontQueue].size(); ++i)
        {
            int nodeSecond = graph[frontQueue][i];
            if (isChecked[nodeSecond] == false)
            {
                queueNodes.push(nodeSecond);
            }
        }
    }
}

int main()
{
    freopen("BFS.in", "r", stdin);
    freopen("BFS.out", "w", stdout);
    int numberNodes, numberPaths;
    cin >> numberNodes >> numberPaths;
    const int maxn = numberNodes;
    for (int i = 1; i <= numberPaths; ++i)
    {
        int nodeFirst, nodeSecond;
        cin >> nodeFirst >> nodeSecond;
        graph[nodeFirst].push_back(nodeSecond);
    }
    for (int i = 1; i <= numberNodes; ++i)
    {
        isChecked[i] = false;
    }
    BFS(1);
    for (int i = 1; i <= numberNodes; ++i)
    {
        cout << isChecked[i] << " ";
    }
}
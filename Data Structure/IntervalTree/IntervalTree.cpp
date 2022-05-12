#include <iostream>

using namespace std;

const int maxn = 1e6;
int NodeTree[maxn * 4];
int Node[maxn];

int MIN_INT = -1e6;

void BuildTree(int index, int left, int right)
{
    if (left == right)
    {
        NodeTree[index] = Node[left];
        return;
    }
    else
    {
        int middle = (left + right) / 2;
        BuildTree(2 * index, left, middle);
        BuildTree(2 * index + 1, middle + 1, right);
        NodeTree[index] = max(NodeTree[index * 2], NodeTree[index * 2 + 1]);
    }
}

int ResultMaxDistance(int index, int left, int right, int indexBegin, int indexEnd)
{

    if (indexEnd < left || right < indexBegin)
        return MIN_INT;
    if (indexBegin <= left && right <= indexEnd)
    {

        return NodeTree[index];
    }

    int middle = (left + right) / 2;
    return max(ResultMaxDistance(index * 2, left, middle, indexBegin, indexEnd), ResultMaxDistance(index * 2 + 1, middle + 1, right, indexBegin, indexEnd));
}

int main()
{
    int numberNodes;
    cin >> numberNodes;
    for (int i = 1; i <= numberNodes; ++i)
    {
        cin >> Node[i];
    }
    BuildTree(1, 1, numberNodes);
    int Test;
    cin >> Test;
    while (Test--)
    {
        int indexBegin, indexEnd;
        cin >> indexBegin >> indexEnd;
        cout << ResultMaxDistance(1, 1, numberNodes, indexBegin, indexEnd) << endl;
    }
}
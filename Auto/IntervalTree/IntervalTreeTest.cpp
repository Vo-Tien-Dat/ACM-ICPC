#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <filesystem>
using namespace std;
using namespace std::chrono;
using namespace std::filesystem;
void InitTest(string nameTest, string input, string output)
{

    srand(time(0));
    string fileInput = nameTest + input;
    string fileOuput = nameTest + output;

    ofstream writeFileInput(fileInput);
    ofstream writeFileOuput(fileOuput);
    int numberNodes = rand() % 5 + 1;
    const int maxn = numberNodes;
    int Node[maxn];
    writeFileInput << numberNodes << "\n";

    for (int i = 1; i <= numberNodes; ++i)
    {
        Node[i] = rand() % 30 + 1;
        writeFileInput << Node[i] << " ";
    }

    cout << "\n";

    int numberTest = rand() % 10 + 1;
    writeFileInput << numberTest << "\n";

    for (int i = 1; i <= numberTest; ++i)
    {
        int nodeFirst, nodeSecond;
        nodeFirst = rand() % numberNodes + 1;
        nodeSecond = rand() % (numberNodes - nodeFirst + 1) + nodeFirst;
        writeFileInput << nodeFirst << " " << nodeSecond << "\n";
        int ans = -1e6;
        for (int j = nodeFirst; j <= nodeSecond; ++j)
        {
            ans = max(ans, Node[j]);
        }

        writeFileOuput << ans << "\n";
    }
}

int main()
{
    string nameTest = "IntervalTree";
    string input = ".in";
    string output = ".ans";
    int numberTest = 4;
    int index = 0;

    while (numberTest--)
    {
        index++;
        string nameTest1 = nameTest + (char)(index + '0');

        // InitTest(nameTest1, input, output);
    }
    cout << "success";
}
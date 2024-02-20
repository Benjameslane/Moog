#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "Moog Managment,", "I am excited for the opportunity!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
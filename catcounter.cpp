#include <iostream>
#include <fstream>

using namespace std;

int counter(string &input);
string getInput();
string readFile(string fileName);

int main(int argc, char *argv[])
{
    
    if (argc == 1)
    {
        cout << "> ";
        string in = getInput();
        cout << counter(in) << endl;
    }
    else if (argc == 2)
    {

    }
    else
    {
        cout << "Invalid input!" << endl;
    }

    return 0;
}

int counter(string &input)
{
    int count = 0;
    size_t nPos = input.find("cat", 0);

    while (nPos != string::npos)
    {
        count++;
        nPos = input.find("cat", nPos + 1);
    }

    return count;
}

string getInput()
{
    string input;
    getline(cin, input);

    if (input.empty())
    {
        return "";
    }

    return input;
}


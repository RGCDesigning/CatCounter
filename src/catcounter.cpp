#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void toLower(string &input)
{
    transform(input.begin(), input.end(), input.begin(), ::tolower);
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

string readFile(string fileName)
{
    ifstream input;
    input.exceptions (ifstream::badbit);
    string fullText;
    try 
    {
        input.open(fileName);

        if (input.fail())
        {
            cout << "Error reading file!" << endl;
            exit(-1);
        }

        if (input.is_open())
        {
            string line;
            while (getline(input, line)) 
            {
                fullText += line;
            }
        }

    }
    catch (const ifstream::failure& e)
    {
        cout << "Error reading file!" << endl;
        exit(-1);
    }

    input.close();
    return fullText;

}
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
    if (input.empty())
    {
        return -1;
    }

    int count = 0;
    size_t nPos = input.find("cat", 0);

    while (nPos != string::npos)
    {
        count++;
        nPos = input.find("cat", nPos + 1);
    }

    return count;
}

string getInput(istream& in = cin)
{
    string input;
    getline(in, input);

    if (input.empty())
    {
        cout << "Returning empty!" << endl;
        return "";
    }

    cout << input << endl;

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
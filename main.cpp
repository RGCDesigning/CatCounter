#include <iostream>
#include <fstream>
#include "src/catcounter.h"

using namespace std;

int main(int argc, char *argv[])
{
    string in;
    if (argc == 1)
    {
        cout << "> ";
        in = getInput();
    }
    else if (argc == 2)
    {
        in = readFile(argv[1]);
    }
    else
    {
        cout << "Invalid input!" << endl;
        return -1;
    }

    toLower(in);
    cout << counter(in) << endl;

    return 0;
}
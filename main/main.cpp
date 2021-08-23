#include "ip_converter.h"

#include <iostream>
#include <sstream>

using namespace std;
using namespace ip_converter;

int main(char * argc, char* argv[])
{
    if (atoi(argc) < 2)
    {
        cout << "Error: incorrect input - no file" << endl;
        return 1;
    }

    ifstream file(argv[1], ios::binary);
    if (!file)
    {
        cout << "Error: Could not read input file!";
        return nullopt;
    }

    if (auto collection = getIPAddresses(file))
        printCollection(*collection);

    int t;
    cin >> t;

    return 0;
}
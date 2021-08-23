#include "ip_converter.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace ip_converter;

optional<ip_address> ip_converter::getIPFromString(const string& str)
{
    ip_address newAdress;
    istringstream stream(str);
    for (string s; getline(stream, s, '.');)
        newAdress.push_back(atoi(s.c_str()));

    if (newAdress.size() != IP_ADDRESS_LENGTH)
        return nullopt;
    
    return newAdress;
}

ip_collection ip_converter::getIPAddresses(istream& inStream)
{
    ip_collection collection;

    for (string s; getline(inStream, s);)
    {
        istringstream lineStream(s);

        for (string str; getline(lineStream, str, '\t'); )
            if (auto newIp = getIPFromString(str))
                collection.push_back(*newIp);
    }

    sort(collection.begin(), collection.end(), [](const ip_address& a, const ip_address& b) {
        for (auto idx = 0; idx < IP_ADDRESS_LENGTH; ++idx)
        {
            if (a[idx] > b[idx])
                return true;
            else if (a[idx] < b[idx])
                return false;
        }

        return false;
        });

    return collection;
}

void ip_converter::printCollection(const ip_collection& collection)
{
    for (auto ip : collection)
    {
        for (auto id : ip)
            cout << id << ".";

        cout << endl;
    }

    for (auto ip : collection)
    {
        if (ip[0] == 1)
        {
            for (auto id : ip)
                cout << id << ".";
        }
        cout << endl;
    }

    for (auto ip : collection)
    {
        if (ip[0] == 46 && ip[1] == 70)
        {
            for (auto id : ip)
                cout << id << ".";
        }
        cout << endl;
    }

    for (auto ip : collection)
    {
        if (find(ip.begin(), ip.end(), 46) != ip.end())
        {
            for (auto id : ip)
                cout << id << ".";
        }
        cout << endl;
    }
}

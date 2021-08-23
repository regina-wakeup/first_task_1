#pragma once

#include <ostream>
#include <string>
#include <optional>
#include <vector>

const unsigned int IP_ADDRESS_LENGTH = 4;

using namespace std;

namespace ip_converter
{
    using ip_address = vector<unsigned int>;
    using ip_collection = vector<ip_address>;

    optional<ip_address> getIPFromString(const string& str);

    ip_collection getIPAddresses(istream& inStream);

    ostream& printCollection(ostream& out, const ip_collection& collection);
}
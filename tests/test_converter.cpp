#include <sstream>

#include <gtest/gtest.h>

#include <ip_converter.h>

TEST(getIPFromString, simple) {

     auto res = ip_converter::getIPFromString("1.2.3.4");
     ASSERT_TRUE(res);

     ip_converter::ip_address resV = { 1, 2, 3, 4 };
     ASSERT_EQ(*res, resV);
}

TEST(getIPFromString, simple_empty) {

    auto res = ip_converter::getIPFromString("1.2.3");
    ASSERT_FALSE(res);
}

TEST(getIPAddresses, simple) {

    istringstream s("1.2.3.4\t3.7.4.0\t2.0.7.4\n5.9.4.3\t4.7.10.7\n");

    ip_converter::ip_collection resExpected = { { 5, 9, 4, 3 }, {4, 7, 10, 7}, {3, 7, 4, 0}, {2, 0, 7, 4}, {1, 2, 3, 4} };

    auto res = ip_converter::getIPAddresses(s);
    ASSERT_FALSE(res.empty());
    ASSERT_EQ(res, resExpected);
}

TEST(getIPAddresses, simple_empty) {

    istringstream s("3245346");
    auto res = ip_converter::getIPAddresses(s);
    ASSERT_TRUE(res.empty());
}

TEST(print, simple) {

    ip_converter::ip_collection input = { {80, 46, 3, 7}, {46, 70, 4, 2}, {46, 2, 5, 8}, { 5, 9, 4, 3 }, {4, 7, 10, 7}, {3, 7, 4, 0}, {2, 0, 7, 4}, {1, 2, 3, 4} };
    string res = "80.46.3.7\n46.70.4.2\n46.2.5.8\n5.9.4.3\n4.7.10.7\n3.7.4.0\n2.0.7.4\n1.2.3.4\n1.2.3.4\n46.70.4.2\n80.46.3.7\n46.70.4.2\n46.2.5.8\n";
    ostringstream s;
    ip_converter::printCollection(s, input);
    ASSERT_EQ(res, s.str());
}

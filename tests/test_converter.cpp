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

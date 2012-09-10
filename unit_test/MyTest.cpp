#include "MyTest.h"
#include "../string_utils.h"

#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

using std::string;
using std::vector;

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(MyTest, "MyTest");

MyTest::MyTest()
{

}

MyTest::~MyTest()
{

}

void MyTest::setUp()
{

}

void MyTest::tearDown()
{

}


void MyTest::toStringTest()
{
    int a = 123213121;
    string s = to_string(a);
    CPPUNIT_ASSERT("123213121" == s);

    a = 1234567890123456789;
    s = to_string(a);
    CPPUNIT_ASSERT("1234567890123456789" != s);
}


void MyTest::toIntTest()
{
    string s = "123";
    int val;

    int result = to_int(s, val);
    CPPUNIT_ASSERT_EQUAL(0, result);
    CPPUNIT_ASSERT_EQUAL(123, val);   
    
    s = "1ab";
    result = to_int(s, val);
    CPPUNIT_ASSERT_EQUAL(1, val);
}

void MyTest::toFloatTest()
{
    string s = "1.11";
    float val;

    int result = to_float(s, val);
    CPPUNIT_ASSERT_EQUAL(0, result);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1.11, val, 0.0001);

    s = "1.111.11";
    result = to_float(s, val);
    CPPUNIT_ASSERT_EQUAL(1, result);
}

void MyTest::splitStringTest()
{
    string s = "2342 4342 abc";
    
    vector<string> vs = split_string(s, " ");

    CPPUNIT_ASSERT_EQUAL(3, (int)vs.size());

    
    CPPUNIT_ASSERT("2342" == vs[0]);

    CPPUNIT_ASSERT("4342" == vs[1]);
    CPPUNIT_ASSERT("abc1" != vs[2]);
    
}

void MyTest::trimBeginTest()
{

    string s = "   \tdfdfd dfff ";
    s = trim_begin(s);
    CPPUNIT_ASSERT("dfdfd dfff " == s);

    s = "dfas";
    s = trim_begin(s);
    CPPUNIT_ASSERT("dfas" == s);

    s = "\r\n\tasd";
    s = trim_begin(s);
    CPPUNIT_ASSERT("asd" == s);

    s = " abc";
    s = trim_begin(s);
    CPPUNIT_ASSERT("abc" == s);

    s = "   ";
    s = trim_begin(s);
    CPPUNIT_ASSERT("" == s);
}

void MyTest::trimEndTest()
{
    string s = " dfsd";

    s = trim_end(s);
    CPPUNIT_ASSERT(" dfsd" == s);

    s = "fas   ";
    s = trim_end(s);
    CPPUNIT_ASSERT("fas" == s);

    s = "\r\nabc\t\r\t\n";
    s = trim_end(s);
    CPPUNIT_ASSERT("\r\nabc" == s);

    s = "\r\n";
    s = trim_end(s);
    CPPUNIT_ASSERT("" == s);
}

#ifndef MY_TEST_H
#define MY_TEST_H

#include <cppunit/extensions/HelperMacros.h>


class MyTest : public CppUnit::TestFixture {

    CPPUNIT_TEST_SUITE(MyTest);
    
    CPPUNIT_TEST(toStringTest);
    CPPUNIT_TEST(toIntTest);
    CPPUNIT_TEST(toFloatTest);
    CPPUNIT_TEST(splitStringTest);

    CPPUNIT_TEST(trimBeginTest);
    CPPUNIT_TEST(trimEndTest);

    CPPUNIT_TEST_SUITE_END();
public:
    MyTest();

    virtual ~MyTest();
    virtual void setUp();
    virtual void tearDown();

    void toStringTest();
    void toIntTest();
    void toFloatTest();
    void splitStringTest();
    
    void trimBeginTest();
    void trimEndTest();
};

#endif

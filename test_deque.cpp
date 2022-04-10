#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"

typedef int T;

TEST_CASE( "Test1", "[deque]" ) {
    Deque<T> d;
    REQUIRE(d.isEmpty());

    //Test Loading List
    d.pushFront(1);
    REQUIRE(d.front()==1);
    REQUIRE_FALSE(d.isEmpty());

    d.pushFront(2);
    REQUIRE_FALSE(d.isEmpty());
    REQUIRE(d.front()==2);

    d.pushFront(3);
    REQUIRE_FALSE(d.isEmpty());
    REQUIRE(d.front()==3);


    d.pushFront(4);
    REQUIRE_FALSE(d.isEmpty());
    REQUIRE(d.front()==4);

    //Test Remove
    REQUIRE(d.back()==1);
    d.popBack();
    REQUIRE(d.back()==2);
    d.popBack();
    REQUIRE(d.back()==3);
    d.popBack();
    REQUIRE(d.back()==4);
    d.popBack();
    //Test Empty
    REQUIRE(d.isEmpty());
    REQUIRE_THROWS(d.front());
    REQUIRE_THROWS(d.back());
    REQUIRE_THROWS(d.popFront());
    REQUIRE_THROWS(d.popBack());

}

TEST_CASE( "Test2", "[deque]" ) {
    Deque<T> d;
    REQUIRE(d.isEmpty());

    //Test Loading List
    d.pushBack(1);
    REQUIRE(d.back()==1);
    REQUIRE_FALSE(d.isEmpty());

    d.pushBack(2);
    REQUIRE_FALSE(d.isEmpty());
    REQUIRE(d.back()==2);

    d.pushBack(3);
    REQUIRE_FALSE(d.isEmpty());
    REQUIRE(d.back()==3);


    d.pushBack(4);
    REQUIRE_FALSE(d.isEmpty());
    REQUIRE(d.back()==4);

    //Test pops
    REQUIRE(d.front()==1);
    d.popFront();
    REQUIRE(d.front()==2);
    d.popFront();
    REQUIRE(d.front()==3);
    d.popFront();
    REQUIRE(d.front()==4);
    d.popFront();

    //Test empty
    REQUIRE(d.isEmpty());
    REQUIRE_THROWS(d.front());
    REQUIRE_THROWS(d.back());
    REQUIRE_THROWS(d.popFront());
    REQUIRE_THROWS(d.popBack());

}

TEST_CASE( "Test3", "[deque]" ) {
    Deque<T> d;
    d.pushBack(1);
    REQUIRE(d.back()==1);
    d.pushBack(2);
    REQUIRE(d.back()==2);
    d.pushBack(3);
    REQUIRE(d.back()==3);
    Deque<T> e;
    e = d;
    REQUIRE(e.back()==3);
    e.popBack();
    REQUIRE(e.back()==2);
    e.popBack();
    REQUIRE(e.back()==1);
    e.popBack();
    REQUIRE(e.isEmpty());

}

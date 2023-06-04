//
// Created by asaf7 on 6/4/2023.
//
#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;

TEST_CASE("add elements and remove elements") {
    // test add element
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(1));
    CHECK_NOTHROW(container.addElement(1));
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(3));
    CHECK(container.size() == 3);
    CHECK_NOTHROW(container.removeElement(1));
    CHECK(container.size() == 2);
    CHECK_FALSE(container.size() == 3);
    CHECK_NOTHROW(container.removeElement(5));
}

TEST_CASE("AscendingIterator") {
    MagicalContainer container;
    container.addElement(100);
    container.addElement(20);
    container.addElement(30);
    container.addElement(15);
    container.addElement(25);

    SUBCASE("Iterating over elements") {
        MagicalContainer::AscendingIterator it(container);

        CHECK(*it == 15);
        ++it;
        CHECK(*it == 20);
        ++it;
        CHECK(*it == 25);
        ++it;
        CHECK(*it == 30);
        ++it;
        CHECK(*it == 100);
        ++it;
        CHECK(it == it.end());
    }
    SUBCASE("Iterating over an empty container") {
        MagicalContainer emptyContainer;
        MagicalContainer::AscendingIterator it(emptyContainer);
        CHECK(it == it.end());
    }

}
TEST_CASE("PrimeIterator with No Prime Numbers") {
    MagicalContainer container;
    container.addElement(4);
    container.addElement(6);
    container.addElement(8);
    container.addElement(9);
    container.addElement(10);
    container.addElement(12);

    SUBCASE("Iterating over elements") {
        MagicalContainer::PrimeIterator it(container);

        CHECK(it == it.end());
        CHECK_THROWS_AS(++it, runtime_error);
    }
}
TEST_CASE("PrimeIterator with Prime Numbers") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(5);
    container.addElement(7);
    container.addElement(11);
    container.addElement(13);

    SUBCASE("Iterating over elements") {
        MagicalContainer::PrimeIterator it(container);

        CHECK(*it == 2);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 7);
        ++it;
        CHECK(*it == 11);
        ++it;
        CHECK(*it == 13);
        ++it;
        CHECK(it == it.end());
    }
}
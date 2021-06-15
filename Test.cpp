/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <yosef desse>
 * 
 * Date: 2021
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */


string nospaces(string input) {
    input.erase(remove(input.begin(),input.end(),' '),input.end());
    input.erase(remove(input.begin(),input.end(),'\t'),input.end());
    input.erase(remove(input.begin(),input.end(),'\r'),input.end());
    input.erase(remove(input.begin(),input.end(),'\n'),input.end());
    return input;
}



TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11111131)) == nospaces("_===_\n<(.,.)>\n(> <)\n( : )"));
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(12222212)) == nospaces("_===_\n\\(o.o)/\n( : )\n(\" \")"));
    CHECK(nospaces(snowman(11114413)) == nospaces("_===_\n(.,.)\n( : )\n(___)"));
    CHECK(nospaces(snowman(21114423)) == nospaces("___\n.....\n(.,.)\n(] [)\n(___)"));
    CHECK(nospaces(snowman(21114411)) == nospaces("___\n.....\n(.,.)\n( : )\n( : )"));

}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(555));
            
    CHECK_THROWS(snowman(51114411));
    CHECK_THROWS(snowman(15134561));
    CHECK_THROWS(snowman(12415124));
    CHECK_THROWS(snowman(14567523));
    CHECK_THROWS(snowman(12411152));
    CHECK_THROWS(snowman(12411125));
    for (int i = 0; i <20 ; ++i) {
        int j=123450+i;
        CHECK_THROWS(snowman(j));
    }
}


TEST_CASE("Snowman Zero") {  
                    
    CHECK_THROWS(snowman(0));
    CHECK_THROWS(snowman(00));
    CHECK_THROWS(snowman(000));
    CHECK_THROWS(snowman(0000));
}


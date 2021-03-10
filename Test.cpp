#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

string nospaces(string input) {
    input.erase(remove(input.begin(),input.end(),' '),input.end());
    input.erase(remove(input.begin(),input.end(),'\t'),input.end()); 
    input.erase(remove(input.begin(),input.end(),'\r'),input.end()); 
    input.erase(remove(input.begin(),input.end(),'\n'),input.end());
	return input;
}

TEST_CASE("Good snowman code") 
{
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(41114411)) == nospaces("___\n(_*_)\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(41144411)) == nospaces("___\n(_*_)\n(.,-)\n( : )\n( : )"));
	CHECK(nospaces(snowman(41444411)) == nospaces("___\n(_*_)\n(-,-)\n( : )\n( : )"));
	CHECK(nospaces(snowman(41444413)) == nospaces("___\n(_*_)\n(-,-)\n( : )\n(___)"));
	CHECK(nospaces(snowman(11144411)) == nospaces("_===_\n(.,-)\n( : )\n( : )"));
	CHECK(nospaces(snowman(11444411)) == nospaces("_===_\n(-,-)\n( : )\n( : )"));
	CHECK(nospaces(snowman(11114413)) == nospaces("_===_\n(.,.)\n( : )\n(___)"));
	CHECK(nospaces(snowman(11144413)) == nospaces("_===_\n(.,-)\n( : )\n(___)"));
	CHECK(nospaces(snowman(11444413)) == nospaces("_===_\n(-,-)\n( : )\n(___)"));
    /* Add more checks here */
}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(555));
	CHECK_THROWS(snowman(1234567));
	CHECK_THROWS(snowman(12345670));
	CHECK_THROWS(snowman(1));
	CHECK_THROWS(snowman(12));
	CHECK_THROWS(snowman(123));
	CHECK_THROWS(snowman(1234));
	CHECK_THROWS(snowman(-1-2-345));
	CHECK_THROWS(snowman(-1));
	CHECK_THROWS(snowman(66666666));
}
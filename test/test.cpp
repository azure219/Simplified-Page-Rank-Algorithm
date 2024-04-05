/*#include <catch2/catch_test_macros.hpp>
#include <iostream>

// change if you choose to use a different header name
#include "AdjacencyList.h"

using namespace std;

// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
/* TEST_CASE("Example Test Name - Change me!", "[tag]"){
    // instantiate any class members that you need to test here
    int one = 1;

    // anything that evaluates to false in a REQUIRE block will result in a failing test
    REQUIRE(one == 0); // fix me!

    // all REQUIRE blocks must evaluate to true for the whole test to pass
    REQUIRE(false); // also fix me!
}

TEST_CASE("Test 2", "[tag]"){
    // you can also use "sections" to share setup code between tests, for example:
    int one = 1;

    SECTION("num is 2") {
        int num = one + 1;
        REQUIRE(num == 2);
    };

    SECTION("num is 3") {
        int num = one + 2;
        REQUIRE(num == 3);
    };

    // each section runs the setup code independently to ensure that they don't affect each other
} */

// you must write 5 unique, meaningful tests for extra credit on this project!

// See the following for an example of how to easily test your output.
// This uses C++ "raw strings" and assumes your PageRank outputs a string with
//   the same thing you print.
/* TEST_CASE("Example PageRank Output Test", "[flag]"){
    // the following is a "raw string" - you can write the exact input (without
    //   any indentation!) and it should work as expected
    string input = R"(7 2
google.com gmail.com
google.com maps.com
facebook.com ufl.edu
ufl.edu google.com
ufl.edu gmail.com
maps.com facebook.com
gmail.com maps.com)";

    string expectedOutput = R"(facebook.com 0.20
gmail.com 0.20
google.com 0.10
maps.com 0.30
ufl.edu 0.20
)";

    string actualOutput;

    //somehow pass your input into your AdjacencyList and parse it to call the
    //correct functions, for example:
    AdjacencyList g;
    actualOutput = g.ParseInput(input);
    // actualOutput = g.getStringRepresentation()

    REQUIRE(actualOutput == expectedOutput);
} */

TEST_CASE("Test 1", "[custom]") {
    // the following is a "raw string" - you can write the exact input (without
    //   any indentation!) and it should work as expected
    string input = R"(4 32
aman.com stackoverflow.com
instagram.com stackoverflow.com
stackoverflow.com aman.com
aman.com instagram.com
)";

    string expectedOutput = R"(aman.com 0.40
instagram.com 0.20
stackoverflow.com 0.40
)";

    string actualOutput;

    //somehow pass your input into your AdjacencyList and parse it to call the
    //correct functions, for example:
    AdjacencyList g;
    actualOutput = g.ParseInput(input);
    // actualOutput = g.getStringRepresentation()

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Test 2", "[custom]") {
    // the following is a "raw string" - you can write the exact input (without
    //   any indentation!) and it should work as expected
    string input = R"(11 12
microsoft.com openai.com
disney.com openai.com
ufl.edu microsoft.com
microsoft.com disney.com
ufl.edu apple.com
openai.com apple.com
apple.com weather.com
apple.com disney.com
disney.com weather.com
microsoft.com apple.com
microsoft.com ufl.edu
)";

    string expectedOutput = R"(apple.com 0.00
disney.com 0.00
microsoft.com 0.00
openai.com 0.00
ufl.edu 0.00
weather.com 0.00
)";

    string actualOutput;

    //somehow pass your input into your AdjacencyList and parse it to call the
    //correct functions, for example:
    AdjacencyList g;
    actualOutput = g.ParseInput(input);
    // actualOutput = g.getStringRepresentation()

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Test 3", "[custom]") {
    // the following is a "raw string" - you can write the exact input (without
    //   any indentation!) and it should work as expected
    string input = R"(35 3
stackoverflow.com pcbuildinguf.com
aman.com chase.com
twitter.com disney.com
chase.com google.com
github.com samsung.com
twitter.com aman.com
facebook.com ufl.edu
twitter.com openai.com
google.com ufl.edu
twitter.com python.org
google.com facebook.com
samsung.com weather.com
python.org microsoft.com
openai.com microsoft.com
getbootstrap.com weather.com
google.com stackoverflow.com
getbootstrap.com twitter.com
aman.com ufl.edu
openai.com chase.com
python.org disney.com
python.org github.com
python.org weather.com
disney.com ufl.edu
facebook.com getbootstrap.com
stackoverflow.com openai.com
instagram.com chase.com
instagram.com pcbuildinguf.com
chase.com disney.com
facebook.com aman.com
github.com instagram.com
python.org aman.com
aman.com microsoft.com
chase.com facebook.com
facebook.com python.org
openai.com aman.com
)";

    string expectedOutput = R"(aman.com 0.04
chase.com 0.05
disney.com 0.04
facebook.com 0.03
getbootstrap.com 0.01
github.com 0.01
google.com 0.02
instagram.com 0.01
microsoft.com 0.04
openai.com 0.02
pcbuildinguf.com 0.02
python.org 0.02
samsung.com 0.01
stackoverflow.com 0.01
twitter.com 0.01
ufl.edu 0.08
weather.com 0.04
)";

    string actualOutput;

    //somehow pass your input into your AdjacencyList and parse it to call the
    //correct functions, for example:
    AdjacencyList g;
    actualOutput = g.ParseInput(input);
    // actualOutput = g.getStringRepresentation()

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Test 4", "[custom]"){
    // the following is a "raw string" - you can write the exact input (without
    //   any indentation!) and it should work as expected
    string input = R"(11 55
roblox.com chase.com
google.com microsoft.com
twitter.com google.com
disney.com facebook.com
disney.com microsoft.com
facebook.com aman.com
aman.com chase.com
microsoft.com github.com
chase.com microsoft.com
disney.com aman.com
microsoft.com aman.com
)";

    string expectedOutput = R"(aman.com 0.00
chase.com 0.00
disney.com 0.00
facebook.com 0.00
github.com 0.00
google.com 0.00
microsoft.com 0.00
roblox.com 0.00
twitter.com 0.00
)";

    string actualOutput;

    //somehow pass your input into your AdjacencyList and parse it to call the
    //correct functions, for example:
    AdjacencyList g;
    actualOutput = g.ParseInput(input);
    // actualOutput = g.getStringRepresentation()

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Test 5", "[custom]"){
    // the following is a "raw string" - you can write the exact input (without
    //   any indentation!) and it should work as expected
    string input = R"(112 7
getbootstrap.com instagram.com
samsung.com weather.com
google.com facebook.com
weather.com twitter.com
instagram.com wikipedia.org
weather.com google.com
ufl.edu python.org
youtube.com ufl.edu
chase.com twitter.com
openai.com github.com
samsung.com wikipedia.org
roblox.com chase.com
google.com openai.com
aman.com python.org
getbootstrap.com chase.com
ufl.edu youtube.com
mozilla.org openai.com
facebook.com chase.com
instagram.com apple.com
apple.com weather.com
facebook.com microsoft.com
github.com facebook.com
ufl.edu instagram.com
wikipedia.org twitter.com
reactjs.org google.com
roblox.com wikipedia.org
ufl.edu aman.com
google.com wikipedia.org
openai.com python.org
chase.com microsoft.com
ufl.edu mozilla.org
apple.com reactjs.org
mozilla.org samsung.com
zoom.us chase.com
weather.com python.org
getbootstrap.com aman.com
python.org microsoft.com
instagram.com roblox.com
wikipedia.org weather.com
github.com pcbuildinguf.com
openai.com stackoverflow.com
roblox.com facebook.com
chase.com weather.com
youtube.com roblox.com
github.com python.org
python.org aman.com
twitter.com mozilla.org
reactjs.org twitter.com
twitter.com apple.com
ufl.edu reactjs.org
youtube.com openai.com
mozilla.org stackoverflow.com
aman.com youtube.com
samsung.com youtube.com
weather.com zoom.us
reactjs.org samsung.com
chase.com facebook.com
facebook.com ufl.edu
openai.com samsung.com
zoom.us python.org
facebook.com getbootstrap.com
chase.com apple.com
roblox.com python.org
chase.com wikipedia.org
openai.com ufl.edu
twitter.com google.com
mozilla.org google.com
getbootstrap.com zoom.us
apple.com pcbuildinguf.com
apple.com instagram.com
zoom.us aman.com
roblox.com youtube.com
pcbuildinguf.com youtube.com
twitter.com reactjs.org
microsoft.com zoom.us
roblox.com stackoverflow.com
wikipedia.org youtube.com
roblox.com instagram.com
wikipedia.org openai.com
weather.com reactjs.org
apple.com facebook.com
stackoverflow.com roblox.com
mozilla.org weather.com
chase.com getbootstrap.com
aman.com mozilla.org
github.com instagram.com
instagram.com reactjs.org
getbootstrap.com apple.com
aman.com facebook.com
mozilla.org chase.com
reactjs.org microsoft.com
openai.com weather.com
facebook.com stackoverflow.com
zoom.us pcbuildinguf.com
pcbuildinguf.com google.com
reactjs.org mozilla.org
microsoft.com google.com
openai.com microsoft.com
facebook.com python.org
chase.com roblox.com
microsoft.com chase.com
aman.com getbootstrap.com
instagram.com facebook.com
stackoverflow.com reactjs.org
wikipedia.org aman.com
stackoverflow.com python.org
aman.com ufl.edu
youtube.com microsoft.com
youtube.com mozilla.org
mozilla.org ufl.edu
wikipedia.org stackoverflow.com
monster.com ufl.edu)";

    string expectedOutput = R"(aman.com 0.07
apple.com 0.03
chase.com 0.06
facebook.com 0.06
getbootstrap.com 0.03
github.com 0.01
google.com 0.07
instagram.com 0.02
microsoft.com 0.08
monster.com 0.00
mozilla.org 0.05
openai.com 0.05
pcbuildinguf.com 0.02
python.org 0.07
reactjs.org 0.05
roblox.com 0.03
samsung.com 0.02
stackoverflow.com 0.04
twitter.com 0.03
ufl.edu 0.04
weather.com 0.04
wikipedia.org 0.05
youtube.com 0.05
zoom.us 0.04
)";

    string actualOutput;

    //somehow pass your input into your AdjacencyList and parse it to call the
    //correct functions, for example:
    AdjacencyList g;
    actualOutput = g.ParseInput(input);
    // actualOutput = g.getStringRepresentation()

    REQUIRE(actualOutput == expectedOutput);
} */

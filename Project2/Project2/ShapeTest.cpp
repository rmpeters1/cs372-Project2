// ShapeTest.hpp
// Hunter Barndt, Yali Wang, Rose Peters

#include <memory>
#include <string>
#include <vector>
#include "catch.hpp"
#include "Shape.hpp"
#include "CompoundShape.h"
using namespace std;
using std::string;
using std::vector;
using std::make_unique;
using std::move;

TEST_CASE("Circle(double radius)") {
	Circle c1(0);
	SECTION("Point")
	{
		REQUIRE(c1.getWidth() == 0);
		REQUIRE(c1.getHeight() == 0);
	}

	Circle c2(10);
	Circle c3(3.14);
	Circle c4(19971129);
	SECTION("Single-Parameter Constructor")
	{
		REQUIRE(c2.getWidth() == 20);
		REQUIRE(c2.getHeight() == 20);

		REQUIRE(c3.getWidth() == 6.28);
		REQUIRE(c3.getHeight() == 6.28);

		REQUIRE(c4.getWidth() == 39942258);
		REQUIRE(c4.getHeight() == 39942258);
	}
	SECTION("PostScript Drawing")
	{
		string testC1 = "0 0 10.000000 0 360 arc stroke\n";
		string testC2 = "0 0 3.140000 0 360 arc stroke\n";
		string testC3 = "0 0 19971129.000000 0 360 arc stroke\n";
		REQUIRE(c2.getPostScript() == testC1);
		REQUIRE(c3.getPostScript() == testC2);
		REQUIRE(c4.getPostScript() == testC3);
	}

}


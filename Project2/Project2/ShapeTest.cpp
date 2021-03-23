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

TEST_CASE("Rectangle(double height, double width)") {
	Rectangle r0(3,4);
	SECTION("Point")
	{
		REQUIRE(r0.getWidth() == 3);
		REQUIRE(r0.getHeight() == 4);
		
	}

	Rectangle r1(3,4);
	Rectangle r2(5,20);
	Rectangle r3(100,999);
	SECTION("Single-Parameter Constructor")
	{
		REQUIRE(r1.getWidth() == 3);
		REQUIRE(r1.getHeight() == 4);

		REQUIRE(r2.getWidth() == 5);
		REQUIRE(r2.getHeight() == 20);

		REQUIRE(r3.getWidth() == 100);
		REQUIRE(r3.getHeight() == 999);
	}
	SECTION("PostScript Drawing")
	{
		string testC1 = "newpath 0 0 moveto 0 4 lineto 3 0 lineto 0 -4 lineto closepath stroke\n";
		string testC2 = "newpath 0 0 moveto 0 20 lineto 5 0 lineto 0 -20 lineto closepath stroke\n";
		string testC3 = "newpath 0 0 moveto 0 999 lineto 100 0 lineto 0 999 lineto closepath stroke\n";
		REQUIRE(r1.getPostScript() == testC1);
		REQUIRE(r2.getPostScript() == testC2);
		REQUIRE(r3.getPostScript() == testC3);
	}

}

TEST_CASE("Spacer(double height, double width)") {
	Spacer r0(3,4);
	SECTION("Point")
	{
		REQUIRE(r0.getWidth() == 3);
		REQUIRE(r0.getHeight() == 4);
		
	}

	Spacer r1(3,4);
	Spacer r2(5,20);
	Spacer r3(100,999);
	SECTION("Single-Parameter Constructor")
	{
		REQUIRE(r1.getWidth() == 3);
		REQUIRE(r1.getHeight() == 4);

		REQUIRE(r2.getWidth() == 5);
		REQUIRE(r2.getHeight() == 20);

		REQUIRE(r3.getWidth() == 100);
		REQUIRE(r3.getHeight() == 999);
	}
	SECTION("PostScript Drawing")
	{
		string testC1 = "255 255 255 setrgbcolor newpath 0 0 moveto 0 4 lineto 3 0 lineto 0 -4 lineto closepath stroke\n";
		string testC2 = "255 255 255 setrgbcolor newpath 0 0 moveto 0 20 lineto 5 0 lineto 0 -20 lineto closepath stroke\n";
		string testC3 = "255 255 255 setrgbcolor newpath 0 0 moveto 0 999 lineto 100 0 lineto 0 999 lineto closepath stroke\n";
		REQUIRE(r1.getPostScript() == testC1);
		REQUIRE(r2.getPostScript() == testC2);
		REQUIRE(r3.getPostScript() == testC3);
	}

}


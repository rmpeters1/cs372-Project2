// ShapeTest.hpp
// Hunter Barndt, Yali Wang, Rose Peters
// Test strategy: 
// 	Verify the height and width for each shape correspond to what
//	are generated by the getPostScript() function.

#include <memory>
#include <string>
#include <vector>
#include "catch.hpp"
#include "Shape.hpp"

using namespace std;
using std::string;
using std::vector;
using std::make_unique;
using std::move;

TEST_CASE("Circle") {
	Circle c1(0);
	SECTION("Empty")
	{
		REQUIRE(c1.getWidth() == 0);
		REQUIRE(c1.getHeight() == 0);
	}

	Circle c2(10);
	Circle c3(3.14);
	Circle c4(19971129);
	SECTION("Circles with different radius")
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
		string testC1 = "100 100 10.000000 0 360 arc stroke\n";
		string testC2 = "100 100 3.140000 0 360 arc stroke\n";
		string testC3 = "100 100 19971129.000000 0 360 arc stroke\n";
		REQUIRE(c2.getPostScript() == testC1);
		REQUIRE(c3.getPostScript() == testC2);
		REQUIRE(c4.getPostScript() == testC3);
	}

}

TEST_CASE("Polygon") {
	SECTION("Triangle")
	{
		Polygon p(3, 50);
		REQUIRE(p.getWidth() == 50);
	}
	SECTION("Triangle Drawing")
	{
		Polygon p(3, 50);

		REQUIRE(p.getPostScript() == "/length 50.000000 def\n" \
			"/nSides 3 def\n" \
			"/angle { 360 nSides div } def\n" \
			"gsave\n" \
			"newpath\n" \
			"0 0 moveto\n" \
			"0 angle 360 {\n" \
			"length 0 lineto\n" \
			"length 0 translate\n" \
			"angle rotate\n" \
			"} for\n" \
			"closepath\n" \
			"stroke\n" \
			"grestore\n");
	}

	SECTION("Square")
	{
		Polygon p(4, 50);
		REQUIRE(p.getWidth() == 50);
	}
	SECTION("Square Drawing")
	{
		Polygon p(4, 50);

		REQUIRE(p.getPostScript() == "/length 50.000000 def\n" \
			"/nSides 4 def\n" \
			"/angle { 360 nSides div } def\n" \
			"gsave\n" \
			"newpath\n" \
			"0 0 moveto\n" \
			"0 angle 360 {\n" \
			"length 0 lineto\n" \
			"length 0 translate\n" \
			"angle rotate\n" \
			"} for\n" \
			"closepath\n" \
			"stroke\n" \
			"grestore\n");
	}
}

TEST_CASE("Rectangle") {
	Rectangle r0(3, 4);
	SECTION("Point")
	{
		REQUIRE(r0.getWidth() == 3);
		REQUIRE(r0.getHeight() == 4);

	}

	Rectangle r1(3, 4);
	Rectangle r2(5, 20);
	Rectangle r3(100, 999);
	SECTION("Rectangles with different width and height")
	{
		REQUIRE(r1.getWidth() == 3);
		REQUIRE(r1.getHeight() == 4);

		REQUIRE(r2.getWidth() == 5);
		REQUIRE(r2.getHeight() == 20);

		REQUIRE(r3.getWidth() == 100);
		REQUIRE(r3.getHeight() == 999);
	}
	SECTION("Rectangle Drawing")
	{
		string testC1 = "newpath \n 0 0 moveto\n 0 4.000000 lineto\n 3.000000 0 lineto\n 0 -4.000000 lineto\n closepath\n stroke\n";
		string testC2 = "newpath \n 0 0 moveto\n 0 20.000000 lineto\n 5.000000 0 lineto\n 0 -20.000000 lineto\n closepath\n stroke\n";
		string testC3 = "newpath \n 0 0 moveto\n 0 999.000000 lineto\n 100.000000 0 lineto\n 0 -999.000000 lineto\n closepath\n stroke\n";
		REQUIRE(r1.getPostScript() == testC1);
		REQUIRE(r2.getPostScript() == testC2);
		REQUIRE(r3.getPostScript() == testC3);
	}

}

TEST_CASE("Spacer") {
	Spacer r0(3, 4);
	SECTION("Simple Spacer")
	{
		REQUIRE(r0.getWidth() == 3);
		REQUIRE(r0.getHeight() == 4);

	}

	Spacer r1(3, 4);
	Spacer r2(5, 20);
	Spacer r3(100, 999);
	SECTION("Spacers with different width and height")
	{
		REQUIRE(r1.getWidth() == 3);
		REQUIRE(r1.getHeight() == 4);

		REQUIRE(r2.getWidth() == 5);
		REQUIRE(r2.getHeight() == 20);

		REQUIRE(r3.getWidth() == 100);
		REQUIRE(r3.getHeight() == 999);
	}
	SECTION("Spacer Drawing")
	{
		string testC1 = "255 255 255 setrgbcolor\n newpath\n 0 0 moveto\n 0 4.000000 lineto\n 3.000000 0 lineto\n 0 -4.000000 lineto\n closepath\n stroke\n";
		string testC2 = "255 255 255 setrgbcolor\n newpath\n 0 0 moveto\n 0 20.000000 lineto\n 5.000000 0 lineto\n 0 -20.000000 lineto\n closepath\n stroke\n";
		string testC3 = "255 255 255 setrgbcolor\n newpath\n 0 0 moveto\n 0 999.000000 lineto\n 100.000000 0 lineto\n 0 -999.000000 lineto\n closepath\n stroke\n";
		REQUIRE(r1.getPostScript() == testC1);
		REQUIRE(r2.getPostScript() == testC2);
		REQUIRE(r3.getPostScript() == testC3);
	}

}

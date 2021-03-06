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
		string testC1 = "%Circle\n 200 200 10.000000 0 360 arc stroke\n\n";
		string testC2 = "%Circle\n 200 200 3.140000 0 360 arc stroke\n\n";
		string testC3 = "%Circle\n 200 200 19971129.000000 0 360 arc stroke\n\n";
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

		REQUIRE(p.getPostScript() == "%Polygon\n/length 50.000000 def\n"
			"/nSides 3 def\n"
			"/angle { 360 nSides div } def\n"
			"gsave\n"
			"newpath\n"
			"200 200 moveto\n"
			"0 angle 360 {\n"
			"length 0 lineto\n"
			"length 0 translate\n"
			"angle rotate\n"
			"} for\n"
			"closepath\n"
			"stroke\n"
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

		REQUIRE(p.getPostScript() == "%Polygon\n/length 50.000000 def\n"
			"/nSides 4 def\n"
			"/angle { 360 nSides div } def\n"
			"gsave\n"
			"newpath\n"
			"200 200 moveto\n"
			"0 angle 360 {\n"
			"length 0 lineto\n"
			"length 0 translate\n"
			"angle rotate\n"
			"} for\n"
			"closepath\n"
			"stroke\n"
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
		string testR1 = "%Rectangle\n newpath \n 200 200 moveto\n 0 4.000000 rlineto\n 3.000000 0 rlineto\n 0 -4.000000 rlineto\n closepath\n stroke\n\n";
		string testR2 = "%Rectangle\n newpath \n 200 200 moveto\n 0 20.000000 rlineto\n 5.000000 0 rlineto\n 0 -20.000000 rlineto\n closepath\n stroke\n\n";
		string testR3 = "%Rectangle\n newpath \n 200 200 moveto\n 0 999.000000 rlineto\n 100.000000 0 rlineto\n 0 -999.000000 rlineto\n closepath\n stroke\n\n";
		REQUIRE(r1.getPostScript() == testR1);
		REQUIRE(r2.getPostScript() == testR2);
		REQUIRE(r3.getPostScript() == testR3);
	}

}

TEST_CASE("Spacer") {
	Spacer s0(3, 4);
	SECTION("Simple Spacer")
	{
		REQUIRE(s0.getWidth() == 3);
		REQUIRE(s0.getHeight() == 4);

	}

	Spacer s1(3, 4);
	Spacer s2(5, 20);
	Spacer s3(100, 999);
	SECTION("Spacers with different width and height")
	{
		REQUIRE(s1.getWidth() == 3);
		REQUIRE(s1.getHeight() == 4);

		REQUIRE(s2.getWidth() == 5);
		REQUIRE(s2.getHeight() == 20);

		REQUIRE(s3.getWidth() == 100);
		REQUIRE(s3.getHeight() == 999);

		SECTION("Spacer Drawing")
		{
			string testS1 = "%Spacer\n 255 255 255 setrgbcolor\n newpath\n 0 0 moveto\n 0 4.000000 lineto\n 3.000000 0 lineto\n 0 -4.000000 lineto\n closepath\n stroke\n";
			string testS2 = "%Spacer\n 255 255 255 setrgbcolor\n newpath\n 0 0 moveto\n 0 20.000000 lineto\n 5.000000 0 lineto\n 0 -20.000000 lineto\n closepath\n stroke\n";
			string testS3 = "%Spacer\n 255 255 255 setrgbcolor\n newpath\n 0 0 moveto\n 0 999.000000 lineto\n 100.000000 0 lineto\n 0 -999.000000 lineto\n closepath\n stroke\n";
			REQUIRE(s1.getPostScript() == testS1);
			REQUIRE(s2.getPostScript() == testS2);
			REQUIRE(s3.getPostScript() == testS3);
		}

	}
}


TEST_CASE("Rotated") {
	SECTION("Rotate a triangle for 90 degrees")
	{
		Triangle t1(56);
		RotatedShape ro1(std::make_unique<Triangle>(56), 90);
		REQUIRE(ro1.getHeight() == t1.getWidth());
		REQUIRE(ro1.getWidth() == t1.getHeight());
		string testRO1 = "gsave\n90 rotate\n%Polygon\n/length 56.000000 def\n"
			"/nSides 3 def\n"
			"/angle { 360 nSides div } def\ngsave\n"
			"newpath\n200 200 moveto\n"
			"0 angle 360 {\nlength 0 lineto\n"
			"length 0 translate\nangle rotate\n} for\n"
			"closepath\nstroke\ngrestore\ngrestore\n";
		REQUIRE(ro1.getPostScript() == testRO1);
	}

	SECTION("Rotate a Rectangle for 180 degrees")
	{
		Rectangle r1(20, 30);
		RotatedShape ro2(std::make_unique<Rectangle>(20, 30), 180);
		REQUIRE(ro2.getHeight() == r1.getHeight());
		REQUIRE(ro2.getWidth() == r1.getWidth());
		string testRO2 = "gsave\n180 rotate\n"
			"%Rectangle\n newpath \n 200 200 moveto\n 0 30.000000 rlineto\n 20.000000 0 rlineto\n 0 -30.000000 rlineto\n closepath\n stroke\n\ngrestore\n";
		REQUIRE(ro2.getPostScript() == testRO2);
	}

	SECTION("Rotate a Triangle for 270 degrees")
	{
		Triangle t2(30);
		RotatedShape ro3(std::make_unique<Triangle>(30), 270);
		REQUIRE(ro3.getHeight() == t2.getWidth());
		REQUIRE(ro3.getWidth() == t2.getHeight());
		string testRO3 = "gsave\n270 rotate\n%Polygon\n/length 30.000000 def\n"
			"/nSides 3 def\n"
			"/angle { 360 nSides div } def\ngsave\n"
			"newpath\n200 200 moveto\n"
			"0 angle 360 {\nlength 0 lineto\n"
			"length 0 translate\nangle rotate\n} for\n"
			"closepath\nstroke\ngrestore\ngrestore\n";
		REQUIRE(ro3.getPostScript() == testRO3);
	}
}


TEST_CASE("Scaled") {
	SECTION("Zoom in a triangle")
	{
		Triangle t1(20);
		ScaledShape sc1(std::make_unique<Triangle>(20), 3.0, 1.0);
		REQUIRE(sc1.getWidth() == t1.getWidth() * 3.0);
		REQUIRE(sc1.getHeight() == t1.getHeight() * 1.0);

		string testSC1 = "gsave\n3.000000 "
			"1.000000 scale\n%Polygon\n/length 20.000000 def\n"
			"/nSides 3 def\n"
			"/angle { 360 nSides div } def\n"
			"gsave\n"
			"newpath\n"
			"200 200 moveto\n"
			"0 angle 360 {\n"
			"length 0 lineto\n"
			"length 0 translate\n"
			"angle rotate\n"
			"} for\n"
			"closepath\n"
			"stroke\n"
			"grestore\ngrestore\n";
		REQUIRE(sc1.getPostScript() == testSC1);
	}
	SECTION("Zoom out a circle (and make an eclipse)")
	{
		Circle c1(40);
		ScaledShape sc2(std::make_unique<Circle>(40), 0.5, 0.8);
		REQUIRE(sc2.getWidth() == c1.getWidth() * 0.5);
		REQUIRE(sc2.getHeight() == c1.getHeight() * 0.8);

		string testSC2 = "gsave\n0.500000 "
			"0.800000 scale\n%Circle\n 200 200 40.000000 0 360 arc stroke\n\n"
			"grestore\n";
		REQUIRE(sc2.getPostScript() == testSC2);
	}
}

TEST_CASE("Layer") {
	

	SECTION("Layer two shapes: a circle and a square")
	{
		Circle c1(18);
		Square sq1(28);
		LayeredShape layer1(vector<shared_ptr<Shape>> {make_shared<Circle>(18), make_shared<Square>(28)});
		REQUIRE(layer1.getWidth() == c1.getWidth());
		REQUIRE(layer1.getHeight() == c1.getHeight());

		string testLayer1 = "%Layered Shape\n"
			"%Circle\n 200 200 18.000000 0 360 arc stroke\n\n"
			"%Polygon\n/length 28.000000 def\n"
			"/nSides 4 def\n"
			"/angle { 360 nSides div } def\n"
			"gsave\n"
			"newpath\n"
			"200 200 moveto\n"
			"0 angle 360 {\n"
			"length 0 lineto\n"
			"length 0 translate\n"
			"angle rotate\n"
			"} for\n"
			"closepath\n"
			"stroke\n"
			"grestore\n";
		REQUIRE(layer1.getPostScript() == testLayer1);
	}

	SECTION("Layer three shapes: a triangle, a rectangle, and a circle")
	{
		Triangle t1(25);
		Rectangle r1(30, 17);
		Circle c1(12);
		LayeredShape layer2({make_shared<Triangle>(25), make_shared<Rectangle>(30, 17), make_shared<Circle>(12)});
		REQUIRE(layer2.getWidth() == r1.getWidth());
		REQUIRE(layer2.getHeight() == c1.getHeight());

		string testLayer2 = "%Layered Shape\n"
			"%Polygon\n/length 25.000000 def\n"
			"/nSides 3 def\n"
			"/angle { 360 nSides div } def\n"
			"gsave\n"
			"newpath\n"
			"200 200 moveto\n"
			"0 angle 360 {\n"
			"length 0 lineto\n"
			"length 0 translate\n"
			"angle rotate\n"
			"} for\n"
			"closepath\n"
			"stroke\n"
			"grestore\n"
			"%Rectangle\n newpath \n 200 200 moveto\n 0 17.000000 rlineto\n 30.000000 0 rlineto\n 0 -17.000000 rlineto\n closepath\n stroke\n\n"
			"%Circle\n 200 200 12.000000 0 360 arc stroke\n\n";
		REQUIRE(layer2.getPostScript() == testLayer2);

	}

}
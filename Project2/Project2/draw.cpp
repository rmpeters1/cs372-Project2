// draw.cpp
// Hunter Barndt, Yali Wang, Rose Peters

#include "Shape.hpp"

#include <fstream>
#include <iostream>

int main() {
	Circle c1(50);
	Spacer s1(50, 50);
	Rectangle r1(50, 50);
	Polygon p1(5, 50);
	//Translate t1(300, 300);

	std::ofstream psfile;
	psfile.open("shapes.ps");

	//psfile << t1.getPostScript();
	psfile << c1.getPostScript();
	psfile << s1.getPostScript();
	psfile << r1.getPostScript();
	psfile << p1.getPostScript() +"showpage";
}
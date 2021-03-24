// draw.cpp
// Hunter Barndt, Yali Wang, Rose Peters

#include "Shape.hpp"
#include "CompoundShape.h"

#include <fstream>
#include <iostream>

int main() {
	Circle c1(50);
	Spacer s1(50, 50);
	Rectangle r1(50, 50);

	std::ofstream psfile;
	psfile.open("shapes.ps");

	psfile << c1.getPostScript();
	psfile << s1.getPostScript();
	psfile << r1.getPostScript() + "showpage";
}
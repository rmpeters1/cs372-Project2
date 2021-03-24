// draw.cpp
// Hunter Barndt, Yali Wang, Rose Peters

#include "Shape.hpp"

#include <fstream>
#include <iostream>

int main() {
    Circle c1(50);
    Spacer s1(50, 50);
    Spacer s2(0, 50);
    Spacer s3(50, 0);
    Rectangle r1(20, 100);
    Rectangle r2(100, 50);
    Polygon p1(5, 50);
    Polygon p2(7, 50);
    Polygon pT(3, 50);
    Polygon pS(4, 50)
        ;    Triangle t1(3);
    //Translate t1(300, 300);

    std::ofstream psfile;
    psfile.open("shapes.ps");

    //psfile << t1.getPostScript();
    psfile << s1.getPostScript();
    psfile << c1.getPostScript();
    psfile << s2.getPostScript();
    psfile << r1.getPostScript();
    psfile << s3.getPostScript();
    psfile << p1.getPostScript();
    psfile << s3.getPostScript();
    psfile << s1.getPostScript();
    psfile << pT.getPostScript();
    psfile << s2.getPostScript();
    psfile << pS.getPostScript();
    psfile << s1.getPostScript();
    psfile << p2.getPostScript() << "showpage";
}

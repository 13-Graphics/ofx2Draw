#pragma once
#include "ofMain.h"

class ofx2d {
public:

    static std::string with_leading_zero(int value, int width);

    static std::string to_lower(string s);

    static int getIndex(vector<std::string> v, std::string s, int notFound);

    static float percent(float percentage, float total);

    static ofVec2f midpoint(ofVec2f p1, ofVec2f p2);

    static ofVec2f intersection(ofVec2f p1, ofVec2f p2, ofVec2f p3, ofVec2f p4);

    static double remap (double value, double fromLow, double fromHigh, double toLow, double toHigh);
    
    static double findDiagonal(double a, double b);

};

#pragma once

#include "ofMain.h"

class ofx2d {
public:

    int getIndex(vector<std::string> v, std::string s, int notFound);

    ofVec2f midpoint(ofVec2f p1, ofVec2f p2);

    ofVec2f intersection(ofVec2f p1, ofVec2f p2, ofVec2f p3, ofVec2f p4);

    double remap (double value, double fromLow, double fromHigh, double toLow, double toHigh);

};

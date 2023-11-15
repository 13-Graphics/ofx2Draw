#include "ofx2d.h"

std::string ofx2d::with_leading_zero(int value, int width)
{
	std::ostringstream oss;
	oss << std::setw(width) << std::setfill('0') << value;
	return oss.str();
}

std::string ofx2d::to_lower(string s) {
    for (char& c : s)
        c = tolower(c);
    return s;
}

int ofx2d::getIndex(vector<std::string> v, std::string s, int notFound = -1) {
    auto it = find(v.begin(), v.end(), s);
    if (it != v.end())
    {
        return it - v.begin();
    }
    else {
        return notFound;
    }
}

float ofx2d::percent(float percentage, float total) {
    return (percentage / total) * 100;
}

ofVec2f ofx2d::midpoint(ofVec2f p1, ofVec2f p2) {
    return ofVec2f((double)(p1.x+p2.x)/2,(double)(p1.y+p2.y)/2);
}

ofVec2f ofx2d::intersection(ofVec2f p1, ofVec2f p2, ofVec2f p3, ofVec2f p4) {

    ofVec2f ret((double)-1,(double)-1);

    // Store the values for fast access and easy
    // equations-to-code conversion
    double x1 = p1.x, x2 = p2.x, x3 = p3.x, x4 = p4.x;
    double y1 = p1.y, y2 = p2.y, y3 = p3.y, y4 = p4.y;
    
    double d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    // If d is zero, there is no intersection
    if (d == 0) return ret;
    
    // Get the x and y
    double pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
    double x = ( pre * (x3 - x4) - (x1 - x2) * post ) / d;
    double y = ( pre * (y3 - y4) - (y1 - y2) * post ) / d;
    
    ret.x = x;
    ret.y = y;
    
    return ret;
}

double ofx2d::remap (double value, double fromLow, double fromHigh, double toLow, double toHigh ) {
    return toLow + (value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow);
}

double ofx2d::findDiagonal(double a, double b)
{
    return sqrt(a * a + b * b);
}


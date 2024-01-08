#include "ofx2d.h"

std::string ofx2d::with_leading_zero(int value, int width)
{
	std::ostringstream oss;
	oss << std::setw(width) << std::setfill('0') << value;
	return oss.str();
}

std::string ofx2d::to_lower(std::string s) {
    for (char& c : s)
        c = tolower(c);
    return s;
}

int ofx2d::getIndex(std::vector<std::string> v, std::string s, int notFound = -1) {
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

glm::vec2 ofx2d::midpoint(glm::vec2 p1, glm::vec2 p2) {
    return glm::vec2((double)(p1.x+p2.x)/2,(double)(p1.y+p2.y)/2);
}

glm::vec2 ofx2d::intersection(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3, glm::vec2 p4) {

    glm::vec2 ret((double)-1,(double)-1);

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

glm::vec4 ofx2d::getCMYK(ofColor& rgb)
{
	// Normalize Values
	double nr = 0, ng = 0, nb = 0;
	if (rgb.r > 0) {
		nr = (double)rgb.r / 255;
	}
	if (rgb.g > 0) {
		ng = (double)rgb.g / 255;
	}
	if (rgb.b > 0) {
		nb = (double)rgb.b / 255;
	}

	double k = 1 - max(max(nr, ng), nb);
	double c = 1 - nr - k;
	double m = 1 - ng - k;
	double y = 1 - nb - k;

    /*
    double kop = 1 - k;
	if (kop > 0) {
		if (c > 0) {
			c /= kop;
		}
		if (m > 0) {
			m /= kop;
		}
		if (y > 0) {
			y /= kop;
		}
	}
    */

	return glm::vec4(c, m, y, k);
}

glm::vec3 ofx2d::getCMY(ofColor& rgb)
{
	// Normalize Values
	double nr = 0, ng = 0, nb = 0;
	if (rgb.r > 0) {
		nr = (double)rgb.r / 255;
	}
	if (rgb.g > 0) {
		ng = (double)rgb.g / 255;
	}
	if (rgb.b > 0) {
		nb = (double)rgb.b / 255;
	}

	double c = 1 - nr;
	double m = 1 - ng;
	double y = 1 - nb;

	return glm::vec3(c, m, y);
}

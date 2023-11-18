#pragma once
#include "ofMain.h"

class ofx2d {
public:

    static std::string with_leading_zero(int value, int width);

    static std::string to_lower(std::string s);

    static int getIndex(std::vector<std::string> v, std::string s, int notFound);

    static float percent(float percentage, float total);

    static glm::vec2 midpoint(glm::vec2 p1, glm::vec2 p2);

    static glm::vec2 intersection(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3, glm::vec2 p4);

    static double remap (double value, double fromLow, double fromHigh, double toLow, double toHigh);
    
    static double findDiagonal(double a, double b);

    template<typename t> static void move(std::vector<t>& v, size_t oldIndex, size_t newIndex);
};

template<typename t>
void ofx2d::move(std::vector<t>& v, size_t oldIndex, size_t newIndex)
{
	if (oldIndex > newIndex)
		std::rotate(v.rend() - oldIndex - 1, v.rend() - oldIndex, v.rend() - newIndex);
	else
		std::rotate(v.begin() + oldIndex, v.begin() + oldIndex + 1, v.begin() + newIndex + 1);
}

ofx2d
=====

A collection of small 2D geometry utilities.

Introduction
------------
This addon brings a basic 2D geometry utils to OpenFrameworks.

Installation
------------
Clone this repo into your `openFrameworks/addons/` folder. Then instantiate the class:

```C++
    #include "ofx2d.h"
    
    ofx2d x2d;

```   

Utils
-----

  - getIndex(vector<std::string> v, std::string lookup, int notFound = -1);
  - midpoint(point1, point2)
  - intersection(p1, p2, p3, p4)
  - remap(value, fromLow, fromHigh, toLow, toHigh)

Compatibility
------------
Written using OpenFrameworks 0.10.1

Known issues
------------
For bugs, see issue tracker.

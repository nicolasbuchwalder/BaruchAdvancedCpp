// Builder4.h: This is a derived Builder class for binding a line with device 2
#pragma once
#include "Shape.h"
#include "Line.h"

#include "IODevice.h"
#include "IODevice2.h"

#include "Builder.h"

#include <tuple>

using ShapePointer = std::shared_ptr<Shape>;
using IODevicePointer = std::shared_ptr<IODevice>;

// Builder 4: for a Line and Device 2
class Builder4 :
    public Builder
{
    // overriding the getShape method to return a pointer to a Line class
    ShapePointer getShape() {
        std::shared_ptr<Line> shapePtr{ new Line };
        return shapePtr;
    };
    // overriding the getShape method to return a pointer to the device 2
    IODevicePointer getIODevice() {
        std::shared_ptr<IODevice2> devicePtr{ new IODevice2 };
        return devicePtr;
    };
};


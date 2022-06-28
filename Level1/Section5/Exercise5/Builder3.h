#pragma once
#include "Shape.h"
#include "Line.h"

#include "IODevice.h"
#include "IODevice1.h"

#include "Builder.h"

#include <tuple>

using ShapePointer = std::shared_ptr<Shape>;
using IODevicePointer = std::shared_ptr<IODevice>;

// Builder 3: for a Line and Device 1
class Builder3 :
    public Builder
{
    // overriding the getShape method to return a pointer to a Line class
    ShapePointer getShape() {
        std::shared_ptr<Line> shapePtr{ new Line };
        return shapePtr;
    };
    // overriding the getShape method to return a pointer to the Device 1
    IODevicePointer getIODevice() {
        std::shared_ptr<IODevice1> devicePtr{ new IODevice1 };
        return devicePtr;
    };
};




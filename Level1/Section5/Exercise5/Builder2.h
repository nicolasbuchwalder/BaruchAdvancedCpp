// Builder2.h: This is a derived Builder class for binding a circle with device 2
#pragma once
#include "Shape.h"
#include "Circle.h"

#include "IODevice.h"
#include "IODevice2.h"

#include "Builder.h"

#include <tuple>

using ShapePointer = std::shared_ptr<Shape>;
using IODevicePointer = std::shared_ptr<IODevice>;

// Builder 2: for a Circle and Device 2
class Builder2 :
    public Builder
{
    // overriding the getShape method to return a pointer to a Circle class
    ShapePointer getShape() {
        std::shared_ptr<Circle> shapePtr{ new Circle };
        return shapePtr;
    };
    // overriding the getShape method to return a pointer to the Device 2
    IODevicePointer getIODevice() {
        std::shared_ptr<IODevice2> devicePtr{ new IODevice2 };
        return devicePtr;
    };
};




// Builder1.h: This is a derived Builder class for binding a circle with device 1
#pragma once
#include "Shape.h"
#include "Circle.h"

#include "IODevice.h"
#include "IODevice1.h"

#include "Builder.h"

#include <tuple>

using ShapePointer = std::shared_ptr<Shape>;
using IODevicePointer = std::shared_ptr<IODevice>;

// Builder 1: for a Circle and Device 1
class Builder1 :
    public Builder
{
    // overriding the getShape method to return a pointer to a Circle class
    ShapePointer getShape() {
        std::shared_ptr<Circle> shapePtr{ new Circle };
        return shapePtr;
    };
    // overriding the getShape method to return a pointer to the Device1
    IODevicePointer getIODevice() {
        std::shared_ptr<IODevice1> devicePtr{ new IODevice1 };
        return devicePtr;
    };
};


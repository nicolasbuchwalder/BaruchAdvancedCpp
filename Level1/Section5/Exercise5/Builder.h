#pragma once
#include "Shape.h"
#include "IODevice.h"

#include <tuple>

// GIVEN CODE
using ShapePointer = std::shared_ptr<Shape>;
using IODevicePointer = std::shared_ptr<IODevice>;

class Builder
{
    // A Builder hierarchy that builds shapes and io devices
public:

    // Hook functions that derived classes must implement
    virtual ShapePointer getShape() = 0;
    virtual IODevicePointer getIODevice() = 0;

    std::tuple<ShapePointer, IODevicePointer> getProduct() {
        // only need to put both shape and io device pointers together in a tuple and returning it
        std::tuple<ShapePointer, IODevicePointer> tuplePtr{ std::make_tuple(getShape(), getIODevice()) };
        return tuplePtr;
    };
};


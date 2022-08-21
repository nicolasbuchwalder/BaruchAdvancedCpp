// ShapeDecorator.h: Abstract class for decorating different shapes
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once
#include "Shape.h"
class ShapeDecorator :
    public Shape
{
private:
    // PART B)

    std::shared_ptr<Shape> _decoratedShape;

public:
    // PART C)
    
    // default contructor
    ShapeDecorator() :
        _decoratedShape{ nullptr } {};

    // PART D)

    // value constructor
    ShapeDecorator(std::shared_ptr<Shape> pt) :
        _decoratedShape{ pt } {};

    // PART E)

    // returns the decorated shape
    std::shared_ptr<Shape> GetShape() {
        return _decoratedShape;
    };

    // sets decorated shape
    void SetShape(std::shared_ptr<Shape> pt) {
        _decoratedShape = pt;
    };

    // clone function (pure virtual function to make class abstract)
    virtual std::shared_ptr<Shape> Clone() = 0;

};


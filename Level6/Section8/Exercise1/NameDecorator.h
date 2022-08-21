// NameDecorator.h: Class for decorating different shapes with a name
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include "ShapeDecorator.h"

#include <string>

class NameDecorator :
    public ShapeDecorator
{
private:
    // PART G)
    std::string _name;

public:
    // PART H)

    NameDecorator() :
        ShapeDecorator(), _name{ "" }{};

    // PART I)
    NameDecorator(std::shared_ptr<Shape> shape, std::string name) :
        ShapeDecorator(shape), _name{ name }{};

    // PART J)

    // returns the name
    std::string GetName() {
        return _name;
    };

    // sets the name
    void SetName(std::string newname) {
        _name = newname;
    };

    // PART K)
    
    // clone method
    std::shared_ptr<Shape> Clone() {
        return std::make_shared<NameDecorator>(*this);
    }

};


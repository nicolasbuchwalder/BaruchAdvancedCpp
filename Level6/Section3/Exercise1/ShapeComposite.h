// ShapeComposite.h: Class that stores a list of pointers to shape objects
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once
#include "Shape.h"

#include <list>
#include <iostream>

class ShapeComposite :
    public Shape
{
private:
    // PART B)
    std::list<std::shared_ptr<Shape>> shapesList;

    // PART C)
    ShapeComposite(const ShapeComposite& copy);
    ShapeComposite& operator=(const ShapeComposite& copy);

public:
    ShapeComposite() {};

    // PART D)
    void AddShape(std::shared_ptr<Shape> s) { shapesList.emplace_back(s); };

    // PART E)
    using it = std::list<std::shared_ptr<Shape>>::iterator;
    using const_it = std::list<std::shared_ptr<Shape>>::const_iterator;

    // PART F
    it begin() { return shapesList.begin(); };
    it end() { return shapesList.end(); };

    // PART G)
    std::size_t count() { return shapesList.size(); };

    // printing the shapes
    std::string print() const {
        std::string out;
        for (auto ptr : shapesList) {
           out = out + *ptr + '\n';
        }; 
        return out;
    };








};



// ShapeComposite.h: Class that stores a list of pointers to shape objects
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once
#include "Shape.h"

#include <list>

class ShapeComposite :
    public Shape
{
private:
    std::list<std::shared_ptr<Shape>> shapesList;

public:
    ShapeComposite() {};

    // PART D)

    ShapeComposite(const ShapeComposite& copy) {
        for (auto elem : copy) {
            this->AddShape(elem->Clone());
        }
    };

    ShapeComposite& operator=(const ShapeComposite& copy) {
        ShapeComposite nonconstcopy(copy);
        return nonconstcopy;
    }

    void AddShape(std::shared_ptr<Shape> s) { shapesList.emplace_back(s); };

    using it = std::list<std::shared_ptr<Shape>>::iterator;
    using const_it = std::list<std::shared_ptr<Shape>>::const_iterator;

    it begin() { return shapesList.begin(); };
    it end() { return shapesList.end(); };

    const_it begin() const { return shapesList.begin(); };
    const_it end() const { return shapesList.end(); };

    std::size_t count() { return shapesList.size(); };

    // printing the shapes
    std::string print() const {
        std::string out;
        for (auto ptr : shapesList) {
            out = out + *ptr + '\n';
        };
        return out;
    };

    // clone method: copy of shape without knowing the exact type
    std::shared_ptr<Shape> Clone() { 
        return std::make_shared<ShapeComposite>(*this); };



};
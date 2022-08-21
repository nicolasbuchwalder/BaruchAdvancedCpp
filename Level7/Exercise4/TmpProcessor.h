// TmpProcessor: This file contains the class that can process things temporarly
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <functional>

// GIVEN CODE


// Function categories
template <typename T>
using FactoryFunction = std::function<T()>;
template <typename T>
using ComputeFunction = std::function<T(const T& t)>;
template <typename T>
using DispatchFunction = std::function<void(T& t)>;
// Class with Input-Processing-Output
template <typename T>
class TmpProcessor
{ // No inheritance used

private:
    FactoryFunction<T> _factory;
    ComputeFunction<T> _compute;
    DispatchFunction<T> _dispatch;

public:
    TmpProcessor(const FactoryFunction<T>& factory,
        const ComputeFunction<T>& compute,
        const DispatchFunction<T>& dispatch)
        : _factory(factory), _compute(compute), _dispatch(dispatch) {}

    // The template method pattern
    virtual void algorithm() final
    {
        T val = _factory();
        T val2 = _compute(val);
        _dispatch(val2);
    }
};

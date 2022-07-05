#include <list>
#include <iostream>
#include <algorithm>

// GIVEN CODE


// C++ 98 approach
// Data storage types
template <typename T> struct oldStorage
{
    // Possible ADTs and their memory allocators
    // typedef std::vector<T, CustomAllocator<T>> type;
    // typedef std::vector<T, std::allocator<T>> type;

    typedef std::list<T, std::allocator<T>> type;

};

template <typename T>
class oldClient
{
    // An example of Composition
private:
    typename oldStorage<T>::type data; // typename mandatory

public:
    oldClient(int n, const T& val) : data(n, val) {};
    void print() const {
        std::for_each(data.begin(), data.end(),
            [](const T& n) { std::cout << n << ", "; });
        std::cout << '\n';
    }
};



// PART A)

template <typename T>
class newClient {
    // "using" keyword for certain datatype
    using newStorage = std::list<T, std::allocator<T>>;

private:
    newStorage data;
public:
    newClient(int n, const T& val) : data(n, val) {};
    void print() const {
        std::for_each(data.begin(), data.end(),
            [](const T& n) {std::cout << n << ", "; });
        std::cout << std::endl;
    };
};


int main() {

    
    int n = 10;
    int val = 2;

    // Client of storage using typedef (C++ 98)
    oldClient<int> myoldClient(n, val);
    myoldClient.print();

    // using "using" keyword
    newClient<int> mynewClient(n, val);
    mynewClient.print();
    // => we get the same results

};
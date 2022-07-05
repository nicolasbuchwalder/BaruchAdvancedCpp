#include <iostream>
#include <memory>

int main() {
    std::cout << std::boolalpha;

    // PART A)
    // Create a shared pointer, print the use count and then create a weak pointer that observes it. Print the use count again.
    std::shared_ptr<int> ptr(new int(1));
    std::cout << "Pointers count before: " << ptr.use_count() << std::endl;
    std::weak_ptr<int> weakPtr(ptr);
    std::cout << "Pointers count after: " << ptr.use_count() << std::endl;

    std::cout << std::endl;

    // PART B)
    // Assign a weak pointer to a shared pointer and check that the weak pointer is not empty.
    std::shared_ptr<int> ptr2(new int(2));
    weakPtr = ptr2;
    std::cout << "Is weak ptr empty: " << weakPtr.expired() << std::endl;

    std::cout << std::endl;

    // PART C)
    // Assign a weak pointer to another weak pointer
    std::weak_ptr<int> weakPtr2(weakPtr);
    std::cout << "Pointers count for weak_ptr: " << weakPtr.use_count() << std::endl;
    // assign a weak pointer to shared pointer
    std::shared_ptr<int> ptr3(weakPtr);
    std::cout << "Pointers count for shared_ptr: " << weakPtr.use_count() << std::endl;
        
}
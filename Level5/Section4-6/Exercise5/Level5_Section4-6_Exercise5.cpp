// Level5_Section4-6_Exercise5.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <unordered_set>
#include <iostream>

template <typename Key, typename Hash, typename EqPred>
void BucketInformation(
    const std::unordered_set<Key, Hash, EqPred>& c)
{
    // PART A)

    std::cout << "buckets number: " << c.bucket_count() << std::endl;
    std::cout << "max buckets number: " << c.max_bucket_count() << std::endl;

    // PART B)

    std::cout << "current load factor: " << c.load_factor() << std::endl;
    std::cout << "max load factor: " << c.max_load_factor() << std::endl;

    // PART C)

    int i{ 0 };

    // bucket_size is only defined if bucket_count > 0
    if (c.bucket_count() > 0) {
        for (auto it{ c.begin() }; it != c.end(); ++it) {
            std::cout << "size of bucket " << i++ << " : " << c.bucket_size(std::distance(c.begin(), it)) << std::endl;
        }
    }

    std::cout << std::endl;

}

int main() {

    // PART A,B, C)

    std::unordered_set<int> set;
    for (int i{ 0 }; i < 10; ++i) { set.emplace(i); };

    BucketInformation(set);

    // PART D)

    // rehashing bucket to size at least of 128
    set.rehash(100);

    BucketInformation(set);
    //=> we see that the number of buckets have changed to the closest bigger power of 2
    //=> everything else has also changed because of that

}
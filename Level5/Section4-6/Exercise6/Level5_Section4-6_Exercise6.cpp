// Level5_Section4-6_Exercise6.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <unordered_set>
#include <iostream>
#include <boost/unordered_set.hpp>

// CODE FROM LAST EXERCISE
template <typename Key, typename Hash, typename EqPred>
void BucketInformation(
    const std::unordered_set<Key, Hash, EqPred>& c)
{
    std::cout << "buckets number: " << c.bucket_count() << std::endl;
    std::cout << "max buckets number: " << c.max_bucket_count() << std::endl;
    std::cout << "current load factor: " << c.load_factor() << std::endl;
    std::cout << "max load factor: " << c.max_load_factor() << std::endl;
    int i{ 0 };
    // bucket_size is only defined if bucket_count > 0
    if (c.bucket_count() > 0) {
        for (auto it{ c.begin() }; it != c.end(); ++it) {
            std::cout << "size of bucket " << i++ << " : " << c.bucket_size(std::distance(c.begin(), it)) << std::endl;
        }
    }
    std::cout << std::endl;

}

// CODE FROM PAST EXERCISE 

template <typename T>
void hash_value(std::size_t& seed, const T& val) {
    boost::hash_combine(seed, val);
}

template <typename T, typename... Types>
void hash_value(std::size_t& seed, const T& val, const Types&... args) {
    boost::hash_combine(seed, val);
    hash_value(seed, args...);
}

template <typename... Types>
std::size_t hash_value(const Types&... args) {
    std::size_t seed = 0;
    hash_value(seed, args...);
    return seed;
}


// GIVEN CODE

struct S
{
    std::string f; std::string s;
    S(const std::string& s1,
       const std::string& s2) : f(s1), s(s2) {}
};

class SHash // Hash for class S
{
public:
    std::size_t operator() (const S & s) const
    {
        return hash_value(s.f, s.s);
    }
};

class SEqual // Equality for S
{
public:
    bool operator()(const S& lhs, const S& rhs) const
    {
        return (rhs.f == lhs.f && rhs.s == lhs.s);
    }
};

int main() {

    // PART A)

    std::unordered_set<S, SHash, SEqual> mySet;

    // adding elements to set
    mySet.emplace(S("Nicolas", "Buchwalder"));
    mySet.emplace(S("John", "Doe"));
    mySet.emplace(S("Barack", "Obama"));

    // PART B)
    BucketInformation(mySet);
    //=> all elements are in bucket 2
}
#include <iostream>

template <typename T>
void toggleUnsigned(T& t, std::true_type) {
    typedef typename std::make_unsigned<T>::type u;
}

int main() {
    int i = -1;
    toggleUnsigned(i, std::is_signed<int>());
}
// TODO
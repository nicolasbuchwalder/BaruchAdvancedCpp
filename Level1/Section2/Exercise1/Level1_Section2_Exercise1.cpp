#include "C.h"
#include "C1.h"
#include "C2.h"
#include "C3.h"
#include "C4.h"

#include <vector>
#include <array>

int main()
{
    // testing class implentation

    C class1;
    class1.print();

    std::vector<double> initvec{ 1.0, 1.41, 3.14, 2.71, 10.0 };
    C class2{ initvec };
    class2.print();

    class1 = class2;

    C class3{ class1 };

    // => everything works fine

    // PART A)

    C1 class4;
    class4.print();

    initvec = { 1.0, 1.41, 3.14, 2.71, 10.0 };
    C1 class5{ initvec };
    class5.print();

    // class4 = class5;
    // => error raised: overload resolution selected deleted operator '='

    // C1 class6{class4};
    // => error raised: call to deleted constructor of 'C1'


    // PART B)

    C2 class7;
    class7.print();

    initvec = { 1.0, 1.41, 3.14, 2.71, 10.0 };
    C2 class8{ initvec };
    class8.print();

    std::array<double, 5> initarray{ 1.0, 1.41, 3.14, 2.71, 10.0 };

    // C2 class9{initarray};
    // => error raised: not possible: no matching 


    // PART C)

    C3<std::vector<double>> class10;
    class10(initvec);
    class10.print();

    C3<std::array<double, 5>> class11;
    class11(initarray);
    class11.print();

    // class11 = class10;
    // => cannot work as it is not the same class type

    C3<std::array<double, 5>> class12(class11);
    // => works fine as the template class is the same as the one that is copy constructed from

    // PART D)

    C4<int> class13;
    C4<int> class14(class13);
    // => this will work no matter which data type (if they are the same)

    // class13.print()
    // => this cannot have the noexcept argument as it is 

}
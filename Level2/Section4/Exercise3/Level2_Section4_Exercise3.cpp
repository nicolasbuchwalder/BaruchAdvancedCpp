#include <iostream>
#include <memory>

int main() {
    // PART A)
    // TODO j'ai pas de runtime error, juste des warnings je dois pas avoir la bonne version du coup je peux pas faire

    // // Define auto_ptr pointers instead of raw pointers
    // std::auto_ptr<double> d(new double (1.0));

    // // Dereference
    // *d = 2.0;

    // // Change ownership of auto_ptr
    // // (after assignment, d is undefined)
    // std::auto_ptr<double> d2 = d;
    // *d2 = 3.0;

    // std::cout <<"Auto values: "<< *d.get() <<", "<< *d2.get();

    // PART B)
    // TODO la meme chose

    // // Define unique_ptr pointers instead of auto_ptr pointers
    // std::unique_ptr<double> e(new double (1.0));

    // // Dereference
    // *e = 2.0;

    // // Change ownership of auto_ptr
    // // (after assignment, d is undefined)
    // std::unique_ptr<double> e2 = e;
    // *e2 = 3.0;

    // std::cout <<"Auto values: "<< *e.get() <<", "<< *e2.get();
}
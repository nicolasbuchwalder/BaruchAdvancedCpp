#include <iostream>
#include <fstream>
#include <memory>

// PART A)
// functor file finalizer
struct FileFinalizer {
    void operator() (FILE *file) {
        fclose(file);
    }
};

// PART B)
// free function file finalizer
void freeFuncFileFinalizer(FILE *file) {
    fclose(file);
}

auto lambdaFileFinalizer = [](FILE *file) {
    fclose(file);
};

int main() {
    // PART C)
    
    FILE *testFile;
    fopen_s(&testFile, "test.txt", "w");

    std::shared_ptr<FILE> mySharedFile1(testFile, FileFinalizer());
    std::shared_ptr<FILE> mySharedFile2(testFile, freeFuncFileFinalizer);
    std::shared_ptr<FILE> mySharedFile3(testFile, lambdaFileFinalizer);

    // PART D)

    // Create a small loop in which records are added to the file; throw an exception at some stage in the loop, catch the exception and then open the file again.
    try {
        for (int i = 0; i < 10; i++) {
            fprintf(testFile, "Record %d\n", i);
            throw 1;
        }

    } catch (int e) {
        FILE *testFile2;
        fopen_s(&testFile2, "test.txt", "w");
    }
    // Does work
}
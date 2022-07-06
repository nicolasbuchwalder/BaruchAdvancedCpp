// Level2_Section4_Exercise5.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <fstream>
#include <memory>

// PART A)
// function object file finalizer
struct FileFinalizer {
    void operator() (FILE* file) {
        fclose(file);
    }
};

// PART B)
// free function file finalizer
void freeFuncFileFinalizer(FILE* file) {
    fclose(file);
}

// stored lambda ffunction file finalizer
auto lambdaFileFinalizer = [](FILE* file) {
    fclose(file);
};

int main() {

    // PART C)

    // testing how the functions react to exceptions
    try {
        FILE* file;
        // opening the file in write mode
        fopen_s(&file, "file.txt", "w");
        std::shared_ptr<FILE> mySharedFile1(file, FileFinalizer());
        std::shared_ptr<FILE> mySharedFile2(file, freeFuncFileFinalizer);
        std::shared_ptr<FILE> mySharedFile3(file, lambdaFileFinalizer);
        throw 1;

    }
    catch (int e) {
        FILE* file_copy;
        fopen_s(&file_copy, "file1.txt", "w");
        fclose(file_copy);

    };


    // PART D)

    // creating a small loop in which records are added to the file, which exception is thrown inbetween
    try {
        FILE* file;
        fopen_s(&file, "file.txt", "w");
        for (int i = 0; i < 10; i++) {
            fprintf(file,"Record %d\n", i);
            if (i == 6) { throw 1; };
            
        }

    }
    catch (int e) {
        FILE* file_copy;
        fopen_s(&file_copy, "file.txt", "w");
        fclose(file_copy);
    }
    //=>does work
}
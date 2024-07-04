# implementations
Writing implementations of Data Structures, Alorithms, and Design Patterns in C/C++.
<br>
Written in a way that the code is built into usable shared and static libraries.
<br>
This repo makes use of [cmake](https://cmake.org/) for building, [GoogleTest](https://github.com/google/googletest) for testing, [cpplint](https://github.com/cpplint/cpplint) for linting, and [doxygen](https://www.doxygen.nl/index.html) for generating documentation. 

The c and cpp folders are each their own cmake project.
<br>
The **c folder** implements from primitives such as Pointers, Structs, etc.
<br>
The **cpp folder** focuses more on using an Object Oriented paradigm, and the Standard Template Library.

## Building
Run the following from the c project root. Make sure you have CMake installed first.
```
cmake -S . -B build
cmake --build build
```

## Usage
. . . debug (includes test builds) subfolder . . . release subfolder . . .

## Testing
After building, run the following from the c project root.
```
build/test/implementation_tests
```

## Linting
Run the following from the c project root. Refer to [Google Style Guide](https://google.github.io/styleguide/cppguide.html) for any errors that come back. Errors are given a certainty scale from 1 to 5 with 5 being most certain.
```
cpplint --recursive src include test
```
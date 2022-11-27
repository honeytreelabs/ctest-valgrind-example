# CTest Valgrind Integration Sample

This is a companion git repository to our article about [how to automatically detect memory leaks in unit-tests](https://honeytreelabs.com/posts/memory-checking-unit-tests/).

## Build and Test Instructions

Make sure to clone this repository including the referenced submodule.

To build the tests:

``` shell
cmake -S . -B build -GNinja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```
Run the tests:

``` shell
ctest --test-dir build --verbose
```


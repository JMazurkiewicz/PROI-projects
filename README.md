# Projects made for "Object-oriented programming" course

[![CI](https://github.com/JMazurkiewicz/PROI-projects/actions/workflows/CI.yaml/badge.svg)](https://github.com/JMazurkiewicz/PROI-projects/actions/workflows/CI.yaml)

## Building projects

Each projects can be built with CMake:

```bash
cd <project name>
cmake -B build
cmake --build build
```

## Running tests

You can run tests in `Complex list` and `Doubly linked list` projects with `ctest`:

```bash
cd build
ctest # Visual Studio requires additional `-C` flag
```

## Quadratic equation

Project requirements:

* Create C++ program with 2 or 3 classes
* The main functionality of application is to solve quadratic equation
* Give user an ability to generate an error (memory leak or null pointer dereference)

Solving `ax^2 + bx + c = 0` equation:

```bash
./QuadraticEquation <a> <b> <c> [optional error code]
```

Where `optional error code` is one of:

* `M` - causes memory leak
* `S` - causes segmentation fault

Score: 5/5

## Complex list

Project requirements:

* Create class that represents complex number with operators:
  * addition operators: `operator+` and `operator+=`
  * subtraction operators: `operator-` and `operator-=`
  * printing operator: `operator<<`
  * comparison operators: `operator==` and `operator!=`
* Create doubly linked list class that can store complex numbers
* List class should implement those operators:
  * direct access operator: `operator[]`
  * addition operators: `operator+` and `operator+=`
  * printing operator: `operator<<`
* Create unit tests for created classes

Score: 15/15

## Doubly linked list

Project requirements:

* Redesign previously implemented doubly linked list to work with any type (make it a `template`)
* List should be implemented as COW (copy-on-write)

Score: 8/8

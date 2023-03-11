# Notes

A collection of information I have learned from doing this project.

[TOC]

# Pure Virtual Function

A pure virtual function is similar to abstract functions in javascript/typescript, where the parent class that defines the function does not have to implement it, however any class that inherits from the parent class has to implement it.

### Syntax

```cpp
virtual void example() = 0;
```

### Example

```cpp
// "animal.h"
#pragma once

class Animal
{
    public:
        Animal();

        virtual void makeNoise() = 0;
}
```

In this code, the `Animal` class defines a constructor and the pure virtual function `makeNoise`. Based on the above definition, this is what the `animal.cpp` file would look like:

```cpp
// "animal.cpp"
#include "animal.h"

Animal::Animal()
{

}
```

And this is what an inheriting class's header and cpp files would look like:

```cpp
// "dog.h"

class Dog: public Animal {
    public:
        Dog();

        void makeNoise();
}
```

```cpp
// "dog.cpp"
#include <stdio>
#include "dog.h"

Dog::Dog()
{

}

Dog::makeNoise()
{
    std::cout << "Woof!" << "\n";
}
```

For a code example in this project, see `State.h`'s update and render functions, and the classes that inherit from `State` (e.x. `GameState`)

# Rays

Rays is a little graphical engine to learn how does computer manage graphics.

Window and painting is managed by [SFML](https://www.sfml-dev.org/)

![demo](./files/demo.gif)

## Build

Compilation is made using `cmake`:

```bash
# Build the configuration
cmake -B build
# Compile the project
cmake --build build
# Run the executable
./build/src/rays
```

Test is done using `gtest`:

```bash
# Build the configuration
cmake -B build -D TEST=true
# Compile the project
cmake --build build
```
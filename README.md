# Fantasy Compiler

## Build Instructions
Run:
```sh
./build.sh
```

## Usage
To run with **JIT**:
```sh
./build/fantasyc test.fan --jit
```

To compile to **AOT (Assembly)**:
```sh
./build/fantasyc test.fan --aot
./output
```

## Running Options
- `--jit` : Executes the program using the Just-In-Time (JIT) compiler.
- `--aot` : Compiles the program to an executable using Ahead-Of-Time (AOT) compilation.
- `--help` : Displays usage instructions.
- `--debug` : Prints debug information about tokenization and execution.

## Example Code (`test.fan`)
```
BEGIN
    let x = 10;
    let y = 20;
    let z = x + y;
END
```

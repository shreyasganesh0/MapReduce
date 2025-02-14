# Mapper - Reducer - Combiner

## Introduction

source files are present in the /src directory

header files are present in the /include directory

input and output test files are present in the /test directory

executable files will be present in the /bin directory

## Usage

- The Makefile can be used to build the executables from source

```
make
```

   -  this will create three executables - /bin/mapper, /bin/reducer, /bin/combiner
   - Building in debug mode
   ```
   make debug
   ```

- To clean the build

```
make clean
```

- the files can also be compiled using 

```
gcc -o bin/mapper mapper.c
gcc -o bin/reducer reducer.c
gcc -o bin/combiner combiner.c
```

NOTE: the files for mapper and reducer are expected to be found in the ./bin
      directory by the combiner program

- To run the programs

```
./bin/mapper < test/inp_map.txt > test/out_map.txt
./bin/reducer < test/inp_red.txt > test/out_red.txt
./bin/combiner < test/inp_map.txt > test/out_combiner.txt
```
    -  the < > operators and mentioned files are optional and will default to stdin and stdout







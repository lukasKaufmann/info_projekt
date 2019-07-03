# Schraeger Wurf
This program plots the trajectory of a thrown object with mass m and radius r depending
on the velocity and angle at the starting point.

WARNING: In order for the program to run on your computer root_v6.16.00 or
newer needs to be installed!

## Building the project
To build the project you will need to run the following commands on your shell:
```
mkdir build/
cd build/ 
cmake .. 
```

## Compiling the project
An alternative to building the project is to compile it yourself. To compile the project you use

```g++ *.cpp $(root-config --clags --glibs)```

This will create a file a.out which you can run by typing
```./a.out```
on your shell.

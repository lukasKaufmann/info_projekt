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
make
```
This will give you a file a.out which you can run by typing ```a.out```.
## Compiling the project
An alternative to building the project is to compile it yourself. To compile the project you use

```
g++ *.cpp $(root-config --clags --glibs)
```
In case this doesn't work on your pc, tru the following
```
/usr/bin/c++ -I`root-config --incdir` -pipe -m64 -fsigned-char -pthread -std=c++11 -g *.cpp `root-config --libs` 
```
Both will create a file a.out which you can run by typing
```./a.out```
on your shell.

## Using the program
After building/ compiling the project you are ready to use it.
The program wants you to enter a few facts about the thrown object, i.e. its mass and its radius, and
the way you throw it, i.e. the velocity and the angle under which the object is thrown.
The program will ask you in the following order:

1. Velocity v 
2. Angle w
3. Mass m
4. Radius r

After you succesfully entered these numbers the program will calculate the trajectory with and without
friction (for the friction case STOKES' law is used) and open a canvas with the drawn trajectories on
your screen. In addition to that, a file plot.png showing the canvas will be created and in your
shell you will find the reach and and the duration of your thrown object.

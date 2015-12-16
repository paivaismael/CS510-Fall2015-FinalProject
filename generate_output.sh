#!/bin/bash # Standard line to start a bash script. '!/bin/bash' is the local bash address.

# Defines some useful variables
min=-2
max=2
points=1000
creal=-1.037
cimag=0.17

# Runs julia.c, informing the necessary inputs as asked in the project instructions, saving the output in juliaset.csv, and deleting the first 8 lines (which are only requests for specifics inputs)
(echo $min; echo $max; echo $min; echo $max; echo $points; echo $points; echo $creal; echo $cimag) | C-JuliaSets/julia | sed '1,8d' > juliaset.csv
# Runs mandelbrot.cpp, informing the necessary inputs as asked in the project instructions, saving the output in mandelbrot.csv, and deleting the first 6 lines (which are only requests for specifics inputs)
(echo $min; echo $max; echo $min; echo $max; echo $points; echo $points) | Cpp-Mandelbrot/mandelbrot | sed '1,6d'  > mandelbrot.csv
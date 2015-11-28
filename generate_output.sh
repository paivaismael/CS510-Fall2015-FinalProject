#!/bin/bash

min=-2
max=2
points=1000
creal=-1.037
cimag=0.17

(echo $min; echo $max; echo $min; echo $max; echo $points; echo $points; echo $creal; echo $cimag) | C-JuliaSets/julia | sed '1,8d' > juliaset.csv

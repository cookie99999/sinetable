# sinetable
Small program to generate a sine table, for example to use on an 8-bit system.

## Usage
`sinetable <scale> <steps>`

## Dependencies
Standard C library, with math header

## Build
gcc -lm -o sinetable sinetable.c

## To do
* Add options for different output formats. Right now it is hard coded for RGBDS on the Gameboy
* Add option for different amounts of outputs. Right now it is hard coded for 256
* Improve error checking

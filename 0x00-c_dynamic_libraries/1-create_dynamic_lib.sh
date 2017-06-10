#!/bin/bash

gcc -shared -Wall -Werror -Wextra -pedantic -fpic -o liball.so ./*.c

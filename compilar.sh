#!/bin/bash
cc creasem.c -o crea
./crea
cc initsem.c -o init
./init
cc versem.c -o ver
./ver
cc PyV.c -Wall -g -c
cc pa.c -Wall -g -c
cc pb.c -Wall -g -c

gcc -Wall -g PyV.o pa.o -o pa
gcc -Wall -g PyV.o pb.o -o pb
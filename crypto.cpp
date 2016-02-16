/*
Lucas Monteiro de Oliveira
Caesar Decipher
ldeolive@usc.edu

Revision History
Date           Changes         Programmer
-----------------------------------------
02/13/2016     Original        Lucas M.O.

Short description of this code:

This programm encrypts the message with the Caesar Cipher algorithm.
(Shift from 0 to 26----20 languages is the limit)

EX1: ./crypto msg.txt 17								--> This printd the encrypted the message with a shift of 17 letters.
															(crypto.cpp)

EX2: ./crack secret.txt corpus-en.txt courpus-fr.txt	--> This is going to discover the laguage of the source message
															(english or french in this case).
															(crack.cpp)
															
EX3: ./crack secret.txt corpus-en.txt					--> This is going to crack the message for english.
															(crack.cpp)
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "caesarlib.h"

int main(int argc, char *argv[]){
	
	int shift=atoi(argv[2]);													//convert to int
	if(argc!=3){																//get error
		std::cout<<"Wrong number of arguments."<<std::endl;
		std::cout<<"Usage: shift message.txt shift_number"<<std::endl;
		return 1;
	}
	return print_file_image(argv[1],shift);										//print the entire file shifted
}

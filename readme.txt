Lucas Monteiro de Oliveira
Caesar Decipher
ldeolive@usc.edu

Revision History
Date           Changes         Programmer
-----------------------------------------
02/13/2016     Original        Lucas M.O.

Short description of this code:

This programm dicovers the source language of the encrypted message or crack message.
(Shift from 0 to 26----20 languages is the limit)

EX1: ./crypto msg.txt 17								--> This printd the encrypted the message with a shift of 17 letters.
															(crypto.cpp)

EX2: ./crack secret.txt corpus-en.txt courpus-fr.txt	--> This is going to discover the laguage of the source message
															(english or french in this case).
															(crack.cpp)
															
EX3: ./crack secret.txt corpus-en.txt					--> This is going to crack the message for english.
															(crack.cpp)

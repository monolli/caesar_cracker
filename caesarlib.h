/*
Lucas Monteiro de Oliveira
Caesar Decipher
ldeolive@usc.edu

Revision History
Date           Changes         Programmer
-----------------------------------------
02/13/2016     Original        Lucas M.O.
*/
// caesarlib.h:

// is this char an English letter?
bool is_letter(char ch);

// return shifted image of ch (if ch not letter, don't shift)
// assumes 0 <= steps < 26
char image(char ch, int steps);

// shift all characters in this file and print it to cout
// return 1 if error (file couldn't be opened), 0 if no error
int print_file_image(const char filename[], int steps);

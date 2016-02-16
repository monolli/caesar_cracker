/*
Lucas Monteiro de Oliveira
Caesar Decipher
ldeolive@usc.edu

Revision History
Date           Changes         Programmer
-----------------------------------------
02/13/2016     Original        Lucas M.O.
*/
#include <iostream>
#include <fstream>

//Function: is_letter
//Purpose:	check if the char is a letter
//Parameters:	the char
//Returns:	true==a letter, false==not a letter
bool is_letter(char ch){
	if(ch>=65&&ch<=90){																			//if is in the ascii letter range, is letter
		return true;
	}else if(ch>=97&&ch<=122){
		return true;
	}
	return false;
}

//Function: image
//Purpose:	encrypt the char with the choosen shift
//Parameters:	the char and the shift amount
//Returns:	the shifted char value
char image(char ch, int steps){
	if(is_letter(ch)){
		if(ch+steps>90&&ch>=65&&ch<=90){														//shift upper case to upper case
			ch-=26;
		}else if(ch+steps>122){																	//shift lower case to lower case
			ch-=26;
		}
		ch+=steps;
	}
	return ch;
}

//Function: print_file_image
//Purpose:	shift the hole file
//Parameters:	the file name and the ammount of shift
//Returns:	return a int(1==fail,0==worked) and print the hole file shifted
int print_file_image(const char filename[], int steps){
	std::ifstream myfile;
	char buff[120];
	int i;
	myfile.open(filename);
	if( myfile.fail() ){																		//get error
    	std::cout << "Couldn't open the input file." << filename <<std::endl;
		return 1;
	}
	while(!myfile.eof()){																		//keep looping until the end of the file
		//std::cout<<std::endl;																	//empty line for style
		myfile.getline(buff,120);																//store the entire line
		for(i=0;buff[i]!='\0';i++){																//shift the entire line, char by char
			std::cout<<image(buff[i],steps);
		}
		if(buff[i]=='\0'&&!myfile.eof()){
			std::cout<<std::endl;
																			//end line
		}
	}
	return 0;
}

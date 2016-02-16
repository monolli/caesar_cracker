/*
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
*/

#include "caesarlib.h"
#include <fstream>
#include <iostream>

using namespace std;

double file_score(const char filename[], int shift);
double char_score(char ch, int shift);
void freq_gen(const char filename[], double lfreq[][26],int llang);

double freq[20][26];																			//space for the frequency of the languages
int lang=0;																		

int main(int argc, char* argv[]) {
	double res[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},temp;								//array for the results
	double res_final=0;
	int pos=0,shift=0;
	
	if (argc<3||argc>22) {																		//get error
		cout << "Wrong number of arguments." << endl;
		cout << "Usage: ./extra ciphertext.txt language1.txt language2.txt" << endl;
		return 1;
	}
	
	for(lang=0;lang<argc-2;lang++){																//keep looping until the last language
		freq_gen(argv[lang+2],freq,lang);														//calculate the frequency of the language
		
		for(int i=1;i<27;i++){																	//calculate the score of the file for all the shift possibilities and
			temp=file_score(argv[1],i);															//store the highest score for that language
			if(temp>res[lang]){
				res[lang]=temp;
				shift=i;																		//store shift
			}		
		}
	}
	if(argc==3){																				//if the just 1 language, crack
		return print_file_image(argv[1],shift);
	}else{																						//discover the language
		for(int i=0;i<argc-2;i++){																//get the higest score comparing all the languages
			if(res[i]>res_final){
				res_final=res[i];
				pos=i+2;																		//save the language position
			}
		}
		std::cout<<argv[pos]<<std::endl;														//print the language name
	}
	return 0;
}

//Function: freq_gen
//Purpose:	calculate the frequency of each letter for the specific language
//Parameters:	language vocabulary file, table of frequencies, the number of the language
//Returns:	nothing
void freq_gen(const char filename[], double lfreq[][26],int llang){
	double count[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};						//count the appearances of each letter
	std::ifstream myfile;																		//variable to manipulate file
	char buff[120];																				//variable to store the line content
	myfile.open(filename);																		//open file
	if( myfile.fail() ){																		//fail message
    	std::cout << "Couldn't open the language file." << filename <<std::endl;
	}
	while(!myfile.eof()){																		//keep looping until the end of the file
		myfile.getline(buff,120);																//store the line
		for(int i=0;buff[i]!='\0';i++){															//go through the line
			if(buff[i]>=65&&buff[i]<=90){														//look for the CAP letters and count(A=a=0,B=b=1...) 
				count[buff[i]-65]++;
			}else if(buff[i]>=97&&buff[i]<=122){												//look for the normal letters and count(A=a=0,B=b=1...) 
				count[buff[i]-97]++;
			}
		}
	}
	double total=0;
	for(int i=0;i<26;i++){																		//store the number of letters in the document
		total+=count[i];
	}
	for(int i=0;i<26;i++){																		//calculate and store the freq of each letter for the language
		lfreq[llang][i]=count[i]/total;
	}
}

//Function: char_score
//Purpose:	return score when ch is shifted (if ch not letter, return 0)
//Parameters:	the char and the shift amount
//Returns:	score(freq) of the char
double char_score(char ch, int shift) {
	if(is_letter(ch)){																			//check if it is a letter
		int val=image(ch,shift);																//encrypt the char with the choosen shift
		if(val>=65&&val<=90){
			return freq[lang][val-65];															//return the frequency of the shifted char
		}else{
			return freq[lang][val-97];
		}
	}
	return 0;
}

//Function: file_score
//Purpose:	return score when contents of entire file are shifted
//Parameters:	the file name and the shift amount
//Returns:	score(freq) of the file
double file_score(const char filename[], int shift) {
	std::ifstream myfile;
	char buff[120];
	double score=0;
	myfile.open(filename);
	if( myfile.fail() ){																		//get error
    	std::cout << "Couldn't open the input file." << filename <<std::endl;
		return 1;
	}
	while(!myfile.eof()){
		myfile.getline(buff,120);																//store the entire line
		for(int i=0;buff[i]!='\0';i++){															//sum the scoe of each char of the line to the total score
			score+=char_score(buff[i],shift);
		}	
	}
	return score;
}

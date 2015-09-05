#ifndef UTIL_H
#define UTIL_H
	#include <stdlib.h>
	#include <stdio.h>
	#include "dateconverter.h"

	#define VERSION "1.0.0"
	
	// It gives the value of ten to the power of p
	int tentopow ( int );
	
	// It converts string to long value (integer)
	int stringtointeger(char *);
	
	// It will parse input string which is in date input format and store it in DATE structure
	int parse_date_input (char *, Date *);
	
	// It prints about this program
	void printabout (void);

	// It print Help
	void print_help (void);
	
	// Print Usage:
	void print_usage (void);
	
	void print_version (void);
	
	// Print Main_menu and receive selected index from menu
	int main_menu (void);
	
	// It is date converter which takes argument which main_menu function returns
	int date_converter (int );
	
	// It prints calander of only one month
	void calprint (Date  ,int );
	
	// It prints calender of a month , year or specified interval of 
	// date
	// andn "english" or "ad" for english date type
	// If miy = 0 -> it prints month's calander
	// If miy = 1 -> it prints year's calander
	// else it prints interval of miy from Date
	int print_calendar (Date , int ,  int );
	
#endif

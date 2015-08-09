#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <getopt.h>
#include "dateconverter.h"
#include "util.h"

#define MAX_IN 32

int main (int argc, char **argv)
{
	int id;
	int opt;
	int option_index = 0;
	int to = 0;
	char *input_date = calloc ( 32 , sizeof (char));
	char *input_calendar_date = calloc (32 , sizeof (char));
	
	strcpy (input_date , "empty");
	Date in;

	Date english_date,nepali_date;
	
	int help_flag = 0;
	int today_flag = 0;
	int now_flag = 0;
	int convert_flag = 0;
	int to_flag = 0;
	int menu_flag = 0;
	
	int bs_calendar_flag = 0;
	int ad_calendar_flag = 0;
	int year_calendar_flag = 0;
	int month_calendar_flag = 0;
	int day_calendar_flag = 0;
	int cal_arg_no = 1;
	
	struct option long_options[] = {
		{"convert", required_argument , 0 , 'c'},
		{"to" , required_argument , 0 , 't'},
		{"help" , no_argument , 0 , 'h'},
		{"today" , no_argument , 0 , 'T'},
		{"now" , no_argument , 0 , 'n'},
		{"menu" , no_argument , 0 , 'm'},
		{"print" , required_argument , 0 , 'p'},
		{0 , 0 , 0 , 0}
	};
	
	while(1){
		opt = getopt_long ( argc, argv , "c:t:hTnmp::" , long_options , &option_index);
		
		if ( opt == -1)
			break;
		switch (opt){
			case 'c':
				convert_flag = 1;
				strcpy ( input_date , optarg);
				break;
				
			case 't':
				to_flag = 1;
				if ((strcmp (optarg , "bs") == 0) || (strcmp(optarg , "nepali") == 0))
					to = 2;
				else if ((strcmp (optarg , "ad") == 0) || (strcmp(optarg , "english") == 0))
					to = 1;
				else
					to = -1;
				break;
				
			case 'T':
				today_flag = 1;
				break;
				
			case 'n': 
				now_flag = 1;
				break;
			case 'p':
				if (cal_arg_no == 1){
					if (strcmp (optarg , "nepali") == 0 || strcmp (optarg , "bs") == 0)
						bs_calendar_flag = 1;
					else if (strcmp (optarg , "english") == 0 || strcmp (optarg , "ad") == 0)
						ad_calendar_flag = 1;
					else if (1) {
						
					}
				}
				//printf ("argument for p first > %s\n", optarg[0]);
				//printf ("argument for p seco. > %s\n", optarg[1]);
				break;
			case 'm':
				menu_flag = 1;
				break;
			case 'h':
				help_flag = 1;
				break;
		}
	}
	
	if ( parse_date_input (input_date , &in) == -1 && convert_flag != 0){
		printf ("Date input is invalid.\n");
		convert_flag = 0;
		to_flag = 0;
	}
	
	if (today_flag != 0){
		printf ("Today : ");	print_now_nepali_date (); printf(" BS\n");
	}
	
	if ( now_flag != 0 ){
		printf ("Now   : ");	print_now_nepali_time () ; printf("\n");
	}
	
	if ( to == 2)
		id = 0;
	else
		id = 1;
	if (convert_flag == 1){
		if(strcmp(input_date , "empty") == 0){
				print_usage();
		
		}else if ( !is_valid_date (in , id)){
				
			printf ("Invalid Date input : ");	print_date (in , "ymd"); 
			printf ("\nDate limit is : \n"\
					"from 2000BS to 2099BS\n");
			printf ("from 1943-4-13AD to 2043-4-12AD\n");
			printf ("input format is yyyy-mm-dd.\n");
			printf ("(c) 2014 - Nabin Bhattarai (nbn.bhattarai99@hotmail.com)\n");
		}
	}

	if ( to_flag == 1 && is_valid_date (in , id)){
		if ( to == 1){
			parse_date_input ( input_date , &nepali_date);
			english_date = convert_BS_date_to_AD (nepali_date);
			printf ("BS date: "); print_date (nepali_date , "ymd") ; printf (" --> ");
			printf ("AD date: ");	print_date (english_date , "ymd");
			printf("\n");
		}
		else if ( to == 2){
			parse_date_input ( input_date , &english_date);
			nepali_date = convert_AD_date_to_BS (english_date);
			printf ("AD date: "); print_date (english_date , "ymd") ; printf (" --> ");
			printf ("BS date: ");	print_date (nepali_date , "ymd");
			printf ("\n");
		}else{
			printf ("\nInvalid argument for --to -t flag.");
		}
	}
	
	if (argc == 1)
		print_usage ();
	if (help_flag == 1)
		print_help();

	if (menu_flag == 1){
		id = main_menu ();
		date_converter (id);
	}

return 0;
}

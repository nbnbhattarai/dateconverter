#include "util.h"

// It gives the value of ten to the power of p
int tentopow( int p)
{
	int ans = 1;
	for (; p > 0; p--)
		ans *= 10;
	return ans;
}

// It converts string s to long value (integer )
int stringtointeger ( char *s )
{
	int i = strlen (s) - 1 , j = 0;
	int result = 0;
	while ( *(s + i) ){
		if (!( *(s + i) >= 48 && *(s + i) <= 57))
			return -1;
		result += ((int) *(s + i) - 48) * tentopow(j);
		i--;
		j++;
	}
	return result;
}


// This function input date in various format and store
// in valid date structure dt.
int parse_date_input (char *in, Date *dt)
{
	int i = 0;
	int line_no = 0, col = 0;
	char **date = calloc (3, sizeof(*date));
		for ( i = 0; i < 3; i++)
			*(date + i) = calloc (10, sizeof(char));
	i = 0;
	while( *(in + i) ){
		if ( col != 0 && ( *(in + i) == ' ' || *(in + i) == '\t' || *(in + i) == '\\' || *(in + i) == '/' || *(in + i) == '-')){
			*( *(date + line_no) + col) = '\0';
			line_no++;
			col = 0;
			i++;
		}else if (col == 0 && ( *(in + i) == ' ' || *(in + i) == '\t' || *(in + i) == '\\' || *(in + i) == '/' || *(in + i) == '-')){
			i++;
			continue;
		}else{
			*(*(date + line_no) + col) = *(in + i);
			col++;
			i++;
		}
	}
	if ( stringtointeger (*(date + 0)) == -1  || stringtointeger (*(date + 1)) == -1  || \
		 stringtointeger (*(date + 2)) == -1 )
		 return -1;
	dt->year = (int) stringtointeger (*(date + 0));
	dt->month = (int) stringtointeger (*(date + 1));
	dt->day = (int) stringtointeger (*(date + 2));
	return 0;
}

void printabout ()
{
	printf(	"About.\n"\
		"===============================================\n"\
		"It is a utility to convert Date format.\n"\
		"Nepali Date (BS) to English (AD) and vice-versa.\n"\
		"developer: Nabin Bhattarai (c) 2014\n");
}

void print_help()
{
	print_version ();
	print_usage ();
	printf(	"\nHelp.\n"\
		"===============================================\n"\
		"Options.\n"\
		" -c --convert   give date to convert in  yyyy-mm-dd format\n"\
		" -t --to        give type of date format to convert ad (english) or bs (nepali)\n"\
		" -T --today     print today's date in Nepali date format.\n"\
		" -n --now       print now time.\n"\
		" -m --menu      run program in menu driven interface.\n"\
		" -h --help      print help.\n\n"\
		"(c) 2014 - Nabin Bhattarai , contact nbn.bhattarai99@hotmail.com for bug report.\n"\
		"                             visit   http://www.nbhattarai.com.np for more projects and help.\n\n"
		);
}

int main_menu ()
{
	int id;
		printf("\n"\
			"===============================================\n"\
			"Main Menu: \n"\
			"1. Convert Nepali Date English Date.\n"\
			"2. Convert English Date to Nepali Date.\n"\
			"3. Help\n"\
			"4. About\n"\
			"0. Exit\n"\
			"> ");
	if ( scanf("%d",&id) == -1)
		main_menu ();
	if (!(id >= 0 && id <= 4))
		main_menu();
	return id;
}

int date_converter (int index)
{
		char *in = calloc (32, sizeof(char));
		Date nepali_date, english_date ;
		
		switch(index){
			case 1:
				printf ("Enter Nepali Date: ");
				while(scanf ("%s" , in) == -1)
					printf("Enter Nepali Date: ");
				//(void) fgets (in , 32 , stdin);
				if (parse_date_input(in , &nepali_date)== -1){
					printf ("Invalid date input.\n"\
							"Enter date in any of the following formats:\n"\
							"yyyy-mm-dd , yyyy/mm/dd , yyyy\\mm\\dd , \"yyyy mm dd\"\n"\
							);
					return 0;
				}
				if (!is_valid_date (nepali_date , 1)){
					printf ("Invalid Date input : ");	print_date (english_date , "ymd"); 
					printf ("\nDate limit is : \n"\
							" --> from 2000BS to 2099BS\n");
					printf (" --> from 1943-4-13AD to 2043-4-12AD\n");
					printf ("Date input formats are: yyyy-mm-dd , yyyy/mm/dd , yyyy\\mm\\dd , \"yyyy mm dd\"\n");
					printf ("(c) 2014 - Nabin Bhattarai (nbn.bhattarai99@hotmail.com)\n");
					return 0;
				}
				
				english_date = convert_BS_date_to_AD( nepali_date );
				printf("Conversion successed.\n%.4d-%.2d-%.2d  --> %.4d-%.2d-%.2d\n",nepali_date.year, nepali_date.month, nepali_date.day,\
				 english_date.year, english_date.month, english_date.day);
			break;
			case 2:
				printf ("Enter English Date: ");
				while (scanf ("%s", in ) == -1)
					printf("Enter English Date: ");
				//(void) fgets (in , 32 , stdin);
				if (parse_date_input (in, &english_date) == -1){
					printf ("Invalid date input.\n"\
							"Enter date in any of the following formats\n"\
							"yyyy-mm-dd , yyyy/mm/dd , yyyy\\mm\\dd , \"yyyy mm dd\"\n"\
							);
					return 0;
				}
				if (!is_valid_date (english_date , 0)){
					printf ("Invalid Date input : ");	print_date (english_date , "ymd"); 
					printf ("\nDate limit is : \n"\
							" --> from 2000BS to 2099BS\n");
					printf (" --> from 1943-4-13AD to 2043-4-12AD\n");
					printf ("Date input formats are: yyyy-mm-dd , yyyy/mm/dd , yyyy\\mm\\dd , \"yyyy mm dd\"\n");
					printf ("(c) 2014 - Nabin Bhattarai (nbn.bhattarai99@hotmail.com)\n");
					return 0;
				}
				nepali_date = convert_AD_date_to_BS(english_date);
				printf("Conversion successed.\n\n%.4d-%.2d-%.2d  -->  %.4d-%.2d-%.2d\n",english_date.year, english_date.month, english_date.day,\
				nepali_date.year, nepali_date.month, nepali_date.day);
			break;
			case 0:
				return -1;
			break;
			case 3:
				print_help ();
				break;
			break;
			case 4:
				printabout ();
			break;
		}
	return 0;
}

void print_usage ()
{
	extern char *__progname;
	printf(	"Usage:\t%s -c <date_input> -t <system_of_date>\n\t%s -m\n\t%s -T | -n\n\t%s -h\n", __progname, __progname, __progname, __progname);
}

void print_version ()
{
	extern char *__progname;
	printf ("%s (nepali date converter) : version %s copyright (c) 2014 , Nabin Bhattarai\n", __progname, VERSION);
}

void calprint (Date dt , int isbs)
{
	int day , daysinmonth ;
	int i , j;
	Date date_tmp = dt;
	date_tmp.day = 1;
	char month_text [12];
	
	get_month_text (dt , month_text , isbs);
	
	if (isbs){
		
	daysinmonth = days_in_month_BS (dt.year , dt.month);
	day = which_day_BS (date_tmp);
	
	}else{
		
	daysinmonth = days_in_month_AD (dt.year , dt.month);
	day = which_day_AD (date_tmp);
	
	}
	printf ("%.4d , %s ",dt.year , month_text);
	if(isbs){
		printf ("\nAIT\tSOM\tMAN\tBUD\tBIH\tSUK\tSAN\n");
	}else{
		printf ("\nSUN\tMON\tTUE\tWED\tTHR\tFRI\tSAT\n");
	}
	for ( i = 0 ; i < day ; i ++)
		printf ("  \t");
	day = 1;
	for (  ; day <= daysinmonth ; ){
		for ( j = i ; j < 7 && day<= daysinmonth; j++){
			printf (" %.2d\t" , day++);
		}
	i = 0;
	printf ("\n");
	}
	
}

int print_calendar (Date dt , int isbs , int miy)
{
	int i , j;
	
		if (miy == 0){
		calprint (dt , isbs);
		
		}else if (miy == 1){
			printf ("%d : \n" ,dt.year);
			for ( i = 1 ; i <= 12 ; i++){
				dt.month = i;
				calprint (dt , isbs);
			}
		}else if (miy > 1){
			for ( j = 1 ; j <= miy ; j++){
				printf ("\n"
						"%d:\n\n"
						, dt.year);
				for ( i = 1 ; i <= 12 ; i++){
					dt.month = i;
					calprint (dt , isbs);
				}
				dt.year++;
			}
		}else
			return -1;
	return 0;
}


#ifndef DATECONVERTER_H
#define DATECONVERTER_H


    #include <stdio.h>
    #include <string.h>
    #include <time.h>
	//#include "util.h"
	
    #define BS_MINIMUM_YEAR 2000
	
	// This is structure date which is used to store date format
	// which has year, month, and day variable
	
	typedef struct {
			int year;
			int month;
			int day;
			} Date;

    ///THIS IS A DATE TAKEN AS REFERENCE which ARE EQUAL... which are calculated by this program by subtracting days
    ///from the day it was programmed, it contain functions to do this
    
    // This calculates total number of days in a month of BS date
    int days_in_month_BS(int ,int );
    
    // This calculate total number of days in year of BS date
    int days_in_year_BS(int );
    
    // This calculates total number of days remaining to complete 
    // year of BS date
    int days_remaining_in_BS_year(Date );
    
    // This returns total number of days till that date in BS date
    int days_till_in_BS_date(Date );
    
    // This returns TRUE(1) if argument year is leap year 
    // And returns FALSE(0) if argument year is not a leap year
    int isleapyear(int);
    
    // Calculate total days in month of AD
    int days_in_month_AD(int ,int );
    
    // Calculates and returns value of number of days in a AD year
    int days_in_AD_year(int );
    
    // This calculates total number of days remaining to complete 
    // year of AD date
    int days_remaining_in_AD_year(Date );
    
    // This returns total number of days till that date in AD date
    int days_till_in_AD_date(Date );
    
    // This calculates difference of two BS dates and returns total 
    // Days difference
    int difference_of_BS_dates(Date ,Date );
    
    // This calculates difference of two AD dates and returns total 
    // Days difference
    int difference_of_AD_dates(Date ,Date );
    
    // This function Add some days to argument Date which is in AD format
    // And returns resultant date
    Date add_days_in_AD_date(Date ,int );
    
    // This function Add some days to argument Date which is in BS format
    // And returns resultant date
    Date add_days_in_BS_date(Date ,int );
    
    // This function subtract some day from argument structure Date in AD
    // And returns resultant date in structure Date
    Date subtract_days_in_AD_date(Date ,int );
    
    // This function subtract some date from argument structure Date in BS
    // And returns resultant date in structure Date
    Date subtract_days_in_BS_date(Date ,int );
    
    // This function takes AD date as argument and returns converted
    // Date to BS date
    Date convert_AD_date_to_BS(Date );
    
    // This function takes BS date as argument and returns converted
    // Date to AD date
    Date convert_BS_date_to_AD(Date );
    
    // It receive Computer's Date ( in AD) and converts it to BS and returns BS date
    Date get_now_BS_date(void);
    
    // it is used to get text of month of Date
    void get_month_text (Date , char *, int );
    
    // It is used to get text of day of Date
    void get_day_text (Date , char * , int );
    
    // It prints Now nepali date
    // It takes computer's localtime to calculate now BS date
    void print_now_nepali_date(void);
    
    // It receive current time and print it
    void print_now_nepali_time(void);
    
    // It print date argument in Nepali date format with day, month's name too
    void print_nepali_date(Date );
    
    // It receive current date and print in Nepali date format
    void print_now_nepali_date(void);
    
    // It returns which day the argument date in BS format is
    int which_day_BS(Date );
    
    // It returns which day the argument date in AD format is
    int which_day_AD(Date );
    
    // It prints English Date in it's own format with month's name 
    // in English
    void print_AD_date(Date );
    
    // It returns TRUE (1) if argument is in range of conversion
    // And false if argument is out of range of conversion
    int is_valid_date(Date ,int );
    
    // This print Date in it's format
    void print_date (Date , char *);


#endif // DATECONVERTER

#include "dateconverter.h"

    // THIS IS A DATE TAKEN AS REFERENCE ARE EQUAL... and calculated
    // by a date subtracting and adding program which is part of it
    // base nepali date is subtracted from today's (programmed day) nepali date
    // which result (days) is subtracted from today's (programmed day) english day 
    // and ad_base date is calculated
    // day = wednesday , can calculate from subtracted date % 7
    Date bs_base_date={2000,01,01},ad_base_date={1943,04,14};
   
    // This is maximum limit of conversion for nepali date
    // it's ad is calculated by subtracting today's (programmed ) nepali date
    // which result days which is added to today's (programmed ) english date
    // which result ad_extreme_date
    Date bs_extreme_date={2099,12,30},ad_extreme_date={2043,4,13};


	// This includes number of days in a month of a specific year
	// which is important because nepali date doesn't follw a specific
	// rule for days in month, it has no rule
    int NepaliDate[100][12]={
                             {30,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {30,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,29,30,30,29,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,29,30,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,29,30,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,31,32,31,31,30,29,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,31,32,31,31,30,29,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {30,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,31,32,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {30,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {30,32,31,32,31,31,29,30,30,29,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,29,30,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,29,30,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,30,29,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,31,32,31,31,30,29,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,31,32,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {30,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {30,32,31,32,31,31,29,30,29,30,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,29,30,30,29,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,29,30,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,30,29,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,31,32,31,31,30,29,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,30} ,
							 {31,31,32,32,31,30,30,30,29,30,30,30} ,
							 {30,32,31,32,31,30,30,30,29,30,30,30} ,
							 {31,31,32,31,31,30,30,30,29,30,30,30} ,
							 {31,31,32,31,31,30,30,30,29,30,30,30} ,
							 {31,32,31,32,30,31,30,30,29,30,30,30} ,
							 {30,32,31,32,31,30,30,30,29,30,30,30} ,
							 {31,31,32,31,31,31,30,30,29,30,30,30} ,
							 {30,31,32,32,30,31,30,30,29,30,30,30} ,
							 {30,32,31,32,31,30,30,30,29,30,30,30} ,
							 {30,32,31,32,31,30,30,30,29,30,30,30} ,
							 {31,31,32,31,31,31,30,30,29,30,30,30} ,
							 {30,31,32,32,31,30,30,30,29,30,30,30} ,
							 {30,32,31,32,31,30,30,30,29,30,30,30} ,
							 {31,31,32,31,31,30,30,30,29,30,30,30} ,
							 {31,31,32,31,31,31,30,29,30,30,30,30} ,
							 {30,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,30,30,30} ,
							 {31,31,32,31,31,31,29,30,29,30,29,31} ,
							 {31,31,32,31,31,31,30,29,29,30,30,30}
                            };



int days_in_month_BS(int year,int month)
{
    return NepaliDate[(year-BS_MINIMUM_YEAR)][(month-1)];
}

int days_in_year_BS(int year)
{
    int i,days=0;
    for(i=1;i<=12;i++)
        days+=days_in_month_BS(year,i);
    return days;
}

int days_remaining_in_BS_year(Date dt)
{
    int days,i;
    days=(days_in_month_BS(dt.year,dt.month)-dt.day);
    for(i=(dt.month+1);i<=12;i++)
        days+=days_in_month_BS(dt.year,i);
    return days;
}

int days_till_in_BS_date(Date dt)
{
    int days=dt.day,i;
    for(i=1;i<dt.month;i++)
        days+=days_in_month_BS(dt.year,i);
    return days;
}


int is_leap_year(int year)
{
    if((year%100!=0 && year%4==0) || year%400==0)
        return 1;
    else
        return 0;
}
int days_in_month_AD(int year,int month)
{
    switch(month){
      case 1 : return(31); break;
      case 2 : if(is_leap_year(year)){
		 return(29);    break;
      }
	       else{
		 return(28);    break;}
      case 3 : return(31);  break;
      case 4 : return(30);  break;
      case 5 : return(31);  break;
      case 6 : return(30);  break;
      case 7 : return(31);  break;
      case 8 : return(31);  break;
      case 9 : return(30);  break;
      case 10: return(31);  break;
      case 11: return(30);  break;
      case 12: return(31);  break;
      default: return(-1);  break;
    }
}

int days_in_AD_year(int year)
{
if(is_leap_year(year))
    return 366;
else
    return 365;
}

int days_remaining_in_AD_year(Date dt)
{
int days,i;
    days=(days_in_month_AD(dt.year,dt.month)-dt.day);
    for(i=(dt.month+1);i<=12;i++)
        days+=days_in_month_AD(dt.year,i);
return days;
}

int days_till_in_AD_date(Date dt)
{
int days=dt.day,i;
    for(i=1;i<dt.month;i++)
        days+=days_in_month_AD(dt.year,i);
return days;
}

int difference_of_BS_dates(Date d1,Date d2)    ///subtract d2 from d1
{
int diff_day=0,yr,ver;
        if(d1.year==d2.year)
            ver=1;
        else
            ver=0;
        for(yr=d2.year;yr<=d1.year;yr++){
            if(yr==d2.year){
                if(ver)
                    diff_day+=(days_remaining_in_BS_year(d2)-days_remaining_in_BS_year(d1));
                else
                    diff_day+=(days_remaining_in_BS_year(d2));
            }else if(yr>d2.year && yr<d1.year)
                diff_day+=days_in_year_BS(yr);
            else if(yr==d1.year)
                diff_day+=days_till_in_BS_date(d1);
        }
    return diff_day;
}

int difference_of_AD_dates(Date d1,Date d2)    ///subtract d2 from d1
{
int diff_day=0,yr,ver;
        if(d1.year==d2.year)
            ver=1;
        else
            ver=0;
        for(yr=d2.year;yr<=d1.year;++yr){
            if(yr==d2.year){
                if(ver==1)
                    diff_day+=(days_remaining_in_AD_year(d2)-days_remaining_in_AD_year(d1));
                else
                    diff_day+=(days_remaining_in_AD_year(d2));
            }else if(yr>d2.year && yr<d1.year)
                diff_day+=days_in_AD_year(yr);
            else if(yr==d1.year)
                diff_day+=days_till_in_AD_date(d1);
        }
    return diff_day;
}

Date add_days_in_AD_date(Date dt,int days)
{
Date date=dt;
    while(days>0){
        if(days>=days_remaining_in_AD_year(date)){
            days-=days_remaining_in_AD_year(date)+1;
            ++date.year;
            date.month=1;
            date.day=1;
        }else if((days<days_remaining_in_AD_year(date)) && days>(days_in_month_AD(date.year,date.month)-date.day)){
            days-=days_in_month_AD(date.year,date.month)-date.day+1;
            ++date.month;
            date.day=1;
        }else{
            date.day+=days;
            days=0;
        }
    }
return date;
}

Date add_days_in_BS_date(Date dt,int days)
{
Date date=dt;
    while(days>0){
        if(days>=days_remaining_in_BS_year(date)){
            days-=days_remaining_in_BS_year(date)+1;
            ++date.year;
            date.month=1;
            date.day=1;
        }else if((days<days_remaining_in_BS_year(date)) && days>(days_in_month_BS(date.year,date.month)-date.day)){
            days-=days_in_month_BS(date.year,date.month)-date.day+1;
            ++date.month;
            date.day=1;
        }else{
            date.day+=days;
            days=0;
        }
    }
return date;
}


Date subtract_days_in_AD_date(Date dt,int days)
{
Date date=dt;
    while(days>0){
        if(days>=days_till_in_AD_date(date)){
            days-=days_till_in_AD_date(date);
            --date.year;
            date.month=12;
            date.day=days_in_month_AD(date.year,12);
        }else if((days<days_till_in_AD_date(date)) && days>=(date.day)){
            days-=date.day;
            --date.month;
            date.day=days_in_month_AD(date.year,date.month);
        }else{
            date.day-=days;
            days=0;
        }
    }
return date;
}

Date subtract_days_in_BS_date(Date dt,int days)
{
Date date=dt;
    while(days>0){
        if(days>=days_till_in_BS_date(date)){
            days-=days_till_in_BS_date(date);
            --date.year;
            date.month=12;
            date.day=days_in_month_BS(date.year,12);
        }else if((days<days_till_in_BS_date(date)) && days>=(date.day)){
            days-=date.day;
            --date.month;
            date.day=days_in_month_BS(date.year,date.month);
        }else{
            date.day-=days;
            days=0;
        }
    }
return date;
}
Date convert_AD_date_to_BS(Date ad_date)
{
int diff_days;
Date converted_BS_date;
    diff_days = difference_of_AD_dates(ad_date,ad_base_date);
    converted_BS_date = add_days_in_BS_date(bs_base_date,diff_days);
return converted_BS_date;
}

Date convert_BS_date_to_AD(Date bs_date)
{
int diff_days;
Date converted_AD_date;
    diff_days = difference_of_BS_dates(bs_date,bs_base_date);
    converted_AD_date = add_days_in_AD_date(ad_base_date,diff_days);
return converted_AD_date;
}

Date get_now_BS_date(void)
{
    Date now_bs_date,now_ad_date;
    time_t t     = time(NULL);
    struct tm tt = *localtime(&t);
    
    now_ad_date.year  = tt.tm_year + 1900;
    now_ad_date.month = tt.tm_mon + 1;
    now_ad_date.day   = tt.tm_mday;
    
    now_bs_date = convert_AD_date_to_BS ( now_ad_date );

return now_bs_date;
}

// It copies month of date to month_text
void get_month_text ( Date date , char *month_text , int is_bs)
{
	if (is_bs){
		switch(date.month){
		case 1:
			strcpy(month_text,"Baishak");
			break;
		case 2:
			strcpy(month_text,"Jestha");
			break;
		case 3:
			strcpy(month_text,"Aashad");
			break;
		case 4:
			strcpy(month_text,"Shrawan");
			break;
		case 5:
			strcpy(month_text,"Bhadra");
			break;
		case 6:
			strcpy(month_text,"Ashwin");
			break;
		case 7:
			strcpy(month_text,"Kartik");
			break;
		case 8:
			strcpy(month_text,"Mangsir");
			break;
		case 9:
			strcpy(month_text,"Paush");
			break;
		case 10:
			strcpy(month_text,"Margh");
			break;
		case 11:
			strcpy(month_text,"Falgun");
			break;
		case 12:
			strcpy(month_text,"Chaitra");
			break;
		default:
			strcpy(month_text,"ERROR");
			break;
		}
	}else{
		switch(date.month){
		case 1:
			strcpy(month_text,"January");
			break;
		case 2:
			strcpy(month_text,"February");
			break;
		case 3:
			strcpy(month_text,"March");
			break;
		case 4:
			strcpy(month_text,"April");
			break;
		case 5:
			strcpy(month_text,"May");
			break;
		case 6:
			strcpy(month_text,"June");
			break;
		case 7:
			strcpy(month_text,"July");
			break;
		case 8:
			strcpy(month_text,"August");
			break;
		case 9:
			strcpy(month_text,"September");
			break;
		case 10:
			strcpy(month_text,"October");
			break;
		case 11:
			strcpy(month_text,"November");
			break;
		case 12:
			strcpy(month_text,"December");
			break;
		default:
			strcpy(month_text,"ERROR");
			break;
			}
	}
}
// It copies day of dt to day_text
void get_day_text ( Date dt , char *day_text , int is_bs)
{
	int which_day;
	if (is_bs){
	which_day = which_day_BS (dt);
    switch(which_day){
		case 0:
			strcpy(day_text,"Aaitabar");
			break;
		case 1:
			strcpy(day_text,"Sombar");
			break;
		case 2:
			strcpy(day_text,"Mangalbar");
			break;
		case 3:
			strcpy(day_text,"Budhabar");
			break;
		case 4:
			strcpy(day_text,"Bihibar");
			break;
		case 5:
			strcpy(day_text,"Sukrabar");
			break;
		case 6:
			strcpy(day_text,"Sanibar");
			break;
		default:
			strcpy(day_text,"ERROR");
			break;
    }
	}else{
		which_day = which_day_AD (dt);
		switch(which_day){
            case 0:
                strcpy(day_text,"Sunday");
                break;
            case 1:
                strcpy(day_text,"Monday");
                break;
            case 2:
                strcpy(day_text,"Tuesday");
                break;
            case 3:
                strcpy(day_text,"Wednesday");
                break;
            case 4:
                strcpy(day_text,"Thursday");
                break;
            case 5:
                strcpy(day_text,"Friday");
                break;
            case 6:
                strcpy(day_text,"Saturday");
                break;
            default:
                strcpy(day_text,"ERROR");
                break;
                }
	}
	
}

void print_nepali_date(Date np_date)
{
    int w_month=np_date.month,w_day=which_day_BS(np_date);
    char month_text[10],day_text[10];
    get_month_text (np_date , month_text , 1);
    get_day_text (np_date , day_text , 1);

    printf("%-9s,%-9s %-.2d,%-.4d",day_text,month_text,np_date.day,np_date.year);
}

void print_now_nepali_date(void)
{
	Date bs_dt;
	bs_dt = get_now_BS_date();
    print_nepali_date ( bs_dt );
}

void print_now_nepali_time(void)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    printf("%.2d:%.2d:%.2d",tm.tm_hour, tm.tm_min, tm.tm_sec);
}

int which_day_BS(Date bs_date)
{
int diff_day,dy,day;
diff_day=difference_of_BS_dates(bs_date,bs_base_date);
dy=(diff_day%7);
    switch(dy){
    case 0:
        day=3;
        break;
    case 1:
        day=4;
        break;
    case 2:
        day=5;
        break;
    case 3:
        day=6;
        break;
    case 4:
        day=0;
        break;
    case 5:
        day=1;
        break;
    case 6:
        day=2;
        break;
    default:
        day=-1;
        break;
    }
return day;
}
int which_day_AD(Date dte)
{
    int days=difference_of_AD_dates(dte,ad_base_date),day,dy;
    dy=(days%7);
    switch(dy){
    case 0:
        day=3;
        break;
    case 1:
        day=4;
        break;
    case 2:
        day=5;
        break;
    case 3:
        day=6;
        break;
    case 4:
        day=0;
        break;
    case 5:
        day=1;
        break;
    case 6:
        day=2;
        break;
    default:
        day=-1;
        break;
    }
return day;
}

void print_AD_date(Date ad_date)
{
int which_day=which_day_AD(ad_date);
char month_text[10],day_text[10];
	get_month_text (ad_date , month_text , 0);
	get_day_text (ad_date , day_text , 0);
	printf("%-9s,%-9s %-.2d,%-.4d",day_text,month_text,ad_date.day,ad_date.year);
}

int is_valid_date(Date dt,int is_bs_date)
{
if(is_bs_date){
    if((dt.year <= bs_extreme_date.year && dt.month <= 12) && \
		(dt.year >= bs_base_date.year && dt.month >= 1)  && \
		(dt.day >= 1 && dt.day <= days_in_month_BS(dt.year , dt.month)))
		return 1;
    else
        return 0;
}else{
    if((dt.year <= ad_extreme_date.year && dt.month <= 12) && \
		(dt.year >= ad_base_date.year && dt.month >= 1)  && \
		(dt.day >= 1 && dt.day <= days_in_month_AD(dt.year , dt.month)))
		return 1;
    else
        return 0;
}
return 1;
}

void print_date (Date dt , char *format)
{
	if ( strcmp (format , "ymd") == 0)
		printf ("%.4d : %.2d : %.2d", dt.year , dt.month , dt.day);
	if ( strcmp (format , "dmy") == 0)
		printf ("%.2d : %.2d : %.4d", dt.day, dt.month , dt.year);
	if ( strcmp (format , "mdy") == 0)
		printf ("%.2d : %.2d : %.4d", dt.month , dt.day , dt.year);
	
}

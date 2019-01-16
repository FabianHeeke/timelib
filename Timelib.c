/**
 * Autor: Fabian Heeke
 * Projekt: Timelib
 * Datum: 07.01.2019
 **/

#include <stdio.h>
#include <stdlib.h>
const int GREGORIAN_CALENDAR_YEAR = 1582; //different calendar before this year

/**
 * checks if a given year is a leapyear
 * (returns 1 if leapyear, 0 if not, -1 if year is not valid)
 **/
int is_leap_year(int year){

    //check if year-number is high enough
    if (year < GREGORIAN_CALENDAR_YEAR){
        return -1;
    }
    //check condition for leapyear
    if ( (year % 4) == 0 ){
        if ( (year % 100) == 0){
            if ( (year % 400) == 0 ){
                return 1;
            }
            else{
                return 0;
            }
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    };
}

/**
 * checks if a given date is valid
 * (returns 1 if yes, 0 if not)
 **/
int exist_date(int day, int month, int year){
    //check for correct area for year and month and if days are greater than 0
    if ( (year >= GREGORIAN_CALENDAR_YEAR && year <= 2400) && (month >= 1 && month <= 12) && day > 0){
        //check days (function checks leapyear and days of month)
        int day_check = get_days_for_month(month);
        if (day <= day_check ){
            return 1;
        }
        else{
            return 0;
        };
    }
    else{
        return 0;
    }
}

/**
 * Returns the maximum number of days for each month (considers leapyears)
 * (e.g. 1 --> 31, 4 --> 30 etc.)
 **/
int get_days_for_month(int month, int year){
    //check for february (return 29, if year is a leapyear)
    if (month == 2){
        int leap_year_check = is_leap_year(year);
        if (leap_year_check != -1){
            if(leap_year_check == 0){
                    return 28;
            }
            else{
                return 29;
            }
        }
    }
    //condition for 31-day-months (uneven months when below or equal to 7 | even months when greater than 7)
    else if ((month <= 7 && month % 2 != 0) || (month >= 8 && month % 2 == 0) ){
        return 31;
    }
    else{
        return 30;
    }
}

/**
 * Function that returns the number of a day given a certain year
 * (e.g. 31.12.2018 --> 365)
 **/
int day_of_the_year(int day, int month, int year){
    int daycount = 0;
    //adding the maximum days of past months of the year
    for(int i = 1; i < month; i++){
        int days_for_month = get_days_for_month(i,year);
        daycount += days_for_month;
    }
    //adding the days of the current month
    daycount += day;

    return daycount;
}

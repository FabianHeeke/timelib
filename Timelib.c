/**
 * Autor: Fabian Heeke
 * Projekt: Timelib
 *          --> Get Date from User-Input and calculate day of the year
 * Datum: 26.02.2019
 **/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

const int GREGORIAN_CALENDAR_YEAR = 1582; //different calendar-type before this year
const int UPPER_BOUND = 2400; // don't consider dates greater than this year

/**
 * gets a date from user input using pointers to change variables
 * (repeats, till input is valid)
 * @return returns a date (type: struct date) after user-input
 **/
struct date input_date(){

    int date_checker = 0;
    struct date date;
    do{
        //clear before getting values
        fflush(stdin);
        //get year
        printf("Bitte Datum eingeben eingeben (dd.mm.yyyy - %i < Jahreszahl < %i)\n", GREGORIAN_CALENDAR_YEAR,UPPER_BOUND);
        printf("Tag: ");
        scanf("%i", &date.day);
        printf("Monat: ");
        scanf("%i", &date.month);
        printf("Jahr: ");
        scanf("%i", &date.year);
        //check if date is valid (inform user if not)
        date_checker = exist_date(date);
        if (date_checker == 0){
            printf("Datum ungueltig!\n");
        };
        //clear reading
        printf("\n");
    }while(date_checker == 0);

    return date;
}

/**
 * checks if a given year is a leapyear
 * @param name: date,type: struct date, descr: date that includes the year-to-check
 * @return  returns 1 (type int) if the year is a leapyear
            returns 0 (type int) if the year is not a leapyear
            returns -1 (type int) if the year is invalid
 **/
int is_leap_year(struct date date){

    //check if year-number is high enough
    if (date.year < GREGORIAN_CALENDAR_YEAR || date.year > UPPER_BOUND){
        return -1;
    }
    //check condition for leapyear
    if ( (date.year % 4) == 0 ){
        if ( (date.year % 100) == 0){
            if ( (date.year % 400) == 0 ){
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
 * @param name: date,type: struct date, descr: date that is to be checked for existence
 * @return returns 1 (type int) if the date is valid
 *         returns 0 (type int) if the date is invalid
 **/
int exist_date(struct date date){

    //check for correct area for year and month and if days are greater than 0
    if ( (date.year >= GREGORIAN_CALENDAR_YEAR && date.year <= 2400) && (date.month >= 1 && date.month <= 12) && date.day > 0){
        //check days (function checks leapyear and days of month)
        int day_check = get_days_for_month(date);
        if (date.day <= day_check ){
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
 * Returns the maximum number of days for a month (considers leapyears for feb)
 * (e.g. 1 --> 31, 4 --> 30 etc.)
 * @param name: date,type: struct date, descr: date that includes the month-to-be-checked
 **/
int get_days_for_month(struct date date){

    //check if month is valid
    if(date.month > 0 && date.month <= 12){
        //check for february (return 29, if year is a leapyear)
        if (date.month == 2){
        int leap_year_check = is_leap_year(date);
        //check if year is valid
        if (leap_year_check != -1){
            //check if year is leapyear
            if(leap_year_check == 0){
                    return 28; //return 28 for feb if not
            }
            else{
                return 29; //return 29 for feb if yes
            }
        }
    }
    //condition for 31-day-months (uneven months when below or equal to 7 || even months when greater than 7)
    else if ((date.month <= 7 && date.month % 2 != 0) || (date.month >= 8 && date.month % 2 == 0) ){
        return 31;
    }
    else{
        return 30;
    }
    }

}

/* TODO: finish this
int get_weekday(struct date date){
    /// get start of weekcount
    //01.01.1582 is a Monday.

    int past_days = 0;

    int i = 0;
    for (i = 1581; i < date.year; i++){
        if (is_leap_year(i)){
            past_days += 366;
        }
        else{
            past_days += 365;
        };
    }

    // get weekday by calculating with current day count
//    char weekdays(7) = (monday, tuesday, wednesday, thursday, friday, saturday, sunday);
    int mod = past_days % 7;
    printf("past days: %i,%i",past_days,mod);
    //fr : 0
    //sa :

}
*/

/**
 * Function that returns the number of a day given a certain year
 * (e.g. 31.12.2018 --> 365)
 * @param name: date, type: struct date, descr: the date of which the day-number of the year is calculated
 * @return returns the number of a day in a given year
 **/
int day_of_the_year(struct date date){
    int daycount = 0;

    //add the maximum days of past months of the year
    for(int i = date.month; i > 1; i--){
        struct date parse_date;
        parse_date.year = date.year;
        parse_date.month = i;
        parse_date.day = date.day;

        int days_for_month = get_days_for_month(parse_date);
        daycount += days_for_month;
    }
    //add the days of the current month
    daycount += date.day;

    return daycount;
}

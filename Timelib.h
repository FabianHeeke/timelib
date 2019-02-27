/**
 * Autor: Fabian Heeke
 * Projekt: Timelib
 *          --> Get Date from User-Input and calculate day of the year
 * Datum: 26.02.2019
 **/

#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

struct date{
    int day;
    int month;
    int year;
};

struct date input_date();
int is_leap_year(struct date date);
int exist_date(struct date date);
int get_days_for_month(struct date date);
int day_of_the_year(struct date date);

#endif // TIMELIB_H_INCLUDED

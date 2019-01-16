#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

int is_leap_year(int year);
int exist_date(int day, int month, int year);
int get_days_for_month(int month, int year);
int day_of_the_year(int day, int month, int year);

#endif // TIMELIB_H_INCLUDED

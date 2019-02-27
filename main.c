/**
 * Autor: Fabian Heeke
 * Projekt: Timelib
 *          --> Get Date from User-Input and calculate day of the year
 * Datum: 26.02.2019
 **/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"


/**
 * Get date from user-input and execute calculation
 * @return return 0 if calculation is finished without error
 */
int main(){
    struct date date;
    date = input_date();
    printf("Tag des Jahres: %i", day_of_the_year(date));
    return 0;
}

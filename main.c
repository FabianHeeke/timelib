#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

int main(){
    int year = 0, month = 0, day = 0;
    input_date(&day,&month, &year);
    printf("Tageszahl des %i.%i im Jahr %i : %i\n",day,month,year,day_of_the_year(day, month, year));
    return 0;
}

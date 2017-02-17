/*
      Program name:  calendar.c
     
      This program creates a month calendar, saves the month calendar to
      the array "cal", copies the "cal" to the year calendar "year_array",
      and displays the "year_array".
     
      jan  feb mar
      apr  may jun
      jul  aug sep
      oct  nov  dec

      In this calendar, any date that can be divided by 5 is a holiday. (5,10,15,..)

 */

#include <stdio.h>
#include <stdlib.h>

void print_head()
{
     printf("S\tM\tT\tW\tT\tF\tS\t|\t");
     printf("S\tM\tT\tW\tT\tF\tS\t|\t");
     printf("S\tM\tT\tW\tT\tF\tS|\n");
}
void print_line()
{

     printf("----------------------------------------------------");    
     printf("----------------------------------------------------");    
     printf("------------------------------------");    
     printf("----------------------------------------------------\n");    
}

int main()
{
     int     days[]={31,28,31,30,31,30,31,31,30,31,30,31};     //number of days in each month if NOT leap year
     int     offset[]={5,1,1,4,6,2,4,0,3,5,1,3};          //For 2010, start days of each month. 0 Sunday, 1 Monday, 5 Friday....

     int     i = 0, j = 0;
     int      month;
     int     cal[6][7] = {0};          //Array to save one month calendar
    
     int year_array[6][21] = {0};     //Array to save year calendar. (Only 3 month here, month together horizontally)
    
     int     row,col;
    
     //initialize the year array
     for(i = 0 ; i < 6; i++)
               for(j = 0; j < 21; j++)
                    year_array[i][j] = 0;
                   
    
     //Generate the calendar for 3 months
     for(month = 1; month <=3; month ++)
     {
    
          //initialize the month array
          for(i = 0 ; i < 6; i++)
               for(j = 0; j < 7; j++)
                    cal[i][j] = 0;

          col = 0;      //Column index of the month array
          row = 0;     //Row index of the month array

          //update the month array
          for(i = 1; i <= days[month - 1]; i++)
          {
               col = ((offset[month-1] + i) % 7) - 1 ;
               row = ((offset[month-1]+i) / 7) ;
               cal[row][col] = i;
          }
    
          int month_position = (month - 1) * 7; //position of the first Sunday of a month in the year array

          //Copy the month array to the year array
          //Month arrays are copied back to back horizontally
          for(i = 0; i < 6; i++)
               for(j = 0; j < 7; j++)
                    year_array[i][month_position + j] = cal[i][j];
    
    
     }
    
     print_line();
     print_head();
     print_line();
    
    
     //Print the year array
     for(row = 0; row < 6; row++)
     {
          for(col = 0; col < 7 * 3; col++)
          {
               if(col > 0 && col % 7 == 0)
                    printf("|\t");
              
               if(year_array[row][col] == 0)
                    printf("\t");
               else{
                    if(year_array[row][col] % 5 == 0)     //Any date than can devided by 5 is a holiday.    
                         printf("(%d)\t",year_array[row][col]);
                    else
                         printf("%d\t",year_array[row][col]);
               }
              
     }
     printf("\n");
    
     }
     print_line();
}

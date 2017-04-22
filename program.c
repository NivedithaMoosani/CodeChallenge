/* C program to find the year in which the most number of people are alive */

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int n= 200;
	int list[n][2];
	int i;
	time_t t;
   
    /* Intializes random number generator */
    srand((unsigned) time(&t));

	for(i=0; i<n; i++)   /* generating a list of 200 people with the Birth year and End year*/
	{
	    list[i][0]= 1900 + rand() % 99; 
	    list[i][1]= list[i][0] + rand() % (2000-list[i][0]);
	    printf( "%d  %d\n", list[i][0], list[i][1]);
	}
	
    int changes[101];  /* from year 1900 to 2000 */
    int population_current = 0;
    int population_max = 0;
    int index = 0;
    for (i=0; i<101; i++) 
    {
        changes[i]=0;
    }
    for (i=0; i<n; i++)  
    {
        changes[list[i][0] - 1900] += 1;
        changes[list[i][1] - 1900] -= 1;
    }
    
    for (i= 0; i< 101; i++) /* Saving the latest year when there is a population rise */
    {
        population_current += changes[i];
        if ( population_current>= population_max)
        {
            population_max= population_current;
            index= i;
        }
    
    }
    printf("Most number of people are alive in the year %d and the number of people alive is %d \n", (1901+index), population_max);
	return 0;

}



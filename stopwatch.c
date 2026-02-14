#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
int main ()
{
  int sec , min , hour  ;
sec = min = hour =0 ;
while (1)
{

system("clear");
printf("^c for exit !!!!\n\n\n\n\n");
printf("%02d:%02d:%02d\t\n",hour,min,sec);


fflush(stdout);

sec++;

if (sec == 60 )
{
  min += 1;
  sec =0 ;
}
if (min == 60)
{
hour +=1 ;
min  = 0;
sec  = 0;
 
}
sleep(1);

}
}

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
int main ()
{
  initscr();
  nodelay(stdscr,TRUE);
  curs_set(0);
  cbreak();
  noecho();
int _hours , _mins , _secs ;
_secs =0;
_hours =0 ;
_mins = 0 ;


  int sec , min , hour  ;
sec =0;
hour =0 ;
min = 0 ;
while (1)
{

int input = getch();
if(input=='q' || input == 'Q' ) break;

if (input =='p'|| input == 'P')
{
  echo();
  nodelay(stdscr,FALSE);
erase();
printw("how much in hours ?!  ");
 scanw("%d",&_hours);
 refresh();

printw("how much in mins ?!  ");
 scanw("%d",&_mins);
 refresh();

 printw("how much in secs ?!  ");
 scanw("%d",&_secs);
 refresh();


  printw("you have %02d:%02d:%02d to rest , you deserve it!!!\n",_hours,_mins,_secs);
 refresh();
 

  nodelay(stdscr,TRUE);
 
while (_hours>0 || _mins >0 || _secs >0 )
{

erase();
printw("\tBREAK TIME  %02d:%02d:%02d\t\n",_hours,_mins,_secs);
refresh();

printw("\n(b)ack \n\n\n\n");

refresh();

int input = getch();
if(input=='b' || input == 'B' ) break;
sleep(1);
if (_secs > 0) 
{
_secs--;

}
else 
{
  if (_mins > 0)
  {
    _mins--;
    _secs = 59;
  }
  else 
  {
    if(_hours>0)
    {
    _hours-- ;
    _mins = 59;
    _secs =59 ;
    }
  }
}
}
noecho();
nodelay(stdscr,TRUE);
}
if(input=='r' || input == 'R' ) 
{

sec =0;
hour =0 ;
min = 0 ;

}
erase();
printw("\t%02d:%02d:%02d\t\n",hour,min,sec);
printw("\n===(r)eset...(q)uit...(p)ause===\n\n\n\n");
refresh();



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

endwin();

return 0;

}

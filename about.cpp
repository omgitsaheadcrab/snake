#include <curses.h>

#include "snake.h"

void Snake::about_splash() {
  // Clear screen
  wclear(stdscr);

  // Fill with white
  wbkgd(stdscr, COLOR_PAIR(6));


  // Write message
  attron(COLOR_PAIR(6));

  mvwaddstr(stdscr,8,4,"Author: omgitsaheadcrab");
  mvwaddstr(stdscr,9,4,"Email:  omgitsaheadcrab@gmail.com");

  mvwaddstr(stdscr,20,4,"Press any key to restart.");

  attroff(COLOR_PAIR(6));

  // Black
  attron(COLOR_PAIR(5));
  mvwaddstr(stdscr,0,nScreenWidth-6," ");
  mvwaddstr(stdscr,0,nScreenWidth-7," ");
  mvwaddstr(stdscr,0,nScreenWidth-8," ");
  mvwaddstr(stdscr,0,nScreenWidth-9," ");
  
  mvwaddstr(stdscr,1,nScreenWidth-4," ");
  mvwaddstr(stdscr,1,nScreenWidth-5," ");
  mvwaddstr(stdscr,1,nScreenWidth-10," ");
  mvwaddstr(stdscr,1,nScreenWidth-11," ");
  mvwaddstr(stdscr,1,nScreenWidth-12," ");
  mvwaddstr(stdscr,1,nScreenWidth-13," ");

  mvwaddstr(stdscr,2,nScreenWidth-4," ");
  mvwaddstr(stdscr,2,nScreenWidth-5," ");
  mvwaddstr(stdscr,2,nScreenWidth-14," ");
  mvwaddstr(stdscr,2,nScreenWidth-15," ");

  mvwaddstr(stdscr,3,nScreenWidth-6," ");
  mvwaddstr(stdscr,3,nScreenWidth-7," ");
  mvwaddstr(stdscr,3,nScreenWidth-16," ");
  mvwaddstr(stdscr,3,nScreenWidth-17," ");
  mvwaddstr(stdscr,3,nScreenWidth-18," ");
  mvwaddstr(stdscr,3,nScreenWidth-19," ");

  mvwaddstr(stdscr,4,nScreenWidth-6," ");
  mvwaddstr(stdscr,4,nScreenWidth-7," ");
  mvwaddstr(stdscr,4,nScreenWidth-20," ");
  mvwaddstr(stdscr,4,nScreenWidth-21," ");
  mvwaddstr(stdscr,4,nScreenWidth-22," ");
  mvwaddstr(stdscr,4,nScreenWidth-23," ");

  mvwaddstr(stdscr,5,nScreenWidth-8," ");
  mvwaddstr(stdscr,5,nScreenWidth-9," ");
  mvwaddstr(stdscr,5,nScreenWidth-24," ");
  mvwaddstr(stdscr,5,nScreenWidth-25," ");
  mvwaddstr(stdscr,5,nScreenWidth-26," ");
  mvwaddstr(stdscr,5,nScreenWidth-27," ");
  mvwaddstr(stdscr,5,nScreenWidth-28," ");
  mvwaddstr(stdscr,5,nScreenWidth-29," ");
  mvwaddstr(stdscr,5,nScreenWidth-30," ");
  mvwaddstr(stdscr,5,nScreenWidth-31," ");
  mvwaddstr(stdscr,5,nScreenWidth-32," ");
  mvwaddstr(stdscr,5,nScreenWidth-33," ");
  mvwaddstr(stdscr,5,nScreenWidth-34," ");
  mvwaddstr(stdscr,5,nScreenWidth-35," ");

  mvwaddstr(stdscr,6,nScreenWidth-8," ");
  mvwaddstr(stdscr,6,nScreenWidth-9," ");
  mvwaddstr(stdscr,6,nScreenWidth-36," ");
  mvwaddstr(stdscr,6,nScreenWidth-37," ");

  mvwaddstr(stdscr,7,nScreenWidth-8," ");
  mvwaddstr(stdscr,7,nScreenWidth-9," ");
  mvwaddstr(stdscr,7,nScreenWidth-34," ");
  mvwaddstr(stdscr,7,nScreenWidth-35," ");

  mvwaddstr(stdscr,8,nScreenWidth-10," ");
  mvwaddstr(stdscr,8,nScreenWidth-11," ");
  mvwaddstr(stdscr,8,nScreenWidth-28," ");
  mvwaddstr(stdscr,8,nScreenWidth-29," ");
  mvwaddstr(stdscr,8,nScreenWidth-30," ");
  mvwaddstr(stdscr,8,nScreenWidth-31," ");
  mvwaddstr(stdscr,8,nScreenWidth-32," ");
  mvwaddstr(stdscr,8,nScreenWidth-33," ");

  mvwaddstr(stdscr,9,nScreenWidth-8," ");
  mvwaddstr(stdscr,9,nScreenWidth-9," ");
  mvwaddstr(stdscr,9,nScreenWidth-22," ");
  mvwaddstr(stdscr,9,nScreenWidth-23," ");
  mvwaddstr(stdscr,9,nScreenWidth-24," ");
  mvwaddstr(stdscr,9,nScreenWidth-25," ");
  mvwaddstr(stdscr,9,nScreenWidth-26," ");
  mvwaddstr(stdscr,9,nScreenWidth-27," ");

  mvwaddstr(stdscr,10,nScreenWidth-6," ");
  mvwaddstr(stdscr,10,nScreenWidth-7," ");
  mvwaddstr(stdscr,10,nScreenWidth-16," ");
  mvwaddstr(stdscr,10,nScreenWidth-17," ");
  mvwaddstr(stdscr,10,nScreenWidth-18," ");
  mvwaddstr(stdscr,10,nScreenWidth-19," ");
  mvwaddstr(stdscr,10,nScreenWidth-20," ");
  mvwaddstr(stdscr,10,nScreenWidth-21," ");
  mvwaddstr(stdscr,10,nScreenWidth-22," ");
  mvwaddstr(stdscr,10,nScreenWidth-23," ");
  mvwaddstr(stdscr,10,nScreenWidth-24," ");
  mvwaddstr(stdscr,10,nScreenWidth-25," ");
  mvwaddstr(stdscr,10,nScreenWidth-28," ");
  mvwaddstr(stdscr,10,nScreenWidth-29," ");

  mvwaddstr(stdscr,11,nScreenWidth-4," ");
  mvwaddstr(stdscr,11,nScreenWidth-5," ");
  mvwaddstr(stdscr,11,nScreenWidth-12," ");
  mvwaddstr(stdscr,11,nScreenWidth-13," ");
  mvwaddstr(stdscr,11,nScreenWidth-14," ");
  mvwaddstr(stdscr,11,nScreenWidth-15," ");
  mvwaddstr(stdscr,11,nScreenWidth-16," ");
  mvwaddstr(stdscr,11,nScreenWidth-17," ");
  mvwaddstr(stdscr,11,nScreenWidth-18," ");
  mvwaddstr(stdscr,11,nScreenWidth-19," ");
  mvwaddstr(stdscr,11,nScreenWidth-22," ");
  mvwaddstr(stdscr,11,nScreenWidth-23," ");
  mvwaddstr(stdscr,11,nScreenWidth-24," ");
  mvwaddstr(stdscr,11,nScreenWidth-25," ");
  mvwaddstr(stdscr,11,nScreenWidth-28," ");
  mvwaddstr(stdscr,11,nScreenWidth-29," ");
  mvwaddstr(stdscr,11,nScreenWidth-30," ");
  mvwaddstr(stdscr,11,nScreenWidth-31," ");

  mvwaddstr(stdscr,12,nScreenWidth-2," ");
  mvwaddstr(stdscr,12,nScreenWidth-3," ");
  mvwaddstr(stdscr,12,nScreenWidth-8," ");
  mvwaddstr(stdscr,12,nScreenWidth-9," ");
  mvwaddstr(stdscr,12,nScreenWidth-12," ");
  mvwaddstr(stdscr,12,nScreenWidth-13," ");
  mvwaddstr(stdscr,12,nScreenWidth-14," ");
  mvwaddstr(stdscr,12,nScreenWidth-15," ");
  mvwaddstr(stdscr,12,nScreenWidth-16," ");
  mvwaddstr(stdscr,12,nScreenWidth-17," ");
  mvwaddstr(stdscr,12,nScreenWidth-18," ");
  mvwaddstr(stdscr,12,nScreenWidth-19," ");
  mvwaddstr(stdscr,12,nScreenWidth-22," ");
  mvwaddstr(stdscr,12,nScreenWidth-23," ");
  mvwaddstr(stdscr,12,nScreenWidth-24," ");
  mvwaddstr(stdscr,12,nScreenWidth-25," ");
  mvwaddstr(stdscr,12,nScreenWidth-26," ");
  mvwaddstr(stdscr,12,nScreenWidth-27," ");
  mvwaddstr(stdscr,12,nScreenWidth-28," ");
  mvwaddstr(stdscr,12,nScreenWidth-29," ");
  mvwaddstr(stdscr,12,nScreenWidth-32," ");
  mvwaddstr(stdscr,12,nScreenWidth-33," ");

  mvwaddstr(stdscr,13,nScreenWidth-4," ");
  mvwaddstr(stdscr,13,nScreenWidth-5," ");
  mvwaddstr(stdscr,13,nScreenWidth-6," ");
  mvwaddstr(stdscr,13,nScreenWidth-7," ");
  mvwaddstr(stdscr,13,nScreenWidth-10," ");
  mvwaddstr(stdscr,13,nScreenWidth-11," ");
  mvwaddstr(stdscr,13,nScreenWidth-12," ");
  mvwaddstr(stdscr,13,nScreenWidth-13," ");
  mvwaddstr(stdscr,13,nScreenWidth-14," ");
  mvwaddstr(stdscr,13,nScreenWidth-15," ");
  mvwaddstr(stdscr,13,nScreenWidth-16," ");
  mvwaddstr(stdscr,13,nScreenWidth-17," ");
  mvwaddstr(stdscr,13,nScreenWidth-18," ");
  mvwaddstr(stdscr,13,nScreenWidth-19," ");
  mvwaddstr(stdscr,13,nScreenWidth-20," ");
  mvwaddstr(stdscr,13,nScreenWidth-21," ");
  mvwaddstr(stdscr,13,nScreenWidth-22," ");
  mvwaddstr(stdscr,13,nScreenWidth-23," ");
  mvwaddstr(stdscr,13,nScreenWidth-24," ");
  mvwaddstr(stdscr,13,nScreenWidth-25," ");
  mvwaddstr(stdscr,13,nScreenWidth-26," ");
  mvwaddstr(stdscr,13,nScreenWidth-27," ");
  mvwaddstr(stdscr,13,nScreenWidth-28," ");
  mvwaddstr(stdscr,13,nScreenWidth-29," ");
  mvwaddstr(stdscr,13,nScreenWidth-30," ");
  mvwaddstr(stdscr,13,nScreenWidth-31," ");
  mvwaddstr(stdscr,13,nScreenWidth-34," ");
  mvwaddstr(stdscr,13,nScreenWidth-35," ");

  mvwaddstr(stdscr,14,nScreenWidth-6," ");
  mvwaddstr(stdscr,14,nScreenWidth-7," ");
  mvwaddstr(stdscr,14,nScreenWidth-22," ");
  mvwaddstr(stdscr,14,nScreenWidth-23," ");
  mvwaddstr(stdscr,14,nScreenWidth-24," ");
  mvwaddstr(stdscr,14,nScreenWidth-25," ");
  mvwaddstr(stdscr,14,nScreenWidth-26," ");
  mvwaddstr(stdscr,14,nScreenWidth-27," ");
  mvwaddstr(stdscr,14,nScreenWidth-34," ");
  mvwaddstr(stdscr,14,nScreenWidth-35," ");

  mvwaddstr(stdscr,15,nScreenWidth-8," ");
  mvwaddstr(stdscr,15,nScreenWidth-9," ");
  mvwaddstr(stdscr,15,nScreenWidth-14," ");
  mvwaddstr(stdscr,15,nScreenWidth-15," ");
  mvwaddstr(stdscr,15,nScreenWidth-16," ");
  mvwaddstr(stdscr,15,nScreenWidth-17," ");
  mvwaddstr(stdscr,15,nScreenWidth-18," ");
  mvwaddstr(stdscr,15,nScreenWidth-19," ");
  mvwaddstr(stdscr,15,nScreenWidth-32," ");
  mvwaddstr(stdscr,15,nScreenWidth-33," ");
  mvwaddstr(stdscr,15,nScreenWidth-34," ");
  mvwaddstr(stdscr,15,nScreenWidth-35," ");

  mvwaddstr(stdscr,16,nScreenWidth-6," ");
  mvwaddstr(stdscr,16,nScreenWidth-7," ");
  mvwaddstr(stdscr,16,nScreenWidth-20," ");
  mvwaddstr(stdscr,16,nScreenWidth-21," ");
  mvwaddstr(stdscr,16,nScreenWidth-22," ");
  mvwaddstr(stdscr,16,nScreenWidth-23," ");
  mvwaddstr(stdscr,16,nScreenWidth-30," ");
  mvwaddstr(stdscr,16,nScreenWidth-31," ");
  mvwaddstr(stdscr,16,nScreenWidth-36," ");
  mvwaddstr(stdscr,16,nScreenWidth-37," ");

  mvwaddstr(stdscr,17,nScreenWidth-6," ");
  mvwaddstr(stdscr,17,nScreenWidth-7," ");
  mvwaddstr(stdscr,17,nScreenWidth-20," ");
  mvwaddstr(stdscr,17,nScreenWidth-21," ");
  mvwaddstr(stdscr,17,nScreenWidth-22," ");
  mvwaddstr(stdscr,17,nScreenWidth-23," ");
  mvwaddstr(stdscr,17,nScreenWidth-24," ");
  mvwaddstr(stdscr,17,nScreenWidth-25," ");
  mvwaddstr(stdscr,17,nScreenWidth-30," ");
  mvwaddstr(stdscr,17,nScreenWidth-31," ");
  mvwaddstr(stdscr,17,nScreenWidth-36," ");
  mvwaddstr(stdscr,17,nScreenWidth-37," ");

  mvwaddstr(stdscr,18,nScreenWidth-6," ");
  mvwaddstr(stdscr,18,nScreenWidth-7," ");
  mvwaddstr(stdscr,18,nScreenWidth-20," ");
  mvwaddstr(stdscr,18,nScreenWidth-21," ");
  mvwaddstr(stdscr,18,nScreenWidth-32," ");
  mvwaddstr(stdscr,18,nScreenWidth-33," ");
  mvwaddstr(stdscr,18,nScreenWidth-34," ");
  mvwaddstr(stdscr,18,nScreenWidth-35," ");

  mvwaddstr(stdscr,19,nScreenWidth-6," ");
  mvwaddstr(stdscr,19,nScreenWidth-7," ");
  mvwaddstr(stdscr,19,nScreenWidth-20," ");
  mvwaddstr(stdscr,19,nScreenWidth-21," ");
  mvwaddstr(stdscr,19,nScreenWidth-30," ");
  mvwaddstr(stdscr,19,nScreenWidth-31," ");
  mvwaddstr(stdscr,19,nScreenWidth-34," ");
  mvwaddstr(stdscr,19,nScreenWidth-35," ");

  mvwaddstr(stdscr,20,nScreenWidth-8," ");
  mvwaddstr(stdscr,20,nScreenWidth-9," ");
  mvwaddstr(stdscr,20,nScreenWidth-20," ");
  mvwaddstr(stdscr,20,nScreenWidth-21," ");
  mvwaddstr(stdscr,20,nScreenWidth-22," ");
  mvwaddstr(stdscr,20,nScreenWidth-23," ");
  mvwaddstr(stdscr,20,nScreenWidth-24," ");
  mvwaddstr(stdscr,20,nScreenWidth-25," ");
  mvwaddstr(stdscr,20,nScreenWidth-30," ");
  mvwaddstr(stdscr,20,nScreenWidth-31," ");
  mvwaddstr(stdscr,20,nScreenWidth-34," ");
  mvwaddstr(stdscr,20,nScreenWidth-35," ");

  mvwaddstr(stdscr,21,nScreenWidth-8," ");
  mvwaddstr(stdscr,21,nScreenWidth-9," ");
  mvwaddstr(stdscr,21,nScreenWidth-18," ");
  mvwaddstr(stdscr,21,nScreenWidth-19," ");
  mvwaddstr(stdscr,21,nScreenWidth-28," ");
  mvwaddstr(stdscr,21,nScreenWidth-29," ");
  mvwaddstr(stdscr,21,nScreenWidth-34," ");
  mvwaddstr(stdscr,21,nScreenWidth-35," ");
  
  mvwaddstr(stdscr,22,nScreenWidth-8," ");
  mvwaddstr(stdscr,22,nScreenWidth-9," ");
  mvwaddstr(stdscr,22,nScreenWidth-18," ");
  mvwaddstr(stdscr,22,nScreenWidth-19," ");
  mvwaddstr(stdscr,22,nScreenWidth-26," ");
  mvwaddstr(stdscr,22,nScreenWidth-27," ");
  mvwaddstr(stdscr,22,nScreenWidth-34," ");
  mvwaddstr(stdscr,22,nScreenWidth-35," ");

  mvwaddstr(stdscr,23,nScreenWidth-6," ");
  mvwaddstr(stdscr,23,nScreenWidth-7," ");
  mvwaddstr(stdscr,23,nScreenWidth-10," ");
  mvwaddstr(stdscr,23,nScreenWidth-11," ");
  mvwaddstr(stdscr,23,nScreenWidth-16," ");
  mvwaddstr(stdscr,23,nScreenWidth-17," ");
  mvwaddstr(stdscr,23,nScreenWidth-22," ");
  mvwaddstr(stdscr,23,nScreenWidth-23," ");
  mvwaddstr(stdscr,23,nScreenWidth-24," ");
  mvwaddstr(stdscr,23,nScreenWidth-25," ");
  mvwaddstr(stdscr,23,nScreenWidth-34," ");
  mvwaddstr(stdscr,23,nScreenWidth-35," ");

  mvwaddstr(stdscr,24,nScreenWidth-4," ");
  mvwaddstr(stdscr,24,nScreenWidth-5," ");
  mvwaddstr(stdscr,24,nScreenWidth-12," ");
  mvwaddstr(stdscr,24,nScreenWidth-13," ");
  mvwaddstr(stdscr,24,nScreenWidth-14," ");
  mvwaddstr(stdscr,24,nScreenWidth-15," ");
  mvwaddstr(stdscr,24,nScreenWidth-36," ");
  mvwaddstr(stdscr,24,nScreenWidth-37," ");

  mvwaddstr(stdscr,25,nScreenWidth-6," ");
  mvwaddstr(stdscr,25,nScreenWidth-7," ");
  mvwaddstr(stdscr,25,nScreenWidth-8," ");
  mvwaddstr(stdscr,25,nScreenWidth-9," ");
  mvwaddstr(stdscr,25,nScreenWidth-10," ");
  mvwaddstr(stdscr,25,nScreenWidth-11," ");
  mvwaddstr(stdscr,25,nScreenWidth-16," ");
  mvwaddstr(stdscr,25,nScreenWidth-17," ");
  mvwaddstr(stdscr,25,nScreenWidth-18," ");
  mvwaddstr(stdscr,25,nScreenWidth-19," ");
  mvwaddstr(stdscr,25,nScreenWidth-20," ");
  mvwaddstr(stdscr,25,nScreenWidth-21," ");
  mvwaddstr(stdscr,25,nScreenWidth-22," ");
  mvwaddstr(stdscr,25,nScreenWidth-23," ");
  mvwaddstr(stdscr,25,nScreenWidth-24," ");
  mvwaddstr(stdscr,25,nScreenWidth-25," ");
  mvwaddstr(stdscr,25,nScreenWidth-26," ");
  mvwaddstr(stdscr,25,nScreenWidth-27," ");
  mvwaddstr(stdscr,25,nScreenWidth-28," ");
  mvwaddstr(stdscr,25,nScreenWidth-29," ");
  mvwaddstr(stdscr,25,nScreenWidth-30," ");
  mvwaddstr(stdscr,25,nScreenWidth-31," ");
  mvwaddstr(stdscr,25,nScreenWidth-32," ");
  mvwaddstr(stdscr,25,nScreenWidth-33," ");
  mvwaddstr(stdscr,25,nScreenWidth-34," ");
  mvwaddstr(stdscr,25,nScreenWidth-35," ");
  
  attroff(COLOR_PAIR(5));
  
  // Bright yellow
  attron(COLOR_PAIR(2));

  mvwaddstr(stdscr,1,nScreenWidth-6," ");
  mvwaddstr(stdscr,1,nScreenWidth-7," ");
  mvwaddstr(stdscr,1,nScreenWidth-8," ");
  mvwaddstr(stdscr,1,nScreenWidth-9," ");

  mvwaddstr(stdscr,2,nScreenWidth-8," ");
  mvwaddstr(stdscr,2,nScreenWidth-9," ");
  mvwaddstr(stdscr,2,nScreenWidth-10," ");
  mvwaddstr(stdscr,2,nScreenWidth-11," ");
  mvwaddstr(stdscr,2,nScreenWidth-12," ");
  mvwaddstr(stdscr,2,nScreenWidth-13," ");
  
  mvwaddstr(stdscr,3,nScreenWidth-10," ");
  mvwaddstr(stdscr,3,nScreenWidth-11," ");
  mvwaddstr(stdscr,3,nScreenWidth-12," ");
  mvwaddstr(stdscr,3,nScreenWidth-13," ");
  mvwaddstr(stdscr,3,nScreenWidth-14," ");
  mvwaddstr(stdscr,3,nScreenWidth-15," ");

  mvwaddstr(stdscr,4,nScreenWidth-12," ");
  mvwaddstr(stdscr,4,nScreenWidth-13," ");
  mvwaddstr(stdscr,4,nScreenWidth-14," ");
  mvwaddstr(stdscr,4,nScreenWidth-15," ");
  mvwaddstr(stdscr,4,nScreenWidth-16," ");
  mvwaddstr(stdscr,4,nScreenWidth-17," ");
  mvwaddstr(stdscr,4,nScreenWidth-18," ");
  mvwaddstr(stdscr,4,nScreenWidth-19," ");
  
  mvwaddstr(stdscr,5,nScreenWidth-16," ");
  mvwaddstr(stdscr,5,nScreenWidth-17," ");
  mvwaddstr(stdscr,5,nScreenWidth-18," ");
  mvwaddstr(stdscr,5,nScreenWidth-19," ");
  mvwaddstr(stdscr,5,nScreenWidth-20," ");
  mvwaddstr(stdscr,5,nScreenWidth-21," ");
  mvwaddstr(stdscr,5,nScreenWidth-22," ");
  mvwaddstr(stdscr,5,nScreenWidth-23," ");

  mvwaddstr(stdscr,6,nScreenWidth-20," ");
  mvwaddstr(stdscr,6,nScreenWidth-21," ");
  mvwaddstr(stdscr,6,nScreenWidth-22," ");
  mvwaddstr(stdscr,6,nScreenWidth-23," ");
  mvwaddstr(stdscr,6,nScreenWidth-24," ");
  mvwaddstr(stdscr,6,nScreenWidth-25," ");
  mvwaddstr(stdscr,6,nScreenWidth-26," ");
  mvwaddstr(stdscr,6,nScreenWidth-27," ");
  mvwaddstr(stdscr,6,nScreenWidth-28," ");
  mvwaddstr(stdscr,6,nScreenWidth-29," ");
  mvwaddstr(stdscr,6,nScreenWidth-30," ");
  mvwaddstr(stdscr,6,nScreenWidth-31," ");
  mvwaddstr(stdscr,6,nScreenWidth-32," ");
  mvwaddstr(stdscr,6,nScreenWidth-33," ");
  mvwaddstr(stdscr,6,nScreenWidth-34," ");
  mvwaddstr(stdscr,6,nScreenWidth-35," ");

  mvwaddstr(stdscr,7,nScreenWidth-18," ");
  mvwaddstr(stdscr,7,nScreenWidth-19," ");
  mvwaddstr(stdscr,7,nScreenWidth-20," ");
  mvwaddstr(stdscr,7,nScreenWidth-21," ");
  mvwaddstr(stdscr,7,nScreenWidth-22," ");
  mvwaddstr(stdscr,7,nScreenWidth-23," ");
  mvwaddstr(stdscr,7,nScreenWidth-24," ");
  mvwaddstr(stdscr,7,nScreenWidth-25," ");

  mvwaddstr(stdscr,8,nScreenWidth-14," ");
  mvwaddstr(stdscr,8,nScreenWidth-15," ");
  mvwaddstr(stdscr,8,nScreenWidth-16," ");
  mvwaddstr(stdscr,8,nScreenWidth-17," ");
  mvwaddstr(stdscr,8,nScreenWidth-18," ");
  mvwaddstr(stdscr,8,nScreenWidth-19," ");

  mvwaddstr(stdscr,10,nScreenWidth-26," ");
  mvwaddstr(stdscr,10,nScreenWidth-27," ");
    
  mvwaddstr(stdscr,11,nScreenWidth-20," ");
  mvwaddstr(stdscr,11,nScreenWidth-21," ");
  mvwaddstr(stdscr,11,nScreenWidth-26," ");
  mvwaddstr(stdscr,11,nScreenWidth-27," ");

  mvwaddstr(stdscr,12,nScreenWidth-20," ");
  mvwaddstr(stdscr,12,nScreenWidth-21," ");

  mvwaddstr(stdscr,16,nScreenWidth-32," ");
  mvwaddstr(stdscr,16,nScreenWidth-33," ");
  mvwaddstr(stdscr,16,nScreenWidth-34," ");
  mvwaddstr(stdscr,16,nScreenWidth-35," ");

  mvwaddstr(stdscr,17,nScreenWidth-32," ");
  mvwaddstr(stdscr,17,nScreenWidth-33," ");
  mvwaddstr(stdscr,17,nScreenWidth-34," ");
  mvwaddstr(stdscr,17,nScreenWidth-35," ");

  mvwaddstr(stdscr,18,nScreenWidth-22," ");
  mvwaddstr(stdscr,18,nScreenWidth-23," ");
  mvwaddstr(stdscr,18,nScreenWidth-24," ");
  mvwaddstr(stdscr,18,nScreenWidth-25," ");

  mvwaddstr(stdscr,19,nScreenWidth-22," ");
  mvwaddstr(stdscr,19,nScreenWidth-23," ");
  mvwaddstr(stdscr,19,nScreenWidth-24," ");
  mvwaddstr(stdscr,19,nScreenWidth-25," ");
  
  attroff(COLOR_PAIR(2));

  // Dirty yellow
  attron(COLOR_PAIR(3));

  mvwaddstr(stdscr,2,nScreenWidth-6," ");
  mvwaddstr(stdscr,2,nScreenWidth-7," ");

  mvwaddstr(stdscr,3,nScreenWidth-8," ");
  mvwaddstr(stdscr,3,nScreenWidth-9," ");

  mvwaddstr(stdscr,4,nScreenWidth-8," ");
  mvwaddstr(stdscr,4,nScreenWidth-9," ");
  mvwaddstr(stdscr,4,nScreenWidth-10," ");
  mvwaddstr(stdscr,4,nScreenWidth-11," ");

  mvwaddstr(stdscr,5,nScreenWidth-10," ");
  mvwaddstr(stdscr,5,nScreenWidth-11," ");
  mvwaddstr(stdscr,5,nScreenWidth-12," ");
  mvwaddstr(stdscr,5,nScreenWidth-13," ");
  mvwaddstr(stdscr,5,nScreenWidth-14," ");
  mvwaddstr(stdscr,5,nScreenWidth-15," ");

  mvwaddstr(stdscr,6,nScreenWidth-10," ");
  mvwaddstr(stdscr,6,nScreenWidth-11," ");
  mvwaddstr(stdscr,6,nScreenWidth-12," ");
  mvwaddstr(stdscr,6,nScreenWidth-13," ");
  mvwaddstr(stdscr,6,nScreenWidth-14," ");
  mvwaddstr(stdscr,6,nScreenWidth-15," ");
  mvwaddstr(stdscr,6,nScreenWidth-16," ");
  mvwaddstr(stdscr,6,nScreenWidth-17," ");
  mvwaddstr(stdscr,6,nScreenWidth-18," ");
  mvwaddstr(stdscr,6,nScreenWidth-19," ");

  mvwaddstr(stdscr,7,nScreenWidth-10," ");
  mvwaddstr(stdscr,7,nScreenWidth-11," ");
  mvwaddstr(stdscr,7,nScreenWidth-12," ");
  mvwaddstr(stdscr,7,nScreenWidth-13," ");
  mvwaddstr(stdscr,7,nScreenWidth-14," ");
  mvwaddstr(stdscr,7,nScreenWidth-15," ");
  mvwaddstr(stdscr,7,nScreenWidth-16," ");
  mvwaddstr(stdscr,7,nScreenWidth-17," ");
  mvwaddstr(stdscr,7,nScreenWidth-26," ");
  mvwaddstr(stdscr,7,nScreenWidth-27," ");
  mvwaddstr(stdscr,7,nScreenWidth-28," ");
  mvwaddstr(stdscr,7,nScreenWidth-29," ");
  mvwaddstr(stdscr,7,nScreenWidth-30," ");
  mvwaddstr(stdscr,7,nScreenWidth-31," ");
  mvwaddstr(stdscr,7,nScreenWidth-32," ");
  mvwaddstr(stdscr,7,nScreenWidth-33," ");
  
  mvwaddstr(stdscr,8,nScreenWidth-12," ");
  mvwaddstr(stdscr,8,nScreenWidth-13," ");
  mvwaddstr(stdscr,8,nScreenWidth-20," ");
  mvwaddstr(stdscr,8,nScreenWidth-21," ");
  mvwaddstr(stdscr,8,nScreenWidth-22," ");
  mvwaddstr(stdscr,8,nScreenWidth-23," ");
  mvwaddstr(stdscr,8,nScreenWidth-24," ");
  mvwaddstr(stdscr,8,nScreenWidth-25," ");
  mvwaddstr(stdscr,8,nScreenWidth-26," ");
  mvwaddstr(stdscr,8,nScreenWidth-27," ");

  mvwaddstr(stdscr,9,nScreenWidth-10," ");
  mvwaddstr(stdscr,9,nScreenWidth-11," ");
  mvwaddstr(stdscr,9,nScreenWidth-12," ");
  mvwaddstr(stdscr,9,nScreenWidth-13," ");
  mvwaddstr(stdscr,9,nScreenWidth-14," ");
  mvwaddstr(stdscr,9,nScreenWidth-15," ");
  mvwaddstr(stdscr,9,nScreenWidth-16," ");
  mvwaddstr(stdscr,9,nScreenWidth-17," ");
  mvwaddstr(stdscr,9,nScreenWidth-18," ");
  mvwaddstr(stdscr,9,nScreenWidth-19," ");
  mvwaddstr(stdscr,9,nScreenWidth-20," ");
  mvwaddstr(stdscr,9,nScreenWidth-21," ");

  mvwaddstr(stdscr,10,nScreenWidth-8," ");
  mvwaddstr(stdscr,10,nScreenWidth-9," ");
  mvwaddstr(stdscr,10,nScreenWidth-10," ");
  mvwaddstr(stdscr,10,nScreenWidth-11," ");
  mvwaddstr(stdscr,10,nScreenWidth-12," ");
  mvwaddstr(stdscr,10,nScreenWidth-13," ");
  mvwaddstr(stdscr,10,nScreenWidth-14," ");
  mvwaddstr(stdscr,10,nScreenWidth-15," ");

  mvwaddstr(stdscr,11,nScreenWidth-6," ");
  mvwaddstr(stdscr,11,nScreenWidth-7," ");
  mvwaddstr(stdscr,11,nScreenWidth-8," ");
  mvwaddstr(stdscr,11,nScreenWidth-9," ");
  mvwaddstr(stdscr,11,nScreenWidth-10," ");
  mvwaddstr(stdscr,11,nScreenWidth-11," ");
  
  mvwaddstr(stdscr,12,nScreenWidth-4," ");
  mvwaddstr(stdscr,12,nScreenWidth-5," ");
  mvwaddstr(stdscr,12,nScreenWidth-6," ");
  mvwaddstr(stdscr,12,nScreenWidth-7," ");
  
  attroff(COLOR_PAIR(3));

  // Blue
  attron(COLOR_PAIR(4));

  mvwaddstr(stdscr,12,nScreenWidth-10," ");
  mvwaddstr(stdscr,12,nScreenWidth-11," ");
  mvwaddstr(stdscr,12,nScreenWidth-30," ");
  mvwaddstr(stdscr,12,nScreenWidth-31," ");
  
  mvwaddstr(stdscr,13,nScreenWidth-8," ");
  mvwaddstr(stdscr,13,nScreenWidth-9," ");
  mvwaddstr(stdscr,13,nScreenWidth-32," ");
  mvwaddstr(stdscr,13,nScreenWidth-33," ");
  
  mvwaddstr(stdscr,14,nScreenWidth-8," ");
  mvwaddstr(stdscr,14,nScreenWidth-9," ");
  mvwaddstr(stdscr,14,nScreenWidth-10," ");
  mvwaddstr(stdscr,14,nScreenWidth-11," ");
  mvwaddstr(stdscr,14,nScreenWidth-12," ");
  mvwaddstr(stdscr,14,nScreenWidth-13," ");
  mvwaddstr(stdscr,14,nScreenWidth-14," ");
  mvwaddstr(stdscr,14,nScreenWidth-15," ");
  mvwaddstr(stdscr,14,nScreenWidth-16," ");
  mvwaddstr(stdscr,14,nScreenWidth-17," ");
  mvwaddstr(stdscr,14,nScreenWidth-18," ");
  mvwaddstr(stdscr,14,nScreenWidth-19," ");
  mvwaddstr(stdscr,14,nScreenWidth-20," ");
  mvwaddstr(stdscr,14,nScreenWidth-21," ");
  mvwaddstr(stdscr,14,nScreenWidth-28," ");
  mvwaddstr(stdscr,14,nScreenWidth-29," ");
  mvwaddstr(stdscr,14,nScreenWidth-30," ");
  mvwaddstr(stdscr,14,nScreenWidth-31," ");
  mvwaddstr(stdscr,14,nScreenWidth-32," ");
  mvwaddstr(stdscr,14,nScreenWidth-33," ");

  mvwaddstr(stdscr,15,nScreenWidth-10," ");
  mvwaddstr(stdscr,15,nScreenWidth-11," ");
  mvwaddstr(stdscr,15,nScreenWidth-12," ");
  mvwaddstr(stdscr,15,nScreenWidth-13," ");
  mvwaddstr(stdscr,15,nScreenWidth-20," ");
  mvwaddstr(stdscr,15,nScreenWidth-21," ");
  mvwaddstr(stdscr,15,nScreenWidth-22," ");
  mvwaddstr(stdscr,15,nScreenWidth-23," ");
  mvwaddstr(stdscr,15,nScreenWidth-24," ");
  mvwaddstr(stdscr,15,nScreenWidth-25," ");
  mvwaddstr(stdscr,15,nScreenWidth-26," ");
  mvwaddstr(stdscr,15,nScreenWidth-27," ");
  mvwaddstr(stdscr,15,nScreenWidth-28," ");
  mvwaddstr(stdscr,15,nScreenWidth-29," ");
  mvwaddstr(stdscr,15,nScreenWidth-30," ");
  mvwaddstr(stdscr,15,nScreenWidth-31," ");
  
  mvwaddstr(stdscr,16,nScreenWidth-8," ");
  mvwaddstr(stdscr,16,nScreenWidth-9," ");
  mvwaddstr(stdscr,16,nScreenWidth-10," ");
  mvwaddstr(stdscr,16,nScreenWidth-11," ");
  mvwaddstr(stdscr,16,nScreenWidth-12," ");
  mvwaddstr(stdscr,16,nScreenWidth-13," ");
  mvwaddstr(stdscr,16,nScreenWidth-14," ");
  mvwaddstr(stdscr,16,nScreenWidth-15," ");
  mvwaddstr(stdscr,16,nScreenWidth-16," ");
  mvwaddstr(stdscr,16,nScreenWidth-17," ");
  mvwaddstr(stdscr,16,nScreenWidth-18," ");
  mvwaddstr(stdscr,16,nScreenWidth-19," ");
  mvwaddstr(stdscr,16,nScreenWidth-24," ");
  mvwaddstr(stdscr,16,nScreenWidth-25," ");
  mvwaddstr(stdscr,16,nScreenWidth-26," ");
  mvwaddstr(stdscr,16,nScreenWidth-27," ");
  mvwaddstr(stdscr,16,nScreenWidth-28," ");
  mvwaddstr(stdscr,16,nScreenWidth-29," ");
  
  mvwaddstr(stdscr,17,nScreenWidth-8," ");
  mvwaddstr(stdscr,17,nScreenWidth-9," ");
  mvwaddstr(stdscr,17,nScreenWidth-10," ");
  mvwaddstr(stdscr,17,nScreenWidth-11," ");
  mvwaddstr(stdscr,17,nScreenWidth-12," ");
  mvwaddstr(stdscr,17,nScreenWidth-13," ");
  mvwaddstr(stdscr,17,nScreenWidth-14," ");
  mvwaddstr(stdscr,17,nScreenWidth-15," ");
  mvwaddstr(stdscr,17,nScreenWidth-16," ");
  mvwaddstr(stdscr,17,nScreenWidth-17," ");
  mvwaddstr(stdscr,17,nScreenWidth-18," ");
  mvwaddstr(stdscr,17,nScreenWidth-19," ");
  mvwaddstr(stdscr,17,nScreenWidth-26," ");
  mvwaddstr(stdscr,17,nScreenWidth-27," ");
  mvwaddstr(stdscr,17,nScreenWidth-28," ");
  mvwaddstr(stdscr,17,nScreenWidth-29," ");

  mvwaddstr(stdscr,18,nScreenWidth-8," ");
  mvwaddstr(stdscr,18,nScreenWidth-9," ");
  mvwaddstr(stdscr,18,nScreenWidth-10," ");
  mvwaddstr(stdscr,18,nScreenWidth-11," ");
  mvwaddstr(stdscr,18,nScreenWidth-12," ");
  mvwaddstr(stdscr,18,nScreenWidth-13," ");
  mvwaddstr(stdscr,18,nScreenWidth-14," ");
  mvwaddstr(stdscr,18,nScreenWidth-15," ");
  mvwaddstr(stdscr,18,nScreenWidth-16," ");
  mvwaddstr(stdscr,18,nScreenWidth-17," ");
  mvwaddstr(stdscr,18,nScreenWidth-18," ");
  mvwaddstr(stdscr,18,nScreenWidth-19," ");
  mvwaddstr(stdscr,18,nScreenWidth-26," ");
  mvwaddstr(stdscr,18,nScreenWidth-27," ");
  mvwaddstr(stdscr,18,nScreenWidth-28," ");
  mvwaddstr(stdscr,18,nScreenWidth-29," ");
  mvwaddstr(stdscr,18,nScreenWidth-30," ");
  mvwaddstr(stdscr,18,nScreenWidth-31," ");
  
  mvwaddstr(stdscr,19,nScreenWidth-8," ");
  mvwaddstr(stdscr,19,nScreenWidth-9," ");
  mvwaddstr(stdscr,19,nScreenWidth-10," ");
  mvwaddstr(stdscr,19,nScreenWidth-11," ");
  mvwaddstr(stdscr,19,nScreenWidth-12," ");
  mvwaddstr(stdscr,19,nScreenWidth-13," ");
  mvwaddstr(stdscr,19,nScreenWidth-14," ");
  mvwaddstr(stdscr,19,nScreenWidth-15," ");
  mvwaddstr(stdscr,19,nScreenWidth-16," ");
  mvwaddstr(stdscr,19,nScreenWidth-17," ");
  mvwaddstr(stdscr,19,nScreenWidth-18," ");
  mvwaddstr(stdscr,19,nScreenWidth-19," ");
  mvwaddstr(stdscr,19,nScreenWidth-26," ");
  mvwaddstr(stdscr,19,nScreenWidth-27," ");
  mvwaddstr(stdscr,19,nScreenWidth-28," ");
  mvwaddstr(stdscr,19,nScreenWidth-29," ");
  mvwaddstr(stdscr,19,nScreenWidth-32," ");
  mvwaddstr(stdscr,19,nScreenWidth-33," ");

  mvwaddstr(stdscr,20,nScreenWidth-10," ");
  mvwaddstr(stdscr,20,nScreenWidth-11," ");
  mvwaddstr(stdscr,20,nScreenWidth-12," ");
  mvwaddstr(stdscr,20,nScreenWidth-13," ");
  mvwaddstr(stdscr,20,nScreenWidth-14," ");
  mvwaddstr(stdscr,20,nScreenWidth-15," ");
  mvwaddstr(stdscr,20,nScreenWidth-16," ");
  mvwaddstr(stdscr,20,nScreenWidth-17," ");
  mvwaddstr(stdscr,20,nScreenWidth-18," ");
  mvwaddstr(stdscr,20,nScreenWidth-19," ");
  mvwaddstr(stdscr,20,nScreenWidth-26," ");
  mvwaddstr(stdscr,20,nScreenWidth-27," ");
  mvwaddstr(stdscr,20,nScreenWidth-28," ");
  mvwaddstr(stdscr,20,nScreenWidth-29," ");
  mvwaddstr(stdscr,20,nScreenWidth-32," ");
  mvwaddstr(stdscr,20,nScreenWidth-33," ");

  mvwaddstr(stdscr,21,nScreenWidth-10," ");
  mvwaddstr(stdscr,21,nScreenWidth-11," ");
  mvwaddstr(stdscr,21,nScreenWidth-12," ");
  mvwaddstr(stdscr,21,nScreenWidth-13," ");
  mvwaddstr(stdscr,21,nScreenWidth-14," ");
  mvwaddstr(stdscr,21,nScreenWidth-15," ");
  mvwaddstr(stdscr,21,nScreenWidth-16," ");
  mvwaddstr(stdscr,21,nScreenWidth-17," ");
  mvwaddstr(stdscr,21,nScreenWidth-20," ");
  mvwaddstr(stdscr,21,nScreenWidth-21," ");
  mvwaddstr(stdscr,21,nScreenWidth-22," ");
  mvwaddstr(stdscr,21,nScreenWidth-23," ");
  mvwaddstr(stdscr,21,nScreenWidth-24," ");
  mvwaddstr(stdscr,21,nScreenWidth-25," ");
  mvwaddstr(stdscr,21,nScreenWidth-26," ");
  mvwaddstr(stdscr,21,nScreenWidth-27," ");
  mvwaddstr(stdscr,21,nScreenWidth-30," ");
  mvwaddstr(stdscr,21,nScreenWidth-31," ");
  mvwaddstr(stdscr,21,nScreenWidth-32," ");
  mvwaddstr(stdscr,21,nScreenWidth-33," ");
  
  mvwaddstr(stdscr,22,nScreenWidth-10," ");
  mvwaddstr(stdscr,22,nScreenWidth-11," ");
  mvwaddstr(stdscr,22,nScreenWidth-12," ");
  mvwaddstr(stdscr,22,nScreenWidth-13," ");
  mvwaddstr(stdscr,22,nScreenWidth-14," ");
  mvwaddstr(stdscr,22,nScreenWidth-15," ");
  mvwaddstr(stdscr,22,nScreenWidth-16," ");
  mvwaddstr(stdscr,22,nScreenWidth-17," ");
  mvwaddstr(stdscr,22,nScreenWidth-20," ");
  mvwaddstr(stdscr,22,nScreenWidth-21," ");
  mvwaddstr(stdscr,22,nScreenWidth-22," ");
  mvwaddstr(stdscr,22,nScreenWidth-23," ");
  mvwaddstr(stdscr,22,nScreenWidth-24," ");
  mvwaddstr(stdscr,22,nScreenWidth-25," ");
  mvwaddstr(stdscr,22,nScreenWidth-28," ");
  mvwaddstr(stdscr,22,nScreenWidth-29," ");
  mvwaddstr(stdscr,22,nScreenWidth-30," ");
  mvwaddstr(stdscr,22,nScreenWidth-31," ");
  mvwaddstr(stdscr,22,nScreenWidth-32," ");
  mvwaddstr(stdscr,22,nScreenWidth-33," ");

  mvwaddstr(stdscr,23,nScreenWidth-8," ");
  mvwaddstr(stdscr,23,nScreenWidth-9," ");
  mvwaddstr(stdscr,23,nScreenWidth-12," ");
  mvwaddstr(stdscr,23,nScreenWidth-13," ");
  mvwaddstr(stdscr,23,nScreenWidth-14," ");
  mvwaddstr(stdscr,23,nScreenWidth-15," ");
  mvwaddstr(stdscr,23,nScreenWidth-18," ");
  mvwaddstr(stdscr,23,nScreenWidth-19," ");
  mvwaddstr(stdscr,23,nScreenWidth-20," ");
  mvwaddstr(stdscr,23,nScreenWidth-21," ");
  mvwaddstr(stdscr,23,nScreenWidth-26," ");
  mvwaddstr(stdscr,23,nScreenWidth-27," ");
  mvwaddstr(stdscr,23,nScreenWidth-28," ");
  mvwaddstr(stdscr,23,nScreenWidth-29," ");
  mvwaddstr(stdscr,23,nScreenWidth-30," ");
  mvwaddstr(stdscr,23,nScreenWidth-31," ");
  mvwaddstr(stdscr,23,nScreenWidth-32," ");
  mvwaddstr(stdscr,23,nScreenWidth-33," ");

  mvwaddstr(stdscr,24,nScreenWidth-6," ");
  mvwaddstr(stdscr,24,nScreenWidth-7," ");
  mvwaddstr(stdscr,24,nScreenWidth-8," ");
  mvwaddstr(stdscr,24,nScreenWidth-9," ");
  mvwaddstr(stdscr,24,nScreenWidth-10," ");
  mvwaddstr(stdscr,24,nScreenWidth-11," ");
  mvwaddstr(stdscr,24,nScreenWidth-16," ");
  mvwaddstr(stdscr,24,nScreenWidth-17," ");
  mvwaddstr(stdscr,24,nScreenWidth-18," ");
  mvwaddstr(stdscr,24,nScreenWidth-19," ");
  mvwaddstr(stdscr,24,nScreenWidth-20," ");
  mvwaddstr(stdscr,24,nScreenWidth-21," ");
  mvwaddstr(stdscr,24,nScreenWidth-22," ");
  mvwaddstr(stdscr,24,nScreenWidth-23," ");
  mvwaddstr(stdscr,24,nScreenWidth-24," ");
  mvwaddstr(stdscr,24,nScreenWidth-25," ");
  mvwaddstr(stdscr,24,nScreenWidth-26," ");
  mvwaddstr(stdscr,24,nScreenWidth-27," ");
  mvwaddstr(stdscr,24,nScreenWidth-28," ");
  mvwaddstr(stdscr,24,nScreenWidth-29," ");
  mvwaddstr(stdscr,24,nScreenWidth-30," ");
  mvwaddstr(stdscr,24,nScreenWidth-31," ");
  mvwaddstr(stdscr,24,nScreenWidth-32," ");
  mvwaddstr(stdscr,24,nScreenWidth-33," ");
  mvwaddstr(stdscr,24,nScreenWidth-34," ");
  mvwaddstr(stdscr,24,nScreenWidth-35," ");
    
  attroff(COLOR_PAIR(4));
}

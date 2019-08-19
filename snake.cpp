#include <iostream>       // std::cout, std::endl
#include <string>         // std::string
#include <cstdlib>        // std::rand, std::srand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <ctime>          // std::time

#include <curses.h>       // ncurses

#include "snake.h"

void Snake::init() {
  // Initialise ncurses.
  setlocale(LC_ALL, "");
  initscr();
  getmaxyx(stdscr, nScreenHeight, nScreenWidth);
  noecho();
  cbreak();
  curs_set(0);
  keypad(stdscr, TRUE);
    
  if (has_colors() == FALSE) {
    endwin();
    std::cerr << "Your terminal does not support color.\n" << std::endl;
  } else {
    start_color();
    init_color(8, 988, 777, 0);
    init_color(9, 722, 546, 0);
    init_color(10, 289, 773, 988);
    init_color(11, 0, 0, 0);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, 8);
    init_pair(3, COLOR_WHITE, 9);
    init_pair(4, COLOR_WHITE, 10);
    init_pair(5, COLOR_WHITE, 11);
    init_pair(6, COLOR_BLACK, COLOR_WHITE);
    //attron(A_BOLD);
    color_set(1, nullptr);
    
  }
    
  // Draw background.
  draw_border(1,2,nScreenWidth-2,nScreenHeight-2);
  draw_greet(greet);
  mvwaddstr(stdscr,1,nScreenWidth-13,"Score: ");
  std::string sscore = std::to_string(score);
  for (int i = 4-sscore.size(); i > 0; --i) {
    sscore.insert(0," ");
  }
  mvwaddstr(stdscr,1,nScreenWidth-6,sscore.c_str());
    
  // Flush initial draws to screen.
  wrefresh(stdscr);

  // Wait for any key press to start.
  getch();
  clear_greet(greet);

  // Init snake (3 segments moving east)
  snake.push_front({nScreenWidth/2,nScreenHeight/2,{1,0}});
  mvwaddstr(stdscr, snake.front().y, snake.front().x , "O");
  move_head(Direction::straight);
  move_head(Direction::straight);

  // Init random seed and first apple
  std::srand(std::time(NULL));
  new_apple();
    
  wrefresh(stdscr);
  nodelay(stdscr, true);
}

void Snake::input() {
  // Get input.
  int key = getch();
    
  if (key == (char)27 || key == 'q') {
    this->gameOver = true;          
  } else if (key == KEY_LEFT || key == 'a' || key == 'A') {
    move_head(Direction::left);
  } else if (key == KEY_RIGHT || key == 'd' || key == 'D') {
    move_head(Direction::right);
  } else {
    move_head(Direction::straight);
  }
}

void Snake::logic() {
  // check for wall collision
  bool collision = collision_check();
  if (snake.front().x == apple.x && snake.front().y == apple.y) {
    // check apple collision -> score increase, new_apple
    increase_score();
    new_apple();
    // check if collision with super secret splash screen
  } else if (snake.front().x == 1 && snake.front().y == 5) {
    about_splash();
    nodelay(stdscr, false);
    getch();
  } else if (collision) {
    // check wall or snake collision -> gameover
    gameOver = true;
  } else {
    del_tail();
  }
    
  // Timing (direction dependant)
  if (snake.front().heading.x != 0) { speed = baseSpeed*0.6; }
  else { speed = baseSpeed; }
  std::this_thread::sleep_for (std::chrono::milliseconds(speed));
}

void Snake::draw() {
  // Flush draws to screen.
  wrefresh(stdscr);
}

int Snake::end() {
  return endwin();
}

void Snake::draw_border(const int &x1, const int &y1, const int &x2, const int &y2) const {
  mvhline(y1, x1, 0, x2-x1);
  mvhline(y2, x1, 0, x2-x1);
  mvvline(y1, x1, 0, y2-y1);
  mvvline(y1, x2, 0, y2-y1);
  mvaddch(y1, x1, ACS_ULCORNER);
  mvaddch(y2, x1, ACS_LLCORNER);
  mvaddch(y1, x2, ACS_URCORNER);
  mvaddch(y2, x2, ACS_LRCORNER);
}
  
void Snake::draw_greet(const std::string &greet) const {
  mvwaddstr(stdscr,
	    nScreenHeight / 2,
	    (nScreenWidth - greet.size()) / 2,
	    greet.c_str() );
}

void Snake::clear_greet(const std::string &greet) const {
  for (auto i = 0; i < (int)greet.size(); ++i) {
    mvwaddstr(stdscr,
	      nScreenHeight / 2,
	      i + (nScreenWidth - greet.size()) / 2,
	      " ");
  }
}

void Snake::move_head(const Direction dir) {
  // Redraw old head
  mvwaddstr(stdscr, snake.front().y, snake.front().x, "o");
    
  // Create new head segment using old head values
  snake.push_front({snake.front().x,snake.front().y,snake.front().heading});

  // Update heading
  switch(dir) {
  case Direction::left:
    snake.front().heading.rotate_left();
    break;
  case Direction::right:
    snake.front().heading.rotate_right();
    break;
  case Direction::straight:
    break;
  }

  // Update x and y of head
  snake.front().x += snake.front().heading.x;
  snake.front().y += snake.front().heading.y;
   
  // Draw new head
  mvwaddstr(stdscr, snake.front().y, snake.front().x, "O");
}

void Snake::del_tail() {
  // Clear tail on screen
  mvwaddstr(stdscr, snake.back().y, snake.back().x, " ");

  // Delete tail 
  snake.pop_back();
}
  
void Snake::new_apple() {
  bool snakeCollision = true;
  int wLoc, hLoc;
  while (snakeCollision) {
    snakeCollision = false;
    wLoc = (rand() % (nScreenWidth-5)) + 2;
    hLoc = (rand() % (nScreenHeight-6)) + 3;
    for (auto s : snake) {
      if (s.x == wLoc && s.y == hLoc) {
	snakeCollision = true;
      }
    }
  }
  apple = Segment{wLoc,hLoc,{0,0}};
  mvwaddstr(stdscr, apple.y, apple.x, "%");
}

bool Snake::collision_check() {
  bool collision = false;

  // Check for collision with wall
  if (snake.front().x <= 1 || snake.front().x >= nScreenWidth-2
      || snake.front().y <= 2 || snake.front().y >= nScreenHeight-2) {
    collision = true;
  }

  // Check for collision with self
  for(std::list<Segment>::iterator s = snake.begin(); s != snake.end(); ++s) {
    if (s != snake.begin() && s->x == snake.front().x && s->y == snake.front().y) {
      collision = true;
    }
  }
  return collision;
}

void Snake::increase_score() {
  score+=1;
  std::string sscore = std::to_string(score);
  for (int i = 4-sscore.size(); i > 0; --i) {
    sscore.insert(0," ");
  }
  mvwaddstr(stdscr,1,nScreenWidth-6,sscore.c_str());

  if (baseSpeed >= 42) { baseSpeed-=2; }
}

void Snake::about_splash() {
  // Clear screen
  wclear(stdscr);

  // Fill with white
  wbkgd(stdscr, COLOR_PAIR(6));

  // Black
  attron(COLOR_PAIR(5));
  mvwaddstr(stdscr,0,nScreenWidth-3," ");
  mvwaddstr(stdscr,0,nScreenWidth-4," ");
  
  mvwaddstr(stdscr,1,nScreenWidth-2," ");
  mvwaddstr(stdscr,1,nScreenWidth-5," ");
  mvwaddstr(stdscr,1,nScreenWidth-6," ");

  mvwaddstr(stdscr,2,nScreenWidth-2," ");
  mvwaddstr(stdscr,2,nScreenWidth-7," ");

  mvwaddstr(stdscr,3,nScreenWidth-3," ");
  mvwaddstr(stdscr,3,nScreenWidth-8," ");
  mvwaddstr(stdscr,3,nScreenWidth-9," ");

  mvwaddstr(stdscr,4,nScreenWidth-3," ");
  mvwaddstr(stdscr,4,nScreenWidth-10," ");
  mvwaddstr(stdscr,4,nScreenWidth-11," ");

  mvwaddstr(stdscr,5,nScreenWidth-4," ");
  mvwaddstr(stdscr,5,nScreenWidth-12," ");
  mvwaddstr(stdscr,5,nScreenWidth-13," ");
  mvwaddstr(stdscr,5,nScreenWidth-14," ");
  mvwaddstr(stdscr,5,nScreenWidth-15," ");
  mvwaddstr(stdscr,5,nScreenWidth-16," ");
  mvwaddstr(stdscr,5,nScreenWidth-17," ");

  mvwaddstr(stdscr,6,nScreenWidth-4," ");
  mvwaddstr(stdscr,6,nScreenWidth-18," ");

  mvwaddstr(stdscr,7,nScreenWidth-4," ");
  mvwaddstr(stdscr,7,nScreenWidth-17," ");

  mvwaddstr(stdscr,8,nScreenWidth-5," ");
  mvwaddstr(stdscr,8,nScreenWidth-14," ");
  mvwaddstr(stdscr,8,nScreenWidth-15," ");
  mvwaddstr(stdscr,8,nScreenWidth-16," ");

  mvwaddstr(stdscr,9,nScreenWidth-4," ");
  mvwaddstr(stdscr,9,nScreenWidth-11," ");
  mvwaddstr(stdscr,9,nScreenWidth-12," ");
  mvwaddstr(stdscr,9,nScreenWidth-13," ");

  mvwaddstr(stdscr,10,nScreenWidth-3," ");
  mvwaddstr(stdscr,10,nScreenWidth-8," ");
  mvwaddstr(stdscr,10,nScreenWidth-9," ");
  mvwaddstr(stdscr,10,nScreenWidth-10," ");
  mvwaddstr(stdscr,10,nScreenWidth-11," ");
  mvwaddstr(stdscr,10,nScreenWidth-12," ");
  mvwaddstr(stdscr,10,nScreenWidth-14," ");

  mvwaddstr(stdscr,11,nScreenWidth-2," ");
  mvwaddstr(stdscr,11,nScreenWidth-6," ");
  mvwaddstr(stdscr,11,nScreenWidth-7," ");
  mvwaddstr(stdscr,11,nScreenWidth-8," ");
  mvwaddstr(stdscr,11,nScreenWidth-9," ");
  mvwaddstr(stdscr,11,nScreenWidth-11," ");
  mvwaddstr(stdscr,11,nScreenWidth-12," ");
  mvwaddstr(stdscr,11,nScreenWidth-14," ");
  mvwaddstr(stdscr,11,nScreenWidth-15," ");

  mvwaddstr(stdscr,12,nScreenWidth-1," ");
  mvwaddstr(stdscr,12,nScreenWidth-4," ");
  mvwaddstr(stdscr,12,nScreenWidth-6," ");
  mvwaddstr(stdscr,12,nScreenWidth-7," ");
  mvwaddstr(stdscr,12,nScreenWidth-8," ");
  mvwaddstr(stdscr,12,nScreenWidth-9," ");
  mvwaddstr(stdscr,12,nScreenWidth-11," ");
  mvwaddstr(stdscr,12,nScreenWidth-12," ");
  mvwaddstr(stdscr,12,nScreenWidth-13," ");
  mvwaddstr(stdscr,12,nScreenWidth-14," ");
  mvwaddstr(stdscr,12,nScreenWidth-16," ");

  mvwaddstr(stdscr,13,nScreenWidth-2," ");
  mvwaddstr(stdscr,13,nScreenWidth-3," ");
  mvwaddstr(stdscr,13,nScreenWidth-5," ");
  mvwaddstr(stdscr,13,nScreenWidth-6," ");
  mvwaddstr(stdscr,13,nScreenWidth-7," ");
  mvwaddstr(stdscr,13,nScreenWidth-8," ");
  mvwaddstr(stdscr,13,nScreenWidth-9," ");
  mvwaddstr(stdscr,13,nScreenWidth-10," ");
  mvwaddstr(stdscr,13,nScreenWidth-11," ");
  mvwaddstr(stdscr,13,nScreenWidth-12," ");
  mvwaddstr(stdscr,13,nScreenWidth-13," ");
  mvwaddstr(stdscr,13,nScreenWidth-14," ");
  mvwaddstr(stdscr,13,nScreenWidth-15," ");
  mvwaddstr(stdscr,13,nScreenWidth-17," ");

  mvwaddstr(stdscr,14,nScreenWidth-3," ");
  mvwaddstr(stdscr,14,nScreenWidth-11," ");
  mvwaddstr(stdscr,14,nScreenWidth-12," ");
  mvwaddstr(stdscr,14,nScreenWidth-13," ");
  mvwaddstr(stdscr,14,nScreenWidth-17," ");

  mvwaddstr(stdscr,15,nScreenWidth-4," ");
  mvwaddstr(stdscr,15,nScreenWidth-7," ");
  mvwaddstr(stdscr,15,nScreenWidth-8," ");
  mvwaddstr(stdscr,15,nScreenWidth-9," ");
  mvwaddstr(stdscr,15,nScreenWidth-16," ");
  mvwaddstr(stdscr,15,nScreenWidth-17," ");

  mvwaddstr(stdscr,16,nScreenWidth-3," ");
  mvwaddstr(stdscr,16,nScreenWidth-10," ");
  mvwaddstr(stdscr,16,nScreenWidth-11," ");
  mvwaddstr(stdscr,16,nScreenWidth-15," ");
  mvwaddstr(stdscr,16,nScreenWidth-18," ");

  mvwaddstr(stdscr,17,nScreenWidth-3," ");
  mvwaddstr(stdscr,17,nScreenWidth-10," ");
  mvwaddstr(stdscr,17,nScreenWidth-11," ");
  mvwaddstr(stdscr,17,nScreenWidth-12," ");
  mvwaddstr(stdscr,17,nScreenWidth-15," ");
  mvwaddstr(stdscr,17,nScreenWidth-18," ");

  mvwaddstr(stdscr,18,nScreenWidth-3," ");
  mvwaddstr(stdscr,18,nScreenWidth-10," ");
  mvwaddstr(stdscr,18,nScreenWidth-16," ");
  mvwaddstr(stdscr,18,nScreenWidth-17," ");

  mvwaddstr(stdscr,19,nScreenWidth-3," ");
  mvwaddstr(stdscr,19,nScreenWidth-10," ");
  mvwaddstr(stdscr,19,nScreenWidth-15," ");
  mvwaddstr(stdscr,19,nScreenWidth-17," ");

  mvwaddstr(stdscr,20,nScreenWidth-4," ");
  mvwaddstr(stdscr,20,nScreenWidth-10," ");
  mvwaddstr(stdscr,20,nScreenWidth-11," ");
  mvwaddstr(stdscr,20,nScreenWidth-12," ");
  mvwaddstr(stdscr,20,nScreenWidth-15," ");
  mvwaddstr(stdscr,20,nScreenWidth-17," ");

  mvwaddstr(stdscr,21,nScreenWidth-4," ");
  mvwaddstr(stdscr,21,nScreenWidth-9," ");
  mvwaddstr(stdscr,21,nScreenWidth-14," ");
  mvwaddstr(stdscr,21,nScreenWidth-17," ");
  
  mvwaddstr(stdscr,22,nScreenWidth-4," ");
  mvwaddstr(stdscr,22,nScreenWidth-9," ");
  mvwaddstr(stdscr,22,nScreenWidth-13," ");
  mvwaddstr(stdscr,22,nScreenWidth-17," ");

  mvwaddstr(stdscr,23,nScreenWidth-3," ");
  mvwaddstr(stdscr,23,nScreenWidth-5," ");
  mvwaddstr(stdscr,23,nScreenWidth-8," ");
  mvwaddstr(stdscr,23,nScreenWidth-11," ");
  mvwaddstr(stdscr,23,nScreenWidth-12," ");
  mvwaddstr(stdscr,23,nScreenWidth-17," ");

  mvwaddstr(stdscr,24,nScreenWidth-2," ");
  mvwaddstr(stdscr,24,nScreenWidth-6," ");
  mvwaddstr(stdscr,24,nScreenWidth-7," ");
  mvwaddstr(stdscr,24,nScreenWidth-18," ");

  mvwaddstr(stdscr,25,nScreenWidth-3," ");
  mvwaddstr(stdscr,25,nScreenWidth-4," ");
  mvwaddstr(stdscr,25,nScreenWidth-5," ");
  mvwaddstr(stdscr,25,nScreenWidth-8," ");
  mvwaddstr(stdscr,25,nScreenWidth-9," ");
  mvwaddstr(stdscr,25,nScreenWidth-10," ");
  mvwaddstr(stdscr,25,nScreenWidth-11," ");
  mvwaddstr(stdscr,25,nScreenWidth-12," ");
  mvwaddstr(stdscr,25,nScreenWidth-13," ");
  mvwaddstr(stdscr,25,nScreenWidth-14," ");
  mvwaddstr(stdscr,25,nScreenWidth-15," ");
  mvwaddstr(stdscr,25,nScreenWidth-16," ");
  mvwaddstr(stdscr,25,nScreenWidth-17," ");
  
  attroff(COLOR_PAIR(5));
  
  // Bright yellow
  attron(COLOR_PAIR(2));

  mvwaddstr(stdscr,1,nScreenWidth-3," ");
  mvwaddstr(stdscr,1,nScreenWidth-4," ");

  mvwaddstr(stdscr,2,nScreenWidth-4," ");
  mvwaddstr(stdscr,2,nScreenWidth-5," ");
  mvwaddstr(stdscr,2,nScreenWidth-6," ");
  
  mvwaddstr(stdscr,3,nScreenWidth-5," ");
  mvwaddstr(stdscr,3,nScreenWidth-6," ");
  mvwaddstr(stdscr,3,nScreenWidth-7," ");

  mvwaddstr(stdscr,4,nScreenWidth-6," ");
  mvwaddstr(stdscr,4,nScreenWidth-7," ");
  mvwaddstr(stdscr,4,nScreenWidth-8," ");
  mvwaddstr(stdscr,4,nScreenWidth-9," ");
  
  mvwaddstr(stdscr,5,nScreenWidth-8," ");
  mvwaddstr(stdscr,5,nScreenWidth-9," ");
  mvwaddstr(stdscr,5,nScreenWidth-10," ");
  mvwaddstr(stdscr,5,nScreenWidth-11," ");

  mvwaddstr(stdscr,6,nScreenWidth-10," ");
  mvwaddstr(stdscr,6,nScreenWidth-11," ");
  mvwaddstr(stdscr,6,nScreenWidth-12," ");
  mvwaddstr(stdscr,6,nScreenWidth-13," ");
  mvwaddstr(stdscr,6,nScreenWidth-14," ");
  mvwaddstr(stdscr,6,nScreenWidth-15," ");
  mvwaddstr(stdscr,6,nScreenWidth-16," ");
  mvwaddstr(stdscr,6,nScreenWidth-17," ");

  mvwaddstr(stdscr,7,nScreenWidth-9," ");
  mvwaddstr(stdscr,7,nScreenWidth-10," ");
  mvwaddstr(stdscr,7,nScreenWidth-11," ");
  mvwaddstr(stdscr,7,nScreenWidth-12," ");

  mvwaddstr(stdscr,8,nScreenWidth-7," ");
  mvwaddstr(stdscr,8,nScreenWidth-8," ");
  mvwaddstr(stdscr,8,nScreenWidth-9," ");

  mvwaddstr(stdscr,10,nScreenWidth-13," ");
    
  mvwaddstr(stdscr,11,nScreenWidth-10," ");
  mvwaddstr(stdscr,11,nScreenWidth-13," ");

  mvwaddstr(stdscr,12,nScreenWidth-10," ");

  mvwaddstr(stdscr,16,nScreenWidth-16," ");
  mvwaddstr(stdscr,16,nScreenWidth-17," ");

  mvwaddstr(stdscr,17,nScreenWidth-16," ");
  mvwaddstr(stdscr,17,nScreenWidth-17," ");

  mvwaddstr(stdscr,18,nScreenWidth-11," ");
  mvwaddstr(stdscr,18,nScreenWidth-12," ");

  mvwaddstr(stdscr,19,nScreenWidth-11," ");
  mvwaddstr(stdscr,19,nScreenWidth-12," ");
  
  attroff(COLOR_PAIR(2));

  // Dirty yellow
  attron(COLOR_PAIR(3));

  mvwaddstr(stdscr,2,nScreenWidth-3," ");

  mvwaddstr(stdscr,3,nScreenWidth-4," ");

  mvwaddstr(stdscr,4,nScreenWidth-4," ");
  mvwaddstr(stdscr,4,nScreenWidth-5," ");

  mvwaddstr(stdscr,5,nScreenWidth-5," ");
  mvwaddstr(stdscr,5,nScreenWidth-6," ");
  mvwaddstr(stdscr,5,nScreenWidth-7," ");

  mvwaddstr(stdscr,6,nScreenWidth-5," ");
  mvwaddstr(stdscr,6,nScreenWidth-6," ");
  mvwaddstr(stdscr,6,nScreenWidth-7," ");
  mvwaddstr(stdscr,6,nScreenWidth-8," ");
  mvwaddstr(stdscr,6,nScreenWidth-9," ");

  mvwaddstr(stdscr,7,nScreenWidth-5," ");
  mvwaddstr(stdscr,7,nScreenWidth-6," ");
  mvwaddstr(stdscr,7,nScreenWidth-7," ");
  mvwaddstr(stdscr,7,nScreenWidth-8," ");
  mvwaddstr(stdscr,7,nScreenWidth-13," ");
  mvwaddstr(stdscr,7,nScreenWidth-14," ");
  mvwaddstr(stdscr,7,nScreenWidth-15," ");
  mvwaddstr(stdscr,7,nScreenWidth-16," ");
  
  mvwaddstr(stdscr,8,nScreenWidth-6," ");
  mvwaddstr(stdscr,8,nScreenWidth-10," ");
  mvwaddstr(stdscr,8,nScreenWidth-11," ");
  mvwaddstr(stdscr,8,nScreenWidth-12," ");
  mvwaddstr(stdscr,8,nScreenWidth-13," ");

  mvwaddstr(stdscr,9,nScreenWidth-5," ");
  mvwaddstr(stdscr,9,nScreenWidth-6," ");
  mvwaddstr(stdscr,9,nScreenWidth-7," ");
  mvwaddstr(stdscr,9,nScreenWidth-8," ");
  mvwaddstr(stdscr,9,nScreenWidth-9," ");
  mvwaddstr(stdscr,9,nScreenWidth-10," ");

  mvwaddstr(stdscr,10,nScreenWidth-4," ");
  mvwaddstr(stdscr,10,nScreenWidth-5," ");
  mvwaddstr(stdscr,10,nScreenWidth-6," ");
  mvwaddstr(stdscr,10,nScreenWidth-7," ");

  mvwaddstr(stdscr,11,nScreenWidth-3," ");
  mvwaddstr(stdscr,11,nScreenWidth-4," ");
  mvwaddstr(stdscr,11,nScreenWidth-5," ");
  
  mvwaddstr(stdscr,12,nScreenWidth-2," ");
  mvwaddstr(stdscr,12,nScreenWidth-3," ");
  
  attroff(COLOR_PAIR(3));

  // Blue
  attron(COLOR_PAIR(4));

  mvwaddstr(stdscr,12,nScreenWidth-5," ");
  mvwaddstr(stdscr,12,nScreenWidth-15," ");
  
  mvwaddstr(stdscr,13,nScreenWidth-4," ");
  mvwaddstr(stdscr,13,nScreenWidth-16," ");
  
  mvwaddstr(stdscr,14,nScreenWidth-4," ");
  mvwaddstr(stdscr,14,nScreenWidth-5," ");
  mvwaddstr(stdscr,14,nScreenWidth-6," ");
  mvwaddstr(stdscr,14,nScreenWidth-7," ");
  mvwaddstr(stdscr,14,nScreenWidth-8," ");
  mvwaddstr(stdscr,14,nScreenWidth-9," ");
  mvwaddstr(stdscr,14,nScreenWidth-10," ");
  mvwaddstr(stdscr,14,nScreenWidth-14," ");
  mvwaddstr(stdscr,14,nScreenWidth-15," ");
  mvwaddstr(stdscr,14,nScreenWidth-16," ");

  mvwaddstr(stdscr,15,nScreenWidth-5," ");
  mvwaddstr(stdscr,15,nScreenWidth-6," ");
  mvwaddstr(stdscr,15,nScreenWidth-10," ");
  mvwaddstr(stdscr,15,nScreenWidth-11," ");
  mvwaddstr(stdscr,15,nScreenWidth-12," ");
  mvwaddstr(stdscr,15,nScreenWidth-13," ");
  mvwaddstr(stdscr,15,nScreenWidth-14," ");
  mvwaddstr(stdscr,15,nScreenWidth-15," ");
  
  mvwaddstr(stdscr,16,nScreenWidth-4," ");
  mvwaddstr(stdscr,16,nScreenWidth-5," ");
  mvwaddstr(stdscr,16,nScreenWidth-6," ");
  mvwaddstr(stdscr,16,nScreenWidth-7," ");
  mvwaddstr(stdscr,16,nScreenWidth-8," ");
  mvwaddstr(stdscr,16,nScreenWidth-9," ");
  mvwaddstr(stdscr,16,nScreenWidth-12," ");
  mvwaddstr(stdscr,16,nScreenWidth-13," ");
  mvwaddstr(stdscr,16,nScreenWidth-14," ");
  
  mvwaddstr(stdscr,17,nScreenWidth-4," ");
  mvwaddstr(stdscr,17,nScreenWidth-5," ");
  mvwaddstr(stdscr,17,nScreenWidth-6," ");
  mvwaddstr(stdscr,17,nScreenWidth-7," ");
  mvwaddstr(stdscr,17,nScreenWidth-8," ");
  mvwaddstr(stdscr,17,nScreenWidth-9," ");
  mvwaddstr(stdscr,17,nScreenWidth-13," ");
  mvwaddstr(stdscr,17,nScreenWidth-14," ");

  mvwaddstr(stdscr,18,nScreenWidth-4," ");
  mvwaddstr(stdscr,18,nScreenWidth-5," ");
  mvwaddstr(stdscr,18,nScreenWidth-6," ");
  mvwaddstr(stdscr,18,nScreenWidth-7," ");
  mvwaddstr(stdscr,18,nScreenWidth-8," ");
  mvwaddstr(stdscr,18,nScreenWidth-9," ");
  mvwaddstr(stdscr,18,nScreenWidth-13," ");
  mvwaddstr(stdscr,18,nScreenWidth-14," ");
  mvwaddstr(stdscr,18,nScreenWidth-15," ");
  
  mvwaddstr(stdscr,19,nScreenWidth-4," ");
  mvwaddstr(stdscr,19,nScreenWidth-5," ");
  mvwaddstr(stdscr,19,nScreenWidth-6," ");
  mvwaddstr(stdscr,19,nScreenWidth-7," ");
  mvwaddstr(stdscr,19,nScreenWidth-8," ");
  mvwaddstr(stdscr,19,nScreenWidth-9," ");
  mvwaddstr(stdscr,19,nScreenWidth-13," ");
  mvwaddstr(stdscr,19,nScreenWidth-14," ");
  mvwaddstr(stdscr,19,nScreenWidth-16," ");

  mvwaddstr(stdscr,20,nScreenWidth-5," ");
  mvwaddstr(stdscr,20,nScreenWidth-6," ");
  mvwaddstr(stdscr,20,nScreenWidth-7," ");
  mvwaddstr(stdscr,20,nScreenWidth-8," ");
  mvwaddstr(stdscr,20,nScreenWidth-9," ");
  mvwaddstr(stdscr,20,nScreenWidth-13," ");
  mvwaddstr(stdscr,20,nScreenWidth-14," ");
  mvwaddstr(stdscr,20,nScreenWidth-16," ");

  mvwaddstr(stdscr,21,nScreenWidth-5," ");
  mvwaddstr(stdscr,21,nScreenWidth-6," ");
  mvwaddstr(stdscr,21,nScreenWidth-7," ");
  mvwaddstr(stdscr,21,nScreenWidth-8," ");
  mvwaddstr(stdscr,21,nScreenWidth-10," ");
  mvwaddstr(stdscr,21,nScreenWidth-11," ");
  mvwaddstr(stdscr,21,nScreenWidth-12," ");
  mvwaddstr(stdscr,21,nScreenWidth-13," ");
  mvwaddstr(stdscr,21,nScreenWidth-15," ");
  mvwaddstr(stdscr,21,nScreenWidth-16," ");
  
  mvwaddstr(stdscr,22,nScreenWidth-5," ");
  mvwaddstr(stdscr,22,nScreenWidth-6," ");
  mvwaddstr(stdscr,22,nScreenWidth-7," ");
  mvwaddstr(stdscr,22,nScreenWidth-8," ");
  mvwaddstr(stdscr,22,nScreenWidth-10," ");
  mvwaddstr(stdscr,22,nScreenWidth-11," ");
  mvwaddstr(stdscr,22,nScreenWidth-12," ");
  mvwaddstr(stdscr,22,nScreenWidth-14," ");
  mvwaddstr(stdscr,22,nScreenWidth-15," ");
  mvwaddstr(stdscr,22,nScreenWidth-16," ");

  mvwaddstr(stdscr,23,nScreenWidth-4," ");
  mvwaddstr(stdscr,23,nScreenWidth-6," ");
  mvwaddstr(stdscr,23,nScreenWidth-7," ");
  mvwaddstr(stdscr,23,nScreenWidth-9," ");
  mvwaddstr(stdscr,23,nScreenWidth-10," ");
  mvwaddstr(stdscr,23,nScreenWidth-13," ");
  mvwaddstr(stdscr,23,nScreenWidth-14," ");
  mvwaddstr(stdscr,23,nScreenWidth-15," ");
  mvwaddstr(stdscr,23,nScreenWidth-16," ");

  mvwaddstr(stdscr,24,nScreenWidth-3," ");
  mvwaddstr(stdscr,24,nScreenWidth-4," ");
  mvwaddstr(stdscr,24,nScreenWidth-5," ");
  mvwaddstr(stdscr,24,nScreenWidth-8," ");
  mvwaddstr(stdscr,24,nScreenWidth-9," ");
  mvwaddstr(stdscr,24,nScreenWidth-10," ");
  mvwaddstr(stdscr,24,nScreenWidth-11," ");
  mvwaddstr(stdscr,24,nScreenWidth-12," ");
  mvwaddstr(stdscr,24,nScreenWidth-13," ");
  mvwaddstr(stdscr,24,nScreenWidth-14," ");
  mvwaddstr(stdscr,24,nScreenWidth-15," ");
  mvwaddstr(stdscr,24,nScreenWidth-16," ");
  mvwaddstr(stdscr,24,nScreenWidth-17," ");
    
  attroff(COLOR_PAIR(4));
}

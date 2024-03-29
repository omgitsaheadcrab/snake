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
    use_default_colors();
    init_color(8, 988, 777, 0);
    init_color(9, 722, 546, 0);
    init_color(10, 289, 773, 988);
    init_color(11, 0, 0, 0);
    init_color(12, 850, 850, 850);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, 8);
    init_pair(3, COLOR_WHITE, 9);
    init_pair(4, COLOR_WHITE, 10);
    init_pair(5, COLOR_WHITE, 11);
    init_pair(6, COLOR_BLACK, COLOR_WHITE);
    init_pair(7, 12, COLOR_BLACK);
    attron(A_BOLD);
    color_set(1, nullptr);
    
  }
  // Init random seed
  std::srand(std::time(NULL));

  // Run rest of initialisation
  reset();

  draw_greet(greet);
  
  // Wait for any key press to start.
  nodelay(stdscr, false);
  getch();
  clear_greet(greet);
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
    reset();
    nodelay(stdscr, true);
  } else if (collision) {
    // check wall or snake collision
    draw_dead();
    nodelay(stdscr, false);
    draw_greet(replay);
    int key = getch();
    nodelay(stdscr, true);
    if (key == ' ') { reset(); }
    else { gameOver = true; }
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

void Snake::reset() {
  // Clear screen
  wclear(stdscr);

  // Fill with black
  wbkgd(stdscr, COLOR_PAIR(1));

  // Reset score, speed, basespeed
  score = 0;
  speed = 260;
  baseSpeed = 260;

  // Draw background.
  draw_border(1,2,nScreenWidth-2,nScreenHeight-2);

    
  mvwaddstr(stdscr,1,nScreenWidth-13,"Score: ");
  std::string sscore = std::to_string(score);
  for (int i = 4-sscore.size(); i > 0; --i) {
    sscore.insert(0," ");
  }
  mvwaddstr(stdscr,1,nScreenWidth-6,sscore.c_str());
  
  mvwaddstr(stdscr,0,nScreenWidth-18,"High Score: ");
  std::string hisscore = std::to_string(hiscore);
  for (int i = 4-hisscore.size(); i > 0; --i) {
    hisscore.insert(0," ");
  }
  mvwaddstr(stdscr,0,nScreenWidth-6,hisscore.c_str());

  // Flush initial draws to screen.
  wrefresh(stdscr);

  // Init snake (3 segments moving east)
  if (!snake.empty()) { snake.clear(); }
  snake.push_front({nScreenWidth/2,nScreenHeight/2,{1,0}});
  mvwaddstr(stdscr, snake.front().y, snake.front().x , "O");
  move_head(Direction::straight);
  move_head(Direction::straight);

  // Init random seed and first apple
  new_apple();
    
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
  
  attron(COLOR_PAIR(7));
  mvaddch(5,1,ACS_VLINE);
  attroff(COLOR_PAIR(7));
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
  
  if (score > hiscore) {
    hiscore = (score > hiscore ? score : hiscore);

    std::string hisscore = std::to_string(hiscore);
    for (int i = 4-hisscore.size(); i > 0; --i) {
      hisscore.insert(0," ");
    }
    mvwaddstr(stdscr,0,nScreenWidth-6,hisscore.c_str());
  }

  if (baseSpeed >= 42) { baseSpeed-=2; }
}

void Snake::draw_dead() {

  mvwaddstr(stdscr, snake.front().y, snake.front().x, "X");
  for(std::list<Segment>::iterator s = snake.begin(); s != snake.end(); ++s) {
    if (s != snake.begin()) {
      mvwaddstr(stdscr, s->y, s->x, "x");
    }
  }
}

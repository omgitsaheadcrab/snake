#include <iostream>
#include <curses.h>
#include <string>

class Snake {
private:
  int nScreenWidth;
  int nScreenHeight;
  const std::string greet = "Press any key to begin.";

  void draw_border(const int &x1, const int &y1, const int &x2, const int &y2) const {
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
  }
  
  void draw_greet(const std::string &greet) const {
    mvwaddstr(stdscr,
	      nScreenHeight / 2,
	      (nScreenWidth - greet.size()) / 2,
	      greet.c_str() );
  }

  void clear_greet(const std::string &greet) const {
    for (auto i = 0; i < (int)greet.size(); ++i) {
      mvwaddstr(stdscr,
		nScreenHeight / 2,
		i + (nScreenWidth - greet.size()) / 2,
		" ");
    }
  }
  
public:
  bool gameOver = false;

  void init() {
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
      std::cerr << "Your terminal does not support color\n" << std::endl;
    } else {
      start_color();
      init_pair(1, COLOR_RED, COLOR_BLACK);
      attron(A_BOLD);
      color_set(1, nullptr);
    }
    
    // Draw background.
    draw_border(1,1,nScreenWidth-2,nScreenHeight-2);
    draw_greet(greet);
    
    // Flush initial draws to screen.
    wrefresh(stdscr);
  }

  void input() {
    // Get input.
    int key = getch();
    
    if (key == (char)27 || key == 'q') {
      this->gameOver = true;          
    } else if (key == KEY_UP || key == 'w' || key == 'W') {
      mvwaddstr(stdscr,0, 20, "\xF0\x9F\x8D\x8C");
      clear_greet(greet);
    } else if (key == KEY_DOWN || key == 's' || key == 'S') {
      mvwaddch(stdscr,20, 20, '.');
    } else if (key == KEY_LEFT || key == 'a' || key == 'A') {
      mvwaddch(stdscr,10, 10, '.');
    } else if (key == KEY_RIGHT || key == 'd' || key == 'D') {
      mvwaddch(stdscr,10, 30, '.');
    }
  }

  void logic() {}

  void draw() {
    // Flush draws to screen.
    wrefresh(stdscr);
  }
};

int main()
{
  Snake game;
  game.init();
  
  while(!game.gameOver) {
    game.input();
    game.logic();
    game.draw();
    //sleep(10);
  }

  return endwin();
}

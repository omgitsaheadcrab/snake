#include <iostream>
#include <curses.h>

class Snake {
private:
  int nScreenWidth;
  int nScreenHeight;

public:
  bool gameOver;

  void setup() {
    gameOver = false;
    
    setlocale(LC_ALL, "");
    initscr();
    getmaxyx(stdscr, nScreenHeight, nScreenWidth);
    noecho();
    cbreak();
    curs_set(0);

    if (has_colors() == FALSE) {
      endwin();
      std::cerr << "Your terminal does not support color\n" << std::endl;
    } else {
      start_color();
      init_pair(1, COLOR_RED, COLOR_BLACK);
      attron(A_BOLD);
      color_set(1, nullptr);
    }
    keypad(stdscr, TRUE);

  }

  void input() {
    int key = getch();
    
    if (key == (char)27 || key == 'q') {
      this->gameOver = true;          
    } else if (key == KEY_UP || key == 'w' || key == 'W') {
      mvaddstr(0, 20, "\xF0\x9F\x8D\x8C");
    } else if (key == KEY_DOWN || key == 's' || key == 'S') {
      mvaddch(20, 20, '.');
    } else if (key == KEY_LEFT || key == 'a' || key == 'A') {
      mvaddch(10, 10, '.');
    } else if (key == KEY_RIGHT || key == 'd' || key == 'D') {
      mvaddch(10, 30, '.');
    }
  }

  void logic() {}

  void draw() {
    wrefresh(stdscr);
  }
};

int main()
{
  Snake game;
  game.setup();
  
  while(!game.gameOver) {
    game.input();
    game.logic();
    game.draw();
    //sleep(10);
  }

  return endwin();
}

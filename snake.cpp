#include <iostream>
#include <string>
#include <list>

#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

#include <curses.h>

enum class Direction { straight, left, right };

struct Heading {
  int x;
  int y;

  void rotate_left() {
    int x1 = y;
    int y1 = -x;
    x = x1;
    y = y1;
  }

  void rotate_right() {
    int x1 = -y;
    int y1 = x;
    x = x1;
    y = y1;
  }
};

struct Segment {
  int x;
  int y;
  Heading heading;
};

class Snake {
private:
  int nScreenWidth;
  int nScreenHeight;
  const std::string greet = "Press any key to start.";
  std::list<Segment> snake;

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

  void del_tail() {
    // Clear tail on screen
    mvwaddstr(stdscr, snake.back().y, snake.back().x, " ");

    // Delete tail 
    snake.pop_back();
  }

  void move_head(const Direction dir) {
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
    getch();
    clear_greet(greet);

    // Init snake (3 segments moving east)
    snake.push_front({nScreenWidth/2,nScreenHeight/2,{1,0}});
    mvwaddstr(stdscr, snake.front().y, snake.front().x , "O");
    move_head(Direction::straight);
    move_head(Direction::straight);
    
    wrefresh(stdscr);
    nodelay(stdscr, true);
  }

  void input() {
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
    del_tail();
  }

  void logic() {
    // check for collisions
  }

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
    std::this_thread::sleep_for (std::chrono::seconds(1));
  }

  return endwin();
}

#include <iostream>
#include <string>
#include <list>

#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

#include <curses.h>

enum class Heading { north, south, east, west };
enum class Direction { straight, left, right };

struct Segment {
  int x;
  int y;
  Heading heading;
};

class Snake {
private:
  int nScreenWidth;
  int nScreenHeight;
  const std::string greet = "Press any key to begin.";
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
    // Create new head segment
    int newx, newy;
    Heading newHeading;

    // Update position for new head
    switch(snake.front().heading) {
    case Heading::north :
      if (dir == Direction::straight) {
	newx = snake.front().x;
	newy = snake.front().y + 1;
	newHeading = Heading::north;
      }
      else if (dir == Direction::left) {
	newx = snake.front().x + 1;
	newy = snake.front().y;
	newHeading = Heading::west;
      }
      else if (dir == Direction::right) {
	newx = snake.front().x - 1;
	newy = snake.front().y;
	newHeading = Heading::east;
      }
    case Heading::south :
      if (dir == Direction::straight) {
	newx = snake.front().x;
	newy = snake.front().y - 1;
	newHeading = Heading::south;
      }
      else if (dir == Direction::left) {
	newx = snake.front().x - 1;
	newy = snake.front().y;
	newHeading = Heading::east;
      }
      else if (dir == Direction::right) {
	newx = snake.front().x + 1;
	newy = snake.front().y;
	newHeading = Heading::west;
      }
    case Heading::east :
      if (dir == Direction::straight) {
	newx = snake.front().x - 1;
	newy = snake.front().y;
	newHeading = Heading::east;
      }
      else if (dir == Direction::left) {
	newx = snake.front().x;
	newy = snake.front().y + 1;
	newHeading = Heading::north;
      }
      else if (dir == Direction::right) {
	newx = snake.front().x;
	newy = snake.front().y - 1;
	newHeading = Heading::south;
      }
    case Heading::west :
      if (dir == Direction::straight) {
	newx = snake.front().x + 1;
	newy = snake.front().y;
	newHeading = Heading::west;
      }
      else if (dir == Direction::left) {
	newx = snake.front().x;
	newy = snake.front().y - 1;
	newHeading = Heading::south;
      }
      else if (dir == Direction::right) {
	newx = snake.front().x;
	newy = snake.front().y + 1;
	newHeading = Heading::north;
      }
    }
    
    // Redraw old head
    mvwaddstr(stdscr, snake.front().y, snake.front().x, "o");

    // Add new head and draw
    snake.push_front({newx,newy,newHeading});
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

    // Init snake (3 segments)
    snake.push_front({nScreenWidth/2,nScreenHeight/2,Heading::east});
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
    } else if (key == ERR) {
      move_head(Direction::straight);
    }
    del_tail();
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
    std::this_thread::sleep_for (std::chrono::seconds(1));
  }

  return endwin();
}

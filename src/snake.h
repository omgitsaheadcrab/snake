#pragma once

#include <string>
#include <list>

#include "segment.h"

enum class Direction { straight, left, right };

class Snake {
public:
  bool gameOver = false;

  void init();
  void input();
  void logic();
  void draw();
  void reset();
  int end();
  
private:
  int nScreenWidth;
  int nScreenHeight;
  const std::string greet = "Press any key to start.";
  const std::string replay = "Press SPACE to restart or any other key to quit..";
  std::list<Segment> snake;
  Segment apple;
  int score = 0;
  int hiscore = 0;
  int speed = 260;
  int baseSpeed = 260;
  bool playAgain = true;

  void draw_border(const int &x1, const int &y1, const int &x2, const int &y2) const;
  void draw_greet(const std::string &greet) const;
  void clear_greet(const std::string &greet) const;
  void move_head(const Direction dir);
  void del_tail();
  void new_apple();
  bool collision_check();
  void increase_score();
  void about_splash();
  void draw_dead();
};

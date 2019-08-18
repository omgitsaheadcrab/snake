#include "heading.h"

void Heading::rotate_left() {
  int x1 = y;
  int y1 = -x;
  x = x1;
  y = y1;
}

void Heading::rotate_right() {
  int x1 = -y;
  int y1 = x;
  x = x1;
  y = y1;
}

#include "snake.h"

Snake create_snake(int start_x, int start_y)
{
  Snake new_snake = {0};
  new_snake.head = vector2_create(start_x, start_y);
  new_snake.direction = vector2_create(1, 0);
  new_snake.length = 1;

  new_snake.segments[0] = new_snake.head;

  return new_snake;
}

void snake_move(Snake *snake)
{
  // Geser segmen
  for (int i = snake->length; i > 0; i--)
  {
    snake->segments[i] = snake->segments[i - 1];
  }

  // Perbarui kepala
  snake->segments[0] = snake->head;
  snake->head = vector2_add(snake->head, snake->direction);
}

bool snake_collides_with_self(Snake *snake)
{
  for (int i = 1; i < snake->length; i++)
  {
    if (vector2_equals(snake->head, snake->segments[i]))
    {
      return true;
    }
  }
  return false;
}

bool snake_grow(Snake *snake)
{
  if (snake->length < MAX_SNAKE_LENGTH)
  {
    snake->length = snake->length + 1;
    return true;
  }
  return false;
}

char get_snake_head_symbol(Snake *snake)
{
  Vector2 dir = snake->direction;

  if (dir.x == 1)
    return '>'; // kanan
  if (dir.x == -1)
    return '<'; // kiri
  if (dir.y == 1)
    return 'v'; // bawah
  if (dir.y == -1)
    return '^'; // atas

  return '>'; // default
}

void snake_change_direction(Snake *snake, Vector2 new_direction)
{
  // Cegah ular bergerak mundur
  if ((new_direction.x == -(snake->direction.x) && new_direction.x != 0) ||
      (new_direction.y == -(snake->direction.y) && new_direction.y != 0))
  {
    return;
  }

  snake->direction = new_direction;
}

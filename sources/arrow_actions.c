#include "ft_select.h"

void arrow_up_action(t_layout *l, t_term *t)
{
  if (l->pos[1] > 0)
    l->pos[1] -= 1;
  else if (layout_case_exist(l, l->pos[0], l->nb_raw - 1))
    l->pos[1] = l->nb_raw - 1;
  else
    l->pos[1] = l->nb_raw - 2;
  print_args(l, t->height);
}

void arrow_down_action(t_layout *l, t_term *t)
{
  if (l->pos[1] < l->nb_raw - 1 && layout_case_exist(l, l->pos[0], l->pos[1] + 1))
    l->pos[1] +=  1;
  else
  {
    l->pos[1] = 0;
    l->y_offset = 0;
  }
  print_args(l, t->height);
}

void arrow_left_action(t_layout *l, int t_height)
{
  int last_x;

  last_x = (l->nb_args % l->nb_col) ? (l->nb_args % l->nb_col) - 1 :  l->nb_col - 1;
  if (l->pos[0] > 0)
    l->pos[0] -= 1;
  else if (l->pos[1] == l->nb_raw - 1)
    l->pos[0] = last_x;
  else
    l->pos[0] = l->nb_col - 1;
  print_args(l, t_height);
}

void arrow_right_action(t_layout *l, int t_height)
{
  if (l->pos[0] < l->nb_col - 1 && layout_case_exist(l, l->pos[0] + 1, l->pos[1]))
    l->pos[0] += 1;
  else
    l->pos[0] = 0;
  print_args(l, t_height);
}

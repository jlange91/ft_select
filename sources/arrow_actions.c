#include "ft_select.h"

int layout_case_exist(t_layout *l, int x, int y)
{
  int pos;

  pos = (y * l->nb_col) + x;
  return (pos < l->nb_args) ? 1 : 0;
}

void arrow_up_action(t_layout *l)
{
  if (l->pos[1] > 0)
    l->pos[1] -= 1;
  else if (layout_case_exist(l, l->pos[0], l->nb_raw - 1))
    l->pos[1] = l->nb_raw - 1;
  else
    l->pos[1] = l->nb_raw - 2;
  print_args(l);
}

void arrow_down_action(t_layout *l)
{
  if (l->pos[1] < l->nb_raw - 1 && layout_case_exist(l, l->pos[0], l->pos[1] + 1))
    l->pos[1] +=  1;
  else
    l->pos[1] = 0;
  print_args(l);
}

void arrow_left_action(t_layout *l)
{
  int last_x;

  last_x = (l->nb_args % l->nb_col) ? (l->nb_args % l->nb_col) - 1 :  l->nb_col - 1;
  if (l->pos[0] > 0)
    l->pos[0] -= 1;
  else if (l->pos[1] == l->nb_raw - 1)
    l->pos[0] = last_x;
  else
    l->pos[0] = l->nb_col - 1;
  print_args(l);
}

void arrow_right_action(t_layout *l)
{
  if (l->pos[0] < l->nb_col - 1 && layout_case_exist(l, l->pos[0] + 1, l->pos[1]))
    l->pos[0] += 1;
  else
    l->pos[0] = 0;
  print_args(l);
}

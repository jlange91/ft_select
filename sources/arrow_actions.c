#include "ft_select.h"

void arrow_up_action(t_layout *l)
{
  l->pos[1] -= (l->pos[1] > 1) ? 1 : 0;
  print_args(l);
}

void arrow_down_action(t_layout *l)
{
  l->pos[1] += (l->pos[1] < l->nb_raw) ? 1 : 0;
  print_args(l);
}

void arrow_left_action(t_layout *l)
{
  l->pos[0] -= (l->pos[0] > 1) ? 1 : 0;
  print_args(l);
}

void arrow_right_action(t_layout *l)
{
  l->pos[0] += ((l->pos[0] < l->nb_col) && (l->pos[0] * l->pos[1]) < l->nb_args) ? 1 : 0;
  print_args(l);
}

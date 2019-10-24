#include "ft_select.h"

void space_action(t_layout *l)
{
  int test = (l->pos[1] * l->nb_col) + l->pos[0];
  l->params[test].selected = !l->params[test].selected;
  test = (test < l->nb_args - 1) ? (test + 1) : 0;
  l->pos[0] = test % l->nb_col;
  l->pos[1] = test / l->nb_col;
  print_args(l);
}

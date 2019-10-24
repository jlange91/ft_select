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

void enter_action(t_layout *l, t_term *t)
{
  int i;

  i = 0;
  term_off(t);
  while (i < l->nb_args)
  {
    if (l->params[i].selected)
    {
      ft_putstr(l->params[i].str);
      if (i == l->nb_args - 1)
        ft_putstr("\n");
      else
        ft_putstr(" ");
    }
    else
      if (i == l->nb_args - 1)
        ft_putstr("\n");
    ++i;
  }
  exit(0);
}

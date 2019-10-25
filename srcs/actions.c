#include "ft_select.h"

void space_action(t_layout *l, int t_height)
{
  int test = (l->pos[1] * l->nb_col) + l->pos[0];
  l->params[test].selected = !l->params[test].selected;
  test = (test < l->nb_args - 1) ? (test + 1) : 0;
  l->pos[0] = test % l->nb_col;
  l->pos[1] = test / l->nb_col;
  print_args(l, t_height);
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

int   delete_action(t_layout *l, t_term *t, int index)
{
  t_param *new;

  new = realloc_params(l->nb_args, index, l->params);
  if (l->params)
    free(l->params);
  l->params = new;
  l->nb_args -= 1;
  calc_layout(t, l);
  while (!layout_case_exist(l, l->pos[0], l->pos[1]))
  {
    index = index - 1;
    l->pos[0] = index % l->nb_col;
    l->pos[1] = index / l->nb_col;
  }
  print_args(l, t->height);
  return (0);
}

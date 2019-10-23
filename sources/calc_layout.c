#include "ft_select.h"

static void calc_nb_col_raw(t_term *t, t_layout *l) {
  int i;

  i = 0;
  while (i < l->nb_args)
  {
    //first calc for size str and second for space between
    if (((i + 1) * l->col_len) + (i * 1) > t->length)
      break ;
    else
      l->nb_col += 1;
    i++;
  }
  l->nb_raw = (l->nb_args / l->nb_col);
  l->nb_raw += (l->nb_args % l->nb_col) ? 1 : 0;
}

static void get_col_len(t_layout *l) {
	int i;

	i = 0;
	while (i < l->nb_args)
	{
		l->col_len = (l->params[i].len > l->col_len) ?
		 l->params[i].len : l->col_len;
		i++;
	}
}

static void calc_layout_x_y(t_layout *l) {
  int i;

  i = 0;
  while (i < l->nb_args)
  {
    l->params[i].l_x = (i % l->nb_col) + 1;
    l->params[i].l_y = (i / l->nb_col) + 1;
    i++;
  }
}

static void calc_term_x_y(t_layout *l) {
  int i;

  i = 0;
  while (i < l->nb_args)
  {
    //first calc for size str and second for space between
    l->params[i].t_x = ((l->params[i].l_x - 1) * l->col_len) + ((l->params[i].l_x - 1) * 1);
    l->params[i].t_y = l->params[i].l_y;
    i++;
  }
}

void calc_layout(t_term *t, t_layout *l) {
  get_col_len(l);
  calc_nb_col_raw(t, l);
  calc_layout_x_y(l);
  calc_term_x_y(l);
}

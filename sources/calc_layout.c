#include "ft_select.h"

void calc_nb_col_raw(t_term *t, t_layout *l) {
  int i;

  i = 0;
  while (i < l->nb_args)
  {
    if (((i + 1) * l->col_len) + (i * 1) > t->length) //first calc for size str and second for space between
      break ;
    else
      l->nb_col += 1;
    i++;
  }
  l->nb_raw = (l->nb_args / l->nb_col);
  l->nb_raw += (l->nb_args % l->nb_col) ? 1 : 0;
}

void get_col_len(t_layout *l) {
	int i;

	i = 0;
	while (i < l->nb_args)
	{
		printf("%s\n", l->params[i].str);
		l->col_len = (l->params[i].len > l->col_len) ?
		 l->params[i].len : l->col_len;
		i++;
	}
}

void calc_layout(t_term *t, t_layout *l) {
  get_col_len(l);
  // printf("%d\n", l->col_len);
  t = (t_term*)t;
  calc_nb_col_raw(t, l);
}

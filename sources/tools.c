#include "ft_select.h"

int layout_case_exist(t_layout *l, int x, int y)
{
  int pos;

  pos = (y * l->nb_col) + x;
  return (pos < l->nb_args) ? 1 : 0;
}

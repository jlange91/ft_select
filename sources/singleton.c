#include "ft_select.h"

t_term  *singleton_term(t_term *t)
{
  static t_term *term = NULL;

  if (t)
    term = t;
  return term;
}

t_layout  *singleton_layout(t_layout *l)
{
  static t_layout *layout = NULL;

  if (l)
    layout = l;
  return layout;
}

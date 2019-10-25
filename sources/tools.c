#include "ft_select.h"

void set_y_offset(t_layout *l, int t_height)
{
  while ((l->pos[1] - l->y_offset) < 0)
    l->y_offset -= 1;
  while ((l->pos[1] - l->y_offset) >= t_height)
    l->y_offset += 1;
}

int layout_case_exist(t_layout *l, int x, int y)
{
  int pos;

  pos = (y * l->nb_col) + x;
  return (pos < l->nb_args) ? 1 : 0;
}

mode_t	get_type_file(char *str)
{
	struct stat s;

	return (lstat(str, &s)) ? 0 : s.st_mode;
}

int        ft_poutchar(int c)
{
    return (write(STDERR_FILENO, &c, 1));
}

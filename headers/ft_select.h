/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:58:33 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/23 15:09:48 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include "libft.h"
#include <termios.h>
#include <term.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include <stdio.h>

# define SPACE " "
# define ARROW_UP "\e[A"
# define ARROW_DOWN "\e[B"
# define ARROW_RIGHT "\e[C"
# define ARROW_LEFT "\e[D"

typedef struct  s_term
{
  char            *type;
  struct termios  old;
  struct termios  new;
  int             length;
  int             height;
}               t_term;

typedef struct   s_param
{
  char  *str;
  int   len;
  int   t_x;
  int   t_y;
  int   l_x;
  int   l_y;
  char  selected;
}                 t_param;

typedef struct    s_layout
{
  int     nb_args;
  int     nb_col;
  int     nb_raw;
  int     col_len;
  t_param *params;
  int     pos[2];
}		t_layout;

int       init_term(t_term *t);
t_term    *singleton_term(t_term *t);
t_layout  *singleton_layout(t_layout *l);
int       read_stdin(t_term *t, t_layout *l);
int       init_params(int ac, char **av, t_layout *l);
int		    init_layout(int ac, t_layout *l);
void      calc_layout(t_term *t, t_layout *l);
void	    print_args(t_layout *lay);
void      arrow_up_action(t_layout *l);
void      arrow_down_action(t_layout *l);
void      arrow_left_action(t_layout *l);
void      arrow_right_action(t_layout *l);
void      space_action(t_layout *l);
int       layout_case_exist(t_layout *l, int x, int y);
void	    ft_handle_signals(int sig);
int	      term_off(t_term *t);
void	    handle_signals(int sig);
void	    ft_set_signals();
int       get_size_term(t_term *t);

#endif

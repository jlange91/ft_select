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

# include "libft.h"
# include <termios.h>
# include <term.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <stdio.h>

# define ARROW_UP "\e[A"
# define ARROW_DOWN "\e[B"
# define ARROW_RIGHT "\e[C"
# define ARROW_LEFT "\e[D"
# define SPACE " "
# define ENTER "\n"
# define DELETE 127

# define BACK_BLACK   "\x1b[40m"
# define BACK_RED     "\x1b[41m"
# define BACK_GREEN   "\x1b[42m"
# define BACK_YELLOW  "\x1b[43m"
# define BACK_BLUE    "\x1b[44m"
# define BACK_MAGENTA "\x1b[45m"
# define BACK_CYAN    "\x1b[46m"
# define BACK_GREY    "\x1b[47m"
# define BLACK        "\033[30m"
# define RED          "\033[31m"
# define GREEN        "\033[32m"
# define BROWN        "\033[33m"
# define BLUE         "\033[34m"
# define MAGENTA      "\033[35m"
# define CYAN         "\033[36m"
# define GREY         "\033[37m"
# define D_GREY       "\033[1m\033[30m"
# define B_RED        "\033[1m\033[31m"
# define B_GREEN      "\033[1m\033[32m"
# define YELLOW       "\033[1m\033[33m"
# define B_BLUE       "\033[1m\033[34m"
# define B_MAGENTA    "\033[1m\033[35m"
# define B_CYAN       "\033[1m\033[36m"
# define WHITE        "\033[1m\033[37m"
# define RESET        "\033[0m"

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
void      enter_action(t_layout *l, t_term *t);
t_param   *realloc_params(int nb_args, int ignored_index, t_param *old);
int       delete_action(t_layout *l, t_term *t, int index);

#endif

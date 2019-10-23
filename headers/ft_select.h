/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:58:33 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/22 18:03:56 by thdelmas         ###   ########.fr       */
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
  int   x;
  int   y;
}                 t_param;

int     init_term(t_term *t);
t_term  *singleton_term(t_term *t);
int      read_stdin(t_term *t);

#endif

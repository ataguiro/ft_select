/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:04:27 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/27 15:21:37 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include <dirent.h>
# include <termios.h>
# include <stdio.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/ipc.h>
# include <sys/ioctl.h>

# include "libft.h"

# define CODE_SPACE 7
# define CODE_ESCAPE -1
# define CODE_RETURN 0
# define CODE_BACK 2
# define CODE_UP 10
# define CODE_DOWN 20
# define CODE_RIGHT 30
# define CODE_LEFT 40
# define CODE_HOME 107
# define CODE_END 2016
# define CODE_DEL 100

# define IS_DIR 0xc
# define REG_FILE 0xa
# define EXE_FILE 0xb
# define NOT_A_FILE 0xd

typedef struct	s_clean
{
	int		j;
	size_t	i;
	int		dq;
	int		q;
	char	*new;
}				t_clean;

typedef struct	s_choice
{
	int	current;
	int	cols;
	int	*selected;
}				t_choice;

extern t_choice	g_choice;

typedef struct	s_termsize
{
	size_t		col;
	size_t		row;
}				t_termsize;

t_termsize		*ft_termsize(void);

int				ft_input(void);
void			ft_raw_mode(void);
void			ft_default_mode(void);

int				key_get(void);
void			key_dump(int key);
int				get_basics(char c);
int				get_x1b(char *c);
int				get_x31(char c);
int				get_max_len(void);
void			print_spaces(int max, char *current);
void			ft_print_args(void);

char			**search(void);
t_choice		*choice(void);
char			***env(void);
int				*status(void);

void			code_down(void);
void			code_right(void);
void			code_left(void);
void			code_up(void);
void			code_space(void);
void			code_escape(void);
void			code_return(void);
void			code_backspace(void);
void			code_delete(void);

void			move_right(int x);
void			move_left(int x);
void			move_up(int x);
void			move_down(int x);

void			ft_print_args(void);
void			sig_handler(int signo);

#endif

/*
** pipe.h for  in /home/charvo_a/42/pipe
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon May 12 17:32:59 2014 Nicolas Charvoz
** Last update Thu May 22 15:08:44 2014 heitzl_s
*/

#ifndef PIPE_H_
# define PIPE_H_

# include "../execution/execution.h"

/* xmalloc.c */
void	*xmalloc(int);

/* pipes.c */
void	create_pipes(t_cmd*, int);
int	check_pipe_cmd(t_cmd*, t_42sh*);

#endif

/*
** pipe.h for  in /home/charvo_a/42/pipe
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon May 12 17:32:59 2014 Nicolas Charvoz
** Last update Mon May 19 10:39:23 2014 heitzl_s
*/

#ifndef PIPE_H_
# define PIPE_H_

# include "../execution/execution.h"

/* xmalloc.c */
void	*xmalloc(int);

/* pipes.c */
int	init_pipes(t_cmd*, t_cmd*, t_42sh*, int);
void	exec_pipe(t_cmd*, int, t_42sh*);

/* error_gest.c */
char	*prompt_2();

#endif

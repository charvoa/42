/*
** execution.h for execution in /home/garcia_t/42/execution
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri May  9 11:18:26 2014 garcia antoine
** Last update Mon May 19 11:34:24 2014 garcia antoine
*/

#ifndef EXECUTION_H_
# define EXECUTION_H_

typedef struct s_signal
{
  int	nb;
  char	*msg;
}		t_signal;

/* redirections.c */
int	redir_left(t_cmd*, t_cmd*, t_42sh*);
int	double_redir_right(t_cmd*, t_cmd*, t_42sh*);
int	redir_right(t_cmd*, t_cmd*, t_42sh*);
int	redirections(t_cmd*, t_cmd*, t_42sh*);

/* global_exec.c */
int	global_exec(t_cmd*, t_42sh*, int);

/* exec_simple_cmd.c */
int	check_cmd(t_cmd*, t_42sh*);
int	exec_cmd(t_cmd*, t_42sh*);
int	exec_cmd_simple(t_cmd*, t_42sh*);

#endif

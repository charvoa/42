/*
** execution.h for execution in /home/garcia_t/42/execution
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri May  9 11:18:26 2014 garcia antoine
** Last update Thu May 22 12:06:55 2014 heitzl_s
*/

#ifndef EXECUTION_H_
# define EXECUTION_H_

typedef struct s_signal
{
  int	nb;
  char	*msg;
}		t_signal;

/* redirections.c */
int	redir_left(t_cmd*, t_cmd*);
int	double_redir_right(t_cmd*, t_cmd*);
int	redir_right(t_cmd*, t_cmd*);
int	redirections(t_cmd*, t_cmd*);

/* global_exec.c */
int	global_exec(t_cmd*, t_42sh*, int);

/* exec_simple_cmd.c */
int	check_cmd(t_cmd*, t_42sh*);
int	exec_cmd(t_cmd*, t_42sh*);
int	exec_cmd_simple(t_cmd*, t_42sh*);

/* prepa_pipes.c */
int	prepa_pipes(t_cmd*);
int	execution(t_cmd*, t_42sh*, int);

/* signal.c */
int	check_signal(int);

#endif

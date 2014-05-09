/*
** execution.h for execution in /home/garcia_t/42/execution
** 
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
** 
** Started on  Fri May  9 11:18:26 2014 garcia antoine
** Last update Fri May  9 13:28:44 2014 garcia antoine
*/

#ifndef EXECUTION_H_
# define EXECUTION_H_

void	exec_cmd(t_cmd *, t_42sh *);
int	check_cmd(t_cmd *, t_42sh *);
int	exec_cmd_simple(t_cmd *, t_42sh *);
int	global_exec(t_cmd *cmd, t_42sh *, int);
int	redir_right(t_cmd *, t_cmd *, t_42sh *);
int	double_redir_right(t_cmd *, t_cmd *, t_42sh *);

#endif

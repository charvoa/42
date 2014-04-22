/*
** 42sh.h for 42sh in /home/garcia_t/rendu/42sh
** 
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
** 
** Started on  Fri Apr  4 12:16:42 2014 garcia antoine
** Last update Tue Apr 22 14:37:22 2014 garcia antoine
*/

#ifndef SHELL_H_
# define SHELL_H_
# include "list.h"
typedef struct s_42sh
{
  t_dlist	*env;
  char		*cmd;
}		t_42sh;

int	isolate_name_and_value_from_env(char *env);
char	*get_name_from_env(char *env);
char	*get_value_from_env(char *env);
char	*get_env(char *name, t_dlist *env);
char	**list_to_tab(t_dlist *env);
void    prompt(t_42sh *shell);
int	start_shell(t_42sh *shell);
void	init_my_shell(t_42sh *shell, char **env);

#endif /*SHELL_H_ */

/*
** 42sh.h for 42sh in /home/garcia_t/rendu/42sh
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Fri Apr  4 12:16:42 2014 garcia antoine
** Last update Fri May  9 11:17:18 2014 garcia antoine
*/

#ifndef SHELL_H_
# define SHELL_H_

# include "list.h"
# include <stdio.h>

typedef struct s_42sh
{
  t_dlist	*env;
  char		*cmd;
  char		**path;
  char		**envtab;
}		t_42sh;

int	isolate_name_and_value_from_env(char *env);
char	*get_name_from_env(char *env);
char	*get_value_from_env(char *env);
char	*get_env(char *name, t_dlist *env);
char	**list_to_tab(t_dlist *env);
void    prompt(t_42sh *shell);
int	start_shell(t_42sh *shell);
int	init_my_shell(t_42sh *shell, char **env);
void	my_clear();
char	**strtotab(char*);
int	count_word(char*);
int	count_char(char*);

#endif /*SHELL_H_ */

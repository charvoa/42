/*
** exec.h for  in /home/charvo_a/42/execution
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon May  5 15:33:03 2014 Nicolas Charvoz
** Last update Wed May  7 12:27:39 2014 Nicolas Charvoz
*/

#ifndef EXEC_H_
# define EXEC_H_

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef	struct s_cmd
{
  char	**args;
}		t_cmd;

/* EXEC.C */
int	size_fo_tab(char**);
int	send(char**, char**, char**);
int	exec_simple(char**, char**, char**);
/* PARS.C */
int	countchar2(char*);
int	count_word2(char*);
void	parser2(char*, t_cmd*);

#endif

/*
** parser.h for  in /home/charvo_a/42/parser
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 28 10:43:54 2014 Nicolas Charvoz
<<<<<<< Updated upstream
** Last update Wed May  7 13:01:29 2014 Nicolas Charvoz
=======
** Last update Mon May  5 13:54:59 2014 garcia antoine
>>>>>>> Stashed changes
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "../env/list.h"
# include "../env/listok.h"
# include "../lexer/src/lexer.h"
# include "../execution/exec.h"

typedef	struct	s_pars	t_pars;

struct	s_pars
{
  char	**tab;
};

/* PARSER.C */
char	*check_token(t_token**, t_lex*);
void	parser(t_token**, t_42sh*);
int	size_of_list(t_token**);

#endif

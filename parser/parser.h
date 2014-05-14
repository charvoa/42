/*
** parser.h for  in /home/charvo_a/42/parser
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 28 10:43:54 2014 Nicolas Charvoz
** Last update Wed May 14 14:49:14 2014 garcia antoine
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "../env/list.h"
# include "../env/listok.h"
# include "../lexer/src/lexer.h"


typedef	struct	s_pars	t_pars;
struct	s_pars
{
  char	**tab;
};

typedef	struct	s_cmd
{
  char		**args;
  char		*token;
  int		type;
  int		status;
  int		fdin;
  int		fdout;
}		t_cmd;

/* PARSER.C */

char	*check_token(t_token**, t_lex*);
void	parser(t_token**, t_42sh*);
int	size_of_list(t_token**);

/* PARS.C */
int	countchar2(char*);
int	count_word2(char*);
void	parser2(char*, t_cmd*);

/* STRUCT_FILL.C */
void	init_struct(t_cmd*);
void	fill_it(t_cmd*, char*, char*);
int	nbr_of_token(t_token**);
void	struct_fill(char**, t_token**, t_42sh*);


#endif

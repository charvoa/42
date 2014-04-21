/*
** lexer.h for  in /home/charvo_a/Work/42
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sat Apr  5 15:42:30 2014 Nicolas Charvoz
** Last update Sat Apr 19 16:06:54 2014 Nicolas Charvoz
*/

typedef	enum	s_token
  {
    TOKEN_WORD,
    TOKEN_PIPE,
    TOKEN_COMMA,
    TOKEN_RED_L,
    TOKEN_RED_R,
    TOKEN_DBL_L,
    TOKEN_DBL_R,
    TOKEN_AND,
    TOKEN_OR,
    TOKEN_NONE,
    TOKEN_UNK,
    TOKEN_END,
  }		e_token;

typedef	struct	s_char
{
  int	token;
  char	*cmd;
}		t_char;

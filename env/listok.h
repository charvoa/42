/*
** lexer.h for lexer in /home/garcia_t/rendu/42sh
** 
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
** 
** Started on  Sat Apr 19 15:15:18 2014 garcia antoine
** Last update Mon Apr 21 15:54:18 2014 garcia antoine
*/

#ifndef LEXER_H_
# define LEXER_H

typedef enum token_id
  {
    TOK_NEWLINE, //\n
    TOK_EOF, //EOF
    TOK_NONE,
    TOK_AND, //&&
    TOK_SEMICOL, //;
    TOK_DLESS, //<<
    TOK_LESS, //<
    TOK_DGREAT, //>>
    TOK_GREAT, //>
    TOK_OR, //||
    TOK_PIPE, // |
    TOK_WORD
  }		e_tokenid;

typedef struct s_token
{
  int		type;
  char		*value;
  struct s_token *next;
}		t_token;

t_token	*insert(t_token *, int, char *);
#endif /* LEXER_H_ */

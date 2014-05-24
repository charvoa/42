/*
** lexer.c for 42sh in /home/heitzl_s/42
**
** Made by heitzl_s
** Login   <heitzl_s@epitech.net>
**
** Started on  Sat May 24 01:04:08 2014 heitzl_s
** Last update Sat May 24 06:07:33 2014 Nicolas Charvoz
*/

#include "lexer.h"
#include "../parser/parser.h"
#include "../xlib/xlib.h"
#include "../alias/alias.h"

int	check_unk(char *str, int i, t_token **token)
{
  char	*unk;
  int	j;

  j = 0;
  unk = xmalloc((strlen(str) + 1) * sizeof(char*));
  unk = memset(unk, 0, (strlen(str) + 1));
  while (((check_letter2(str[i]) == -1) && str[i] != '\t' ) && str[i] != '\0')
    {
      unk[j] = str[i];
      j++;
      i++;
    }
  unk[i] = '\0';
  if (unk[0] != '\0')
    *token = insert(*token, TOKEN_UNK, strdup(unk), i);
  free(unk);
  return (i);
}

int	word_check(char *str, int i, t_token **token)
{
  char	*word;
  int	j;

  j = 0;
  word = xmalloc((strlen(str) + 1) * sizeof(char*));
  word = memset(word, 0, (strlen(str) + 1));
  while (((check_letter(str[i]) != -1) || str[i] == '\t' ) && (str[i] != '\0'))
    {
      word[j] = str[i];
      j++;
      i++;
    }
  word[i] = '\0';
  if (word[0] != '\0')
    {
      word = epur_str(word);
      *token = insert(*token, TOKEN_WORD, strdup(word), i);
    }
  free(word);
  return (i);
}

void	lex(char *str, t_token **token)
{
  int	i;

  i = 0;
  while (str[i])
    {
      i = comma_check(str, i, token);
      i = pipe_check(str, i, token);
      i = red_r(str, i, token);
      i = red_l(str, i, token);
      i = check_and(str, i, token);
      i = word_check(str, i, token);
      i = check_unk(str, i, token);
    }
}

int	lexer(char *cmd, t_token **token, t_42sh *shell)
{
  int	i;
  char	*error;
  t_lex	*lexi;

  i = 0;
  lexi = xmalloc(sizeof(*lexi));
  lexi->cmd = strdup(cmd);
  lexi->cmd = epur_str(lexi->cmd);
  if (!(lexi->cmd[i]))
    return (0);
  lex(lexi->cmd, token);
  if ((error = check_token(token, lexi)) != NULL)
    {
      printf("42sh : Syntax error near unexpected token `%s`\n", error);
      return (0);
    }
  else
    {
      token = alias(token, shell);
      if (parser(token, shell) == -42)
	return (-42);
    }
  free(lexi->cmd);
  free(lexi);
  return (0);
}

/*
** main.c for  in /home/charvo_a/Work/42
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Fri Apr  4 13:56:53 2014 Nicolas Charvoz
** Last update Mon Apr 28 13:17:48 2014 Nicolas Charvoz
*/

#include "lexer.h"

int	word_check(char *str, int i, t_token **token)
{
  char	*word;
  int	j;

  j = 0;
  word = malloc((strlen(str) + 1) * sizeof(char*));
  word = memset(word, 0, (strlen(str) + 1));
  while (((check_letter(str[i]) != -1) || str[i] == '\t' ) && (str[i] != '\0'))
    {
      word[j] = str[i];
      j++;
      i++;
    }
  word[i] = '\0';
  if (word[0] != '\0')
    *token = insert(*token, TOKEN_WORD, strdup(word), i);
  free(word);
  return (i);
}

void	lex(char *str, t_token **token)
{
  int	i;

  i = 0;
  while (str[i])
    {
      i = word_check(str, i, token);
      i = comma_check(str, i, token);
      i = pipe_check(str, i, token);
      i = red_r(str, i, token);
      i = red_l(str, i, token);
      i = check_and(str, i, token);
    }
}

int		lexer(char *cmd, t_token **token)
{
  cmd = epur_str(cmd);
  lex(cmd, token);
  if ((check_token(token)) == -1)
    printf("erreur token\n");
  return (0);
}

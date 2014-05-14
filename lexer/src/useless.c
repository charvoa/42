/*
** useless.c for  in /home/charvo_a/42/lexer
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 21 14:54:33 2014 Nicolas Charvoz
** Last update Mon Apr 21 15:16:57 2014 Nicolas Charvoz
*/

#include "lexer.h"

void    lexer_test(char *cmd)
{
  int   i = 0;
  int   pipe = 0;
  int   comma = 0;
  int   red_r = 0;
  int   red_l = 0;
  int   dbl_r = 0;
  int   dbl_l = 0;
  int   unk = 0;

  while (cmd[i])
    {
      if (cmd[i] == '|')
        pipe++;
      else if (cmd[i] == ';')
        comma++;
      else if (cmd[i] == '<' && cmd[i + 1] != '<')
        red_r++;
      else if (cmd[i] == '>' && cmd[i + 1] != '>')
        red_l++;
      else if (cmd[i] == '>' && cmd[i + 1] == '>')
	dbl_r++;
      else if (cmd[i] == '<' && cmd[i + 1] == '<')
        dbl_l++;
      else if ((check_letter(cmd[i]) == -1))
        unk++;
      i++;
    }
  printf("La commande suivante comporte %d pipe, %d point-virgule, %d redirection simple droite, %d redirection simple gauche, %d redirection double gauche, %d redirection double droite et %d séparateurs inconnus \n", pipe, comma, red_r, red_l, dbl_l, dbl_r, unk);
}

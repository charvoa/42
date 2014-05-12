/*
** error_gest.c for 4deush in /home/girard_s/rendu/42/execution/pipes
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Wed May  7 13:31:59 2014 Nicolas Girardot
** Last update Mon May 12 17:36:58 2014 Nicolas Charvoz
*/

#include <stdio.h>
#include <string.h>
#include "pipe.h"

char	*prompt_2()
{
  char	*buffer;
  char	*final;
  int	size_realloc;
  int	ret;
  int	size;

  my_putchar('>');
  ret = 0;
  buffer = xmalloc(15 * sizeof(char));
  final = xmalloc(1 *sizeof(char));
  while ((ret = read(0, buffer, 15)) != 0)
    {
      final = realloc(final, strlen(final) + 15);
      strcat(final, buffer);
      memset(buffer, '\0', 15);
      printf("%d\n", ret);
      ret = 0;
      printf("%s\n", final);
    }
  size = strlen(final) - 1;
  final[size] = '\0';
  return (final);
}

/* char	**if_last_pipe(char **cmd_line) */
/* { */
/*   char	**modified_cmd; */
/*   int	y; */

/*   y = 0; */
/*   modified_cmd = xmalloc((nbr_of_str_in_tab(cmd_line) + 2) * sizeof(char *)); */
/*   while (cmd_line[y] != NULL) */
/*     { */
/*       modified_cmd[y] = strdup(cmd_line[y]); */
/*       y++; */
/*     } */
/* } */

int	main()
{
  prompt_2();
}

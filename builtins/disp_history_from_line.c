/*
** disp_history_from_line.c for 42sh in /home/girard_s/rendu
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Wed May 21 13:42:33 2014 Nicolas Girardot
** Last update Fri May 23 10:28:40 2014 heitzl_s
*/

#include "builtins.h"

int	gest_error_hist_disp_from_line(char *buffer, int line, int nbr_of_line)
{
  if (line >= nbr_of_line)
    {
      my_putstr(buffer);
      return (0);
    }
  if (line == 0)
    return (0);
  return (0);
}

void	display_history_from_pos(char *buffer, int pos)
{
  while (buffer[pos] != '\0')
    putchar(buffer[pos++]);
}

int	get_start_pos(char *buffer, int line)
{
  int	i;
  int	passed_line;

  passed_line = 0;
  i = strlen(buffer);
  while (passed_line <= line)
    {
      if (buffer[i] == '\n')
	passed_line++;
      i--;
    }
  return (i + 2);
}

int	get_nbr_of_line(char *buffer)
{
  int	i;
  int	nbr_of_line;

  i = 0;
  nbr_of_line = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
	nbr_of_line++;
      i++;
    }
  return (nbr_of_line);
}

int	disp_history_from_line(char *buffer, int line)
{
  int	nbr_of_line;
  int	start_pos;

  nbr_of_line = get_nbr_of_line(buffer);
  if ((gest_error_hist_disp_from_line(buffer, line, nbr_of_line)) == 0)
    return (0);
  start_pos = get_start_pos(buffer, line);
  display_history_from_pos(buffer, start_pos);
  return (0);
}

/*
** check_func.c for dipzdazd in /home/girard_s/rendu/42/env/check_cmd
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Sun May 25 22:17:23 2014 Nicolas Girardot
** Last update Sun May 25 22:59:33 2014 Nicolas Girardot
*/

int	check_all();
{
  void	*s;
  char	str[2] = "h";
  char	*test;
  int	fd;
  int	jog;

  if ((s = xmalloc(10000)) == NULL)
    return (-1);
  if ((s = xcalloc(10000, 10000)) == NULL)
    return (-1);
  if ((fd = open("../main.c", O_RDWR)) == -1)
    {
      close(fd);
      return (-1);
    }
  if ((read(fd) == -1))
    return (-1);
  if ((test = strdup(str)) ==  NULL)
    return (-1);
  if (check_second == -1)
    return (-1);
  return (0);
}

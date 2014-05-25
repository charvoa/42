int	check_second()
{
  int	fd;
  int	jog;
  int	fd[2];

  fd = open("../main.c", O_RDWR);
  jog = open("../list.c", O_RDWR);
  if (dup2(fd, jog) == -1)
    {
      close(fd);
      close(jog);
      return (-1);
    }
  jog = open("../main.c", O_RDWR);
  if (close(jog) == -1)
    return (-1);
  if (xpipe(fd) == - 1)
    return (-1);
}

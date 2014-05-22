/*
** or_and.c for  in /home/charvo_a/42/execution
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon May 19 22:51:34 2014 Nicolas Charvoz
** Last update Mon May 19 23:52:23 2014 Nicolas Charvoz
*/

int	exec_or(t_cmd *cmd, t_cmd *cmd_2, t_42sh *shell)
{
  if (cmd->status == 0)
    {
      //exec
    }
  else
    return (0);
}

int	exec_and(t_cmd *cmd, t_cmd *cmd_2, t_42sh *shell)
{
  if (cmd->status == 0)
    {
      return (0);
    }
  else
    //exec
}

int	check_or_and(t_cmd *cmd, t_cmd *cmd_2, t_42sh *shell)
{
  if (!strcmp(cmd->token, "||"))
    {
      exec_or(cmd, cmd_2, shell);
    }
  else if (!strcmp(cmd->token, "||"))
    {
      exec_and(cmd, cmd_2, shell);
    }
}

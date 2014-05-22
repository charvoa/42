/*
** builtins.h for  in /home/charvo_a/42/builtins
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Thu May 22 15:55:51 2014 Nicolas Charvoz
** Last update Thu May 22 16:19:50 2014 Nicolas Charvoz
*/

#ifndef BUILTINS_H_
# define BUILTINS_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../env/42sh.h"
# include "../env/list.h"

/* MY_HISTORY.C */
int	restricted_history(char*, char*);
int	my_history(t_42sh*, char**, t_dlist*);

/* MY_ENV.C */
int	my_env(t_42sh*, char**, t_dlist*);

/* MY_ECHO.C */
int	echo_from_var_env(char*, t_dlist*);
int	my_echo(t_42sh*, char**, t_dlist*);

/* MY_CD.C */
char	*get_old_pwd(t_dlist*);
char	*get_my_home(t_dlist*);
char	*get_path_from_opt(char*);
int	check_chdir(char*, t_dlist*);
int	my_cd(t_42sh*, char**, t_dlist*);

/* MODIF_PWD.C */
char	*clean_arg(char*);
void	modif_simple_pwd(char*, t_dlist*);
void	modif_pwd_from_home_to_path(char*, t_dlist*);
void	modif_pwd_home(char*, t_dlist*);
int	modif_oldpwd(char*, t_dlist*);

/* MODIF_PWD2.C */
char	*get_pwd_from_home(char *pwd, char *name, t_dlist *env);
char	*check_name(char *name);
char	*parse_name2(char *arg, char *path, int i);
char	*parse_name(char *arg, char *path);

/* DISP_HISTORY_FROM_LINE.C */
int	gest_error_hist_disp_from_line(char *buffer, int line, int nbr_of_line);
void	display_history_from_pos(char *buffer, int pos);
int	get_start_pos(char *buffer, int line);
int	get_nbr_of_line(char *buffer);
int	disp_history_from_line(char *buffer, int line);

/* CHECK_BUILTINS.C */
int	find_cmd(char*);
void	fill_builtins(int (**builtins)(t_42sh *shell, char **args, t_dlist *env));
int	check_builtins(t_42sh*, char**, t_dlist*);

#endif

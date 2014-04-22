/*
** listok.h for  in /home/charvo_a/42/env
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Mon Apr 21 16:32:17 2014 Nicolas Charvoz
** Last update Tue Apr 22 13:50:19 2014 Nicolas Charvoz
*/

#ifndef LISTOK_H_
# define LISTOK_H_

typedef struct s_token
{
  int           type;
  char          *value;
  struct s_token *next;
}               t_token;

t_token	*insert(t_token *, int, char *);

#endif /* LISTOK_H_ */

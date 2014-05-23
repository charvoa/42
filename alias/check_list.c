#include "alias.h"

t_token		**check_list(t_alias **alias, t_token **token)
{
  t_token	*tok;
  t_alias	*a;

  tok = *token;
  a = *alias;

  while (tok)
    {
      while (a)
	{
	  if (!(strncmp(a->ali[0], tok->value, strlen(a->ali[0]))))
	    {
	      tok->value = realloc(tok->value, (strlen(tok->value) + strlen(a->ali[1]) + 2));
	      strcpy(tok->value, a->ali[1]);
	    }
	  a = a->next;
	}
      tok = tok->next;
    }
  return (token);
}

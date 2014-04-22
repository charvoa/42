/*
** my.h for my in /home/garcia_t/rendu/Piscine-C-include
** 
** Made by garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Fri Oct 11 13:21:20 2013 garcia
** Last update Fri Mar 21 14:05:38 2014 garcia antoine
*/

#ifndef MY_H_
# define MY_H_

void	my_putchar(char c);

char	**my_str_to_word_tab(char *str);

char	*my_strdup(char *str);

int	my_isneg(int nb);

void	my_putnbr(int nb);

int	my_swap(int *a, int *b);

int	my_putstr(char *str);

int	my_strlen(char *str);

int	my_getnbr(char *str);

void	my_sort_int_tab(int *tab, int size);

int	my_power_rec(int nb, int power);

int	my_square_root(int nb);

int	my_is_prime(int nombre);

int	my_find_prime_sup(int nb);

char	*my_strcpy(char *dest, char *src);

char	*my_strncpy(char *dest, char *src, int nb);

char	*my_revstr(char *str);

char	*my_strstr(char *str, char *to_find);

int	my_strcmp(char *s1, char *s2);

int	my_strncmp(char *s1, char *s2, int nb);

char	*my_strupcase(char *str);

char	*my_strlowcase(char *str);

char	*my_strcapitalize(char *str);

int	my_str_isalpha(char *str);

int	my_str_isnum(char *str);

int	my_str_islower(char *str);

int	my_str_isupper(char *str);

int	my_str_isprintable(char *str);

int	my_showstr(char *str);

int	my_showmem(char *str, int size);

char	*my_strcat(char *dest, char *src);

char	*my_strncat(char *dest, char *src, int nb);

int	my_strlcat(char *dest, char *src, int size);

void	my_putnbr_base(int nb, char *base);

int	my_flag(char c);
void	init_fs(int (**fs)(va_list ap));
int	my_printf(const char *format, ...);
int	my_putstr_printf(va_list ap);
int	my_putnbr_printf(va_list ap);
int	my_putchar_printf(va_list ap);
int	my_ptr_printf(va_list ap);
int	my_nbbin_printf(va_list ap);
int	my_putoctal_printf(va_list ap);
int	my_octal_printf(va_list ap);
int	my_puthexa_printf(va_list ap);
int	my_puthexa2_printf(va_list ap);
int	my_modulo_printf(va_list ap);
int	my_putnbru_printf(va_list ap);
int	my_flag(char c);
char	*my_memset(char *s, char c, int size);
ssize_t	xread(int, void *, size_t);

#endif

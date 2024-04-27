#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
void	ft_putchar(const char a);
void	ft_putstr(char *c);
int	ft_strlen(char *c);
int	type_c(va_list ap);
int	type_s(va_list ap);

#endif

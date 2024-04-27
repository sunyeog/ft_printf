/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */

/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:00:15 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/04/27 21:50:01 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(const char a)
{
	write(1, &a, 1);
}

void ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
}

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int	ft_form(const char *str, va_list ap)
{
	int	i;
	int cnt;
	
	i = 0;
	cnt = 0;
	if (str[i + 1] == 'c')
		cnt = type_c(ap);
	else if (str[i + 1] == 's')
		cnt = type_s(ap);
	else if (str[i + 1] == 'p');
		cnt = type_p(ap);
	else if (str[i + 1] == 'd');
	else if (str[i + 1] == 'i');
	else if (str[i + 1] == 'u');
		va_arg(ap, unsigned int);
	else if (str[i + 1] == 'x');
	else if (str[i + 1] == 'X');
	return (cnt);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	va_start(ap, str);
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == '%')
		{
			cnt += ft_form(str, ap);
			str++;
			str++;
		}
		else
		{
			ft_putchar(*str);
			cnt++;
			str++;
		}
	}
	return (cnt);
}


int main(void)
{
	int	i = 0;
	i = ft_printf("a%sdf", "bc");
	write(1, &i, 4);
}













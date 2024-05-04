/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:00:15 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/05/04 21:52:53 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(const char a)
{
	write(1, &a, 1);
}

void	ft_putstr(char *c)
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
	int	cnt;

	i = 0;
	cnt = 0;
	if (str[i + 1] == 'c')
		cnt = type_c(ap);
	else if (str[i + 1] == 's')
		cnt = type_s(ap);
	else if (str[i + 1] == 'p')
		cnt = type_p(ap);
	else if (str[i + 1] == 'd')
		cnt = type_d(ap);
	else if (str[i + 1] == 'i')
		cnt = type_d(ap);
	else if (str[i + 1] == 'u')
		cnt = type_u(ap);
	else if (str[i + 1] == 'x')
		cnt = type_x(ap);
	else if (str[i + 1] == 'X')
		cnt = type_xu(ap);
	else if (str[i + 1] == '%')
		cnt = type_per(ap);
	return (cnt);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		cnt;

	va_start(ap, str);
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
/*
#include <stdio.h>

int main(void)
{
	ft_printf("%%\n");
	//ft_printf("%u\n", 4294967295);
	//printf("\n\n");
	printf("%%");
	//printf("%u", 4294967295);
}*/

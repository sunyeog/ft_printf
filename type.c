/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:48:45 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/05/04 21:45:18 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_c(va_list ap)
{
	char	a;

	a = (char)va_arg(ap, int);
	ft_putchar(a);
	return (1);
}

int	type_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	ft_putstr(s);
	return (ft_strlen(s));
}

int	unsigned_hex(unsigned long long res)
{
	char				*hexa;
	unsigned long long	i;
	unsigned long long	cnt;

	hexa = "0123456789abcdef";
	cnt = 0;
	if (res <= 0)
		return ((int)cnt);
	else
	{
		i = res % 16;
		cnt++;
		cnt += unsigned_hex(res / 16);
		ft_putchar(hexa[i]);
	}
	return ((int)cnt);
}

int	type_p(va_list ap)
{
	unsigned long long	p;
	int					cnt;

	p = (unsigned long long)va_arg(ap, void *);
	ft_putstr("0x");
	cnt = unsigned_hex(p);
	return (cnt + 2);
}

int	type_u(va_list ap)
{
	unsigned int	u;
	int				cnt;

	u = va_arg(ap, unsigned int);
	cnt = ft_putnbr_u(u);
	return (cnt);
}

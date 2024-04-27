/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:48:45 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/04/27 22:36:22 by sunhnoh          ###   ########.fr       */
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

int type_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	ft_putstr(s);
	return (ft_strlen(s));
}

int type_p(va_list ap)
{
	char	*p;

}

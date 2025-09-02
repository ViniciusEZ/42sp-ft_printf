/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:28:04 by vfirmino          #+#    #+#             */
/*   Updated: 2025/09/01 16:05:02 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	char			i;
	unsigned int	len;

	len = 1;
	i = (nb % 10) + '0';
	nb = nb / 10;
	if (nb != 0)
		len += ft_putunbr(nb);
	write(1, &i, 1);
	return (len);
}

int	ft_format(va_list ap, char c, const char *str, size_t i)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (c == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'x')
		return (ft_puthex((unsigned long)va_arg(ap, unsigned int),
				"0123456789abcdef", str, i));
	if (c == 'X')
		return (ft_puthex((unsigned long)va_arg(ap, unsigned int),
				"0123456789ABCDEF", str, i));
	if (c == 'p')
		return (ft_putptr(va_arg(ap, void *), "0123456789abcdef", str, i));
	return (0);
}

int	ft_printf(const char *ptr, ...)
{
	va_list	ap;
	int		len;
	size_t	i;

	va_start(ap, ptr);
	len = 0;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '%' && ptr[i + 1])
		{
			i++;
			while (ptr[i] == '#' || (ptr[i] >= '0' && ptr[i] <= '9'))
				i++;
			len += ft_format(ap, ptr[i], ptr, i);
		}
		else
			len += ft_putchar(ptr[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

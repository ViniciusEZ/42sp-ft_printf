/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_outs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:53:17 by vfirmino          #+#    #+#             */
/*   Updated: 2025/09/01 15:40:30 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	size_t	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
		i++;
	return (write(1, str, i));
}

int	ft_putnbr(int nb)
{
	char	i;
	int		len;

	len = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		i = ((nb % 10) * -1) + '0';
		len += 1;
	}
	else
		i = (nb % 10) + '0';
	nb = nb / 10;
	if (nb < 0)
		nb = nb * -1;
	if (nb != 0)
		len += ft_putnbr(nb);
	write(1, &i, 1);
	return (len);
}

int	ft_puthex(unsigned long nb, char *base, const char *str, size_t i)
{
	int	len;

	len = 0;
	if (i != 0 && nb != 0 && str[i - 1] == '#' && str[i] == 'x')
		len += ft_putstr("0x");
	if (i != 0 && nb != 0 && str[i - 1] == '#' && str[i] == 'X')
		len += ft_putstr("0X");
	if (nb >= 16)
		len += ft_puthex(nb / 16, base, str, 0);
	len += write(1, &base[nb % 16], 1);
	return (len);
}

int	ft_putptr(void *p, char *base, const char *str, size_t i)
{
	int	len;

	if (!p)
		return (ft_putstr("(nil)"));
	len = ft_putstr("0x");
	len += ft_puthex((unsigned long)p, base, str, i);
	return (len);
}

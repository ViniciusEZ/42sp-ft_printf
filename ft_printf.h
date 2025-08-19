/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfirmino <vfirmino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:50:51 by vfirmino          #+#    #+#             */
/*   Updated: 2025/08/19 00:56:15 by vfirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_puthex(unsigned long nb, char *base, const char *str, size_t i);
int	ft_putptr(void *p, char *base, const char *str, size_t i);
int	ft_putunbr(unsigned int nb);
int	ft_format(va_list ap, char c, const char *str, size_t i);
int	ft_printf(const char *ptr, ...);

#endif
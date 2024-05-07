/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angerard <angerard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:23:31 by angerard          #+#    #+#             */
/*   Updated: 2024/05/07 15:40:38 by angerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	spf_handler(va_list args, const char c)
{
	size_t	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += convert_integer(va_arg(args, int));
	else if (c == 'u')
		count += convert_unsigned_decimal(va_arg(args, unsigned int));
	else if (c == 'x')
		count += convert_hex_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		count += convert_hex_upper(va_arg(args, unsigned int));
	else if (c == 'p')
		count += convert_pointer(va_arg(args, void *));
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	count;
	va_list	args;
	char	*spf_format;

	i = 0;
	count = 0;
	va_start(args, str);
	spf_format = "cspdiuxX%";
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr(spf_format, str[i + 1]))
		{
			count += spf_handler(args, str[i + 1]);
			i++;
		}
		else
		{
			count += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
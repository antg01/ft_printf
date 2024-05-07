/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angerard <angerard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:47:00 by angerard          #+#    #+#             */
/*   Updated: 2024/05/07 15:36:11 by angerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_pos_num(unsigned long num)
{
	char	num_buffer[12];
	int		i;
	int		count;

	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	i = 0;
	while (num != 0)
	{
		num_buffer[i++] = num % 10 + '0';
		num = num / 10;
	}
	count = 0;
	while (i > 0)
	{
		i = i - 1;
		ft_putchar(num_buffer[i]);
		count = count + 1;
	}
	return (count);
}

int	print_number(long num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
		count = 1;
	}
	count += print_pos_num(num);
	return (count);
}

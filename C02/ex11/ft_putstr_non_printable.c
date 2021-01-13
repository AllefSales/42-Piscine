/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asales-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:42:22 by asales-f          #+#    #+#             */
/*   Updated: 2021/01/12 21:07:19 by asales-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	convert(int num)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[num / 16], 1);
	write(1, &hex[num % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 0 && str[i] <= 31)
		{
			write(1, "\\", 1);
			convert(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:07 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/15 14:22:24 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	ft_specifics(const char *str, int i, va_list args)
{
	void	*temp;
	char	c;	

	if (str[i] == '%' && str[i + 1] == 'c')
	{
		c = (char)(va_arg(args, int));
		write(1, &c, 1);
	}
	else if (str[i] == '%' && str[i + 1] == 's')
	{
		temp = (char *)va_arg(args, char *);
		ft_putstr(temp);
	}
	else if (str[i] == '%' && str[i + 1] == 'p')
	{
		ft_putstr("0x10");
		ft_putstr(ft_convert_base((unsigned int)va_arg(args, void *)));
	}
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	unsigned int	i;
	va_list			args;

	i = -1;
	va_start(args, str);
	while (str[++i] != '\0')
	{
		if (!ft_specifics(str, i, args))
			ft_putchar(str[i]);
		else
			i++;
	}
	va_end(args);
	return (1);
}


int	main(void)
{
	char	x = 'i';
	char	*y = "Hello World !";
	void	*z = "t";
	ft_printf("Bonjour %c J'aime ca\n Hallo%stop %p", x, y, z);
	write(1, "\n", 1);
	printf("Bonjour %c J'aime ca\n Hallo%stop %p", x, y, z);
}

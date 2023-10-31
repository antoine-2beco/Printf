/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:07 by ade-beco          #+#    #+#             */
/*   Updated: 2023/10/31 16:26:19 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	unsigned int	i;

	i = 0;

	while (str[i] != '\0')
	{
		if (ft_isprint(str[i]))
			ft_putchar(str[i]);
	}
	return (1);
}

/*int	main()
{
	ft_printf("gfshghfdg4564");
}*/
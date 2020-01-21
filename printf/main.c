/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekindomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:44:35 by ekindomb          #+#    #+#             */
/*   Updated: 2020/01/21 11:55:15 by ekindomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	printf("%s\n", "toto");
	ft_printf("%s\n", "toto");
	printf("Magic %s is %5d\n", "number", 42);
	ft_printf("Magic %s is %5d\n", "number", 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%5.5s\n", "toto");
	ft_printf("%5.5s\n", "toto");
	printf("Magic %s is [%.0d]\n", "number", 0);
	ft_printf("Magic %s is [%.0d]\n", "number", 0);
	printf("Hexadecimal for %.0d is %x\n", 42, 42);
	ft_printf("Hexadecimal for %.0d is %x\n", 42, 42);
	printf("ret [%d]\n", printf("%5d\n", 8));
	printf("ret [%d]\n", ft_printf("%5d\n", 8));
	printf("ret [%d]\n", printf("%.5d\n", 8));
	printf("ret [%d]\n", ft_printf("%.5d\n", 8));
	printf("ret [%d]\n", printf("%.d\n", 8));
	printf("ret [%d]\n", ft_printf("%.d\n", 8));
	printf("ret [%d]\n", printf("%5d\n", 0));
	printf("ret [%d]\n", ft_printf("%5d\n", 0));
	printf("ret [%d]\n", printf("[%.0d]\n", 0));
	printf("ret [%d]\n", ft_printf("[%.0d]\n", 0));
	printf("ret [%d]\n", printf("%.8d\n", 0));
	printf("ret [%d]\n", ft_printf("%.8d\n", 0));
	printf("ret [%d]\n", printf("%18d\n", 8));
	printf("ret [%d]\n", ft_printf("%18d\n", 8));
	printf("ret [%d]\n", printf("%18d\n", -8));
	printf("ret [%d]\n", ft_printf("%18d\n", -8));
	printf("ret [%d]\n", printf("%.5d\n", -8));
	printf("ret [%d]\n", ft_printf("%.5d\n", -8));
	printf("ret [%d]\n", printf("%.d\n", -8));
	printf("ret [%d]\n", ft_printf("%.d\n", -8));
	printf("ret [%d]\n", printf("%.d\n", 8));
	printf("ret [%d]\n", ft_printf("%.d\n", 8));
	printf("ret [%d]\n", printf("%5x\n", 15));
	printf("ret [%d]\n", ft_printf("%5x\n", 15));
	printf("ret [%d]\n", printf("%5x\n", -15));
	printf("ret [%d]\n", ft_printf("%5x\n", -15));
	printf("ret [%d]\n", printf("%.5x\n", 15));
	printf("ret [%d]\n", ft_printf("%.5x\n", 15));
	printf("ret [%d]\n", printf("%.x\n", 15));
	printf("ret [%d]\n", ft_printf("%.x\n", 15));
	printf("ret [%d]\n", printf("%s\n", "bonjour"));
	printf("ret [%d]\n", ft_printf("%s\n", "bonjour"));
	printf("ret [%d]\n", printf("%.5s\n", "bonjour"));
	printf("ret [%d]\n", ft_printf("%.5s\n", "bonjour"));
	printf("ret [%d]\n", printf("%5s\n", "bonjour"));
	printf("ret [%d]\n", ft_printf("%5s\n", "bonjour"));
	printf("ret [%d]\n", printf("%s\n", ""));
	printf("ret [%d]\n", ft_printf("%s\n", ""));
	printf("ret [%d]\n", printf("%s\n", NULL));
	printf("ret [%d]\n", ft_printf("%s\n", NULL));
	system ("leaks ft_printf");
	return (0);
}

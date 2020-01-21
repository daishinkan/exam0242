/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekindomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:53:02 by ekindomb          #+#    #+#             */
/*   Updated: 2020/01/21 11:53:21 by ekindomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 ** Remplir la stream de sortie soit par "-" ou " " ou "0"
 */
void	filler(char c, int num, int *char_written)
{
	int i = 0;
	while (i < num)
	{
		write(1, &c, 1);
		(*char_written)++; // compte le nombre de caractere ecrit en output
		i++;
	}
}

/*
 ** affiche la string a une taille donnee lim
 */
void	put_str_lim(const char *str, int lim, int *char_written)
{
	write(1, str, lim);
	(*char_written) += lim;
}

/*
 ** test si le caractere rencontre est dans la chaine 
 */
int		is_from_str(char c, const char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_atoi(const char *str, int *i)
{
	int res = 0;
	while (is_from_str(str[*i], "0123456789"))
	{
		res = res * 10 + (str[*i] - '0');
		(*i)++;
	}
	(*i)--;
	return (res);
}

int		ft_strlen(const char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return(i);
}

int		num_char_count(long long int num, long long int base)
{
	int i = 1;
	while (num >= base)
	{
		num /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa(long long int num, long long int base, int padding)
{
	char *str;
	char *base_str = "0123456789abcdef";
	if (num < 0)
		num = -num;
	int i = num_char_count(num, base);
	if (num == 0 && padding == 0)
	{
		if(!(str = (char *)malloc(sizeof(char) * 1 + 1)))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (padding > i)
		i = padding;
	if(!(str = (char *)malloc(sizeof(char) * (i + 1) + 1)))
		return (NULL);
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = base_str[num % base];
		num /= base;
		i--;
	}
	return (str);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int char_written = 0;
	int padding = -1;
	int field = 0;
	int fill = ' ';
	int i = 0;
	int d;
	unsigned int x;
	char *str;
	char *nullstr = "(null)";
	int size;

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			padding = -1;
			field = 0;
			fill = ' ';
			while (format[i])
			{
				if (format[i] == '0')
					fill = '0';
				else if (is_from_str(format[i], "123456789"))
					field = ft_atoi(format, &i);
				else if (format[i] == '.')
				{
					fill = ' ';
					i++;
					padding = ft_atoi(format, &i);
				}
				else
					break;
				i++;
			}
			if (format[i] == 's')
			{
				str = va_arg(ap, char *);
				if (!str)
					str = nullstr;
				size = ft_strlen(str);
				if (padding == -1)
				{
					filler(fill, field - size, &char_written);
					put_str_lim(str, size, &char_written);
				}
				else if (padding < size)
				{
					filler(fill, field - padding, &char_written);
					put_str_lim(str, padding, &char_written);
				}
				else 	
				{
					filler(fill, field - size, &char_written);
					put_str_lim(str, size, &char_written);
				}
			}
			else if (format[i] == 'd')
			{
				d = va_arg(ap, int);
				str = ft_itoa(d, 10, padding);
				if (!str)
				{
					va_end(ap);
					return (-1);
				}
				size = ft_strlen(str);
				if (d < 0)
				{
					size++;
					filler(fill, field - size, &char_written);
					filler('-', 1, &char_written);
					put_str_lim(str, ft_strlen(str), &char_written);
				}
				else
				{
					filler(fill, field - size, &char_written);
					put_str_lim(str, ft_strlen(str), &char_written);
				}
				free(str);
			}
			else if (format[i] == 'x')
			{
				x = va_arg(ap, unsigned int);
				str = ft_itoa(x, 16, padding);
				if (!str)
				{
					va_end(ap);
					return (-1);
				}
				size = ft_strlen(str);
				if (x < 0)
				{
					size++;
					filler(fill, field - size, &char_written);
					filler('-', 1, &char_written);
					put_str_lim(str, ft_strlen(str), &char_written);
				}
				else
				{
					filler(fill, field - size, &char_written);
					put_str_lim(str, ft_strlen(str), &char_written);
				}
				free(str);
			}
		}
		else
			filler(format[i], 1, &char_written);
		i++;
	}
	va_end(ap);
	return (char_written);
}

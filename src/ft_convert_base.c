/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:47:14 by klakbuic          #+#    #+#             */
/*   Updated: 2024/01/02 08:44:41 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

int	is_nbr(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_not_valide_base(char *base)
{
	int	i;
	int	j;
	int	base_lenght;

	i = 0;
	base_lenght = ft_strlen(base);
	while (i < base_lenght)
	{
		if (base[i] == '\n' || base[i] == '\t' || base[i] == '\v'
			|| base[i] == '\r' || base[i] == '\f' || base[i] == ' '
			|| base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (i <= (base_lenght - 1) && base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	get_index(char nb, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == nb)
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int				i;
	int				signe;
	unsigned int	nbr;
	unsigned int	base_fact;
	int				len_base;

	i = 0;
	signe = 1;
	nbr = 0;
	len_base = ft_strlen(base);
	base_fact = -1;
	if (len_base <= 1 || is_not_valide_base(base))
		return (0);
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	while ((str[i] == '+' || str[i] == '-'))
		if (str[i++] == '-')
			signe *= -1;
	while (is_nbr(str[i], base))
	{
		nbr = (nbr * len_base) + (get_index(str[i], base));
		i++;
	}
	return ((int)nbr * signe);
}

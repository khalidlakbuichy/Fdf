/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:49:08 by klakbuic          #+#    #+#             */
/*   Updated: 2024/01/02 08:57:04 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_valide_base(char *base)
{
	int	i;
	int	j;
	int	base_lenght;

	i = 0;
	base_lenght = ft_strlen(base);
	while (i < (base_lenght - 1))
	{
		j = i + 1;
		if (base[i] == '\n' || base[i] == '\t' || base[i] == '\v'
			|| base[i] == '\r' || base[i] == '\f' || base[i] == ' ')
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			else
				j++;
		}
		i++;
	}
	if (base[i] == '\n' || base[i] == '\t' || base[i] == '\v' || base[i] == '\r'
		|| base[i] == '\f' || base[i] == ' ')
		return (0);
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

unsigned int	ft_atoi_base(char *str, char *base)
{
	int i;
	int signe;
	unsigned int nbr;
	unsigned int base_fact;
	int len_base;

	i = 0;
	signe = 1;
	nbr = 0;
	len_base = ft_strlen(base);
	base_fact = -1;
	if (len_base <= 1 || is_valide_base(base))
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
	return (nbr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:52:05 by klakbuic          #+#    #+#             */
/*   Updated: 2024/01/02 08:46:00 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_strlen(char *str);
int	is_not_valide_base(char *base);
int	ft_atoi_base(char *str, char *base);

char	*allocate_memo(int nbr, int base_to)
{
	int		size;
	char	*nbre;

	if (nbr < 0)
		size = 2;
	size = 1;
	while ((nbr / base_to) != 0)
	{
		nbr /= base_to;
		size++;
	}
	nbre = (char *)malloc((size + 1) * sizeof(char));
	return (nbre);
}

void	convert_base_helper(unsigned int nbr, char *base_to, char *result,
		int *index)
{
	unsigned int	nb;
	int				base;

	base = ft_strlen(base_to);
	if (nbr / base == 0)
	{
		nb = (nbr % base);
		result[(*index)++] = base_to[nb];
	}
	else
	{
		convert_base_helper((nbr / base), base_to, result, index);
		nb = (nbr % base);
		result[(*index)++] = base_to[nb];
	}
}

void	convert_base(int nbr, char *base_to, char *result)
{
	int				index;
	int				base_to_lentgh;
	unsigned int	nbre;

	base_to_lentgh = ft_strlen(base_to);
	index = 0;
	if (nbr < 0)
	{
		nbre = (unsigned int)(nbr * -1);
		result[index] = '-';
		index++;
	}
	else
		nbre = (unsigned int)nbr;
	convert_base_helper(nbre, base_to, result, &index);
	result[index] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		nb_dec;

	if (ft_strlen(base_to) <= 1 || is_not_valide_base(base_to)
		|| ft_strlen(base_from) <= 1 || is_not_valide_base(base_from))
		return (NULL);
	nb_dec = ft_atoi_base(nbr, base_from);
	result = allocate_memo(nb_dec, ft_strlen(base_to));
	convert_base(nb_dec, base_to, result);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:48:00 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/02 21:15:32 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_ver_str(char	*str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (ft_putstr_fd("Error\nInvalid Number detected", 2), 1);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i])
		return (ft_putstr_fd("Error\nInvalid Number detected", 2), 1);
	return (0);
}

int	ft_iterate_split(t_data *data, char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		if (ft_ver_str(split[i]))
			return (1);
		if (ft_lista_add_back(&data->head_a, &data->tail_a, ft_atol(split[i])))
			return (1);
		i++;
	}
	return (0);
}

t_data	*ft_new_data(int ac, char **av)
{
	t_data	*data;
	char	**split;
	int		i;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	i = 0;
	while (++i < ac)
	{
		split = ft_split_multi(av[i], " \t");
		if (!split)
			return (ft_free_data(data), NULL);
		if (ft_iterate_split(data, split))
			return (ft_free_split(split), ft_free_data(data), NULL);
		ft_free_split(split);
	}
	return (data);
}

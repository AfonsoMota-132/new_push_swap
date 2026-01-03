/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:32:32 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/03 11:59:55 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac < 2)
		return (ft_putstr_fd("Error!\nNot Enough Arguments", 2), 1);
	else
	{
		data = ft_new_data(ac, av);
		if (!data)
			return (1);
		ft_stack_index(data->head_a);
		data->size = ft_stack_size(data->head_a);
		ft_sort(data);
		if (data)
			ft_free_data(data);
	}
	return (0);
}

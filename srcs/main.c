/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:32:32 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/02 21:15:42 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_lista	*prev;
	t_lista	*curr;
	t_lista	*next;

	if (ac < 2)
		return (ft_putstr_fd("Error!\nNot Enough Arguments", 2), 1);
	else
	{
		data = ft_new_data(ac, av);
		if (!data)
			return (1);
		prev = NULL;
		curr = data->head_a;
		while (curr)
		{
			printf("%i\n", curr->nbr);
			next = ft_xor(prev, curr->both);
			prev = curr;
			curr = next;
		}
		printf("\n");
		curr = data->tail_a;
		next = NULL;
		while (curr)
		{
			printf("%i\n", curr->nbr);
			prev = ft_xor(next, curr->both);
			next = curr;
			curr = prev;
		}
		ft_free_data(data);
	}
	return (0);
}

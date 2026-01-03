/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:40:11 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/03 18:40:15 by afogonca         ###   ########.fr       */
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

int	ft_abs(int cost)
{
	if (cost >= 0)
		return (cost);
	else
		return (cost * -1);
}

bool	ft_comp_swap(t_stack *head)
{
	t_stack	*first;
	t_stack	*second;

	first = head;
	if (!head)
		return (false);
	second = first->both;
	return (first->id < second->id);
}

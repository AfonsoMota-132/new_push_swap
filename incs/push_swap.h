/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:25:52 by afogonca          #+#    #+#             */
/*   Updated: 2026/01/03 12:04:16 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int					nbr;
	int					id;
	struct s_stack		*both;
}	t_stack;

typedef struct s_data
{
	t_stack	*head_a;
	t_stack	*tail_a;
	t_stack	*head_b;
	t_stack	*tail_b;
	size_t	size;
}	t_data;

//	Ft_data

int		ft_iterate_split(t_data *data, char **split);
t_data	*ft_new_data(int ac, char **av);
void	ft_free_data(t_data	*data);

//	Ft_index

t_stack	*ft_index_min(t_stack *curr);
void	ft_stack_index(t_stack *head);


//	Ft_utils.c

int		ft_abs(int cost);
bool	ft_comp_swap(t_stack *head);
int		ft_ver_str(char	*str);
t_stack	*ft_find_max(t_stack *head);

#endif

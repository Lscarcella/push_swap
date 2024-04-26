/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:10:20 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/26 11:51:20 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	init_stack(t_element **stack_a, int argc, char **argv, int stack_len)
{
	if (argc == 2)
		store_string_arg(argv, stack_a);
	else
		store_tab_arg(argv, stack_a);
	stack_len = get_stack_len(stack_a);
	if (is_sorted(stack_a, stack_len))
		exit (EXIT_SUCCESS);
	if (check_for_duplicates(stack_a))
	{
		write (2, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	return (stack_len);
}

void	store_string_arg(char **argv, t_element **stack_a)
{
	char		**tab;
	int			i;
	t_element	*temp;

	temp = NULL;
	i = 0;
	tab = ft_split(argv[1], ' ');
	is_int(tab, i);
	create_stack(stack_a, temp, tab, i);
	free_tab(tab);
}

void	store_tab_arg(char **argv, t_element **stack_a)
{
	int			i;
	t_element	*temp;

	temp = NULL;
	i = 1;
	is_int(argv, i);
	create_stack(stack_a, temp, argv, i);
}

void	simplify_value(t_element **stack_a, int stack_len)
{
	int			value;
	t_element	*i;
	t_element	*j;
	int			count;

	count = 0;
	i = *stack_a;
	j = i->next;
	value = 0;
	while (count < stack_len)
	{
		while (j != i)
		{
			if (j->value < i->value)
				value++;
			j = j->next;
		}
		i->simplified_value = value;
		value = 0;
		i = i->next;
		j = i->next;
		count++;
	}
}

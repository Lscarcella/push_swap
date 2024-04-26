/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:46:44 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/26 11:58:45 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_element	*stack_a;
	int			stack_len;

	stack_len = 0;
	stack_a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else
		stack_len = init_stack(&stack_a, argc, argv, stack_len);
	simplify_value(&stack_a, stack_len);
	if (stack_len <= 5)
		little_sort(stack_a, stack_len);
	else if (stack_len > 5)
		radix_sort(&stack_a, stack_len);
}

void	free_stack(t_element **stack_a, int stack_len)
{
	t_element	*current;
	t_element	*next;
	int			i;

	i = 0;
	current = *stack_a;
	next = NULL;
	while (i < stack_len)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
	stack_a = NULL;
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

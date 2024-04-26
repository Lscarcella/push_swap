/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:10:20 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/26 12:07:52 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	is_int(char **argv, int i)
{
	int	j;

	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
			{
				if (ft_strlen(argv[i]) == 1 || !ft_isdigit(argv[i][j + 1]))
				{
					write(2, "Error\n", 6);
					exit(EXIT_FAILURE);
				}
			}
			else if (!ft_isdigit(argv[i][j]))
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	create_stack(t_element **stack_a, t_element *temp, char **argv, int i)
{
	t_element	*node;

	while (argv[i])
	{
		node = (t_element *)malloc(sizeof(t_element));
		if (!node)
			exit(EXIT_FAILURE);
		node->value = ft_atol(argv[i]);
		node->simplified_value = 0;
		if (!*stack_a)
		{
			*stack_a = node;
			temp = node;
		}
		else
		{
			temp->next = node;
			node->prev = temp;
			temp = node;
		}
		i++;
	}
	temp->next = *stack_a;
	(*stack_a)->prev = temp;
}

int	is_sorted(t_element **stack_a, int stack_len)
{
	t_element	*ptr;

	ptr = *stack_a;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (TRUE);
	while (stack_len > 1)
	{
		if (ptr->value > ptr->next->value)
			return (FALSE);
		ptr = ptr->next;
		stack_len--;
	}
	return (TRUE);
}

int	check_for_duplicates(t_element **stack_a)
{
	t_element	*ptr1;
	t_element	*ptr2;

	ptr1 = *stack_a;
	ptr2 = *stack_a;
	while (ptr1 != (*stack_a)->prev)
	{
		while (ptr2 != (*stack_a)->prev)
		{
			ptr2 = ptr2->next;
			if (ptr2->value == ptr1->value)
				return (TRUE);
		}
		ptr1 = ptr1->next;
		ptr2 = ptr1;
	}
	return (FALSE);
}

int	get_stack_len(t_element **stack_a)
{
	t_element	*ptr;
	int			count;

	count = 1;
	ptr = (*stack_a)->next;
	while (ptr != (*stack_a))
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

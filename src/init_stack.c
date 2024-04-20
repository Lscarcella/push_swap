/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lozkuro <lozkuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:10:20 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/20 08:48:13 by lozkuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	init_stack(t_element **stack_a, int argc, char **argv, int stack_len)
{	
	if(argc == 2)
		store_string_arg(argv, stack_a);
	else
		store_tab_arg(argv, stack_a);
	
	stack_len = get_stack_len(stack_a);
	if (is_sorted(stack_a, stack_len))
		exit(EXIT_SUCCESS);
	if (check_for_duplicates(stack_a))
	{
		write(2, "Error\n", 6);	
		exit(EXIT_FAILURE);
	}
	return(stack_len);
}

void    store_string_arg(char **argv, t_element **stack_a)
{
    char **tab;
	int i;
	t_element *temp;

	temp = NULL;
	i = 0;
    tab = ft_split(argv[1], ' ');
	is_int(tab, i);
    create_stack(stack_a, temp, tab, i);
}

void    store_tab_arg(char **argv, t_element **stack_a)
{
	int i;
	t_element *temp;

	temp = NULL;
	i = 1;
	is_int(argv, i);
    create_stack(stack_a, temp, argv, i);
}
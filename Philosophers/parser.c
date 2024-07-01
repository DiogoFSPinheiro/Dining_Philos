/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:57:00 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/28 01:09:54 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_error_syntax(char *nbr);

int	ft_data_parsing(t_data *data, char **args)
{
	int	c;

	c = 1;
	while (args[c])
	{
		if (ft_error_syntax(args[c]) || ft_atol(args[c]) > INT_MAX)
			ft_error_exit("Input is above INT_MAX!");
		c++;
	}
	data->nbr_of_philos = ft_atol(args[1]);
	data->time_to_die = ft_atol(args[2]) * 1e3;
	data->time_to_eat = ft_atol(args[3]) * 1e3;
	data->time_to_sleep = ft_atol(args[4]) * 1e3;
	if (!args[5])
		data->nbr_of_meals = -1;
	else
		data->nbr_of_meals = ft_atol(args[5]);
	return (SUCCESS);
}

static int	ft_error_syntax(char *nbr)
{
	while (*nbr >= 9 && *nbr <= 13)
	{
		nbr++;
	}
	if (*nbr == '-')
		ft_error_exit("Negative Numbers Not Permited!");
	if (*nbr == '+' && !(nbr[1] >= '0' && nbr[1] <= '9'))
		ft_error_exit("Input must be a Number!");
	if (*nbr == '+')
		nbr++;
	while (*nbr != '\0')
	{
		if (!(*nbr >= '0' && *nbr <= '9'))
			ft_error_exit("Input must be a Number!");
		nbr++;
	}
	return (SUCCESS);
}

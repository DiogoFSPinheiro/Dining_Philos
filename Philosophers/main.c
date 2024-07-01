/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:25:30 by diogosan          #+#    #+#             */
/*   Updated: 2024/07/01 12:50:43 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int c, char *v[])
{
	t_data	data;

	if (c == 5 || c == 6)
	{
		ft_data_parsing(&data, v);
		ft_data_init(&data);
		ft_meal_start(&data);
		ft_cleanup(&data);
	}
	else
		ft_error_exit("Please put the correct input");
	return (0);
}

void	ft_print_data(t_data *data)
{
	t_philo	*philo;
	int		c;

	c = 0;
	printf("%ld\n", data->nbr_of_philos);
	printf("%ld\n", data->time_to_die);
	printf("%ld\n", data->time_to_eat);
	printf("%ld\n", data->time_to_sleep);
	printf("%ld\n", data->nbr_of_meals);
	printf("\n");
	while (data->nbr_of_philos > c)
	{
		philo = data->philos + c;
		printf("philo->id %d\n", philo->id);
		printf("philo->full %d\n", philo->full);
		printf("philo->meals_eaten %d\n\n", philo->meals_eaten);
		c++;
	}
}

void	ft_cleanup(t_data *data)
{
	t_philo	*philo;
	int		c;

	c = 0;
	while (data->nbr_of_philos > c)
	{
		philo = data->philos + c;
		ft_safe_mutex(&philo->philo_mutex, DESTROY);
		c++;
	}
	ft_safe_mutex(&data->table_mutex, DESTROY);
	ft_safe_mutex(&data->log_mutex, DESTROY);
	free(data->forks);
	free(data->philos);
}

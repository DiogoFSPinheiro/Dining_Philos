/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:58:43 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/28 02:28:21 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//
// if the philo nbr is even:
//						takes the right fork first 
//						and then the left last 
// if the philo nbr is odd:
//						takes the left fork first 
//						and then the right second
//
static void	ft_get_forks(t_philo *philo, t_fork *forks, int c)
{
	int	philo_nbr;

	philo_nbr = philo->data->nbr_of_philos;
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[c];
		philo->second_fork = &forks[(c + 1) % philo_nbr];
	}
	else
	{
		philo->first_fork = &forks[(c + 1) % philo_nbr];
		philo->second_fork = &forks[c];
	}
}

// Init all philos
// id	
// full	
// meals_eaten	
// pos_in_table
// Give forks

static void	ft_init_philos(t_data *data)
{
	int		c;
	t_philo	*philo;

	c = 0;
	while (c < data->nbr_of_philos)
	{
		philo = data->philos + c;
		philo->id = c + 1;
		philo->full = false;
		philo->meals_eaten = 0;
		philo->data = data;
		ft_safe_mutex(&philo->philo_mutex, INIT);
		ft_get_forks(philo, data->forks, c);
		c++;
	}
}

// Philos and forks allocation
// Give forks IDs
void	ft_data_init(t_data *data)
{
	int	c;

	c = 0;
	data->end_sim = false;
	data->all_threads_ready = false;
	data->threads_running_nbr = 0;
	data->philos = ft_safe_malloc(sizeof(t_philo) * data->nbr_of_philos);
	ft_safe_mutex(&data->table_mutex, INIT);
	ft_safe_mutex(&data->log_mutex, INIT);
	data->forks = ft_safe_malloc(sizeof(t_fork) * data->nbr_of_philos);
	while (c < data->nbr_of_philos)
	{
		ft_safe_mutex(&data->forks[c].fork, INIT);
		data->forks[c].id = c;
		c++;
	}
	ft_init_philos(data);
}

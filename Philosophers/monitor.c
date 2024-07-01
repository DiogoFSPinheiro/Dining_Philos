/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:13:34 by diogosan          #+#    #+#             */
/*   Updated: 2024/07/01 15:11:26 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	ft_philo_died(t_philo *philo)
{
	long	elapsed;
	long	time_to_die;

	if (ft_get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	elapsed = ft_gettime(MILISECOND) - ft_get_long(&philo->philo_mutex,
			&philo->last_meal);
	time_to_die = philo->data->time_to_die / 1e3;
	if (elapsed > time_to_die)
		return (true);
	return (false);
}

void	*monitor_philo(void *arg)
{
	int		c;
	t_data	*data;

	c = 0;
	data = (t_data *)arg;
	while (!ft_all_thread_runnning(&data->table_mutex,
			&data->threads_running_nbr, data->nbr_of_philos))
		usleep(500);
	while (!ft_sim_finished(data))
	{
		while (data->nbr_of_philos > c && !ft_sim_finished(data))
		{
			if (ft_philo_died(data->philos + c))
			{
				ft_set_bool(&data->table_mutex, &data->end_sim, true);
				ft_log_status(data->philos + c, DIED);
				c++;
			}
		}
	}
	return (NULL);
}

/*
* One philo will have only one fork so, he dies
*/
void	*ft_solo_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_wait_threads(philo->data);
	ft_set_long(&philo->philo_mutex, &philo->last_meal, ft_gettime(MILISECOND));
	ft_increase_long(&philo->philo_mutex, &philo->data->threads_running_nbr);
	ft_log_status(philo, TAKE_FORK);
	while (!ft_sim_finished(philo->data))
		usleep(200);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:31:07 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/28 02:29:05 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo, bool pre_start)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (!pre_start)
		ft_log_status(philo, THINKING);
	if (philo->data->nbr_of_philos % 2 == 0)
		return ;
	t_eat = philo->data->time_to_eat;
	t_sleep = philo->data->time_to_sleep;
	t_think = t_eat * 2 - t_sleep;
	if (t_think < 0)
		t_think = 0;
	ft_usleep(t_think * 0.42, philo->data);
}

static void	ft_eat(t_philo *philo)
{
	ft_safe_mutex(&philo->first_fork->fork, LOCK);
	ft_log_status(philo, TAKE_FORK);
	ft_safe_mutex(&philo->second_fork->fork, LOCK);
	ft_log_status(philo, TAKE_FORK);
	ft_set_long(&philo->philo_mutex, &philo->last_meal, ft_gettime(MILISECOND));
	philo->meals_eaten++;
	ft_log_status(philo, EATING);
	ft_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->nbr_of_meals > 0
		&& philo->meals_eaten == philo->data->nbr_of_meals)
		ft_set_bool(&philo->philo_mutex, &philo->full, true);
	ft_safe_mutex(&philo->first_fork->fork, UNLOCK);
	ft_safe_mutex(&philo->second_fork->fork, UNLOCK);
}

/*
*	philo = (t_philo *)arg the casting 
*		is needed to access the philo data
*/
void	*ft_meal_simulation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_wait_threads(philo->data);
	ft_set_long(&philo->philo_mutex, &philo->last_meal, ft_gettime(MILISECOND));
	ft_increase_long(&philo->data->table_mutex,
		&philo->data->threads_running_nbr);
	ft_desinc_philo(philo);
	while (!ft_sim_finished(philo->data))
	{
		if (philo->full)
			break ;
		ft_eat(philo);
		ft_log_status(philo, SLEEPING);
		ft_usleep(philo->data->time_to_sleep, philo->data);
		ft_think(philo, false);
	}
	return (NULL);
}

void	ft_meal_start(t_data *data)
{
	int	c;

	c = -1;
	if (data->nbr_of_meals == 0)
		return ;
	else if (data->nbr_of_philos == 1)
		ft_safe_phread(&data->philos[0].thread_id,
			ft_solo_philo, &data->philos[0], CREATE);
	else
	{
		while (++c < data->nbr_of_philos)
			ft_safe_phread(&data->philos[c].thread_id, ft_meal_simulation,
				&data->philos[c], CREATE);
	}
	ft_safe_phread(&data->monitor_thread, monitor_philo, data, CREATE);
	data->start_sim = ft_gettime(MILISECOND);
	ft_set_bool(&data->table_mutex, &data->all_threads_ready, true);
	c = -1;
	while (++c < data->nbr_of_philos)
		ft_safe_phread(&data->philos[c].thread_id, NULL, NULL, JOIN);
	ft_set_bool(&data->table_mutex, &data->end_sim, true);
	ft_safe_phread(&data->monitor_thread, NULL, NULL, JOIN);
}

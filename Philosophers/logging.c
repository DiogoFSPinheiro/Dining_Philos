/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:25:24 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/28 02:29:54 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_log_status(t_philo *philo, t_philo_status status)
{
	long	elapsed;

	elapsed = ft_gettime(MILISECOND) - philo->data->start_sim;
	if (philo->full)
		return ;
	ft_safe_mutex(&philo->data->log_mutex, LOCK);
	if (status == TAKE_FORK && !ft_sim_finished(philo->data))
		printf("%-6ld  %d has taken a fork\n", elapsed, philo->id);
	else if (status == EATING && !ft_sim_finished(philo->data))
		printf("%-6ld  %d is eating\n", elapsed, philo->id);
	else if (status == SLEEPING && !ft_sim_finished(philo->data))
		printf("%-6ld  %d is sleeping\n", elapsed, philo->id);
	else if (status == THINKING && !ft_sim_finished(philo->data))
		printf("%-6ld  %d is thinking\n", elapsed, philo->id);
	else if (status == DIED)
		printf("%-6ld  %d died\n", elapsed, philo->id);
	ft_safe_mutex(&philo->data->log_mutex, UNLOCK);
}

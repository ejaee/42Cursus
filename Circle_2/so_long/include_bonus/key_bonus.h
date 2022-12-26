/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:50:34 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/26 13:50:38 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_BONUS_H
# define KEY_BONUS_H

# define X_EVENT_KEY_PRESS		2

# define X_EVENT_KEY_EXIT		17

# define KEY_ESC	53
# define KEY_R		15

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_UP		126
# define KEY_LEFT	123
# define KEY_DOWN	125
# define KEY_RIGHT	124

typedef struct s_game	t_game;

typedef struct s_step
{
	int	count;
}	t_step;

#endif

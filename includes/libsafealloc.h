/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsafealloc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:50:24 by chutterm          #+#    #+#             */
/*   Updated: 2026/01/07 20:51:51 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSAFEALLOC_H
# define LIBSAFEALLOC_H

# include <stdlib.h>
# include <unistd.h>

// Configs
# define MAX_TRACKER_CHAINS 1024

void	free_safealloc(void);
void	free_nth_chain(size_t nth_chain);
void	*safealloc(size_t count, size_t size, size_t nth_chain);

#endif
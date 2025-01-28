/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:33:38 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/28 15:55:41 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h"

// half the distance between patrol spawns
# define PATROL_RADIUS 5

// animation loops to show before ending the game
# define ANIMATIONS_AFTER_ENDED 20

// animation speed. Recommended values depending on the machine:
//   |CLUSTER          |VALGRIND|LOOPS_PER_ANIMATION|
//   |bess-f3  paul-f5B|      no|              20000|
//   |bess-f3  paul-f5B|     yes|               2800|
//   |bess-f2  bess-f4 |      no|              60000|
//   |bess-f2  bess-f4 |     yes|               7500|
# define LOOPS_PER_ANIMATION 20000

// indexes and files for bonus images
// They all have the same number of images (3) (see loop_hook function)
# define ANIMATIONS_FIRST_INDEX 5

// wave (walls) on top of the map
# define IMAGE_INDEX_2_0 5
# define SPRITE_FILE_2_0 "textures/wave1.xpm"
# define IMAGE_INDEX_2_1 6
# define SPRITE_FILE_2_1 "textures/wave2.xpm"
# define IMAGE_INDEX_2_2 7
# define SPRITE_FILE_2_2 "textures/wave3.xpm"

// seaweed (walls) to decorate
# define IMAGE_INDEX_3_0 8
# define SPRITE_FILE_3_0 "textures/weed1.xpm"
# define IMAGE_INDEX_3_1 9
# define SPRITE_FILE_3_1 "textures/weed2.xpm"
# define IMAGE_INDEX_3_2 10
# define SPRITE_FILE_3_2 "textures/weed3.xpm"

// seaweed tips (walls) to end columns of seaweed
# define IMAGE_INDEX_4_0 11
# define SPRITE_FILE_4_0 "textures/weed4.xpm"
# define IMAGE_INDEX_4_1 12
# define SPRITE_FILE_4_1 "textures/weed5.xpm"
# define IMAGE_INDEX_4_2 13
# define SPRITE_FILE_4_2 "textures/weed6.xpm"

// dolphin (player)
# define IMAGE_INDEX_P_0 14
# define SPRITE_FILE_P_0 "textures/alive1.xpm"
# define IMAGE_INDEX_P_1 15
# define SPRITE_FILE_P_1 "textures/alive2.xpm"
# define IMAGE_INDEX_P_2 16
# define SPRITE_FILE_P_2 "textures/alive3.xpm"

// fish (collectible)
# define IMAGE_INDEX_C_0 17
# define SPRITE_FILE_C_0 "textures/fish1.xpm"
# define IMAGE_INDEX_C_1 18
# define SPRITE_FILE_C_1 "textures/fish2.xpm"
# define IMAGE_INDEX_C_2 19
# define SPRITE_FILE_C_2 "textures/fish3.xpm"

// group of dolphins (exit)
# define IMAGE_INDEX_E_0 20
# define SPRITE_FILE_E_0 "textures/exit1.xpm"
# define IMAGE_INDEX_E_1 21
# define SPRITE_FILE_E_1 "textures/exit2.xpm"
# define IMAGE_INDEX_E_2 22
# define SPRITE_FILE_E_2 "textures/exit3.xpm"

// eel looking north (patrol)
# define IMAGE_INDEX_6_0 23
# define SPRITE_FILE_6_0 "textures/eel_n1.xpm"
# define IMAGE_INDEX_6_1 24
# define SPRITE_FILE_6_1 "textures/eel_n2.xpm"
# define IMAGE_INDEX_6_2 25
# define SPRITE_FILE_6_2 "textures/eel_n3.xpm"

// eel lookng east (patrol)
# define IMAGE_INDEX_7_0 26
# define SPRITE_FILE_7_0 "textures/eel_e1.xpm"
# define IMAGE_INDEX_7_1 27
# define SPRITE_FILE_7_1 "textures/eel_e2.xpm"
# define IMAGE_INDEX_7_2 28
# define SPRITE_FILE_7_2 "textures/eel_e3.xpm"

// eel looking south (patrol)
# define IMAGE_INDEX_8_0 29
# define SPRITE_FILE_8_0 "textures/eel_s1.xpm"
# define IMAGE_INDEX_8_1 30
# define SPRITE_FILE_8_1 "textures/eel_s2.xpm"
# define IMAGE_INDEX_8_2 31
# define SPRITE_FILE_8_2 "textures/eel_s3.xpm"

// eel looking west (patrol)
# define IMAGE_INDEX_9_0 32
# define SPRITE_FILE_9_0 "textures/eel_w1.xpm"
# define IMAGE_INDEX_9_1 33
# define SPRITE_FILE_9_1 "textures/eel_w2.xpm"
# define IMAGE_INDEX_9_2 34
# define SPRITE_FILE_9_2 "textures/eel_w3.xpm"

// stunned dolphin (player fail)
# define IMAGE_INDEX_D_0 35
# define SPRITE_FILE_D_0 "textures/dead1.xpm"
# define IMAGE_INDEX_D_1 36
# define SPRITE_FILE_D_1 "textures/dead2.xpm"
# define IMAGE_INDEX_D_2 37
# define SPRITE_FILE_D_2 "textures/dead3.xpm"

// flying dolphins (player wins)
# define IMAGE_INDEX_W_0 38
# define SPRITE_FILE_W_0 "textures/win1.xpm"
# define IMAGE_INDEX_W_1 39
# define SPRITE_FILE_W_1 "textures/win2.xpm"
# define IMAGE_INDEX_W_2 40
# define SPRITE_FILE_W_2 "textures/win3.xpm"

# define COUNT_IMAGES 41

void	move_patrols(t_map *map);
void	init_patrols(t_map *map);
void	decorate_map(t_map *map);
void	player_win(t_state *state, int exit_x, int exit_y);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:43:56 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/30 19:18:34 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# define FIRST_TEX 1
# define LAST_TEX 9

# define LAST_WALL 4

# define FIRST_WALK 7
# define LAST_WALK 20

# define FIRST_FREE 10
# define LAST_FREE 16

# define FIRST_SHOP 17
# define LAST_SHOP 19




# define FIRST_SPR 10
# define LAST_SPR 22

# define WALL1 "textures/boi/wall.XPM"
# define WALL2 "textures/boi/shop_floor.XPM"
# define FLOOR1 "textures/boi/floor.XPM"
# define SECRET "textures/boi/wall_secret.XPM"
# define DOOR_C "textures/boi/door_closed.XPM"
# define GDOOR_C "textures/greystone.XPM"
# define DOOR_O "textures/boi/door_open.XPM"
# define GDOOR_O "textures/colorstone.XPM"
# define CDOOR "textures/eagle.XPM"

# define SKYBOX "textures/pixel_sky.XPM"

# define COIN "textures/boi/coin.XPM"
# define RHEART "textures/boi/heart_red.XPM"
# define RHEART_HALF "textures/boi/heart_red_half.XPM"
# define KEY "textures/boi/key.XPM"
# define GOLDEN "textures/boi/key_golden.XPM"

# define MAP "textures/boi/treasure_map.XPM"
# define HEELS "textures/boi/heels.XPM"

# define POLY "textures/boi/polyphemus.XPM"
# define IPECAC "textures/boi/Ipecac.XPM"
# define GODHEAD "textures/boi/godhead.XPM"

# define WEB "textures/boi/cobweb.XPM"

# define ROCK "textures/boi/rock.XPM"
# define SHOPKEEPER "textures/boi/shopkeeper.XPM"


//**start textures**

//solid walls
# define ID_WALL1 1
# define ID_WALL2 2
# define ID_FLOOR1 3

//not solid walls
# define ID_SECRET 4

//solid doors
# define ID_DOOR_C 5
# define ID_GDOOR_C 6

//not solid doors
# define ID_DOOR_O 7
# define ID_GDOOR_O 8
# define ID_CDOOR 9

//**end textures**

//**start sprites**

//*start not solid sprites*

//free pickables
# define ID_COIN 10
# define ID_RHEART 11
# define ID_RHEART_HALF 12
# define ID_KEY 13
# define ID_GOLDEN 14

//free items
# define ID_MAP 15
# define ID_HEELS 16

//shop items
# define ID_POLY 17
# define ID_IPECAC 18
# define ID_GODHEAD 19

//esthetic spr
# define ID_WEB 20

//*end not solid sprites*

//*start solid sprites*

//esthetic spr
# define ID_ROCK 21
//interact spr
# define ID_SHOPKEEPER 22

//*end solid sprites*

//**end sprites**








#endif

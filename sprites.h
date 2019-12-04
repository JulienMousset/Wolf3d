/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:43:56 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/04 19:54:58 by pasosa-s         ###   ########.fr       */
/*   Updated: 2019/12/04 16:23:49 by jmousset         ###   ########.fr       */
/*   Updated: 2019/12/02 18:34:03 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# define FIRST_TEX 1
# define LAST_TEX 9

# define LAST_WALL 4

# define FIRST_WALK 7
# define LAST_WALK 20

# define FIRST_FREE 12
# define LAST_FREE 16

# define FIRST_SHOP 17
# define LAST_SHOP 19

# define FIRST_SPR 10
# define LAST_SPR 29

# define SKYBOX "textures/skybox_pixel.XPM"

# define SHIFT_OFF "textures/typo_shift_off.XPM"
# define SHIFT_ON "textures/typo_shift_on.XPM"
# define PRICE_TAG_15 "textures/typo_price_tag_15.XPM"
# define PRICE_TAG_5 "textures/typo_price_tag_5.XPM"

# define DOOR_CLOSED "textures/texture_door_closed.XPM"
# define DOOR_CURSE "textures/texture_door_curse.XPM"
# define DOOR_GOLDEN_CLOSED "textures/texture_door_golden_closed.XPM"
# define DOOR_GOLDEN_OPEN "textures/texture_door_golden_open.XPM"
# define DOOR_HEART "textures/texture_door_heart.XPM"
# define DOOR_OPEN "textures/texture_door_open.XPM"
# define FLOOR "textures/texture_floor.XPM"
# define FLOOR2 "textures/texture_floor2.XPM"
# define FLOOR3 "textures/texture_floor3.XPM"
# define FLOOR_SHOP "textures/texture_floor_shop.XPM"
# define WALL1 "textures/texture_wall.XPM"
# define WALL2 "textures/texture_wall2.XPM"
# define WALL3 "textures/texture_wall3.XPM"
# define WALL1_SECRET "textures/texture_wall_secret.XPM"
# define WALL2_SECRET "textures/texture_wall2_secret.XPM"
# define WALL3_SECRET "textures/texture_wall3_secret.XPM"
# define WALL_SHOP "textures/texture_wall_shop.XPM"

# define CONTAINER_HEART_EMPTY "textures/container_heart_empty.XPM"
# define CONTAINER_HEART_RED "textures/container_heart_red.XPM"
# define CONTAINER_HEART_RED_HALF "textures/container_heart_red_half.XPM"
# define CONTAINER_HEART_SOUL "textures/container_heart_soul.XPM"
# define CONTAINER_HEART_SOUL_HALF "textures/container_heart_soul_half.XPM"

# define COIN "textures/pickup_coin.XPM"
# define HEART_RED "textures/pickup_heart_red.XPM"
# define HEART_RED_DOUBLE "textures/pickup_heart_red_double.XPM"
# define HEART_RED_HALF "textures/pickup_heart_red_half.XPM"
# define HEART_SOUL "textures/pickup_heart_soul.XPM"
# define HEART_SOUL_HALF "textures/pickup_heart_soul_half.XPM"
# define KEY "textures/pickup_key.XPM"

# define GODHEAD "textures/item_godhead.XPM"
# define GODHEAD_PRICE_TAG "textures/item_godhead_price_tag.XPM"
# define HEELS "textures/item_heels.XPM"
# define IPECAC "textures/item_ipecac.XPM"
# define IPECAC_PRICE_TAG "textures/item_ipecac_price_tag.XPM"
# define POLY "textures/item_polyphemus.XPM"
# define POLYPHEMUS_PRICE_TAG "textures/item_polyphemus_price_tag.XPM"
# define MAP "textures/item_treasure_map.XPM"

# define BEGGAR "textures/npc_beggar.XPM"
# define BEGGAR_DEVIL "textures/npc_beggar_devil.XPM"
# define BEGGAR_KEY "textures/npc_beggar_key.XPM"
# define ERROR "textures/npc_error.XPM"
# define GUPPY "textures/npc_guppy.XPM"
# define HANGING_SHOPKEEPER "textures/npc_hanging_shopkeeper.XPM"
# define SHOPKEEPER "textures/npc_shopkeeper.XPM"

# define TNT "textures/barrel_tnt.XPM"
# define TNT2 "textures/barrel_tnt2.XPM"
# define CHEST "textures/chest.XPM"
# define CHEST_ANGEL "textures/chest_angel.XPM"
# define CHEST_FINAL "textures/chest_final.XPM"
# define CHEST_GOLDEN "textures/chest_golden.XPM"
# define CHEST_MIMIC "textures/chest_mimic.XPM"
# define CHEST_SPIKED "textures/chest_spiked.XPM"
# define COBWEB "textures/cobweb.XPM"
# define DONATION_MACHINE "textures/donation_machine.XPM"
# define DONATION_MACHINE_BLOOD "textures/donation_machine_blood.XPM"
# define DONATION_MACHINE_RANDOM "textures/donation_machine_random.XPM"
# define FIREPLACE "textures/fireplace.XPM"
# define FIREPLACE_BLUE "textures/fireplace_blue.XPM"
# define FIREPLACE_PURPLE "textures/fireplace_purple.XPM"
# define FIREPLACE_RED "textures/fireplace_red.XPM"
# define MUSHROOM "textures/mushroom.XPM"
# define MUSHROOM2 "textures/mushroom2.XPM"
# define POOP "textures/poop.XPM"
# define POOP_BLACK "textures/poop_black.XPM"
# define POOP_CORN "textures/poop_corn.XPM"
# define POOP_GOLD "textures/poop_gold.XPM"
# define POOP_RAINBOW "textures/poop_rainbow.XPM"
# define POOP_RED "textures/poop_red.XPM"
# define POOP_WHITE "textures/poop_white.XPM"
# define ROCK "textures/rock.XPM"
# define ROCK_BLACK_TINTED "textures/rock_black_tinted.XPM"
# define ROCK_BLUE "textures/rock_blue.XPM"
# define ROCK_BRIGHT "textures/rock_bright.XPM"
# define ROCK_BLACK "textures/rock_black.XPM"
# define ROCK_POLYP "textures/rock_polyp.XPM"
# define ROCK_POLYP2 "textures/rock_polyp2.XPM"
# define ROCK_RED_TINTED "textures/rock_red_tinted.XPM"
# define ROCK_SPECIAL "textures/rock_special.XPM"
# define ROCK_SPECIAL_BLACK "textures/rock_special_black.XPM"
# define ROCK_SPECIAL_BLACK2 "textures/rock_special_black2.XPM"
# define ROCK_SPECIAL_BROWN "textures/rock_special_brown.XPM"
# define ROCK_SPECIAL_RED "textures/rock_special_red.XPM"
# define ROCK_TINTED "textures/rock_tinted.XPM"
# define SKULL "textures/skull.XPM"
# define URN "textures/urn.XPM"
# define URN2 "textures/urn2.XPM"

//**start textures**

//solid walls
# define ID_WALL1 1
# define ID_WALL2 2
# define ID_WALL3 3
# define ID_WALL_SHOP 4

//solid doors
# define ID_DOOR_HEART 5
# define ID_DOOR_C 6
# define ID_GDOOR_C 7

//not solid doors
# define ID_DOOR_O 8
# define ID_GDOOR_O 9
# define ID_CDOOR 10

//**end textures**

//**start sprites**

//*start not solid sprites*

//free pickables
# define ID_RHEART 11
# define ID_RHEART_HALF 12

# define ID_COIN 13
# define ID_KEY 14

//free items
# define ID_MAP 15
# define ID_HEELS 16
# define ID_CANDLE 17

//shop items
# define ID_POLY 18
# define ID_IPECAC 19
# define ID_GODHEAD 20
# define ID_AXE 21
# define ID_MANTLE 22
# define ID_QUARTER 23
# define ID_GLASSES 24
# define ID_DINNER 25

//esthetic spr
# define ID_WEB 26

//*end not solid sprites*

//*start solid sprites*

//esthetic spr
# define ID_ROCK1 27
# define ID_ROCK2 28
# define ID_ROCK3 29
# define ID_URN1 30
# define ID_URN2 31
# define ID_MUSHROOM1 32
# define ID_MUSHROOM2 33
# define ID_SKULL 34
# define ID_POOP 35
# define ID_TNT 36
# define ID_CAMPFIRE 37
# define ID_DMACHINE 38
# define ID_FINAL_CHEST 39


//interact spr
# define ID_SHOPKEEPER 40
# define ID_ERROR 41
# define ID_GUPPY 42
# define ID_HANGING 43
# define ID_BEGGAR_COIN 44
# define ID_BEGGAR_HEART 45
# define ID_BEGGAR_KEY 46
# define ID_BLOOD_MACHINE 47


//*end solid sprites*

//**sprites for the gui**
# define ID_CONTAINER_RED 48
# define ID_CONTAINER_RED_HALF 49
# define ID_CONTAINER_EMPTY 50
# define ID_SHIFT_ON 51
# define ID_SHIFT_OFF 52
# define ID_PRICE_TAG_15 53
# define ID_PRICE_TAG_5 54

//**end sprites**

#endif

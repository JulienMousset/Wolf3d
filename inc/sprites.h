/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:06:02 by jmousset          #+#    #+#             */
/*   Updated: 2019/12/16 16:46:34 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# define FIRST_TEX 1
# define LAST_TEX 9

# define LAST_WALL 13

# define FIRST_WALK 8
# define LAST_WALK 29

# define FIRST_FREE 16
# define LAST_FREE 20

# define FIRST_ITEM 18
# define LAST_ITEM 28

# define FIRST_SHOP_99 21
# define LAST_SHOP_99 23

# define FIRST_SHOP_15 24
# define LAST_SHOP_15 28

# define FIRST_SHOP 21
# define LAST_SHOP 28

# define FIRST_SOLID 29
# define LAST_SOLID 38

# define FIRST_INTER 42
# define LAST_INTER 50

# define FIRST_SPR 14
# define LAST_SPR 50

# define SKYBOX "textures/skybox_pixel.XPM"

# define WALL1 "textures/texture_wall.XPM"
# define WALL2 "textures/texture_wall2.XPM"
# define WALL3 "textures/texture_wall3.XPM"
# define WALL_SHOP "textures/texture_wall_shop.XPM"

# define DOOR_HEART "textures/texture_door_heart.XPM"
# define DOOR_CLOSED "textures/texture_door_closed.XPM"
# define DOOR_GOLDEN_CLOSED "textures/texture_door_golden_closed.XPM"
# define DOOR_OPEN "textures/texture_door_open.XPM"
# define DOOR_GOLDEN_OPEN "textures/texture_door_golden_open.XPM"
# define DOOR_CURSE "textures/texture_door_curse.XPM"

# define WALL1_SECRET "textures/texture_wall_secret.XPM"
# define WALL2_SECRET "textures/texture_wall2_secret.XPM"
# define WALL3_SECRET "textures/texture_wall3_secret.XPM"

# define HEART_RED "textures/pickup_heart_red.XPM"
# define HEART_RED_HALF "textures/pickup_heart_red_half.XPM"
# define COIN "textures/pickup_coin.XPM"
# define KEY "textures/pickup_key.XPM"

# define MAP "textures/item_treasure_map.XPM"
# define HEELS "textures/item_heels.XPM"
# define RED_CANDLE "textures/item_red_candle.XPM"
# define POLY "textures/item_polyphemus.XPM"
# define IPECAC "textures/item_ipecac.XPM"
# define GODHEAD "textures/item_godhead.XPM"
# define AXE "textures/item_notched_axe.XPM"
# define HOLY_MANTLE "textures/item_holy_mantle.XPM"
# define QUARTER "textures/item_a_quarter.XPM"
# define XRAY_VISION "textures/item_x-ray_vision.XPM"
# define DINNER "textures/item_dinner.XPM"

# define COBWEB "textures/cobweb.XPM"
# define ROCK1 "textures/rock.XPM"
# define ROCK2 "textures/rock_blue.XPM"
# define ROCK3 "textures/rock_black.XPM"
# define URN1 "textures/urn.XPM"
# define URN2 "textures/urn2.XPM"
# define MUSHROOM1 "textures/mushroom.XPM"
# define MUSHROOM2 "textures/mushroom2.XPM"
# define SKULL "textures/skull.XPM"
# define POOP "textures/poop.XPM"
# define TNT "textures/barrel_tnt.XPM"
# define CAMPFIRE "textures/fireplace.XPM"
# define DONATION_MACHINE "textures/donation_machine.XPM"

# define CHEST_FINAL "textures/chest_final.XPM"
# define SHOPKEEPER "textures/npc_shopkeeper.XPM"
# define ERROR "textures/npc_error.XPM"
# define GUPPY "textures/npc_guppy.XPM"
# define HANGING "textures/npc_hanging_shopkeeper.XPM"
# define BEGGAR_COIN "textures/npc_beggar.XPM"
# define BEGGAR_DEVIL "textures/npc_beggar_devil.XPM"
# define BEGGAR_KEY "textures/npc_beggar_key.XPM"
# define DONATION_MACHINE_BLOOD "textures/donation_machine_blood.XPM"

# define CONTAINER_HEART_EMPTY "textures/container_heart_empty.XPM"
# define CONTAINER_HEART_RED "textures/container_heart_red.XPM"
# define CONTAINER_HEART_RED_HALF "textures/container_heart_red_half.XPM"
# define SHIFT_OFF "textures/typo_shift_off.XPM"
# define SHIFT_ON "textures/typo_shift_on.XPM"

# define FLOOR1 "textures/texture_floor.XPM"
# define FLOOR2 "textures/texture_floor2.XPM"
# define FLOOR3 "textures/texture_floor3.XPM"

# define TAG_5 "textures/typo_price_tag_5.XPM"
# define TAG_15 "textures/typo_price_tag_15.XPM"
# define TAG_99 "textures/typo_price_tag_99.XPM"

# define CEILING1 "textures/texture_ceiling1.XPM"
# define CEILING2 "textures/texture_ceiling2.XPM"
# define CEILING3 "textures/texture_ceiling3.XPM"

# define ID_WALL1 1
# define ID_WALL2 2
# define ID_WALL3 3
# define ID_WALL_SHOP 4

# define ID_DOOR_HEART 5
# define ID_DOOR_C 6
# define ID_GDOOR_C 7
# define ID_DOOR_O 8
# define ID_GDOOR_O 9
# define ID_CDOOR 10

# define ID_SECRET1 11
# define ID_SECRET2 12
# define ID_SECRET3 13

# define ID_RHEART 14
# define ID_RHEART_HALF 15
# define ID_COIN 16
# define ID_KEY 17

# define ID_MAP 18
# define ID_HEELS 19
# define ID_CANDLE 20
# define ID_POLY 21
# define ID_IPECAC 22
# define ID_GODHEAD 23
# define ID_AXE 24
# define ID_MANTLE 25
# define ID_QUARTER 26
# define ID_XRAY 27
# define ID_DINNER 28

# define ID_WEB 29
# define ID_ROCK1 30
# define ID_ROCK2 31
# define ID_ROCK3 32
# define ID_URN1 33
# define ID_URN2 34
# define ID_MUSHROOM1 35
# define ID_MUSHROOM2 36
# define ID_SKULL 37
# define ID_POOP 38
# define ID_TNT 39
# define ID_CAMPFIRE 40
# define ID_DMACHINE 41

# define ID_FINAL_CHEST 42
# define ID_SHOPKEEPER 43
# define ID_ERROR 44
# define ID_GUPPY 45
# define ID_HANGING 46
# define ID_BEGGAR_COIN 47
# define ID_BEGGAR_HEART 48
# define ID_BEGGAR_KEY 49
# define ID_BLOOD_MACHINE 50

# define ID_HEART_SHOP 51
# define ID_KEY_SHOP 52
# define ID_CONTAINER_RED 51
# define ID_CONTAINER_HALF 52
# define ID_CONTAINER_EMPTY 53
# define ID_SHIFT_ON 54
# define ID_SHIFT_OFF 55

# define ID_FLOOR1 56
# define ID_FLOOR2 57
# define ID_FLOOR3 58

# define ID_TAG_5 59
# define ID_TAG_15 60
# define ID_TAG_99 61

# define ID_CEILING1 62
# define ID_CEILING2 63
# define ID_CEILING3 64

#endif

/*
** EPITECH PROJECT, 2021
** macros rpg
** File description:
** macros rpg
*/

#ifndef MACRO_RPG
#define MACRO_RPG


//// EXIT STATUS ////
#define ERROR 84
#define SUCCESS 0
/////////////////////

//// SCENES ////
#define MENU 0
#define GAME 1
#define PAUSE 2
#define SETTINGS 3
#define SCENES 4
////////////////

//// MENU BUTTONS ////
#define PLAY 0
#define EXIT 1
#define SETTINGS_B 2
#define HELP 3
//////////////////////

//// DROPS ////
#define INV_SIZE 24
#define DROPS 4
////////////////

//// SETTINGS BUTTONS ////
#define VOLUME 0
#define FPS 1
#define BACK 2
//////////////////////////

//// PATHS ////
#define TOWER_BACKGROUND "./resources/img/map/background_inventory.png"
#define ORC_WALK "./resources/img/player/orc_walk_sprite_x400.png"
#define SHADOW_WALK "./resources/img/player/shadow_guy_walk_sprite_x400.png"
#define PLAYER_WALK "./resources/img/player/player_walk.png"
#define PLAYER_IDLING "./resources/img/player/knight_idle_sprite.png"
    //// PROJECTILES ////
    #define PLAYER_SHOT "./resources/img/projectiles/player_shot.png"
    #define BOSS_SHOT "./resources/img/projectiles/projectile1.png"
    #define DAGGER "./resources/img/projectiles/dagger.png"
    #define MACE "./resources/img/projectiles/mace.png"
    #define HAMMER "./resources/img/projectiles/hammer.png"
    /////////////////////
    //// ENEMIES ////
    #define GOBLIN "./resources/img/enemies/goblin.png"
    #define ORC "./resources/img/enemies/orc_run.png"
    #define OGRE "./resources/img/enemies/ogre_idle.png"
    #define BOSS "./resources/img/enemies/boss.png"
    /////////////////
#define NEW_PLAYER "./resources/img/player/new_player.png"
#define BARTENDER "./resources/img/player/bartender.png"
#define GEI "./resources/img/player/gei.png"
#define REDDIT "./resources/img/player/reddit.png"
///////////////
//// CONFIGS ////
#define FLOOR_CONFIG "./resources/.dependencies/game/tower/"
#define ENEMY_CONFIG "./resources/.dependencies/game/enemies/1.conf"
#define PROJECTILE_CONFIG "./resources/.dependencies/game/projectiles/1.conf"
/////////////////
#define MAP "./resources/img/map/place_holder_map.jpg"
#define BACKGROUND "./resources/img/backgrounds/menu_background.jpg"
#define BACKGROUND_P "./resources/img/backgrounds/pause_background.jpg"
#define BACKGROUND_S "./resources/img/backgrounds/settings_background.jpg"
#define RED_PLAY "./resources/img/buttons/red/play.png"
#define RED_EXIT "./resources/img/buttons/red/exit.png"
#define RED_SETTINGS "./resources/img/buttons/red/settings.png"
#define RED_HELP "./resources/img/buttons/red/help.png"
#define BLUE_PLAY "./resources/img/buttons/blue/play.png"
#define BLUE_EXIT "./resources/img/buttons/blue/exit.png"
#define BLUE_SETTINGS "./resources/img/buttons/blue/settings.png"
#define BLUE_HELP "./resources/img/buttons/blue/help.png"
#define HELP_DISPLAY "./resources/img/backgrounds/help_display.png"
#define RED_BACK "./resources/img/buttons/red/back.png"
#define BLUE_BACK "./resources/img/buttons/blue/back.png"
#define RED_EMPTY "./resources/img/buttons/red/empty.png"
#define BLUE_EMPTY "./resources/img/buttons/blue/empty.png"
#define INVENTORY "./resources/img/backgrounds/inventory_background.jpg"
#define TEXT "./resources/text/font.ttf"
#define BLUE_BOTTLE "./resources/img/drops/blue_bottle.png"
#define GREEN_BOTTLE "./resources/img/drops/green_bottle.png"
#define RED_BOTTLE "./resources/img/drops/red_bottle.png"
#define YELLOW_BOTTLE "./resources/img/drops/yellow_bottle.png"
#define STATS "./resources/text/stats_font.ttf"
#define MAIN_FLOOR "./resources/img/backgrounds/floor_0_intro.png"
#define FINAL_FLOOR "./resources/img/backgrounds/final.png"
///////////////

/// AUDIO /////
#define OST_TOWN "./resources/sound/song-of-storms.ogg"

#endif /* !MACRO_RPG */

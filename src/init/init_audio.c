/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
**  initial the buttons
*/
 
#include "my_rpg.h"

void init_audio_storm(audio_t *audio_storms)
{
    
    audio_storms->volume = 25;
    audio_storms->ost = sfSound_create();
    audio_storms->ost_buffer = sfSoundBuffer_createFromFile(OST_TOWN);
    sfSound_setBuffer(audio_storms->ost, audio_storms->ost_buffer);
    sfSound_play(audio_storms->ost);
    sfSound_setVolume(audio_storms->ost, audio_storms->volume);
    sfSound_setLoop(audio_storms->ost, 1);
}

void init_audio(game_t *game)
{
    game->audio_storms = malloc(sizeof(audio_t));
    init_audio_storm(game->audio_storms);
}
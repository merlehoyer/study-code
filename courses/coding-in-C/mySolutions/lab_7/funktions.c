#include "funktions.h"
#include <stdio.h>
#include <stdlib.h>



/**
* File: funktions.c
* Description: defining functions for playlist management
* 
*/

/**
* initialises new playlist
* @param[in] none
* @param[out] pointer to struct playlist
*/

Playlist* init_playlist() {

	Playlist* new_playlist = malloc(sizeof(*new_playlist));

	new_playlist->p_first_song = NULL;

	return new_playlist;
}

/**
* creates new song and adds it to end of playlist
* param[in]  pointer to playlist 
* param[out] 0 for everything fine -1 for problem with reading names
*/

int add_song(Playlist* curplaylist) {

	Song* new_song = malloc(sizeof(*new_song));
	new_song->title = calloc(100, sizeof(*new_song->title));
	
	printf("choose your artist:\n");

	if (fgets(new_song->title, 100, stdin) == NULL) {
		printf("ERROR with songtitle\n");

		return -1;
	}
	printf("choose your title:\n");

	new_song->artist = calloc(100, sizeof(*new_song->artist));

	if (fgets(new_song->artist, 100, stdin) == NULL) {
		printf("ERROR with artist\n");

		return -1;
	}

	Song* temp = curplaylist->p_first_song;
	
	if(curplaylist->p_first_song==NULL){
		curplaylist->p_first_song = new_song;
		return 0;
	}

		while (temp->p_next != NULL) {
			temp = temp->p_next; 
		// searches for end of playlist
		}

		temp->p_next = new_song;

	

	return 0;
}

/**
 * displays songs saved in playlist starting at the top
 * param in: pointer to playlist 
 * param out : none
 */

void print_playlist(Playlist* cur_playlist) {
	Song *temp = cur_playlist->p_first_song;
	
	if(temp==NULL){
		printf("empty playlist");
	}
	
	while(temp!=NULL){
		printf("Title: %s, Artist: %s\n", temp->title, temp->artist);
		temp= temp->p_next;
	}

	
	printf("----------\n");

	return;
}

/**
 * deletes first song in playlist
 * param in : pointer to playlist
 * param out: none
 */

void delete_firstSong(Playlist* cur_playlist){
	Song *temp = cur_playlist->p_first_song;

	cur_playlist->p_first_song=temp->p_next;

	free(temp);

	return;
}

/**
 * deltetes whole playlist
 * param in: pointer to playlist
 * param out: none
 */


void delete_playlist(Playlist* cur_playlist){
	
	while(cur_playlist->p_first_song!=NULL){
		delete_firstSong(cur_playlist);
	}

	free(cur_playlist);

	return;
}
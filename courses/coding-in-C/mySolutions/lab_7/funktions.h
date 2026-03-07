#ifndef FUNKTIONS_H
#define FUNKTIONS_H

typedef struct Song {
	char *title;
	char *artist;
	struct Song* p_next;
}Song;

typedef struct Playlist {
	Song* p_first_song;
}Playlist;

Playlist* init_playlist();

void add_song(Playlist* cur_playlist);

void print_playlist(Playlist* cur_playlist);

void delete_firstSong(Playlist* cur_playlist);

void delete_playlist(Playlist* cur_playlist);




#endif
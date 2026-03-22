#ifndef FUNCTIONS_PLAYLIST_H
#define FUNCTIONSPLAYLIST_H

#define MAX_SONGS 6

typedef struct Song{
    char *title;
    char *artist;

    struct Song *p_next;

}Song ;

struct Playlist{
    int counter;
    Song *p_first;
    Song *p_last;
};

struct Playlist *init_playlist();

int add_Song(struct Playlist *cur_playlist);

void print_playlist(struct Playlist *cur_playlist);

void delete_firstSong(struct Playlist *cur_playlist);

void delete_playlist(struct Playlist *cur_playlist);
#endif  /*FUNCTIONSPLAYLIST_H */


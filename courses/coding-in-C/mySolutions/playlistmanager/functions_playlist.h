#ifndef FUNCTIONS_PLAYLIST_H
#define FUNCTIONSPLAYLIST_H
struct Song{
    char *title;
    char *artist;

    struct Song *p_next;

} ;

struct Playlist{
    struct Song *p_first;
    struct Song *p_last;
};

struct Playlist *init_playlist();

int add_Song(struct Playlist *cur_playlist);

void print_playlist(struct Playlist *cur_playlist);

void delete_firstSong(struct Playlist *cur_playlist);

void delete_playlist(struct Playlist *cur_playlist);
#endif  /*FUNCTIONSPLAYLIST_H */


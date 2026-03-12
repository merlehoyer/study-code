#include "functions_playlist.h"
#include <stdio.h>
#include <stdlib.h>

struct Playlist *init_playlist(){

    //in main check for NULL pointer!!!!

    struct Playlist *playlist = malloc( sizeof(*playlist));
    if(playlist==NULL){
        printf("ERROR \n");
    }else{
        playlist->p_first=NULL;
        playlist->p_last=NULL;
    }

    return playlist;
}

int add_Song(struct Playlist *cur_playlist){

    //check return value for 0!!!!!

    struct Song *new_song = malloc(sizeof(*new_song));

    new_song->title= calloc(100, sizeof(*new_song->title));

    printf("title of new song:\n");
    if(new_song->title!=NULL){
        fgets(new_song->title, 100 , stdin);
        
    }else{
        printf("ERROR");

        return -1;
    }

    new_song->artist = calloc(100, sizeof(*new_song->artist));

    printf("Artist of new song:\n");
    if(new_song->artist!=NULL){
        fgets(new_song->artist, 100, stdin);
    }else{
        printf("ERROR");

        return -1;
    }    


    if(cur_playlist->p_first==NULL){
        cur_playlist->p_first=new_song;
        cur_playlist->p_last= new_song;
    }else{
        cur_playlist->p_last->p_next= new_song;
        cur_playlist->p_last= new_song;
    }

    return 0;
}

void print_playlist(struct Playlist *cur_playlist){

    struct Song *temp = cur_playlist->p_first;

    if(cur_playlist->p_first==NULL){
        printf("Empty playlist\n");
    }

    while(temp!= NULL){
        printf("Artist: %s, Title: %s \n", temp->artist, temp->title);
        temp= temp->p_next;
    }

    printf("-----------\n");

    return;
}

void delete_firstSong(struct Playlist *cur_playlist){
   

    if(cur_playlist->p_first!=NULL){
        struct Song *temp = cur_playlist->p_first; 
        cur_playlist->p_first= temp->p_next;
        free(temp);
    }

    return;
}

void delete_playlist(struct Playlist *cur_playlist){
   
    while(cur_playlist->p_first!=NULL){
        delete_firstSong(cur_playlist);
    }

    free(cur_playlist);
}
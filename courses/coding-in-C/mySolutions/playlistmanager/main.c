#include "include/functions_playlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (){

    struct Playlist *my_playlist = init_playlist();

   /* 
    if(my_playlist==NULL){
        return -1;
    }

    if(add_Song(my_playlist)!=0){
        return -1;
    }
    if(add_Song(my_playlist)!=0){
        return -1;
    }
    if(add_Song(my_playlist)!=0){
        return -1;
    }
    */
    char option_adding_songs[100]; 
    char ja[12]= "ja\n";
    
    printf("Do you want to add a song?\n <ja> for new song any other key for not\n");


    for(int i= 0; i<MAX_SONGS; i++){

        fgets(option_adding_songs, 100, stdin);

        if(strcmp(option_adding_songs, ja)==0){
           
            if(add_Song(my_playlist)==-1){
            printf("error\n");
            return -1; 
            } 
        }else {
            printf("stopped adding songs\n");
            break;
        }
        
        
        
        /*if(i==MAX_SONGS-1){
            printf("reached max songs possible in playlist no more able to add\n");
            break;
        }*/
    }
    
    
    

    print_playlist(my_playlist);

    delete_firstSong(my_playlist);

    print_playlist(my_playlist);

    delete_playlist(my_playlist);

    return 0;
}

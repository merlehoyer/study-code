#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../include/functions_playlist.h"

/* === Unit-tests === */

// example unit test
void test_init_playlist(void)
{
    struct Playlist *p;
    p=init_playlist();

    assert(p->p_first == NULL);
    assert(p->counter == 0);
}

void test_add_song(void){
    
}
void test_delete_firstSong(){

}
test_delete_firstSong_empty(); // what happens if we delete first song from empty playlist
test_delete_playlist();
test_max_songs_limit(); // verify if the limit will be not be surpassed


/* === Test-Runner === */

int main(void)
{
    
    test_init_playlist();
    /*
    test_add_song();
    test_delete_firstSong();
    test_delete_firstSong_empty(); // what happens if we delete first song from empty playlist
    test_delete_playlist();
    test_max_songs_limit(); // verify if the limit will be not be surpassed
*/
    struct Playlist p;
    init_playlist(&p);

    assert(add_Song(&p)==0);
    add_Song(&p);
    assert(p.counter==2);

    delete_firstSong(&p);
    assert(p.counter==1);
    delete_firstSong(&p);
    delete_firstSong(&p);
    assert(p.p_first==NULL);
    delete_playlist(&p);
    
    assert(&p==NULL);
    
    init_playlist(&p);
    p.counter=7;

    assert(add_Song(&p)==1);

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}

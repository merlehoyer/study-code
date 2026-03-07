#include "funktions.h"
#include "funktions.c"
#include <stdio.h>
#include <stdlib.h>

int main() {

	Playlist *my_playlist = init_playlist();
	
	for(int i=0; i<3; i++){
		
		add_song(my_playlist);
	}
	print_playlist(my_playlist);

	delete_firstSong(my_playlist);
	print_playlist(my_playlist);

	delete_playlist(my_playlist);
	
	return 0;
}


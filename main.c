#include <stdlib.h>		// for random numbers
#include <time.h>		// for randomization (using system time)
#include "screen.h"
#include <stdio.h>
#include "sound.h"
#include <signal.h>

int main(){
	FILE *f;
	short sd[RATE];
	while(1){
	int ret = system(CMD); 		// have been defined in sound.h
					//system ("arecord -r16000 -c1 -f S16_LE -d5 -q test.wav");
	if(ret == SIGINT) break;
	f = fopen("test.wav", "r");
	if(f == NULL){
		printf("Cannot open the file\n");
		return 1;
	}

	clearScreen();
	setColors(RED, bg(PINK));
	struct WAVHDR hdr;
	fread(&hdr, sizeof(hdr), 1, f);		// read WAV header
	fread(&sd, sizeof(sd), 1, f);		// read WAV data
	fclose(f);
	displayWAVHDR(hdr);
	displayWAVDATA(sd);
	}
	resetColors();
	getchar();
}

#include <stdlib.h>		// for random numbers
#include <time.h>		// for randomization (using system time)
#include "screen.h"
#include <stdio.h>
#include "sound.h"
#include <signal.h>
#include "comm.h"

int main(int argc, char **argv){
	if(argc == 2){
		int ch;
		printf("how many channels? (1:mono, 2:stereo):");
		scanf("%d", &ch);
		float duration;
		printf("how long is the test tone? (1-10) sec):");
		scanf("%f", &duration);
		testTone(ch, atoi(argv[1]), duration);
		return 0;
	}
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
	setColors(RED, bg(BLACK));
	struct WAVHDR hdr;
	fread(&hdr, sizeof(hdr), 1, f);		// read WAV header
	displayWAVHDR(hdr);
	fread(&sd, sizeof(sd), 1, f);		// read WAV data
	displayWAVDATA(sd);
	fclose(f);		// close the opened file
	sendDATA(sd);
	}
	resetColors();
}

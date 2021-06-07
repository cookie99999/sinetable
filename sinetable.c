#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TWO_PI M_PI * 2.0
#define SCALE 64.0
#define STEPS 256

int main(int argc, char* argv[]) {
	int col = 0;
	double phase_shift = TWO_PI / ((double) STEPS);
	
	for (int i = 0; i < 256; i++) {
		double theta = ((double) i) * phase_shift;
		double sin_theta = sin(theta);
		unsigned char x = (double) (((double) (sin_theta * SCALE)));
		if (col == 0) {
			printf("DB $%02x,", x);
			col++;
		} else if (col == 15) {
			printf("$%02x\n", x);
			col = 0;
		} else {
			printf("$%02x,", x);
			col++;
		}
	}
	printf("\n");

	return EXIT_SUCCESS;
}

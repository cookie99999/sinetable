#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TWO_PI M_PI * 2.0
#define SCALE 64.0
#define STEPS 256

int main(int argc, char* argv[]) {
	int col = 0;
	double scale, steps;
	
	if (argc != 3) {
		printf("Usage: sinetable <scale> <steps>\n");
		return EXIT_FAILURE;
	}
	
	if (strtod(argv[1], NULL) < 0.1 || strtod(argv[1], NULL) > 256.0) {
		printf("Error: scale out of bounds\n");
		return EXIT_FAILURE;
	}

	scale = strtod(argv[1], NULL);
	steps = strtod(argv[2], NULL);
	double phase_shift = TWO_PI / steps;
	
	for (int i = 0; i < 256; i++) {
		double theta = ((double) i) * phase_shift;
		double sin_theta = sin(theta);
		unsigned char x = (double) (((double) (sin_theta * scale)));
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

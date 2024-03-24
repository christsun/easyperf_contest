/* -*- mode: c -*-
 * $Id$
 * http://www.bagley.org/~doug/shootout/
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(int argc, char *argv[]) {
#ifdef SMALL_PROBLEM_SIZE
#define LENGTH 17000
#else
#define LENGTH 170000
#endif
    int NUM = ((argc == 2) ? atoi(argv[1]) : LENGTH);
    static char flags[8192 + 1];
    long i, k;
    int count = 0;
	long sqrt_max = sqrt(8192);

    while (NUM--) {
		count = 0; 
		for (i=2; i <= 8192; i+=2) {
			flags[i] = 0; //偶数不是素数
			flags[i+1] = 1; // 奇数可能是
		}
		// flags[8192] doesn't need to be set, because it's even

		// since even numbers already crossed out we can:
			//  - start from i=3 
			//  - iterate over odd numbers (i+=2)
		for (i=3; i <= 8192; i++) {
			if (flags[i]) {
				/* remove all multiples of prime: i */
				// 1. less than i*i already marked
				// 2. only mark odd multiples (i*i+i will
				//    produce even number, which is already marked)
				for (k=i*i; k <= 8192; k+=2*i) {
					flags[k] = 0;
				}
			}
		}
		count = 1; // accounting for 2 is prime
        for (long i = 2; i <= 8192; i++) {
            if (flags[i])
                count++;
        }
    }
    printf("Count: %d\n", count);
    return(0);
}


// Book Notes Programs
// 
// Libraries
#include <stdlib.h>
#include <stdio.h>


// * Modern C, Listing 1

int main(void) {
	// declerations
	double A[5] = {
		[0] = 9.0 ,
	 	[1] = 2.9 ,
 		[4] = 3.E+25 ,
 		[3] = .00007 ,
	}; // end with declerations

	/// doing some homework
	// prints elements in the double[] array 
		for (size_t i = 0; i < 5; ++i) {

		printf("element %zu is %.02f, \t its square is %g\n",
		i,
		A[i],
		A[i]*A[i]);
	}	
	
	return EXIT_SUCCESS;
}

	

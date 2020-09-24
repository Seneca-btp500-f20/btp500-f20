
/*
let n represent the number we are finding factorial for
let T(n) represent the number operations needed to find 
		factorial of n

*/

unsigned int factorial (unsigned int n){
	unsigned int rc=1;				//1
	if(n > 1){						//1
		rc = n * factorial(n-1);	//3 + the number operations needed
		                            //    to find (n-1)!
	}
	return rc;						//1

}


unsigned int factorial (unsigned int n){
	unsigned int rc=1;				//1
	if(n > 1){						//1
		rc = n * factorial(n-1);	//3 + T(n-1)
		                            //    
	}
	return rc;						//1

}

/*what if n == 0 or n == 1 ... the number of operation needed to find
  1! is 3.  the number of operations needed to find 0! is 3.
  In other words T(1) = T(0) = 3

*/ 
unsigned int factorial (unsigned int n){
	unsigned int rc=1;				//1
	if(n > 1){						//1
		rc = n * factorial(n-1);	
	}
	return rc;						//1

}


/*what if n == 2 ..*/ 
unsigned int factorial (unsigned int n){
	unsigned int rc=1;				//1
	if(n > 1){						//1
		rc = n * factorial(n-1);	//3 + # of ops needed to find 1!
								    // in other words 3 + T(1) = 3 + 3
	}
	return rc;						//1

}

/*
T(n) = 1 + 1 + 3 + T(n-1)+ 1
     = 6 + T(n-1)


T(0) = 3
T(1) = 3

T(2) = 6 + T(1)
     = 6 + 3

T(3) = 6  + T(2)
     = 6 + 6 + 3

T(4) = 6 + T(3)
	 = 6 + 6 + 6 + 3

....

T(n) = 6 + T(n-1)
	 = 6 + 6 + 6 + 6 ... 6+ 3     <--- how many 6s are there? ... total of n-1 6's
	 = 6(n-1) + 3
	 = 6n - 6 + 3
	 = 6n - 3

Therefore T(n) is O(n)
	 

*/
/*
let n represent length of s
let A(n) represent number of ops for f1()
let B(n) represent number of ops for f2()
let C(n) represent number of ops for f3()
*/


int f1(const char* s){
	int rc=0;						//1
	for(int i=0;i<strlen(s);i++){	//1 + n*n + n
									
		rc+=s[i];					//n
	}	
	return rc;						//1
}


/*
A(n) = 1 + 1 + n*n + n + n + 1
	 = n^2 + 2n + 3

Therefore A(n) is O(n^2)
*/

int f2(const char* s){
	int rc=0;						//1
	for(int i=0;s[i]!='\0';i++){	//1 + n + n
		rc+=s[i];					//n
	}	
	return rc;						//1
}
/*
B(n) = 1 + 1 + n + n + n + 1
     = 3n +3

Therefore B(n) is O(n)
*/
int f3(const char* s){
	int rc=0;						//1
	int len=strlen(s);				//n
	for(int i=0;i<len;i++){			//1 + n + n
		rc+=s[i];					//n
	}	
	return rc;						//1
}

/*
C(n) = 1 + n + 1 + n +n + n +1
    =4n +3

C(n) is O(n)
*/

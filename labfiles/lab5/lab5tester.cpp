#include <string>
#include <iostream>
/************************************************************/
/*  Lab 5 tester                                            */
/*  To compile:                                             */
/*     g++ lab5.cpp lab5tester.cpp -std=c++0x               */
/*  To run:                                                 */
/*     ./a.out                                              */
/************************************************************/

bool bracketCheck(const std::string& s);
int main(void){
	std::string tests[5]={
		"a(b)c[d]ef{g}",
		"a[(a[bcd(efg{h[i]j}k{[(l)m]}n{}o)p])[q]]rs",
		"a(b)c]d",
		"[[]",
		"aa(bb{cc)dd}ee"
	};
	bool results[5]={true,true,false,false,false};

	for(int i=0;i<5;i++){
		if(bracketCheck(tests[i])==results[i]){
			std::cout << "Test "<< i+1 << " passed" << std::endl;
		}
		else{
			std::cout << "Test "<< i+1 << " error" << std::endl;
		}
	}
	return 0;
}

#include <iostream>

#include <sstream>

using namespace std;

struct complex_t {
	
  float real;
  
  float imag;
} one, two, three;

bool read(std::istringstream & stream, complex_t & complex) {
	
	float real;
	
	float imag;
	
	char symbol;
	
	if( stream >> symbol && symbol == '(' && 
	
		stream >> real && 
		
		stream >> symbol && symbol == ',' && 
		
		stream >> imag && 
		
		stream >> symbol && symbol == ')' ) {
			
		complex.real = real;
		
		complex.imag = imag;
		
		return true;
	}
	
	return false;
}

complex_t add (complex_t one, complex_t two){
	
	complex_t result;
	
	result.real  = one.real + two.real;
	
	result.imag = one.imag + two.imag;
	
	return result;
}

complex_t sub (complex_t one, complex_t two){
	
	complex_t result;
	
	result.real = one.real - two.real;
	
	result.imag = one.imag - two.imag;
	
	return result;
}

complex_t mul (complex_t one, complex_t two){
	
	complex_t result;
	
	result.real = one.real*two.real - one.imag*two.imag;
	
	result.imag = one.imag*two.real + one.real*two.imag;
	
	return result;
	
}

complex_t div (complex_t one, complex_t two){
	
	complex_t result;
	
	result.real = (one.real*two.real + one.imag*two.imag) / (two.real*two.real + two.imag*two.imag);
	
	result.imag = (one.imag*two.real - one.real*two.imag) / (two.real*two.real + two.imag*two.imag);
	
	return result;
	
}

void write (complex_t one, complex_t two, char op){
	
	switch (op) {
		
		case '+': {
			
			three = add(one, two);
			
			break;
		}
		
		case '-': {
			
			three = sub( one, two);
			
			break;
		}
		
		case '*': {
			
			three = mul( one,  two);
			
			break;
		}
		
		case '/': {
			
			three = div( one, two);
			
			break;
		}
		
	}
	
	cout << endl << "Result: " << '(' << three.real << ',' << three.imag << ')' << endl << endl;
	
}

int main () {
	
	std::string line;
	
	char op;
	
	while (1) {
	
		cout << "Write complex numbers by (r1, i1) op (r2, i2)" << endl << endl;
	
		std::getline( std::cin, line );
	
		std::istringstream stream( line );
	
		if( read( stream, one ) && stream >> op && read( stream, two ) ) {
		
			write (one, two, op);
		
		}
	
		else {
		
			cout << endl << "An error has occured while reading input data" << endl << endl;
		
		}
	}
	
	cin.get();
	
	return 0;
}

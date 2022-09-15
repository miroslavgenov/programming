#include "naturalNumber.h"

NaturalNumber::NaturalNumber(int number):number(number){}

std::ostream& operator<<(std::ostream& os ,const  NaturalNumber& naturalNumber){
	os<<naturalNumber.number;
	return os;
}

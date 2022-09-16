#pragma once

class NullptrChecker{
public:	
	static bool isNumberNullptr(int* number){
		return number == nullptr;
	}	
};

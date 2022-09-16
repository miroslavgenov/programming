#pragma once
#include <iostream>

class NaturalNumberController;

class NaturalNumber{
private:
	int number;
	friend NaturalNumberController;

public:
	NaturalNumber(int );
	friend std::ostream& operator<<(std::ostream&, const NaturalNumber&);
};

class NaturalNumberController{
public:
	static int getNaturaNumberNumber(NaturalNumber naturalNumberObject){
		return naturalNumberObject.number;
	}

	static int getNaturaNumberNumber(NaturalNumber* naturalNumberObject){
		return naturalNumberObject->number;
	}
};

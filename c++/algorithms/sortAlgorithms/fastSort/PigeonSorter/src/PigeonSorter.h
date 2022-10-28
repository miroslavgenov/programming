#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/NumberFinder.cpp"


class PigeonHoleSorter : NumberSorter{
	private:
		std::vector<std::vector<int>> pigeonHoles;
		int minimumNumber;
		int maximumNumber;
		int totalPigeonHolesRange ;


	public:
		PigeonHoleSorter(int [], size_t );

	private:
		void setMaximumNumber();

		void setMinimumNumber();

	public:
		void sort();
	
	
	private:
		int getTheSuitablePigeonHoleIndexForTheCurrentNumber(int );

		int getMinimumNumber();

	public:
		std::vector<int> getNumbers(){
    return NumberSorter::getNumbers();
}

};

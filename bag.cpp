#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int countThings;
	double *weightOfThings, *costOfThings;
	double *valOfThings, maxWeightOfBag;
	double currentWeightOfBag( 0 ), valOfBag ( 0 );
	
	cin >> countThings >> maxWeightOfBag;
	weightOfThings = new double[countThings];
	costOfThings = new double[countThings];
	valOfThings = new double[countThings];
	
	for(int i = 0; i < countThings; i++) cin >> weightOfThings[i];
	for(int i = 0; i < countThings; i++) cin >> costOfThings[i];
	for(int i = 0; i < countThings; i++) valOfThings[i] = costOfThings[i] / weightOfThings[i];
	
	bool isOverSort = false;
	while(!isOverSort)
	{
		isOverSort = true;
		for(int i = 0; i < countThings - 1 && isOverSort; i++)
		if(valOfThings[i] < valOfThings[i+1]) 
		{
			swap(valOfThings[i], valOfThings[i+1]);
			swap(weightOfThings[i], weightOfThings[i+1]);
			swap(costOfThings[i], costOfThings[i+1]);
			isOverSort = false;
		}
	}
	
	
	for(int currentThing = 0; currentThing < countThings && currentWeightOfBag <= maxWeightOfBag; currentThing++) 
		if( weightOfThings[ currentThing ] + currentWeightOfBag <= maxWeightOfBag ) 
		{
			currentWeightOfBag += weightOfThings[ currentThing ];
			valOfBag += costOfThings [ currentThing ];
		}
		
		cout << valOfBag << endl;
	
	
	
	
	delete []weightOfThings;
	delete []costOfThings;
	delete []valOfThings;
	
	return 0;	
}

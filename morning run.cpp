#include <iostream>
using namespace std;

int main() {
	double distanceBefore;
	double distanceAfter;
	int searchCountDays = 0;
	cin >> distanceBefore;
	cin >> distanceAfter;
	bool isOver = false;
	while( !isOver ) {
		distanceBefore += distanceBefore * 0.7;
		searchCountDays++;
		if(distanceBefore >= distanceAfter) isOver = true;
	}
	cout << searchCountDays << endl;
	
	system("pause");
	return 0;
} 

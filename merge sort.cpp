#include <iostream>
using namespace std;

int* sort(int *mas, int *mas_buff, int left, int right)
{
    if (left == right)
    {
        mas_buff[left] = mas[left];
        return mas_buff;
    }

    int mid = ((left + right) / 2);

    int *l_buff = sort(mas, mas_buff, left, mid);
    int *r_buff = sort(mas, mas_buff, mid + 1, right);

    int *target = l_buff == mas ? mas_buff : mas;

    int width = right - left, l_cur = left, r_cur = mid + 1;
    for (int i = left; i <= right; i++)
    {
        if (l_cur <= mid && r_cur <= right)
        {
            if (l_buff[l_cur] < r_buff[r_cur])
            {
                target[i] = l_buff[l_cur];
                l_cur++;
            }
            else
            {
                target[i] = r_buff[r_cur];
                r_cur++;
            }
        }
        else if (l_cur <= mid)
        {
            target[i] = l_buff[l_cur];
            l_cur++;
        }
        else
        {
            target[i] = r_buff[r_cur];
            r_cur++;
        }
    }
    return target;
}

int main() {
	int arrSize;
	do cin >> arrSize; 
	while (arrSize <= 0);
	int *arr = new int[arrSize];
	int *arrBuff = new int[arrSize];
	for(int i = 0; i < arrSize; i++) cin >> arr[i];
	
	arr = sort(arr, arrBuff, 0, arrSize - 1);
	
	for(int i = 0; i < arrSize; i++) cout << arr[i] << "  "; cout << endl;
		
	delete []arr;
	delete []arrBuff;
	return 0;
}

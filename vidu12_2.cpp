#include <iostream>
	void FindSum(int& sum, int n) // Phần khai báo hàm đã thay đổi
	{
    	for (int j = 0; j < n; j++)
        		sum = sum + j;
	}
	int main()
	{
    		int Sum = 0;
    		int n = 10;
    		FindSum(Sum, n);
    		std::cout << "The sum of " << n << " integers is " << Sum << std::endl;
            return 0;
	}

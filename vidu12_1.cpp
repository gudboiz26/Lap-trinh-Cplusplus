#include <iostream>
	// LƯU Ý: kết quả trả về từ hàm này không thể sử dụng được!
	void FindSum(int sum, int n)
	{
    	for(int j = 0; j < n; j++)
        		sum = sum + j;
	}
	int main()
	{
    	int Sum = 0;
    	int n = 10;
    	FindSum(Sum, n); // Gọi hàm FindSum() tại đây
    	std::cout << "The sum of " << n << " integers is " << Sum << std::endl;
        return 0;
	}

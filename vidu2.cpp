/* Chương trình này gọi một hàm (hai lần) để cộng hai số lại với nhau
   từ trong hàm main và xuất kết quả ra màn hình. */
#include <iostream>
using namespace std;

float Add (float a, float b) // Hàm Add()
{
    float sum;
    sum = a + b;
    return sum;
}

int main() // Hàm main
{
    float p = 1, q = 2.3, r = 3, s = 4.5;
    float Sum1, Sum2;

    Sum1 = Add(p, q); // Lần gọi thứ nhất tới hàm Add
    cout << "First Sum " << Sum1 << endl;

    Sum2 = Add(r, s); // Lần gọi thứ hai tới hàm Add
    cout << "Second Sum " << Sum2 << endl;
    return 0;
}


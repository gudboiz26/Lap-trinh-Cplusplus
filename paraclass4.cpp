#include <iostream>
#include <iomanip>

class ParallelPort {
private:
    unsigned int BaseAddress;
    unsigned char InDataPort1; // Register BASE+1 (Status)
    unsigned char DataPort0;   // Register BASE (Data) - Dùng để giả lập

public:
    // Constructor mặc định (Địa chỉ chuẩn LPT1: 0x378)
    ParallelPort() : BaseAddress(0x378), InDataPort1(0), DataPort0(0) {}

    // Constructor với địa chỉ tùy chỉnh
    ParallelPort(int baseaddress) : BaseAddress(baseaddress), InDataPort1(0), DataPort0(0) {}

    // Ghi dữ liệu vào Port 0 (Data Port)
    void WritePort0(unsigned char data) {
        DataPort0 = data;
        std::cout << "[Ghi] Port " << std::hex << std::uppercase << BaseAddress 
                  << " <- Gia tri: 0x" << (int)DataPort0 << std::endl;
    }

    // Đọc dữ liệu từ Port 1 (Status Port)
    unsigned char ReadPort1(unsigned char physicalInput) {
        // Giả lập đọc từ phần cứng (trong thực tế là inportb)
        InDataPort1 = physicalInput;

        std::cout << "[Doc] Nhan tu phan cung tai " << std::hex << BaseAddress + 1 
                  << ": 0x" << (int)InDataPort1 << std::endl;

        // 1. Nghịch đảo bit MSB (Bit 7 - Busy) 
        // Trong phần cứng Parallel Port, bit Busy thường bị đảo ngược mức logic.
        InDataPort1 ^= 0x80; 

        // 2. Filter (Mặt nạ bit): Xóa các bit D0, D1, D2 (thành 0)
        // Chỉ lấy các bit từ D3 đến D7.
        InDataPort1 &= 0xF8; 

        return InDataPort1;
    }
};

int main() {
    ParallelPort ourPort;

    // Giả lập ghi dữ liệu (ví dụ bật tất cả đèn LED)
    ourPort.WritePort0(0xFF); 

    // Giả lập nhận dữ liệu từ các cảm biến bên ngoài qua cổng Status
    // Giả sử cảm biến gửi về giá trị 0xAB (1010 1011)
    unsigned char rawInput = 0xAB; 
    unsigned char processedData = ourPort.ReadPort1(rawInput);

    // Hiển thị kết quả sau khi xử lý logic
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Du lieu sau khi xu ly logic (XOR & AND): 0x" 
              << std::hex << std::uppercase << (int)processedData << std::endl;

    return 0;
}
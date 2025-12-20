#include <iostream>
#include <bitset>
#include <string>

class ParallelPort {
public:
    // Để công khai (public) theo yêu cầu bài học cũ để minh họa truy cập trực tiếp
    unsigned int BaseAddress;

    // Constructor mặc định (Cổng LPT1 thường là 0x378)
    ParallelPort() : BaseAddress(0x378) {}

    // Constructor tùy chỉnh địa chỉ
    ParallelPort(unsigned int baseaddress) : BaseAddress(baseaddress) {}

    // Hàm giả lập ghi dữ liệu ra cổng
    void WritePort0(unsigned char data) {
        std::cout << "\n[SIMULATION] Dang ghi du lieu vao dia chi: 0x" 
                  << std::hex << std::uppercase << BaseAddress << std::dec << std::endl;
        
        std::cout << "Gia tri (Thap phan): " << (int)data << std::endl;
        
        // Chuyển đổi dữ liệu sang dạng nhị phân để mô phỏng 8 chân dữ liệu (D0-D7)
        std::bitset<8> binaryData(data);
        std::cout << "Trang thai cac chan (D7 -> D0): " << binaryData << std::endl;
        
        std::cout << "------------------------------------------" << std::endl;
    }
};

int main() {
    // Khởi tạo đối tượng
    ParallelPort OurPort;

    // Minh họa việc thay đổi BaseAddress trực tiếp (do thuộc tính là public)
    std::cout << "Dia chi mac dinh: 0x" << std::hex << OurPort.BaseAddress << std::endl;
    
    OurPort.BaseAddress = 0x3BC; 
    std::cout << "Dia chi sau khi thay doi: 0x" << std::hex << OurPort.BaseAddress << std::endl;

    // Ghi giá trị 255 (tương ứng tất cả các chân đều ở mức cao - HIGH)
    OurPort.WritePort0(255);

    // Thử nghiệm với một giá trị khác (ví dụ: 170 tương ứng 10101010)
    OurPort.WritePort0(170);

    return 0;
}
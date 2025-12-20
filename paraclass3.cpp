#include <iostream>
#include <iomanip> // Để định dạng số Hex (thập lục phân)

class ParallelPort {
private:
    unsigned int BaseAddress;

public:
    // Constructor mặc định: Thiết lập địa chỉ tiêu chuẩn 0x378
    ParallelPort();

    // Constructor tham số: Cho phép tùy chỉnh địa chỉ khi khởi tạo
    ParallelPort(unsigned int baseaddress);

    // Giả lập ghi dữ liệu xuống cổng
    void WritePort0(unsigned char data);

    // Hàm công khai để thay đổi địa chỉ (Setter)
    void ChangeAddress(unsigned int newaddress);
};

// Triển khai Constructor mặc định
ParallelPort::ParallelPort() {
    BaseAddress = 0x378;
    std::cout << "[He thong] Dang khoi tao cong mac dinh tai: 0x" 
              << std::hex << BaseAddress << std::endl;
}

// Triển khai Constructor tham số
ParallelPort::ParallelPort(unsigned int baseaddress) {
    BaseAddress = baseaddress;
    std::cout << "[He thong] Dang khoi tao cong tuy chinh tai: 0x" 
              << std::hex << BaseAddress << std::endl;
}

// Giả lập việc ghi dữ liệu
void ParallelPort::WritePort0(unsigned char data) {
    std::cout << "[Ghi du lieu] Dang gui gia tri: " << (int)data 
              << " toi dia chi: 0x" << std::hex << BaseAddress << std::endl;
    
    // Trong môi trường học thuật, ta mô phỏng kết quả
    if (BaseAddress == 0x3BC) {
        std::cout << " >> Thong bao: Da gui toi cong phu (Secondary Port)." << std::endl;
    }
}

// Thay đổi địa chỉ cổng một cách an toàn
void ParallelPort::ChangeAddress(unsigned int newaddress) {
    std::cout << "[Cau hinh] Thay doi dia chi tu 0x" << std::hex << BaseAddress 
              << " sang 0x" << newaddress << std::endl;
    BaseAddress = newaddress;
}

int main() {
    // 1. Khởi tạo đối tượng
    ParallelPort OurPort;

    // 2. Thay đổi địa chỉ thông qua phương thức công khai (Encapsulation)
    // Thay vì can thiệp trực tiếp vào biến private, ta dùng hàm ChangeAddress
    OurPort.ChangeAddress(0x3BC);

    // 3. Ghi dữ liệu (255 tương đương với việc bật tất cả các chân dữ liệu lên mức cao)
    OurPort.WritePort0(255);

    return 0;
}
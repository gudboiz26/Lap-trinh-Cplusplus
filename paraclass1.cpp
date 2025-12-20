#include <iostream>
#include <iomanip> // Thư viện để định dạng hiển thị

// Lớp giả lập Cổng Song Song
class ParallelPort {
private:
    unsigned int BaseAddress;
    unsigned char CurrentData; // Biến lưu trữ giá trị đang có trên cổng

public:
    // Constructor mặc định
    ParallelPort() {
        BaseAddress = 0x378;
        CurrentData = 0;
        std::cout << "[System] Da khoi tao cong tai dia chi: 0x" << std::hex << BaseAddress << std::endl;
    }

    // Constructor tùy chỉnh địa chỉ
    ParallelPort(int baseaddress) {
        BaseAddress = baseaddress;
        CurrentData = 0;
        std::cout << "[System] Da khoi tao cong tai dia chi tuy chinh: 0x" << std::hex << BaseAddress << std::endl;
    }

    // Hàm ghi dữ liệu (Gia lập thuật toán xuất tín hiệu)
    void WritePort0(unsigned char data) {
        CurrentData = data;
        
        // Thay vì outportb, chúng ta in kết quả ra màn hình để kiểm tra
        std::cout << "\n--- GIA LAP TIN HIEU ---" << std::endl;
        std::cout << "Dang ghi vao dia chi 0x" << std::hex << BaseAddress << std::endl;
        std::cout << "Gia tri thap phan: " << std::dec << (int)data << std::endl;
        std::cout << "Gia tri Hex: 0x" << std::hex << (int)data << std::endl;
        std::cout << "------------------------" << std::endl;
    }
};

int main() {
    // 1. Khoi tao doi tuong (Object instantiation)
    ParallelPort OurPort; 

    // 2. Goi ham thanh vien de thuc hien thuat toan
    // Gui gia tri 255 (tuong duong tat ca cac chan deu co dien cao)
    OurPort.WritePort0(255);

    // Thu gui mot gia tri khac
    OurPort.WritePort0(127);

    return 0;
}
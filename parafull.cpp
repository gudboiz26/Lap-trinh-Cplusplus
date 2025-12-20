#include <iostream>
#include <cstdio>

// Giả lập hàm getch() của conio.h trên Windows/Modern C++
void waitForKey() {
    std::cout << "\n[Nhan Enter de tiep tuc...]";
    std::cin.get();
}

class ParallelPort {
private:
    unsigned int BaseAddress;
    unsigned char InDataPort1;

public:
    ParallelPort();
    ParallelPort(int baseaddress);
    void WritePort0(unsigned char data);
    void WritePort2(unsigned char data);
    unsigned char ReadPort1();
};

ParallelPort::ParallelPort() {
    BaseAddress = 0x378;
    InDataPort1 = 0;
}

ParallelPort::ParallelPort(int baseaddress) {
    BaseAddress = baseaddress;
    InDataPort1 = 0;
}

void ParallelPort::WritePort0(unsigned char data) {
    // Giả lập outportb(BaseAddress, data);
    printf("[Hardware Out] Port 0x%X (Data Port)  <- Value: 0x%02X\n", BaseAddress, data);
}

void ParallelPort::WritePort2(unsigned char data) {
    // Logic: Đảo bit 0, 1, 3 bằng XOR 0x0B (1011 nhị phân)
    unsigned char finalData = data ^ 0x0B;
    // Giả lập outportb(BaseAddress + 2, finalData);
    printf("[Hardware Out] Port 0x%X (Control Port) <- Value: 0x%02X (Goc: 0x%02X)\n", BaseAddress + 2, finalData, data);
}

unsigned char ParallelPort::ReadPort1() {
    // Giả lập inportb(BaseAddress + 1); 
    // Giả sử thiết bị ngoại vi đang gửi về giá trị 0x7F để test
    unsigned char simulatedHardwareInput = 0x7F; 
    
    InDataPort1 = simulatedHardwareInput;

    // Inverting Most significant bit (S7) để bù cho việc đảo ngược của phần cứng
    InDataPort1 ^= 0x80;

    // Filter để xóa các bit D0, D1, D2 (không sử dụng trong Status Port)
    InDataPort1 &= 0xF8;

    printf("[Hardware In ] Port 0x%X (Status Port)  -> Raw: 0x%02X | Sau khi xu ly: 0x%02X\n", 
            BaseAddress + 1, simulatedHardwareInput, InDataPort1);
            
    return InDataPort1;
}

int main() {
    unsigned char BASE1Data;
    ParallelPort OurPort; // Khởi tạo với địa chỉ mặc định 0x378

    // 1. Ghi vào Port 0
    OurPort.WritePort0(0x55);
    printf("-> Data 0x55 sent to Port at BASE\n");
    waitForKey();

    // 2. Đọc từ Port 1
    BASE1Data = OurPort.ReadPort1();
    printf("-> Data read from Port at BASE+1 (Processed): %02X\n", BASE1Data);
    waitForKey();

    // 3. Ghi vào Port 2
    OurPort.WritePort2(0x00);
    printf("-> Data 0x00 sent to Port at BASE+2\n");
    waitForKey();

    return 0;
}
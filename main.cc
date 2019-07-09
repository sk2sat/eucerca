#include <iostream>
#include <cstdint>

int main(int argc, char **argv){
	bool halt_flag = false;
	uint16_t ip = 0x00;	// プログラムカウンタ
	uint8_t memory[] = {
		0x90, 0xf4,
	};

	while(!halt_flag){
		uint8_t opcode = memory[ip];
		std::cout << "ip = " << std::hex << ip << ", "
			<< "opcode = " << (uint32_t)opcode << std::endl;

		switch(opcode){
		case 0x90:	// NOP
			ip++;
			break;
		case 0xf4:	// HLT
			halt_flag = true;
		}
	}

	return 0;
}

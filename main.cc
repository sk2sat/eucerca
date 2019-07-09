#include <iostream>
#include <cstdint>

#define AX	reg[0]
#define CX	reg[1]
#define DX	reg[2]
#define BX	reg[3]
#define SP	reg[4]
#define BP	reg[5]
#define SI	reg[6]
#define DI	reg[7]

int main(int argc, char **argv){
	bool halt_flag = false;
	uint16_t ip = 0x00;	// プログラムカウンタ
	uint16_t reg[8];	// レジスタ
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

#include "disassembler.h"
#include "cpu.h"

#include <iostream>
#include <iomanip>

void disassemble_rom(char* buf, int size) {
    uint16_t p = 0;
    while (p < size) {
        uint8_t op = (uint8_t)buf[p];
        uint8_t sz = 1;
        std::string name = "?";
        // skipping a lot of alphabetical shit
        switch (op) {
        case ADC_AB:
            name = "ADC_AB";
            sz = 3;
            break;
        case ADC_ABX:
            name = "ADC_ABX";
            sz = 3;
            break;
        case ADC_ABY:
            name = "ADC_ABY";
            sz = 3;
            break;
        case ADC_IMM:
            name = "ADC_IMM";
            sz = 2;
            break;
        case ADC_INX:
            name = "ADC_INX";
            sz = 2;
            break;
        case ADC_INY:
            name = "ADC_INY";
            sz = 2;
            break;
        case ADC_ZP:
            name = "ADC_ZP";
            sz = 2;
            break;
        case ADC_ZPX:
            name = "ADC_ZPX";
            sz = 2;
            break;
        case AND_AB:
            name = "AND_AB";
            sz = 3;
            break;
        case AND_ABX:
            name = "AND_ABX";
            sz = 3;
            break;
        case AND_ABY:
            name = "AND_ABY";
            sz = 3;
            break;
        case AND_IMM:
            name = "AND_IMM";
            sz = 2;
            break;
        case AND_INX:
            name = "AND_INX";
            sz = 2;
            break;
        case AND_INY:
            name = "AND_INY";
            sz = 2;
            break;
        case AND_ZP:
            name = "AND_ZP";
            sz = 2;
            break;
        case AND_ZPX:
            name = "AND_ZPX";
            sz = 2;
            break;
        case JMP_AB:
            name = "JMP_AB";
            sz = 3;
            break;
        case JMP_IN:
            name = "JMP_IN";
            sz = 3;
            break;
        default:
            break;
        }
        // std::cout << unsigned(op) << std::endl;
        std::cout << name;
        for (uint8_t i = 1; i < sz; i++) {
            uint8_t v = buf[p + i];
            std::cout << " "
                    << "0x" << std::setfill('0') << std::setw(2) << unsigned(v);
        }
        std::cout << std::endl;
        p += sz;
    }
}
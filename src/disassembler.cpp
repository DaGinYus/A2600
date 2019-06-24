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
        case ASL_AB:
            name = "ASL_AB";
            sz = 3;
            break;
        case ASL_ABX:
            name = "ASL_ABX";
            sz = 3;
            break;
        case ASL_ACC:
            name = "ASL_ACC";
            sz = 1;
            break;
        case ASL_ZP:
            name = "ASL_ZP";
            sz = 2;
            break;
        case ASL_ZPX:
            name = "ASL_ZPX";
            sz = 2;
            break;
        case BCC_REL:
            name = "BCC_REL";
            sz = 2;
            break;
        case BCS_REL:
            name = "BCS_REL";
            sz = 2;
            break;
        case BEQ_REL:
            name = "BEQ_REL";
            sz = 2;
            break;
        case BIT_AB:
            name = "BIT_AB";
            sz = 3;
            break;
        case BIT_ZP:
            name = "BIT_ZP";
            sz = 2;
            break;
        case BMI_REL:
            name = "BMI_REL";
            sz = 2;
            break;
        case BNE_REL:
            name = "BNE_REL";
            sz = 2;
            break;
        case BPL_REL:
            name = "BPL_REL";
            sz = 2;
            break;
        case BRK:
            name = "BRK";
            sz = 1;
            break;
        case BVC_REL:
            name = "BVC_REL";
            sz = 2;
            break;
        case BVS_REL:
            name = "BVS_REL";
            sz = 2;
            break;
        case CLC:
            name = "CLC";
            sz = 1;
            break;
        case CLD:
            name = "CLD";
            sz = 1;
            break;
        case CLI:
            name = "CLI";
            sz = 1;
            break;
        case CLV:
            name = "CLV";
            sz = 1;
            break;
        case CMP_AB:
            name = "CMP_AB";
            sz = 3;
            break;
        case CMP_ABX:
            name = "CMP_ABX";
            sz = 3;
            break;
        case CMP_ABY:
            name = "CMP_ABY";
            sz = 3;
            break;
        case CMP_IMM:
            name = "CMP_IMM";
            sz = 2;
            break;
        case CMP_INX:
            name = "CMP_INX";
            sz = 2;
            break;
        case CMP_INY:
            name = "CMP_INY";
            sz = 2;
            break;
        case CMP_ZP:
            name = "CMP_ZP";
            sz = 2;
            break;
        case CMP_ZPX:
            name = "CMP_ZPX";
            sz = 2;
            break;
        case CPX_AB:
            name = "CPX_AB";
            sz = 3;
            break;
        case CPX_IMM:
            name = "CPX_IMM";
            sz = 2;
            break;
        case CPX_ZP:
            name = "CPX_ZP";
            sz = 2;
            break;
        case CPY_AB:
            name = "CPY_AB";
            sz = 3;
            break;
        case CPY_IMM:
            name = "CPY_IMM";
            sz = 2;
            break;
        case CPY_ZP:
            name = "CPY_ZP";
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
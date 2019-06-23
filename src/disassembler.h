#pragma once

#include "cpu.h"
// http://www.emulator101.com/reference/6502-reference.html
// http://www.obelisk.me.uk/6502/reference.html#JMP
// http://www.obelisk.me.uk/6502/addressing.html

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
            std::cout << " " << "0x" << std::setfill('0') << std::setw(2) << unsigned(v);
        }
        std::cout << std::endl;
        p += sz;
    }
}

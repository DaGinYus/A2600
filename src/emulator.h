#pragma once

#include <iomanip>
#include <fstream>

class Emulator {
    public:
        void run_file(std::ifstream file);
        void process_line(std::string line);   

    private:
    // flags
    uint8_t z   : 1; // zero
    uint8_t s   : 1; // sign
    uint8_t p   : 1; // parity
    uint8_t cy  : 1; // cary
    uint8_t ac  : 1; // auxillary carry
    uint8_t pad : 1; // something

    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t h;
    uint8_t l;

    uint16_t sp;
    uint16_t pc; // program counter

    uint8_t *memory; // ram
    uint8_t int_enable; 
};
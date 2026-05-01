// Main file for the assembler part of the toolchain to run separately

#include<stdio.h>
#include"assembler.h"

int main(){
    assemble("test/assembly.txt");
    return 0;
}

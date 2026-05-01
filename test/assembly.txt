; JAL and JALR test

start:
ADDI R1, R0, 10

JAL R10, target

ADDI R2, R0, 99
JAL R0, end

target:
ADDI R3, R0, 55

JALR R11, 0(R10)

end:
HLT

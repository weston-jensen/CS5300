.text
.global __main
j __main
__main:
move $fp, $sp
move $gp, $fp
li $8, 5
sw $8, 0($fp)
li $8, 1
sw $8, 4($fp)
lw $9, 0($fp)
li $10, 5
slt $8, $9, $10
beq $8 , $zero, __control0IfStmt0
la $a0,__stringConstLabel0
li $v0, 4
syscall
lw $9, 4($fp)
li $10, 1
seq $8, $9, $10
beq $8 , $zero, __control1IfStmt0
la $a0,__stringConstLabel1
li $v0, 4
syscall
j __controlStmtAfter1
__control1IfStmt0: 
__conrolStmtAfter1: 
j __controlStmtAfter0
__control0IfStmt0: 
lw $9, 0($fp)
li $10, 5
seq $8, $9, $10
beq $8 , $zero, __control0IfStmt1
la $a0,__stringConstLabel2
li $v0, 4
syscall
j __controlStmtAfter0
__control0IfStmt1: 
la $a0,__stringConstLabel3
li $v0, 4
syscall
j __controlStmtAfter0
__control0IfStmt2: 
__conrolStmtAfter0: 
li $v0, 10
syscall
.data
__newline: .asciiz "\n"
__stringConstLabel0: .asciiz "i less than 5!\n"
__stringConstLabel1: .asciiz "j is 1\n"
__stringConstLabel2: .asciiz "i is 5!"
__stringConstLabel3: .asciiz "i is greater than 5!"

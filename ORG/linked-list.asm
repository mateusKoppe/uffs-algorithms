	.globl main
	
	.data
msg_menu_header:		.string "\n -- List manager --\n"
msg_menu_insert:		.string "\t [1] Insert value\n"
msg_menu_remove_value:		.string "\t [2] Remove by value\n"
msg_menu_remove_index:		.string "\t [3] Remove by index\n"
msg_menu_list:			.string "\t [4] List values\n"
msg_menu_exit:			.string "\t [0] Exit\n"
breakln:			.string "\n"
space:				.string " "

	.text
main:
	nop
	add s0, zero, sp    # pointer to start of the stack
	
menu:
	la a0, msg_menu_header
	jal print_str

	la a0, msg_menu_insert
	jal print_str
	
	la a0, msg_menu_remove_value
	jal print_str

	la a0, msg_menu_remove_index
	jal print_str
	
	la a0, msg_menu_list
	jal print_str
	
	la a0, msg_menu_exit
	jal print_str
	
	
	jal read_int
	
	li t0, 0
	beq  a0, t0, exit
	
	li t0, 1
	beq  a0, t0, insert
	
	li t0, 2
	beq a0, t0, remove_value
	
	li t0, 3
	beq  a0, t0, remove_index
	
	li t0, 4
	beq  a0, t0, print_list

	j menu


#####
# Insertion option
#####

insert:
	jal read_int
	beq s0, sp, _insert_first
	j _insert_common

_insert_first:
	sw  a0, 0(sp)
	sw  zero, -4(sp)
	addi sp, sp, -8
	j menu
	
_insert_common:
	sw a0, 0(sp)         ## Write node value
	lw t1, 4(sp)         ## Get prev node next pointer
	sw t1, -4(sp)        ## Save prev node next pointer in this node next pointer
	sw sp, 4(sp)         ## Save this node address in prev node next pointer
	addi sp, sp, -8
	j menu

		
#############
# Print List#
#############
print_list:
	add t0, zero, s0

_list_loop:
	beqz t0, menu
	lw a0, 0(t0) 
	jal print_int
	jal print_space
	lw t0, -4(t0)
	j _list_loop
	
############
# Remove by value
###########
remove_value:
	jal read_int
	
_remove_value_start:
	beq s0, sp, menu
	add t0, zero, s0
	lw t1, 0(t0)
	bne t1, a0, _remove_value_loop
	lw t3, -4(t0)
	add s0, zero, t3
	beqz s0, _restore_stack
	j _remove_value_start
	
_remove_value_loop:
	lw t1, -4(t0)				 # Get next node
	beqz t1, menu				 # if node is zero go back to menu
	
	lw t2, 0(t1)
	
	bne t2,  a0, _remove_value_loop_next 	 # If diferent next iteration
	lw t3, -4(t1)
	sw t3, -4(t0)
	j _remove_value_loop
	
_remove_value_loop_next:
	add t0, zero, t1
	j _remove_value_loop

_restore_stack:
	add s0, zero, sp
	j menu


###########################
# Remove by index
###########################
remove_index:
	jal read_int
	li t1, 0
	
_remove_index_start:
	beq s0, sp, menu
	add t0, zero, s0
	bne t1, a0, _remove_index_loop
	lw t2, -4(t0)
	add s0, zero, t2
	beqz s0, _restore_stack
	j menu
	
_remove_index_loop:
	lw t2, -4(t0)				 # Get next node
	beqz t2, menu				 # if node is zero go back to menu
	addi t1, t1, 1
	bne t1, a0, _remove_index_loop_next 	 # If diferent next iteration
	
	lw t3, -4(t2)
	sw t3, -4(t0)
	j _remove_index_loop

_remove_index_loop_next:
	add t0, zero, t2
	j _remove_index_loop

###############################
#    Helpers  Section         #
###############################
read_int:                  # label to read input from the user to a0
	li a7, 5
	ecall
	ret

print_str:                 # auxiliary function to print string loaded to a0
	li a7, 4
	ecall
	ret
	
print_break_line:
	la a0, breakln
	li a7, 4
	ecall
	ret
	
print_space:
	la a0, space
	li a7, 4
	ecall
	ret

print_int:
	li a7, 1
	ecall
	ret

exit:                     # exits


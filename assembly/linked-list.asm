## Alunos:
## Amadeus Dabela - 1621101005
## Mateus Koppe - 1821101023

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

msg_menu_created_item_index:		.string "\ncreated in index:"
msg_menu_removed_item_index:		.string "\nremoved in index:"
msg_menu_removed_item_value:		.string "\nremoved in value:"
msg_number_inserted:            .string "\nnumber of items inserted:"
msg_number_removed:             .string "\nnumber of items removed:"

	.text
main:
	nop

	add s0, zero, sp    # pointer to head of the linked list
	li t0, 0
	sw t0 0(sp)
	sw t0 -4(sp) 		## Inserted items
	sw t0 -8(sp) 		## Removed items
	addi sp, sp, -12
	
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
	
	li t0, 1
	beq  a0, t0, menu_insert
	
	li t0, 2
	beq a0, t0, menu_remove_value
	
	li t0, 3
	beq  a0, t0, menu_remove_index
	
	li t0, 4
	beq  a0, t0, menu_print_list

	li t0, 0
	beq  a0, t0, menu_exit

	j menu


#
# Menu methods
#
menu_insert:
	jal read_int
	add a1 zero a0
	add a0 zero s0
	jal lkdlist_insert
	add t0 zero a0
	la a0, msg_menu_created_item_index
	jal print_str
	add a0 zero t0
	jal print_int
	j menu

menu_remove_value:
	jal read_int
	add a1 zero a0
	add a0 zero s0
	jal lkdlist_remove_value
	add t0 zero a0
	la a0, msg_menu_removed_item_index
	jal print_str
	add a0 zero t0
	jal print_int
	j menu

menu_remove_index:
	jal read_int
	add a1 zero a0
	add a0 zero s0
	jal lkdlist_remove_index
	add t0 zero a0
	la a0, msg_menu_removed_item_value
	jal print_str
	add a0 zero t0
	jal print_int
	j menu

menu_print_list:
	add a0 zero s0
	jal lkdlist_print
	j menu

menu_exit:                     
	la a0, msg_number_inserted
	jal print_str
	lw a0, -4(s0)
	jal print_int
	la a0, msg_number_removed
	jal print_str
	lw a0, -8(s0)
	jal print_int
	jal print_break_line
	li a7, 10
	ecall


#
# Linked List Functions
#

## Insert
# Receives:
# - a0 -> linked list
# - a1 -> value to insert
#
# Returns:
# - a0 -> added items index
lkdlist_insert:
	li t4 0 
	lw t0, 0(a0)
	beqz t0, _lkdlist_insert_head
	lw t1, 0(t0)
	blt a1, t1, _lkdlist_insert_head
	j _lkdlist_insert_loop

_lkdlist_insert_head:
	lw t1, 0(a0)
	sw a1, 0(sp)
	sw t1, -4(sp)
	sw sp 0(a0)
	addi sp, sp, -8

	lw t0 -4(a0)
	addi t0, t0, 1
	sw t0 -4(a0)

	add a0 zero t4
	ret
	
_lkdlist_insert_loop:
	addi t4 t4 1
	lw t1, -4(t0)
	beqz t1, _lkdlist_insert_node
	lw t2, -0(t1)
	blt a1, t2, _lkdlist_insert_node
	add t0, zero, t1
	j _lkdlist_insert_loop
	
_lkdlist_insert_node:
	lw t1, -4(t0)
	sw a1, 0(sp)
	sw t1, -4(sp)
	sw sp, -4(t0)
	addi sp, sp, -8

	lw t0 -4(a0)
	addi t0, t0, 1
	sw t0 -4(a0)
	
	add a0 zero t4
	ret
		
## Print
# Receives:
# - a0 -> linked list
lkdlist_print:
	lw t0, 0(a0)
	add t6, zero, ra                  # Save return address

_lkdlist_print_loop:
	beqz t0, _lkdlist_print_finish
	lw a0, 0(t0) 
	jal print_int
	jal print_space
	lw t0, -4(t0)
	j _lkdlist_print_loop

_lkdlist_print_finish:
	add ra, zero, t6
	ret
	
## Remove by value
# Receives:
# - a0 -> linked list
# - a1 -> value to remove
#
# Returns:
# - a0 -> removed index
lkdlist_remove_value:
	li t4, 0
	lw t0, 0(a0)
	beqz t0, _lkdlist_remove_value_return
	lw t1, 0(t0)
	bne t1, a1, _lkdlist_remove_value_loop
	lw t1, -4(t0)
	sw t1, 0(a0) 
	lw t0 -8(a0)
	addi t0, t0, 1
	sw t0 -8(a0)
	add a0, zero, t4
	ret
	
_lkdlist_remove_value_loop:
	addi t4, t4, 1
	lw t1, -4(t0)				          # Get next node
	beqz t1, _lkdlist_remove_value_return # if node is zero go back to menu
	
	lw t2, 0(t1)
	
	bne t2, a1, _lkdlist_remove_value_loop_next 	 # If diferent next iteration
	lw t3, -4(t1)
	sw t3, -4(t0)
	lw t0 -8(a0)
	addi t0, t0, 1
	sw t0 -8(a0)
	add a0, zero, t4
	ret
	
_lkdlist_remove_value_loop_next:
	add t0, zero, t1
	j _lkdlist_remove_value_loop

_lkdlist_remove_value_return:
	addi a0, zero, -1
	ret

## Remove by index
# Receives:
# - a0 -> linked list
# - a1 -> index to remove
#
# Returns:
# - a0 -> removed value
lkdlist_remove_index:
	li t4, 0
	
_lkdlist_remove_index_start:
	lw t0 0(a0)
	beqz t0, _lkdlist_remove_index_return
	bne t4, a1, _lkdlist_remove_index_loop
	lw t3 0(t0) 
	lw t1, -4(t0)
	sw t1, 0(a0)
	lw t0 -8(a0)
	addi t0, t0, 1
	sw t0 -8(a0)
	add a0 zero t3
	ret
	
_lkdlist_remove_index_loop:
	lw t1, -4(t0)				 # Get next node
	beqz t1, _lkdlist_remove_index_return				 # if not found go back to menu
	addi t4, t4, 1
	bne t4, a1, _lkdlist_remove_index_loop_next 	 # If diferent next iteration
	
	lw t3 0(t1)
	lw t2, -4(t1)
	sw t2, -4(t0)
	lw t0 -8(a0)
	addi t0, t0, 1
	sw t0 -8(a0)
	add a0 zero t3
	ret

_lkdlist_remove_index_loop_next:
	add t0, zero, t1
	j _lkdlist_remove_index_loop

_lkdlist_remove_index_return:
	addi a0 zero -1
	ret

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

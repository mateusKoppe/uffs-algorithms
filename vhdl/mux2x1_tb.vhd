-- Code your testbench here
library IEEE;
use IEEE.std_logic_1164.all;

entity TB_MUX2BITS is
end TB_MUX2BITS;

architecture TESTBENCH of TB_MUX2BITS is 
	signal TB_A: std_logic;
    signal TB_B: std_logic;
    signal TB_SEL: std_logic;
    signal TB_S: std_logic;

begin

	SSC4bits: entity work.mux2bits port map(in_a => TB_A, in_b => TB_B, sel => TB_SEL, s => TB_S);
    
    process
    begin
------------ A selected
    	TB_SEL <= '0';

		TB_A <= '1';
        TB_B <= '0';
        wait for 10 ns;

		TB_A <= '0';
        TB_B <= '1';
        wait for 10 ns;

------------ B selected
        TB_SEL <= '1';

		TB_A <= '1';
        TB_B <= '0';
        wait for 10 ns;

		TB_A <= '0';
        TB_B <= '1';
        wait for 10 ns;
        
        wait;

	end process;


end architecture;
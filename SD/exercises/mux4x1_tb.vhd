library IEEE;
use IEEE.std_logic_1164.all;

entity TB_MUX2BITS is
end TB_MUX2BITS;

architecture TESTBENCH of TB_MUX2BITS is 
	signal TB_A: std_logic;
    signal TB_B: std_logic;
    signal TB_C: std_logic;
    signal TB_D: std_logic;

    signal TB_SEL_A: std_logic;
    signal TB_SEL_B: std_logic;
    signal TB_S: std_logic;

begin

	SSC4bits: entity work.mux4bits port map(
        in_a => TB_A,
        in_b => TB_B,
        in_c => TB_C,
        in_d => TB_D,
        sel_a => TB_SEL_A,
        sel_b => TB_SEL_B,
        s => TB_S
    );
    
    process
    begin
------------ A selected
    	TB_SEL_A <= '0';
    	TB_SEL_B <= '0';

		TB_A <= '1';
        TB_B <= '0';
        TB_C <= '0';
        TB_D <= '0';
        wait for 10 ns;

		TB_A <= '0';
        TB_B <= '0';
        TB_C <= '0';
        TB_D <= '0';
        wait for 10 ns;

------------ B selected
        TB_SEL_A <= '1';
        TB_SEL_B <= '0';

        TB_A <= '0';
        TB_B <= '1';
        TB_C <= '0';
        TB_D <= '0';
        wait for 10 ns;

        TB_A <= '0';
        TB_B <= '0';
        TB_C <= '0';
        TB_D <= '0';
        wait for 10 ns;

------------ C selected
        TB_SEL_A <= '0';
        TB_SEL_B <= '1';

        TB_A <= '0';
        TB_B <= '0';
        TB_C <= '1';
        TB_D <= '0';
        wait for 10 ns;

        TB_A <= '0';
        TB_B <= '0';
        TB_C <= '0';
        TB_D <= '0';
        wait for 10 ns;

------------ C selected
        TB_SEL_A <= '1';
        TB_SEL_B <= '1';

        TB_A <= '0';
        TB_B <= '0';
        TB_C <= '0';
        TB_D <= '1';
        wait for 10 ns;

        TB_A <= '0';
        TB_B <= '0';
        TB_C <= '0';
        TB_D <= '0';
        wait for 10 ns;
        
        wait;

	end process;


end architecture;
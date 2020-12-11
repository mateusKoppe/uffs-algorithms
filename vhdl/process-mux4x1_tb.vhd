library IEEE;
use IEEE.std_logic_1164.all;

entity TB_MUX2BITS is
end TB_MUX2BITS;

architecture TESTBENCH of TB_MUX2BITS is 
	signal TB_A: std_logic_vector(3 downto 0);
    signal TB_B: std_logic_vector(3 downto 0);
    signal TB_C: std_logic_vector(3 downto 0);
    signal TB_D: std_logic_vector(3 downto 0);
    signal TB_SEL: std_logic_vector(1 downto 0);
    signal TB_S: std_logic_vector(3 downto 0);

begin

	SSC4bits: entity work.mux4bits port map(
        in_a => TB_A,
        in_b => TB_B,
        in_c => TB_C,
        in_d => TB_D,
        sel => TB_SEL,
        s => TB_S
    );
    
    process
    begin
------------ A selected
    	TB_SEL <= "00";

		TB_A <= "1111";
        TB_B <= "0000";
        TB_C <= "0000";
        TB_D <= "0000";
        wait for 10 ns;

		TB_A <= "0000";
        TB_B <= "0000";
        TB_C <= "0000";
        TB_D <= "0000";
        wait for 10 ns;

------------ B selected
        TB_SEL <= "01";

        TB_A <= "0000";
        TB_B <= "1111";
        TB_C <= "0000";
        TB_D <= "0000";
        wait for 10 ns;

        TB_A <= "0000";
        TB_B <= "0000";
        TB_C <= "0000";
        TB_D <= "0000";
        wait for 10 ns;

------------ C selected
        TB_SEL <= "10";

        TB_A <= "0000";
        TB_B <= "0000";
        TB_C <= "1111";
        TB_D <= "0000";
        wait for 10 ns;

        TB_A <= "0000";
        TB_B <= "0000";
        TB_C <= "0000";
        TB_D <= "0000";
        wait for 10 ns;

------------ C selected
        TB_SEL <= "11";

        TB_A <= "0000";
        TB_B <= "0000";
        TB_C <= "0000";
        TB_D <= "1111";
        wait for 10 ns;

        TB_A <= "0000";
        TB_B <= "0000";
        TB_C <= "0000";
        TB_D <= "0000";
        wait for 10 ns;
        
        wait;

	end process;


end architecture;

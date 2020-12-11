library IEEE;
use IEEE.std_logic_1164.all;

entity mux4bits is
	port(
    	in_a, in_b, in_c, in_d: in  std_logic;
        sel_a, sel_b : in  std_logic;
        s : out std_logic
    );
end entity;

architecture struct of mux4bits is
    signal connector_a: std_logic;
    signal connector_b: std_logic;
    begin
	    SSC4bitsa: entity work.mux2bits port map(in_a => in_a, in_b => in_b, sel => sel_a, s => connector_a);
        SSC4bitsb: entity work.mux2bits port map(in_a => in_c, in_b => in_d, sel => sel_a, s => connector_b);
	    SSC4bitsc: entity work.mux2bits port map(in_a => connector_a, in_b => connector_b, sel => sel_b, s => s);
    end
architecture;
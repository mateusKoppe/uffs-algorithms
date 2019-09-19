library IEEE;
use IEEE.std_logic_1164.all;

entity mux2bits is
	port(
    	in_a, in_b: in  std_logic;
        sel       : in  std_logic;
        s         : out std_logic
    );
end entity;

architecture struct of mux2bits is
    begin    
        s <= (not sel and in_a) or (sel and in_b);    
    end
architecture;
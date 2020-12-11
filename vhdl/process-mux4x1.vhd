library IEEE;
use IEEE.std_logic_1164.all;

entity mux4bits is
	port(
    	in_a, in_b, in_c, in_d: in  std_logic_vector(3 downto 0);
        sel: in  std_logic_vector(1 downto 0);
        s: out std_logic_vector(3 downto 0)
    );
end entity;

architecture struct of mux4bits is
    begin
        process (sel, in_a, in_b, in_c, in_d) is begin
            case (sel) is
                when "00" =>
                    s <= in_a;
                when "01" =>
                    s <= in_b;
                when "10" =>
                    s <= in_c;
                when others =>
                    s <= in_d;
            end case;
        end process;
	end 
struct;
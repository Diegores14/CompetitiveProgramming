with Ada.Text_IO;
with Ada.Long_Long_Float_Text_IO;

procedure ProbA is
    A : String(1..100);
    longitud : Natural;
    I : Integer := 1;
    ans, p : Long_Long_Float := 0.0;
begin
    Ada.Text_IO.Get_Line(A, longitud);
    Ada.Long_Long_Float_text_IO.Get(p);
    MyLoop:
    loop
        if I > longitud then
            exit MyLoop;
        end if;
        if A(I) = '1' then 
            ans := ans + 1.0;
        end if;
        if A(I) = '?' then 
            ans := ans + p;
        end if;
        I := I + 1;
    end loop MyLoop;
    ans := ans / Long_Long_Float(longitud);
    Ada.Long_Long_Float_Text_IO.Put(Item => ans, Aft => 5, Exp => 0);
end ProbA;

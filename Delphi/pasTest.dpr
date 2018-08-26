program pasTest;

uses
    SysUtils, {for time function}
    Unit1 in 'Unit1.pas' {Needed for Delphi};

{$R *.RES}

const
     UPPER = 20 ;
     ARRAYUPPER = UPPER - 1 ;

   { Index prints at each 1e7 for the Pentium3
	   Limit is 10e7 to test for an even distribution of random() numbers }
var
   limit,       // the value to randomize and cast
	 target,      // the target value
	 i : integer ;
	 num : integer = -1 ;    // initial value to start the loop

	 index : longint = 1 ;   // number of times through the loop
   // array to track the number of times each number appears
	 count : array[0..ARRAYUPPER] of longint ;  

begin
   // set default values
	 target := UPPER ;
   limit := UPPER ;
   Randomize ;

   writeln('Time: ', TimeToStr(Time)) ;
   while (num <> target) and (index <= 100000000) do
   begin
	    num := random(limit) ;
		 // print out result at each 1e7 times through the loop
		 if (index mod 10000000 = 0) then
        begin
		   writeln('Index is ', index) ;
		   writeln('Number is ', num)
		   end ;
		 inc(index) ;
		 inc(count[num]) ;
	 end ;

     { print out the final values if the loop ended early,
		  i.e. by reaching the target value }
	 if (index < 10e7) then
	   begin
	   writeln('Final index is ', index - 1) ;
	   writeln('Final number is ', num)
	   end ;

	 { print out the final distribution of the cast values; they should be
	   present in about equal numbers if the random function really is random }
   for i := 0 to ARRAYUPPER do
      writeln('Count [', i, '] is ', count[i]) ;

   writeln('Time: ', TimeToStr(Time)) ;
end.

// Dec 20, 2000 -- run time is ~10 sec
// Dec 21, 2000 -- run time is ~10 sec

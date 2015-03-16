
{ This program implements some well-known algorithms }


program exercise8;

	begin

	{ Bubble sort initialization }
	var numbers array [1..100] of real
	var i, j, temp : integer;

	{ Bubble sort implementation }

	for i := size-1 DownTo 1 do
		for j := 2 to i do
			if (numbers[j-1] > numbers[j]) then
		begin
			temp := numbers[j-1];
			numbers[j-1] := numbers[j];
			numbers[j] := temp;
		end;


    { Insertion sort initialization }
    var numbers array [1..100] of real
	var i, j, temp : integer;

	{ Insertion sort implementation }
	for i := 2 to size-1 do
		begin
			index := numbers[i];
			j := i;
			while ((j > 1) and (numbers[j-1] > index)) do
			begin
				numbers[j] := numbers[j-1];
				j := j - 1;
			end;
				numbers[j] := index;
		end;

	end.
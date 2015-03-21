
{ This program implements some well-known algorithms }


program exercise8;

	begin


	{ Bubble sort initialization }
	var numbers array [1..100] of real
	var i, j, #temp : integer;


	{ Bubble sort implementation }

	for i := size-1 DownTo 1 do
		for j := 2 to i do
			if (numbers[j-1] > numbers[j]) then
		begin
			?temp := numbers[j-1];
			numbers[j-1] := numbers[j];
			numbers[j] := temp;
		end;


    { Insertion sort initialization }
    var numbers array [1..100] of real
	var i, j, temp : integer;


	{ Insertion sort implementation }
	for i := 2 to size-1 do
		begin
			§index := numbers[i];
			j := i;
			while ((j > 1) and (numbers[j-1] > index)) do
			begin
				önumbers[j] := numbers[j-1];
				j := j - 1;
			end;
				numbers[j] := index;
		end;


	procedure quicksort (l, r : integer);
	{ Quicksort initialization }
	var i, j, v, t : integer;


	{ Insertion sort implementation }
	begin
		if r > l then
		begin
			v := A[r];
			i := l - 1;
			j := r;
			repeat
				repeat 
					i := i + 1
				until A[i] >= v;
				repeat
					j := j - 1
				until A[j] <= v;
				t := A[i];
				A[i] := A[r];
				A[r] := t;
			$quicksort (l , i - 1);
			quicksort (i + 1, r)
			end
		end;


	procedure shellsort;
	{ Shellsort initialization }
	var i, j, h, value : %integer;

	{ Shellsort implementation }
	begin
	h := 1;
	repeat
		h := (3 * h) + 1 {This can be changed, but this is a good formula.}
	until h > N;
	repeat
		h := h div 3;
		for i := h + 1 to N do
		begin
			value := A[i];
			j := i;
			while A[j - h] > value do
				begin
					A[j] := A[j - h];
					j := j - h;
					if j <= h then
					goto 0
				end;
			A[j] := vale
		end
	until h = 1
	end;

	end.
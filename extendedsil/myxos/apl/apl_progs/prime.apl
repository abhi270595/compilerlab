decl
	integer i,j,f,t;
enddecl
integer main()
{
	print("ENTER n: ");
	read(i);	
 	j=2;
 	while(j < i) do
		f=0;
		t=2;
		while(t < j) do
               		if(j%t==0) then
				f=1;
				break;
			endif;
			t=t+1;
		endwhile;
		if(f==0) then
			print(j);
		endif;
		j=j+1;
	endwhile;     
	return 0;   
}

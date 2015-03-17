decl
	integer lseek,write,fd1,fd2,fd3,status,close;	
	string row,value;
	integer even,odd,i,value1,value2;
enddecl

integer main()
{

	// Even
	status = Create("even.dat");
	
	fd1 = Open("even.dat");

	i = 2;
	
	while(i <= 1000) do

		write = Write(fd1,i);
		i = i + 2;
	
	endwhile;

	close = Close(fd1);

	// Odd
	status = Create("odd.dat");
	
	fd2 = Open("odd.dat");

	i = 1;
	
	while(i <= 1000) do

		write = Write(fd2,i);
		i = i + 2;
	
	endwhile;

	close = Close(fd2);

	// Merge
	status = Create("merge.dat");
	
	fd1 = Open("even.dat");
	fd2 = Open("odd.dat");
	fd3 = Open("merge.dat");
	
	lseek = Seek(fd1,0);
	lseek = Seek(fd2,0);

	value1 = Read(fd1,even);
	value2 = Read(fd2,odd);

	while(value1 != -1 || value2 != -1) do
		
		print(odd);
		print(even);
		write = Write(fd3,odd);
		write = Write(fd3,even);
		value1 = Read(fd1,even);
		value2 = Read(fd2,odd);
		
	endwhile;	
	
	close = Close(fd1);
	close = Close(fd2);
	close = Close(fd3);

	return 0;
}

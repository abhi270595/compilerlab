decl
	integer lseek,write,fd1,fd2,fd3,status,close;	
	string row,value;
	integer even,odd,i,value1,value2,delete;
enddecl

integer main()
{

	// a.dat
	status = Create("a.dat");
	
	fd1 = Open("a.dat");

	i = 1;
	
	while(i <= 10000) do

		write = Write(fd1,i);
		i = i + 1;
	
	endwhile;

	close = Close(fd1);

	// b.dat
	status = Create("b.dat");
	
	fd1 = Open("a.dat");
	fd2 = Open("b.dat");

	integer j;
	j=1;

	i = i - 1;

	while((i - j) >= 0) do
		
		print(j);
		lseek = Seek(fd1,i-j);
		value1 = Read(fd1,even);
		write = Write(fd2,even);
		j = j + 1;
		
	endwhile;	
	
	close = Close(fd1);
	close = Close(fd2);

	// Deleting a.dat
	delete = Delete("a.dat");

	return 0;
}

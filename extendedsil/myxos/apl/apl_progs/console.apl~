decl
	integer pid,status,status1;
	string filename;
enddecl

integer main()
{
	while(1 == 1) do
		
		print("File Name :");
		read(filename);
		if(filename == "exit") then
			break;
		endif;

		pid = Fork();
			
		if(pid != -2) then
			status = Wait(pid);
		endif;	

		if(pid == -2) then
			status1 = Exec(filename);
		endif;
	
	endwhile;	

	return 0;
}

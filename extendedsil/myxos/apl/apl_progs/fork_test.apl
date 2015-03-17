decl
	integer pid,PID,PPID,status;
enddecl

integer main()
{
	print("Before Fork");
	pid = Fork();
	PID = Getpid();
	PPID = Getppid();
	if(pid == -2) then
		status = Wait(0);	
	endif;
	print("PID :");
	print(PID);
	print("PPID : ");
	print(PPID);
	print("After Fork");
	return 0;
}

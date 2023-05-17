#CREATING A SIMPLE.
Our interest is to create a basic shell which has the ability to print a prompt and wait for end users to enter command then print what has been input.

For this to be a success we need_
# BOILERPLATE
# ACTIVATE A PROMPT
# CREATE READING AND PRINTING
# ACTIVATION OF OUTPUT
# HAS TO COMPILE 
# CREATING INFINITE LOOP
# BE ABLE TO EXIT
# CREATE PARSING COMMANDS
# MEMORY ALLOCATION (DYNAMICALLY)
#
# FUNCTIONS NEEDED
>access_: it check user's permissions for a
>       file.DESCRIPTION_ checks whether the calling process can access the file
>              pathname.  If pathname is a symbolic link, it is dereferenced
>
>
>
>
>chdir_:It changes working directory. DESCRIPTION_changes
>       the current working directory of the calling
>       process to the directory specified in path.
>
>
>
>close_:close a file descriptor. DESCRIPTION_close()
>       closes a file descriptor, so that it no longer refers to
>       any file and may be reused.  Any record locks (see fcntl(2)) held
>       on the file it was associated with, and owned by the process, are
>       removed (regardless of the file descriptor that was used to obtain the lock).
>
>
>
>closedir_:It closes a directory. DESCRIPTION_ The closedir()
>       function closes the directory stream associated
>       with dirp.  A successful call to closedir() also closes the
>       underlying file descriptor associated with dirp.  The directory
>       stream descriptor dirp is not available after this call
>
>
>
>execve_:It executes program. DESCRIPTION_ execve() execute
>       the program referred to by pathname.  This
>       causes the program that is currently being run by the calling
>       process to be replaced with a new program, with newly initialized
>       stack, heap, and (initialized and uninitialized) data segments.
>
>
>
>exit_: cause normal process termination. DESCRIPTION_The exit()
>       function causes normal process termination and the
>       least significant byte of status (i.e., status & 0xFF) is
>       returned to the parent
>
>
>
>_exit_: _Exit - terminate the calling process. DESCRIPTION_ _exit()
>       terminates the calling process "immediately".  Any open
>       file descriptors belonging to the process are closed.  Any
>       children of the process are inherited by init(1) (or by the
	nearest "subreaper" process as defined through the use of the
        prctl(2) PR_SET_CHILD_SUBREAPER operation).  The process's parent
>       is sent a SIGCHLD signal.
>fflush
	>fork
	>free
	>getcwd
	>getline
	>getpid
	>isatty
	>kill
	>malloc
	>open
	>opendir
	>perror
	>read
	>readdir
	>signal
	>stat (__xstat)
	>lstat
	>fstat
	>strtok
	>wait
	>waitpid
	>wait3
	>wait4
	>write

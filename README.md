#CREATING A SIMPLE.
Our interest is to create a basic shell which has the ability to print a prompt and wait for end users to enter command then print what has been input.

For this to be a success we need_
# BOILERPLATE CODE
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
>
>
>fflush_:flush a stream. DESCRIPTION_For output streams, fflush() forces a write of
>        all user-space buffered data for the given output or update
>        stream via the stream's underlying write function.
>        For input streams associated with seekable files (e.g., disk
         files, but not pipes or terminals), fflush() discards any
>        buffered data that has been fetched from the underlying file, but
>        has not been consumed by the application.
>        The open status of the stream is unaffected.
>        If the stream argument is NULL, fflush() flushes all open output
         streams.


>fork_:it creates a child process. DESCRIPTION_fork() creates a new process
>      by duplicating the calling process. The new process is referred to as
>      the child process.  The calling process is referred to as the parent process.
>
>
>free_:It allocates and free dynamic memory. DESCRIPTION_The malloc() function
>     allocates size bytes and returns a pointer to the allocated memory.
>     The memory is not initialized. If size is 0, then malloc() returns either
>     NULL, or a unique pointer value that can later be successfully passed to free().
>     The free() function frees the memory space pointed to by ptr, which must have
>     been returned by a previous call to malloc(), calloc() or realloc(). Otherwise,
      or if free(ptr) has already been called before, undefined behavior occurs.
      If ptr is NULL, no operation is performed.


>getcwd_:get current working directory.DESCRIPTION_ These functions return a
>        null-terminated string containing an absolute pathname that is the
>        current working directory of the calling process.  The pathname is
>        returned as the function result
>        and via the argument buf, if present
>
>
>getline_: delimited string input. DESCRIPTION_ getline() reads an entire line
>          from stream, storing the address of the buffer containing the text
>          into *lineptr.  The buffer is null-terminated and includes the
>          newline character, if one was found.
>
>
>getpid_: It gets process identification. DESCRIPTION_getpid() returns the
>       process ID (PID) of the calling process.(This is often used by routines
        that generate unique temporary filenames.)
        getppid() returns the process ID of the parent of the calling process.
	This will be either the ID of the process that created
>       this process using fork(), or, if that process has already
>       terminated, the ID of the process to which this process has been
>       reparented (either init(1) or a "subreaper" process defined via
	the prctl(2) PR_SET_CHILD_SUBREAPER operation)


>isatty_: tests whether a file descriptor refers to a terminal. DESCRIPTION_The isatty()
>         function tests whether fd is an open file descriptor
>         referring to a terminal.
>
>
>kill_: sends signal to a process. DESCRIPTION_The kill() system call can be used to send
>      any signal to any process group or process.
>
>
>malloc_: allocates and free dynamic memory. DESCRIPTION_The malloc() function
>        allocates size bytes and returns a pointer to the allocated memory.
>        The memory is not initialized.  If size is 0, then malloc() returns
>        either NULL, or a unique pointer value that can later be successfully
>        passed to free().
>
>
>open_: opens and possibly creates a file. DESCRIPTION_The open() system call opens
>       the file specified by pathname.  If the specified file does not exist,
	it may optionally (if O_CREAT is specified in flags) be created by open()


>opendir_: it opens a directory. DESCRIPTION_The opendir() function opens a directory
>          stream corresponding to the directory name, and returns a pointer to the
>          directory stream.  The stream is positioned at the first entry in the
>          directory.
>
>
>perror_: print a system error message. DESSCRIPTION_The perror() function produces
>         a message on standard error describing the last error encountered during
>         a call to a system or library function
>
>
>read_: read from a file descriptor. DESCRIPTION_read() attempts to read up to count
>       bytes from file descriptor fd into the buffer starting at buf.
>
>
>readdir_:It reads a directory. DESCRIPTION_The readdir() function returns a pointer
>         to a dirent structure representing the next directory entry in the directory
>         stream pointed to by dirp.  It returns NULL on reaching the end of the
>         directory stream or if an error occurred.
>
>
>signal_: ANSI C signal handling. DESCRIPTION_WARNING: the behavior of signal() varies
>         across UNIX versions and has also varied historically across different versions
>         of Linux.  Avoid its use: use sigaction(2) instead.  See Portability below.
>         signal() sets the disposition of the signal signum to handler,
	  which is either SIG_IGN, SIG_DFL, or the address of a programmer-
	  defined function (a "signal handler").


>stat (__xstat)_: gets file status. DESCRIPTION_These functions return information about a file,
	          in the buffer pointed to by statbuf.  No permissions are required on the file
>                 itself, but—in the case of stat(), fstatat(), and lstat()—execute
>                 (search) permission is required on all of the directories in
>                 pathname that lead to the file.
>
>
>lstat_:get file status. DESCRIPTION_These functions return information about a file.
>       No permissions are required on the file itself, but-in the case of stat()
	and lstat() - execute (search) permission is required on all of the directories
	in path that lead to the file.


>fstat_:gets file status. DESCRIPTION_ These functions return information about a file.
>       No permissions are required on the file itself, but-in the case of stat() and
>       lstat() - execute (search) permission is required on all of the directories in
>       path that lead to the file.
>
>
>strtok_:extract tokens from strings. DESCRIPTION_The strtok() function breaks
>        a string into a sequence of zero or more nonempty tokens.
>        On the first call to strtok(), the string to be parsed should be
>        specified in str.  In each subsequent call that should parse the same
>        string, str must be NULL.
>
>
>wait_:it waits for process to change state. DESCRIPTION_All of these system calls
>      are used to wait for state changes in a child of the calling process,
       and obtain information about the child whose state has changed.
       A state change is considered to be: the child terminated;
       the child was stopped by a signal; or the child was resumed by a signal.
       In the case of a terminated child, performing a wait allows the system
       to release the resources associated with the child; if a wait is not performed,
       then the terminated child remains in a "zombie" state


>waitpid_:wait for process to change state. DESCRIPTION_All of these system calls
>         are used to wait for state changes in a child of the calling process,
	  and obtain information about the child whose state has changed.
	  A state change is considered to be: the child terminated;
	  the child was stopped by a signal; or the child was resumed by a signal.
	  In the case of a terminated child, performing a wait allows the system to
	  release the resources associated with the child; if a wait is not performed,
	  then the terminated child remains in a "zombie" state


>wait3_:wait for process to change state, BSD style. DESCRIPTION_These functions
>       are obsolete; use waitpid(2) or waitid(2) in new programs.
>       The wait3() and wait4() system calls are similar to waitpid(2),
	but additionally return resource usage information about the
	child in the structure pointed to by rusage.


>wait4_: wait for process to change state, BSD style. DESCRIPTION_These functions
>        are nonstandard; in new programs, the use of waitpid(2)
>        or waitid(2) is preferable.
>
>
>write_:write to a file descriptor. DESCRIPTION_write() writes up to count bytes
>       from the buffer starting at buf to the file referred to by
>       the file descriptor fd.

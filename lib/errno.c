#include <string.h>
#include <stdlib.h>

#include "include/stdio.h"
#include "include/bdos.h"
#include "include/stdlib.h"


extern int errno;


void clearerr ( FILE * stream )
{
	stream->ErrNo = EOK;
}

void perror ( const char * str )
{
	switch(errno)
	{
		case EOK:
			break;
		case EPERM:
			fprintf(stderr, "\n\rERRNO(%d) - Operation not permitted: %s\n\r",
				errno, str);
		break;
		case ENOENT:
			fprintf(stderr, "\n\rERRNO(%d) - No such file or directory: %s\n\r",
				errno, str);
		break;
		case EIO:
			fprintf(stderr, "\n\rERRNO(%d) - Input/output error: %s\n\r",
				errno, str);
		break;
		case EBADF:
			fprintf(stderr, "\n\rERRNO(%d) - Bad file descriptor: %s\n\r",
				errno, str);
		break;
		case EOPNOTSUPP:
			fprintf(stderr, "\n\rERRNO(%d) - Operation not supported %s\n\r",
				errno, str);
		break;
		default:
			fprintf(stderr, "\n\rERRNO(%d) - Unknown error: %s\n\r",
				errno, str);
		break;

	}
}

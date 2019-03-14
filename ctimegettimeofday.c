#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

int main() {
	//https://stackoverflow.com/questions/3673226/how-to-print-time-in-format-2009-08-10-181754-811
	//https://blog.habets.se/2010/09/gettimeofday-should-never-be-used-to-measure-time.html
	//https://www.reddit.com/r/programming/comments/2surcq/gettimeofday_should_never_be_used_to_measure_time/
	char buffer[26];
	int millisec;
	struct tm* tm_info;
	struct timeval tv;

	gettimeofday(&tv, NULL);

	millisec = lrint(tv.tv_usec/1000.0); // Round to nearest millisec
	if (millisec>=1000) { // Allow for rounding up to nearest second
		millisec -=1000;
		tv.tv_sec++;
	}

	tm_info = localtime(&tv.tv_sec);

	strftime(buffer, 26, "%Y:%m:%d %H:%M:%S", tm_info);
	printf("%s.%03d\n", buffer, millisec);

	return 0;
}
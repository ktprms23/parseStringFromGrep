#include <stdio.h>

#define RED_BOLD "\x1b[;31;1m"
#define RESET "\x1b[0;m"

/**
 * Search the string in the file or folder
 * @param file the file or folder will be searched
 * @param parseS the string to be searched
 */
void parsingDataFromFile( const char * file, const char * parseS ) {

	char command[256] = {0};
	sprintf( command, "grep -Rs \"%s\" %s", parseS, file );
	printf( "[GREP] Execute command: %s\n", command );
	FILE *grepCommandExe = popen( command, "r" );

	if( grepCommandExe == NULL ) {
		printf( "[GREP] Can't execute command\n" );
		pclose(grepCommandExe);
		return;
	} // end if 

	char buf[256];
	while( fgets(buf, sizeof(buf), grepCommandExe) ) {
		printf( RED_BOLD"[GREP] Get result: %s\n"RESET, buf );
	} // end while
	pclose(grepCommandExe);

} // end function parsingDataFromFile



int main(void) {

	parsingDataFromFile( "file1.txt", "string" );
	parsingDataFromFile( "file1.txt", "string 0" );
	parsingDataFromFile( "file2.txt", "string" );
	parsingDataFromFile( "file2.txt", "s1 123" );

	parsingDataFromFile( ".", "string" );

	return 0;
} // end main

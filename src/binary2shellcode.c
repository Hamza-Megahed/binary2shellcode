/*
 ============================================================================
 Name        : binary2shellcode.c
 Author      : Hamza Megahed
 Version     : 2.0
 Copyright   : Copyright 2012-2013 Hamza Megahed
 Description : Binary to Shellcode converter on Linux
 ============================================================================
 */
/*
 ============================================================================
   This file is part of binary2shellcode.

    binary2shellcode is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    binary2shellcode is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with binary2shellcode.  If not, see <http://www.gnu.org/licenses/>.
 ===========================================================================
*/
/********************************* Headers *********************************/

#include <stdio.h>
#include <stdlib.h>
/*==========================================================================*/

int main(int argc, char *argv[]) {

/********************************* Local Variables **************************/
	char v[500] ;
	char v2[100];
	FILE *ft;
/*==========================================================================*/

		/*check in there is no input file .. argc < 2*/
		/*if no file input then exit normally */

	/*clean screen*/

	system("clear");

	printf("\n");
	printf("\t////////////////////////////////////////////////////\n");
	printf("\t///////// Binary to Shellcode Converter ////////////\n");
	printf("\t////////////////////////////////////////////////////\n");
	printf("\n");
	/* test if there is no input file */

	if(argc == 1)
	{
		printf("Usage: %s InputBinaryFile\n", argv[0]);
		exit(0);
	}

	/*open file to test for exist*/

	ft = fopen(argv[1], "r");
	if (!ft) {
		printf("Unable to open file: %s\n", argv[1]);
	exit(-1);
	}
	fclose(ft);

	printf("\t\t\tBinary Name = %s\n", argv[1]);
	printf("    size in bytes = \n");


	/*use sprintf to concat the command with argv[] and put all of it in v */


	snprintf(v2,100, "size %s | grep  '[0-9]' | cut -f4 ", argv[1]);

	snprintf (v,500, "objdump -D %s |grep '[0-9a-f]:'|grep -v 'file'|cut -f2 -d:|cut -f1-6 -d' '|tr -s ' '|tr '\t' ' '|sed 's/ $//g'|sed 's/ /\\\\x/g'|paste -d '' -s", argv[1]);

	/* use system () to execute the command line inside v */
	system(v2);
	printf("\n");
	printf("    Shellcode = \n\n");
	system(v);
	printf("\n");
	/* Exit normally */
	return EXIT_SUCCESS;
}

#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>




void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);



/**
 * check_elf - Set to checks if a file is an ELF file.
 * @e_ident: The pointer to an array containing the ELF magic numbers.
 * Description: Once the file is not an ELF file - exit code 98.
 */

void check_elf(unsigned char *e_ident)
{
	int base;

	for (base = 0; base < 4; base++)
	{
		if (e_ident[base] != 127 &&
		    e_ident[base] != 'E' &&
		    e_ident[base] != 'L' &&
		    e_ident[base] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Set to print the magic
 * numbers of an ELF header.
 * @e_ident: The pointer to an array
 * that will contain the ELF magic numbers.
 *
 * Description: The magic numbers are separated by spaces.
 */

void print_magic(unsigned char *e_ident)
{
	int gent;

	printf(" Magic: ");

	for (gent = 0; gent < EI_NIDENT; gent++)
	{
		printf("%02x", e_ident[gent]);

		if (gent == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Set to prints the class of an ELF header.
 * @e_ident: The pointer to an array containing the ELF class.
 */

void print_class(unsigned char *e_ident)
{

	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}



/**
 * print_data - Set to prints the data of an ELF header.
 * @e_ident: The pointer to an array containing the ELF class.
 */


void print_data(unsigned char *e_ident)
{

	printf(" Data: ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}


/**
 * print_version - Set to prints the
 * version of an ELF header.
 * @e_ident: The pointer to an array containing the ELF version.
 */


void print_version(unsigned char *e_ident)
{

	 printf(" Version: %d",
			  e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}


/**
 * print_osabi - Set to prints the OS/ABI
 * of an ELF header.
 * @e_ident: The pointer to an array that
 * will contain the ELF version.
 */


void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

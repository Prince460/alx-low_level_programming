#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void print_type(unsigned int e_type, unsigned char *e_ident);
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);


/**
 * print_abi - Set to print the ABI
 * version of an ELF header.
 * @e_ident: The pointer to an array that will
 * contain the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{

	printf(" ABI Version: %d\n",
	e_ident[EI_ABIVERSION]);
}


/**
 * print_type - Set to print the type of an ELF header.
 * @e_type: ELF type.
 * @e_ident: The pointer to an array that will
 * contain the ELF class.
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	e_type >>= 8;

	printf(" Type: ");

	switch (e_type)
	{
	case ET_NONE:
	printf("NONE (None)\n");
		break;
	case ET_REL:
	printf("REL (Relocatable file)\n");
	break;
	case ET_EXEC:
	printf("EXEC (Executable file)\n");
	break;
	case ET_DYN:
	printf("DYN (Shared object file)\n");
	break;
	case ET_CORE:
	printf("CORE (Core file)\n");
	break;
	default:
	printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Set to prints the entry point of an ELF header.
 * @e_entry: Address of the ELF entry point.
 * @e_ident: The pointer to an arraythat will
 * containing the ELF class.
 */


void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
	e_entry = ((e_entry << 8) & 0xFF00FF00) |
		((e_entry >> 8) & 0xFF00FF);
	e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
	printf("%#x\n", (unsigned int)e_entry);

	else
	printf("%#lx\n", e_entry);
}

/**
 * close_elf - Set to close an ELF file.
 * @elf:File descriptor of the ELF file.
 * Description: Once the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
	dprintf(STDERR_FILENO,
	"Error: Can't close fd %d\n", elf);
	exit(98);
	}
}


/**
 * main - Set to display the information contained
 * in the ELF header at the start of an ELF file.
 * @argc: The list of arguments supplied to the program.
 * @argv: The array of pointers to the arguments.
 * Return: 0 on success.
 * Description: Once the file is not an ELF File
 * or the function fails - exit code 98.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{

	Elf64_Ehdr *header;
	int f, k;

	f = open(argv[1], O_RDONLY);
	if (f == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
	exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
	close_elf(f);
	dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
	exit(98);
	}
	k = read(f, header, sizeof(Elf64_Ehdr));
	if (k == -1)
	{
	free(header);
	close_elf(f);
	dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
	exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(f);
	return (0);
}

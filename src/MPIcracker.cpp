#include <iostream>
#include <vector>
#include <mpi.h>

#include <getopt.h>

#include "Messages.h"
#include "Logger.h"
#include "PasswordFile.h"
#include "Dictionary.h"

#include <bitset>

int main(int argc, char *argv[])
{
	std::shared_ptr<Logger> LOGGER = std::make_shared<Logger>();

	LOGGER->Info("Main program execution started.");

	std::cout << PROGRAM_NAME << " " << PROGRAM_VERSION << " by " << PROGRAM_AUTHOR << std::endl;
	std::cout << RIGHTS << std::endl;

	if (argc == 1)
	{
		return 0;
	}

	std::shared_ptr<PasswordFile> passwordFile = std::make_shared<PasswordFile>(LOGGER);
	if (!passwordFile->Initialize())
	{
		LOGGER->Info("Exiting.");

		std::cout << "ERROR: Password file could not be opened." << std::endl;
		return 0;
	}

	std::shared_ptr<Dictionary> dictionary = std::make_shared<Dictionary>(LOGGER);
	dictionary->Initialize();

	//std::bitset<16> foo = 16;
	//std::bitset<16> bar(std::string("0101111001"));

	//std::cout << "foo: " << foo << '\n';
	//std::cout << "bar: " << bar << '\n';

	LOGGER->Info("Initializing MPI");
	MPI_Init(NULL, NULL);

	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int taskid;
	MPI_Comm_rank(MPI_COMM_WORLD, &taskid);

	printf("MPI task %d has started...\n", taskid);

	MPI_Finalize();
	LOGGER->Info("MPI Finalized");
	std::vector<int> v;

	LOGGER->Info("Exiting.");
}
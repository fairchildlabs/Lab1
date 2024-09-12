
#include <scootd.h>




scoot_device * scootd_util_open_shared_memory(char *strFileName)
{

	int shm_fd;
	char *shm_ptr;
	
	// Create shared memory object
	shm_fd = shm_open(strFileName, O_CREAT | O_RDWR, 0666);
	if (shm_fd == -1) 
	{
			perror("shm_open");
			exit(1);
	}
	
	// Set the size of shared memory
	if (ftruncate(shm_fd, sizeof(scoot_device)) == -1) 
	{
			perror("ftruncate");
			exit(1);
	}
	
		// Map the shared memory object into the process address space
	shm_ptr = mmap(0, sizeof(scoot_device), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if (shm_ptr == MAP_FAILED) 
	{
			perror("mmap");
			exit(1);
	}

	return (scoot_device *)shm_ptr;


}





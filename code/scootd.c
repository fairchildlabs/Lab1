#include <scootd.h>





int main(int argc, char **argv)
{

	scoot_device scootDevice;

	printf("scootd - Lab1\n");

	scootDevice.state = 0;

	scootd_util_open_shared_memory("scootd_shared.mem");
	


	return 0;
}



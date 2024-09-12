#include <scootd.h>





int main(int argc, char **argv)
{
	unsigned int old_state = 0;
	scoot_device *pScootDevice;

	printf("scootd - Lab1\n");

	scootDevice.state = 0;

	pScootDevice = scootd_util_open_shared_memory("scootd_shared.mem");

	if(pScootDevice)
	{
		while(1)
		{
			if(old_state != pScootDevice->state)
			{
				printf("State Change old_state = %d new_state = %d\n", old_state, pScootDevice->state);
				old_state = pScootDevice->state;
				sleep(1);
			}

		}

	}


	return 0;
}



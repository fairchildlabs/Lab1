#include <scootd.h>





int main(int argc, char **argv)
{
	unsigned int old_state = 0;
	scoot_device aScootDevice;

	printf("scootd - Lab1\n");

	pScootDevice->state = 0;


	if(	scootd_util_open_shared_memory("scootd_shared.mem", &aScootDevice))
	{
		printf("Error opening shared memory\n");
	}
	else
	{
		while(1)
		{
			if(old_state != aScootDevice.pState->state)
			{
				printf("State Change old_state = %d new_state = %d\n", old_state, aScootDevice.pState->state);
				old_state = aScootDevice.pState->state;
				sleep(1);
			}

		}

	}


	return 0;
}



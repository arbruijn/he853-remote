#include <stdlib.h>
#include <stdio.h>
#include "he853.h"

int main(int argc, char **argv)
{
	if (argc < 3) {
		printf("%s: deviceId command\n", argv[0]);
		return 1;
	}
	int deviceId = atoi(argv[1]);
	int command = atoi(argv[2]);
	HE853Controller *remote = new HE853Controller();
	if (!remote->getDeviceStatus())
		return 1;
	printf("Sending command[%i] to deviceId[%i]\n", command, deviceId);
	remote->sendEU((uint16_t)deviceId, (uint8_t)command);
	return 0;
}

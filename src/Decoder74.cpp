#include "Decoder74.h"



std::vector<uint8_t> Decoder74::Decode(const std::vector<uint8_t> &kData)
{
	std::vector<uint8_t> tmp(7), Output(4);
	uint8_t S = 0;
	if (kData.size() != 7) return kData;
	for (int i = 0; i < 7; i++) tmp[i] = kData[i];
	
	S |= (kData[0] ^ kData[1] ^ kData[2] ^ kData[4]) << 2;
	S |= (kData[1] ^ kData[2] ^ kData[3] ^ kData[5]) << 1;
	S |= (kData[0] ^ kData[1] ^ kData[3] ^ kData[6]) << 0;
	

	switch (S)
	{
		case 1:
			tmp[6] = tmp[6] ^ 1;
			break;	
		case 2:
			tmp[5] = tmp[5] ^ 1;
			break;
		case 3:
			tmp[3] = tmp[3] ^ 1;
			break;
		case 4:
			tmp[5] = tmp[5] ^ 1;
			break;
		case 5:
			tmp[0] = tmp[0] ^ 1;
			break;
		case 6:
			tmp[2] = tmp[2] ^ 1;
			break;
		case 7:
			tmp[1] = tmp[1] ^ 1;
			break;
		default:
			break;	
	}
	for(int i = 0; i < 4; i++) Output[i] = tmp[i];
	return Output;
}


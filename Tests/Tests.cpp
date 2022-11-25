#include <iostream>
#include "gtest/gtest.h"

#include <locale>
#include <Decoder74.h>

void TestDecode()
{
	std::vector<uint8_t> input = { 0, 1, 1, 0, 0, 0, 1}, output(4);
	std::cout << "Input Vector" << std::endl;
	for (int i = 0; i < 7; i++) std::cout <<  (int) input[i] << ' ';
	std::cout << std::endl << std::endl << "Output Vector" << std::endl;
	Decoder74 decoder;
    output = decoder.Decode(input);
	for (int i = 0; i < 4; i++) std::cout << (int)output[i] << ' ';
	std::cout << std::endl;
}


TEST(testVector, testDecode){
	
	std::vector<uint8_t> vectorInput = { 0, 1, 0, 0, 1, 1, 1 }, vectorRef = { 0, 1, 0, 0 }, vectorOutput(4);
	Decoder74 decoder;
    vectorOutput = decoder.Decode(vectorInput);

	for (int i = 0; i < 4; i++) {
		ASSERT_EQ(vectorOutput[i], vectorRef[i]) << "Ошибка";
	}
}

int main(int argc, char **argv)
{
	setlocale(LC_ALL, "Russian");
	TestDecode();
	
    /*
    Coder *coder = new Coder74();
    coder->Encode(input);*/

	
    ::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

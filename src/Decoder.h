#ifndef DECODER_H
#define DECODER_H

#include <cstdint>
#include <vector>

class Decoder
{
    public:
        virtual std::vector<uint8_t> Decode(const std::vector<uint8_t> &kData) = 0;
    protected:
    private:
};

#endif // DECODER_H

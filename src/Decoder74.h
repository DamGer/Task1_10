#ifndef DECODER74_H
#define DECODER74_H

#include "Decoder.h"

class Decoder74 : public Decoder
{
    public:
        virtual std::vector<uint8_t> Decode(const std::vector<uint8_t> &kData);
    protected:
    private:
};

#endif // DECODER74_H

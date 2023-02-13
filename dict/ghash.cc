//
// Created by root on 10/16/22.
//
#include "ghash.h"
#include "common.h"
namespace inforefiner{
    namespace model{
        static long primes[16] = {0x01EE5DB9, 0x491408C3, 0x0465FB69, 0x421F0141,0x2E7D036B, 0x2D41C7B9, 0x58C0EF0D, 0x7B15A53B,0x7C9D3761, 0x5ABB9B0B, 0x24109367, 0x5A5B741F,0x6B9F12E9, 0x71BA7809, 0x081F69CD, 0x4D9B740B};
        long GHash::gHash(const std::string &s){
            long sum=0;
            const unsigned char * bt = (const unsigned char*)s.c_str();
            int i=0;
            while(*bt) {
                sum += primes[i & 15] * getUnit32(*bt++);
                i++;
            }
            return getUnit32(sum);
        }
    }
}

//
// Created by root on 10/16/22.
//

#ifndef INFOREFINER_MODEL_GHASH_H
#define INFOREFINER_MODEL_GHASH_H
namespace inforefiner {
    namespace model{
        class GHash {
            long getUnit32(long d) {
                long ret = 4294967296;
                if (d >= 0) {
                    return d;
                } else {
                    return ret + d;
                }
            }
        public:
            long gHash(const std::string &s);
        };
    }
}
#endif //INFOREFINER_MODEL_GHASH_H

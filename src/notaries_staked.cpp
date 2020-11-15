
#include "notaries_staked.h"
#include "crosschain.h"
#include "cc/CCinclude.h"
#include "komodo_defs.h"
#include <cstring>

extern pthread_mutex_t staked_mutex;

int8_t is_STAKED(const char *chain_name) 
{
    return 0;
};

int32_t STAKED_era(int timestamp)
{
  return(0);
};

int8_t StakedNotaryID(std::string &notaryname, char *Raddress) {
    return(-1);
}

int8_t numStakedNotaries(uint8_t pubkeys[64][33],int8_t era) {
    return 0;
}

void UpdateNotaryAddrs(uint8_t pubkeys[64][33],int8_t numNotaries) {
}

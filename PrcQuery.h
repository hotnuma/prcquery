#ifndef PRCQUERY_H
#define PRCQUERY_H

#include "PrcList.h"

class PrcQuery
{
public:

    PrcQuery();

    bool execute(int argc, char **argv);

private:

    PrcList _prclist;

};

#endif // PRCQUERY_H



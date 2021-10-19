#include "libapp.h"
#include "PrcQuery.h"

int main(int argc, char **argv)
{
    PrcQuery query;

    if (!query.execute(argc, argv))
        return 1;

    return 0;
}



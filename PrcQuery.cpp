#include "PrcQuery.h"

#include <libapp.h>
#include <libfile.h>
#include <libpath.h>

#include <print.h>

enum class ExecCmd
{
    None,
    Export
};

PrcQuery::PrcQuery()
{
}

bool PrcQuery::execute(int argc, char **argv)
{
    CString homeDir = getHomeDirectory();
    CString outpath = pathJoin(getHomeDirectory(), "ps_aux.txt");

    int n = 1;
    while (n < argc)
    {
        const CString &part = argv[n];

        if (part == "-o")
        {
            if (++n >= argc)
                return false;

            outpath = argv[n];
        }
        else
        {
            print("*** Invalid option.");
            return false;
        }

        n++;
    }

    if (!_prclist.queryAll())
    {
        print("*** PrcList error.");
        return false;
    }

    _prclist.writeTxt(outpath);

    return true;
}



#include "PrcList.h"
#include "PrcEntry.h"

#include <CFile.h>
#include <CProcess.h>
#include <stdlib.h>

#include <print.h>

DELETEFUNC(PrcEntry)

PrcList::PrcList()
{
    SETDELETEFUNC(&_entryList, PrcEntry);
}

bool PrcList::queryAll()
{
    CString cmd = "ps aux";

    CProcess process;
    if (!process.start(cmd, CP_PIPEOUT))
    {
        print("start failed");

        return -1;
    }

    int status = process.exitStatus();

    if (status != 0)
    {
        print("program returned : %d", status);

        return -1;
    }

    char *ptr = process.outBuff.data();
    CString line;
    int count = 0;

    while (strGetLine(&ptr, line))
    {
        if (count > 0)
        {
            _addEntry(line);

            //print(line);
        }

        ++count;
    }

    return true;
}

bool PrcList::_addEntry(const CString &line)
{
    PrcEntry *entry = new PrcEntry();

    if (!entry->readLineTxt(line))
    {
        delete entry;
        return false;
    }

    print(entry->name);

    _entryList.append(entry);

    return true;
}

bool PrcList::writeTxt(const CString &filepath)
{
    CFile outfile;

    if (!outfile.open(filepath, "wb"))
        return false;

    PrcEntry::writeHeaderTxt(outfile);

    int size = _entryList.size();

    for (int i = 0; i < size; ++i)
    {
        PrcEntry *entry = (PrcEntry*) _entryList[i];
        entry->writeLineTxt(outfile);
    }

    return true;
}



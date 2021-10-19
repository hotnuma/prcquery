#include <stdlib.h>
#include "print.h"
#include "CFile.h"
#include "PrcEntry.h"
#include "PrcList.h"

DELETEFUNC(PrcEntry)

PrcList::PrcList()
{
    SETDELETEFUNC(&_entryList, PrcEntry);
}

bool PrcList::queryAll()
{
    FILE *inpipe;

    if ((inpipe = popen("ps aux", "r")) == nullptr)
    {
        perror("popen");
        return false;
    }

    CString line(1024);
    int count = 0;

    while (fgets(line.data(), line.capacity(), inpipe))
    {
        if (count > 0)
        {
            line.terminate();
            _addEntry(line);
        }

        ++count;
    }

    pclose(inpipe);

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

//    if (entry->name == "prcquery.exe"
//        || entry->name == "tasklist.exe"
//        || entry->name == "VBoxTray.exe"
//        || entry->name == "VBoxService.exe")
//    {
//        delete entry;
//        return true;
//    }

//    PrcEntry *found = (PrcEntry*) _find(entry->name);

//    if (found)
//    {
//        found->pid = "";
//        found->count += 1;
//        found->memory += entry->memory;

//        delete entry;
//        return true;
//    }

    _entryList.append(entry);

    return true;
}

//PrcEntry* PrcList::_find(const CString &name)
//{
//    if (name == "")
//        return nullptr;

//    int size = _entryList.size();
//    for (int i = 0; i < size; ++i)
//    {
//        PrcEntry *entry = (PrcEntry*) _entryList[i];

//        if (entry->name == name)
//            return entry;
//    }

//    return nullptr;
//}

bool PrcList::write(const CString &filepath)
{
    CFile outfile;

    if (!outfile.open(filepath, "wb"))
        return false;

    PrcEntry::writeHeaderCsv(outfile);

    int size = _entryList.size();

    for (int i = 0; i < size; ++i)
    {
        PrcEntry *entry = (PrcEntry*) _entryList[i];
        entry->writeLineCsv(outfile);
    }

    return true;
}

//bool PrcList::_writeBuffer(const CString &filepath, const CString &buffer)
//{
//    if (filepath.endsWith(".xls", false))
//    {
//        CString buff = strconv(buffer, CP_UTF8, 1252);
//        if (buff.isEmpty())
//            return false;

//        fileWrite(filepath, buff);
//    }
//    else
//    {
//        fileWrite(filepath, buffer);
//    }

//    return true;
//}



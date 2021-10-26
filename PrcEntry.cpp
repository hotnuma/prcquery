#include "PrcEntry.h"
#include <libstr.h>
#include <ctype.h>

#include <print.h>

#define SEP_TAB     "\t"
#define SEP_SPACE   " "

#define COL_NAME    16
#define COL_USER    8
#define COL_PID     7

bool strEllipsize(CString &str, int length)
{
    if (length < 4)
        return false;

    int size = str.size();

    if (size <= length)
        return false;

    length -= 3;
    str.terminate(length);
    str.append("...");

    return true;
}

bool strPadRight(CString &str, int length, char c)
{
    int delta = length - str.size();

    if (length < 1 || delta < 1)
        return false;

    str.resize(length + 1);

    for (int i = 0; i < delta; ++i)
    {
        str.append(c);
    }

    return true;
}

const char* strCommand(const char *path)
{
    if (!path || !*path)
        return nullptr;

    const char *p = path;
    const char *cmd = path;

    while (1)
    {
        if (*p == '/')
        {
            cmd = ++p;
            continue;
        }
        else if (*p == ' ' || *p == '\0')
        {
            return cmd;
        }

        ++p;
    }
}

PrcEntry::PrcEntry()
{
}

bool PrcEntry::readLineTxt(const CString &buffer)
{
    if (buffer.isEmpty())
        return false;

    int nparts = 10;

    char *ptr = buffer.data();
    char *part;
    int len;

    int count = 0;
    while (count < nparts && strGetPart(&ptr, &part, &len))
    {
        part[len] = '\0';

        switch (count)
        {
        case 0:
            user = part;
            break;
        case 1:
            pid = part;
            break;
        }

        //print(result);

        ++count;
    }

    while(isspace(*ptr)) ++ptr;

    // end of buffer ?
    if (*ptr == '\0')
        return -1;

    if (ptr[0] == '[')
        return false;

    command = strCommand(ptr);
    name = strBaseName(command);

    if (name == "bash"
        || name == "ps"
        || name == "prcquery")
    {
        return false;
    }

    return true;
}

bool PrcEntry::writeHeaderTxt(CFile &outfile)
{
    CString col;

    col = "Name";
    strPadRight(col, COL_NAME, ' ');
    outfile << col;

    outfile << SEP_SPACE;

    col = "User";
    strPadRight(col, COL_USER, ' ');
    outfile << col;

    outfile << SEP_SPACE;

    col = "Pid";
    strPadRight(col, COL_PID, ' ');
    outfile << col;

    outfile << SEP_SPACE;

    outfile << "Command";

    outfile << "\n";

    return true;
}

bool PrcEntry::writeLineTxt(CFile &outfile)
{
    strEllipsize(name, COL_NAME);
    strPadRight(name, COL_NAME, ' ');
    outfile << name;

    outfile << SEP_SPACE;

    strEllipsize(user, COL_USER);
    strPadRight(user, COL_USER, ' ');
    outfile << user;

    outfile << SEP_SPACE;

    strEllipsize(pid, COL_PID);
    strPadRight(pid, COL_PID, ' ');
    outfile << pid;

    outfile << SEP_SPACE;

    outfile << command;

    outfile << "\n";

    return true;
}

bool PrcEntry::writeLineCsv(CFile &outfile)
{
    outfile << name;
    outfile << SEP_TAB;
    outfile << user;
    outfile << SEP_TAB;
    outfile << pid;
    outfile << SEP_TAB;
    outfile << command;

    outfile << "\n";

    return true;
}



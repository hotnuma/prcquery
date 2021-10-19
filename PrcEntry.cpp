#include <ctype.h>
#include "Global.h"
#include "PrcEntry.h"

#include <print.h>

PrcEntry::PrcEntry()
{
}

bool PrcEntry::readLineTxt(const CString &buffer)
{
    if (buffer.isEmpty())
        return false;

    CString part(128);

    int count = 0;
    const char *start = buffer.c_str();
    const char *p = start;

    while (1)
    {
        if (count == 10)
        {
            part.clear();
            part.append(start);
            part.chop(1);

            if (!part.startsWith("["))
            {
                command = part;

                print("command = %s", command.c_str());

                return true;
            }

            return false;
        }
        else if (*p == ' ' /*|| *p == '\n'*/)
        {
            part.clear();
            part.append(start, p - start);

            switch (count)
            {
            case 0:
                user = part;
                break;

            case 1:
                pid = atoi(part);
                break;
            }

            while (*p == ' ') ++p;
            start = p;
            ++count;
        }

        if (*p == '\n' || *p == '\0')
        {
            print("error");
            break;
        }

        ++p;
    }

    return false;
}

//bool PrcEntry::readBufferCsv(const CString &buffer)
//{
//    CStringList cols = buffer.split("\",\"");
//    int size = cols.size();

//    if (size != 5)
//        return false;

//    name = cols[0];
//    pid = cols[1];
//    type = cols[2];

//    CString temp = cols[4];
//    int len = temp.size();
//    CString result;

//    for (int i = 0; i < len; ++i)
//    {
//        char c = temp[i];
//        if (isdigit((int) c))
//            result.append(temp[i]);
//    }

//    memory = result.toInt();

//    return true;
//}

bool PrcEntry::writeHeaderCsv(CFile &outfile)
{
    outfile << "User";

    outfile << SEP_TAB;
    outfile << "Pid";

    outfile << SEP_TAB;
    outfile << "Command";

    outfile << "\n";

    return true;
}

bool PrcEntry::writeLineCsv(CFile &outfile)
{
    outfile << user;

    outfile << SEP_TAB;
    outfile << intToStr(pid);;

    outfile << SEP_TAB;
    outfile << command;

    outfile << "\n";

    return true;
}



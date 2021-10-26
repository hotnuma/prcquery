#if 0

//    if (entry->name == "gnome-keyring-daemon")
//    {
//        entry->name = "GnomeKeyring";
//    }
//    else if (entry->name == "polkit-gnome-authentication-agent-1")
//    {
//        entry->name = "Policykit-1";
//    }
//    else if (entry->name == "ayatana-indicator-application-service")
//    {
//        entry->name = "AyatanaIndicator";
//    }
//    else if (entry->name == "gvfs-udisks2-volume-monitor")
//    {
//        entry->name = "GvfsUdisk2";
//    }


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

            if (!part.startsWith("["))
            {
                command = part;

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

bool PrcEntry::readBufferCsv(const CString &buffer)
{
    CStringList cols = buffer.split("\",\"");
    int size = cols.size();

    if (size != 5)
        return false;

    name = cols[0];
    pid = cols[1];
    type = cols[2];

    CString temp = cols[4];
    int len = temp.size();
    CString result;

    for (int i = 0; i < len; ++i)
    {
        char c = temp[i];
        if (isdigit((int) c))
            result.append(temp[i]);
    }

    memory = result.toInt();

    return true;
}

bool PrcList::_writeBuffer(const CString &filepath, const CString &buffer)
{
    if (filepath.endsWith(".xls", false))
    {
        CString buff = strconv(buffer, CP_UTF8, 1252);
        if (buff.isEmpty())
            return false;

        fileWrite(filepath, buff);
    }
    else
    {
        fileWrite(filepath, buffer);
    }

    return true;
}

#endif



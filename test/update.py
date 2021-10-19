import os

basedir = os.path.dirname(__file__)

prcquery = os.path.join(basedir, "../build/prcquery.exe")
outpath = os.path.join(basedir, "prclist.xls")

cmd = "%s -o \"%s\"" % (prcquery, outpath)

os.system(cmd)

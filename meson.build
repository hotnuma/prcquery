project(
    'prcquery',
    ['cpp'],
    version : '1.0',
    license : 'GPL-2.0',
    default_options : [
        'cpp_std=c++11',
    ],
)

cpp_args = [
    '-Wall',
    '-fno-rtti',
    '-fno-exceptions',
    '-O2',
]

app_deps = [
    dependency('tinycpp', static : true),
]

app_src = [
    'main.cpp',
    'PrcEntry.cpp',
    'PrcList.cpp',
    'PrcQuery.cpp',
]

executable(
    'prcquery',
    cpp_args : cpp_args,
    dependencies : app_deps,
    sources : app_src,
    install : true,
)



## ELF header reader

read needed libraries and rpath info from elf header.

## Compile:
```
make
```

## Run:
```
./elf_reader shared_object/executables
```

## Example:

```
command:
readelf -d /bin/ls

output:
Dynamic section at offset 0x1fa38 contains 28 entries:
  Tag        Type                         Name/Value
 0x0000000000000001 (NEEDED)             Shared library: [libselinux.so.1]
 0x0000000000000001 (NEEDED)             Shared library: [libc.so.6]
 0x000000000000000c (INIT)               0x3758
 0x000000000000000d (FINI)               0x1636c
 0x0000000000000019 (INIT_ARRAY)         0x21eff0
 0x000000000000001b (INIT_ARRAYSZ)       8 (bytes)
 0x000000000000001a (FINI_ARRAY)         0x21eff8
 0x000000000000001c (FINI_ARRAYSZ)       8 (bytes)
 0x000000006ffffef5 (GNU_HASH)           0x298
 0x0000000000000005 (STRTAB)             0x1180
 0x0000000000000006 (SYMTAB)             0x388
 0x000000000000000a (STRSZ)              1666 (bytes)
 0x000000000000000b (SYMENT)             24 (bytes)
 0x0000000000000015 (DEBUG)              0x0
 0x0000000000000003 (PLTGOT)             0x21fc38
 0x0000000000000002 (PLTRELSZ)           2664 (bytes)
 0x0000000000000014 (PLTREL)             RELA
 0x0000000000000017 (JMPREL)             0x2cf0
 0x0000000000000007 (RELA)               0x19a0
 0x0000000000000008 (RELASZ)             4944 (bytes)
 0x0000000000000009 (RELAENT)            24 (bytes)
 0x000000000000001e (FLAGS)              BIND_NOW
 0x000000006ffffffb (FLAGS_1)            Flags: NOW PIE
 0x000000006ffffffe (VERNEED)            0x1930
 0x000000006fffffff (VERNEEDNUM)         1
 0x000000006ffffff0 (VERSYM)             0x1802
 0x000000006ffffff9 (RELACOUNT)          193
 0x0000000000000000 (NULL)               0x0

command:
./elf_reader /bin/ls

output:
rpath:
libs needed: libselinux.so.1:libc.so.6
```


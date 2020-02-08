#include "elf_reader.h"

int main(int argc, char *argv[]){
    assert(argc > 1);

    int fd = open(argv[1], O_RDONLY);
    assert(fd);

    Elf64_Ehdr *header; //elf header
    size_t size = read(fd, (void *)header, sizeof(Elf64_Ehdr));
    assert(size);

    if(header->e_ident[EI_MAG0] == '\177' && header->e_ident[EI_MAG1] == 'E' && header->e_ident[EI_MAG2] == 'L' && header->e_ident[EI_MAG3] == 'F'){
        if(header->e_ident[EI_CLASS] == ELFCLASS64){
            printf("ELF64 header\n");
        }
        if(header->e_ident[EI_DATA] == ELFDATA2LSB){
            printf("Litte endian\n");
        }
        //shared object
        if(header->e_type == ET_DYN){
            printf("section num:%d \n",header->e_shnum);
        }else{
            printf("e_type is not ET_DYN");
            return -1;
        }
    }else{
        printf("%s is not a valid ELF",argv[1]);
        return -1;
    }
    return 0;
}

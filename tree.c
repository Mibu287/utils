#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <colorterm.h>

int check_dir(const char *path)
{
    /*check if path is folder or not 
    return -1 and set errno on error
    return 1 if path is directory
    return 0 otherwise
    */

    struct stat buffer;
    int rc = stat(path, &buffer);
    if(rc == -1)
        return -1;
        
    return S_ISDIR(buffer.st_mode);
}

void print_path(const char *path, const char *format, int level, int tabswidth)
{
    /*print path with format and indent*/
    char indent[level * tabswidth + 1];

    for(int i = 0; i < (level - 1) * tabswidth; ++i)
        indent[i] = ' ';

    indent[(level - 1) * tabswidth] = '|';
        
    for(int i = (level - 1) * tabswidth + 1; i < level * tabswidth; ++i)
        indent[i] = '-';

    indent[level * tabswidth] = '\0';

    printf("%s%s%s%s\n", format, indent, path, STYLE_RESET_ALL);
}

int tree(const char *parent_path, const char *child_path, int level)
{
    /* print file/folder name recursively
    return 0 on succes
    return -1 and set errno on failure */

    /*check if path is directory or not */
    char full_path[strlen(parent_path) + strlen(child_path) + 2];
    strcpy(full_path, parent_path);

    if(strcmp(parent_path, "") != 0)
        strcat(full_path, "/");

    strcat(full_path, child_path);

    int is_dir = check_dir(full_path);
    if(is_dir == -1)
        return -1;

    /*print file name*/
    if(!is_dir){
        print_path(child_path, FG_RESET, level, 4);
        return 0;
    }

    /*recursively print folder*/
    print_path(child_path, FG_MAGENTA, level, 4);

    DIR *dirptr = opendir(full_path);
    if(!dirptr)
        return -1;

    struct dirent *de = NULL;
    while((de = readdir(dirptr)) != NULL){
        const char *new_path = de->d_name;
        int cmp = strcmp(new_path, ".") * strcmp(new_path, "..");
        if(cmp == 0)
            continue;

        int rc = tree(full_path, new_path, level + 1);
        if(rc == -1){
            closedir(dirptr);
            return -1;
        }
    }

    closedir(dirptr);
    return 0;
}
 
int main(int argc, char *argv[])
{
    if(argc == 1){
        fprintf(stderr, "%s: No path is supplied\n", ERROR);
        return -1;
    }

    const char *path = argv[1];
    int rc = tree("", path, 0);

    if(rc == -1){
        const char *err_msg = strerror(errno);
        fprintf(stderr, "%s%s\n", ERROR, err_msg);
        return -1;
    }

    return 0;
}

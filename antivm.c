#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <dirent.h>

int main(void)
{
    //Registry key checks
    HKEY key;
    
    // Core count   
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("Hardware\\Description\\System\\CentralProcessor\\2"), 0, KEY_QUERY_VALUE, &key) == ERROR_SUCCESS)
        printf("Probably not vm System has two or more cores\n");
    else
        printf("VM detected system run on 1 core\n");

            printf("\n-----------------------------------------------------------------------\n");
    //Vmware Tools
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\VMware, Inc.", 0, KEY_QUERY_VALUE, &key) == ERROR_SUCCESS)
        printf("VM detected Registry found in HKEY_LOCAL_MACHINE\\SOFTWARE\\VMware, Inc. \n");
    else 
        printf("Vm not detected from Registry Keys \n");
            printf("\n-----------------------------------------------------------------------\n");

    
    //Vm Dll Search 
    int i=0;    
    DIR *d;
    struct dirent *dir;
    printf("Vm files under System32 :\n");
    d = opendir("C:\\windows\\system32");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if(strncmp(dir->d_name,"vm",2)==0)
            printf("\n%s ", dir->d_name);
            i++;
        }
        closedir(d);
    }
    if(i==0) printf("Vm files doesnt exist under System32 :");
         printf("\n-----------------------------------------------------------------------\n\n");
    
    //Vm Driver file Search 
    int p =0;   
    DIR *t;
    struct dirent *dirr;
    printf("Driver files :\n");
    t = opendir("C:\\windows\\system32\\drivers");
    if (t)
    {
        while ((dirr = readdir(t)) != NULL)
        {
            if(strncmp(dirr->d_name,"vm",2)==0)
            printf("\n%s ", dirr->d_name);
            p++;
        }
        closedir(t);
    }
    if(p==0) printf("Vm driver files doesnt exist:");
    printf("\n-----------------------------------------------------------------------\n\n");
    
    //Vmware processleri lisleme
    printf("Searching for Vm process\n");
    char *taskbul= "tasklist/fi \"imagename eq vmtoolsd.exe\"";
    system(taskbul);
    //Vmware servisleri 
    printf("\n------------------------------------------------------------------\n");
    printf("Searching for Vm services \n\n");
    char *servisbul = "net start|find \"VM\"";
    system(servisbul);
   
   


    return 0;
}
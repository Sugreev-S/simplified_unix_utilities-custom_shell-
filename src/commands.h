#ifndef COMMANDS_H
#define COMMANDS_H

void custom_ls(const char *path);
void custom_cat(const char *filename);
void custom_grep(const char *pattern, const char *filename);
void custom_wc(const char *filename);
void custom_cp(const char *source, const char *destination);
void custom_mv(const char *source, const char *destination);
void custom_rm(const char *filename);
//void custom_pipe(const char *command);
void custom_cd(const char *path);   
void custom_clear();                 
void custom_whoami();              
void custom_echo(const char *text); 
void custom_touch(const char *filename); 
void custom_pwd();


#endif // COMMANDS_H

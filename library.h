#include <stdbool.h>
void show_loading_bar();
int get_console_width();
void set_color(int color);
void print_centered(const char *text);
void print_options(const char *text);
void bus();
int traveloption();
int homexit();
int travordash();
void userdash();
void welcome_screen();
void seatdesign(int ns,char *foundseat);
void moneydeduct(char *id,char *nbalanceforfile);
void markseatvisited();
void markseatvisited(char *foundseat,int seatcheck,char *storebus);
void alltrain();
bool trainpayment(char *seatprice);

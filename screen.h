#define UNICODE
//constant definitions 
enum COLORS{BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, PINK};
#define bg(c) (c+10) //macro difinition
// function declarations 
void clearScreen(void); 
void setColors(short fg, short bg); 
void resetColors(void);
void barChart(int arr[]);

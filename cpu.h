extern int cpuBusy; //1==busy, 0==not busy
void run(int quanta);

struct CPU{
        char IR[1000];  //instruction register (currently executing instruction)
        int IP;         //points to next instruction to be executed from ram
        int quanta;     //quanta is 2 lines of code for each program
};


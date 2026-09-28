#ifndef PASYSTEM_H
#define PASYSTEM_H

//  GoF Participant: Adaptee - Adapter pattern.
//      Legacy PA system: incompatible interface (C-string + priority code,
//      returns an int status code) vs. the void sendAlert(string) that
//      CommsSystem (the Target) expects. 
class PaSystem {
public:
    int broadcast(const char* message, int priorityCode); // 0 = success, non-zero = legacy failure code
};

#endif

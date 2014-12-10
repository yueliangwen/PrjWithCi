#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_handler(int sig_no) {
    exit(1);
}

__attribute__((constructor))
void initialer() {
    struct sigaction sa;
    sa.sa_handler = sig_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESETHAND;
    if (-1 == sigaction(SIGINT, &sa, NULL) || 
            -1 == sigaction(SIGQUIT, &sa, NULL) || 
            -1 == sigaction(SIGTERM, &sa, NULL)) {
        // log
    }
}


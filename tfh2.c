#include <stdio.h>

#define MAX 100  
typedef struct {
    int n;
    char from, to, aux;
} Frame;

Frame stack[MAX];
int top = -1;


void push(Frame f) {
    if (top < MAX - 1) {
        stack[++top] = f;
    }
}


Frame pop() {
    return stack[top--];
}

int isEmpty() {
    return (top == -1);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

   
    push((Frame){n, 'A', 'C', 'B'});

    while (!isEmpty()) {
        Frame f = pop();

        if (f.n == 1) {
            printf("Move disk 1 from %c to %c\n", f.from, f.to);
        } else {
            
            push((Frame){f.n - 1, f.aux, f.to, f.from});  // Step 3
            push((Frame){1, f.from, f.to, f.aux});        // Step 2 (move single disk)
            push((Frame){f.n - 1, f.from, f.aux, f.to});  // Step 1
        }
    }

    return 0;
}

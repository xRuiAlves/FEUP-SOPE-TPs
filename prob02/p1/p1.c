#include <termios.h>
#include <unistd.h>
#include <string.h>

#define PASSWORD_LEN 50

int main(){
	struct termios t1, t2;
	char password[PASSWORD_LEN];
	char ch;
	
	write(STDOUT_FILENO , "Enter your password: " , strlen("Enter your password: "));

	// Read current Terminal status and save it in t2
	tcgetattr(STDIN_FILENO , &t1);
	t2 = t1;

	// Prevent character echoing
	t1.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
	tcsetattr(STDIN_FILENO , TCSAFLUSH , &t1);

	int i=0;

	// Read the password, echoing * in each character written
	while(i<PASSWORD_LEN && read(STDIN_FILENO, &ch, 1) && ch != '\n'){
		write(STDOUT_FILENO , "*" , 1);
		password[i] = ch;
		i++;
	}
	password[i] = '\0';

	// Print out the password for the user
	write(STDOUT_FILENO , "\nThe password written was ", strlen("\nThe password written was "));
	write(STDOUT_FILENO , password , strlen(password));
	write(STDOUT_FILENO , "\n" , 1);

	// Restore Terminal status
	tcsetattr(STDIN_FILENO , TCSANOW , &t2);
	

	return 0;
}

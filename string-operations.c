// Maria Apostolopoulou 1117202100016
//
// Πρόγραμμα σε γλώσσα C που δίνει τη δυνατότητα:
//   α) αναζήτησης ενός χαρακτήρα σε αλφαριθμητικό (string)
//   β) αντικατάστασης ενός χαρακτήρα σε string με έναν άλλο
//   γ) εντοπισμού καρκινικών επιγραφών (παλίνδρομων φράσεων)
//
// Η main χρησιμοποιεί switch με 4 επιλογές (cases). Το flag ελέγχει τον
// τερματισμό του μενού (case 4). Η input διαβάζεται με fgets αντί για το
// (μη ασφαλές / καταργημένο) gets.

#include <stdio.h>
#include <string.h>

void replace_char(char *str, char from, char to); // αντικατάσταση χαρακτήρα
int  is_palindrome(const char *str);              // έλεγχος παλίνδρομου

// διαβάζει μια γραμμή με ασφάλεια και αφαιρεί το newline στο τέλος
void read_line(char *buf, int size) {
    if (fgets(buf, size, stdin)) {
        buf[strcspn(buf, "\n")] = '\0';
    }
}

int main(void) {
    int flag = 0; // όσο είναι 0 εμφανίζεται ξανά το μενού επιλογών

    while (flag == 0) {
        char str[50];
        char target;
        int choice, i, freq = 0, found = 0;

        printf("\n press 1 for character search\n");
        printf(" press 2 for character change\n");
        printf(" press 3 for palindrome search\n");
        printf(" press 4 for termination\n");
        printf("Enter a number: ");

        if (scanf("%d", &choice) != 1) break;
        getchar(); // καταναλώνει το newline μετά τον αριθμό

        switch (choice) {
            case 1: // αναζήτηση χαρακτήρα στο string
                printf("character search\n");
                printf("Enter the string: ");
                read_line(str, sizeof(str));
                printf("Enter character: ");
                target = getchar();
                getchar();

                printf("Positions of '%c' in \"%s\" are: ", target, str);
                for (i = 0; str[i] != '\0'; i++) {
                    if (str[i] == target) {
                        printf("%d ", i + 1); // 1-based θέση
                        freq++;
                    }
                }
                if (freq > 0)
                    printf("\nCharacter '%c' occurs %d time(s).\n", target, freq);
                else
                    printf("\nNone\n");
                break;

            case 2: { // αντικατάσταση ενός χαρακτήρα με έναν άλλο
                char from, to;
                printf("character change\n");
                printf("Enter the string: ");
                read_line(str, sizeof(str));
                printf("Enter a character to replace: ");
                from = getchar();
                getchar();
                printf("Enter character to replace '%c' with: ", from);
                to = getchar();
                getchar();

                printf("before replace: %s\n", str);
                replace_char(str, from, to);
                printf("after replace:  %s\n", str);
                break;
            }

            case 3: // έλεγχος αν το string είναι παλίνδρομο
                printf("palindrome search\n");
                printf("Enter the string: ");
                read_line(str, sizeof(str));
                if (is_palindrome(str))
                    printf("string is a palindrome\n");
                else
                    printf("string is not a palindrome\n");
                break;

            case 4: // τερματισμός
                flag = 1;
                printf("termination\n");
                break;

            default: // μη έγκυρη επιλογή (π.χ. 5)
                printf("invalid message\n");
                break;
        }

        (void)found; // (διατηρείται για συμβατότητα με το αρχικό σκεπτικό)
    }

    return 0;
}

// αντικαθιστά κάθε εμφάνιση του χαρακτήρα 'from' με τον χαρακτήρα 'to'
void replace_char(char *str, char from, char to) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == from) {
            str[i] = to;
        }
    }
}

// επιστρέφει 1 αν το string είναι παλίνδρομο, αλλιώς 0
// (σύγκριση πρώτου με τελευταίο, δεύτερου με προτελευταίο, κ.ο.κ.)
int is_palindrome(const char *str) {
    int len = (int)strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // βρέθηκε ασυμφωνία -> δεν είναι παλίνδρομο
        }
    }
    return 1;
}

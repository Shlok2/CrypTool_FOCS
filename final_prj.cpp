#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

char cptext[100];

int Input(char[], int);
void encrypt(char[], int);
void decrypt(char[], int);

// Rail Fence Declarations

char cptext1[1000];
char railMatrix[100][1000];

int Input1(char[], int);
void encrypt1(char[], int);
void decrypt1(char[], int);
void prePosses1(char[], int);
void railFenceCipher(char[], int);

// Hill Cipher Declarations

char cptext2[100];

void input2(char[]);
void encrypt2(char[]);
void decrypt2(char[]);

void removeSpaces2(char[]);

// Vigenere Cipher Declarations

char cptext3[100];
char table3[50][50];

void fillTabel3();
void Input3(char[], char[]);
void encrypt3(char[], char[]);
void decrypt3(char[], char[]);
void prePosses3(char[], char[]);
void vigenereCipher(char[], char[]);

// Final Code

int main()
{
    system("COLOR 0A");
    cout << endl
         << endl;
    Sleep(1500);
    cout << "............. You are Entering Cipher Interface .............";
    cout << endl
         << endl;
    Sleep(1500);
    cout << "Group Members: " << endl;
    Sleep(1500);
    printf("\n\n\n\n\t\t(1) Shlok Saraogi (20103285) B10");
    Sleep(1500);
    printf("\n\t\t(2) Srijan Gupta (20103286) B10");
    Sleep(1500);
    printf("\n\t\t(3) Dhruv Jain (20103277) B10");
    Sleep(1500);
    printf("\n\t\t(4) Yashika Kushwaha (20103280) B10");
    Sleep(1500);
    cout << endl
         << endl;

    system("cls");
label:
    cout << endl
         << endl
         << " Choose an algo to Encrypt and Decrypt: ";
    printf("\n\t\t(1) Caesar Cipher");
    printf("\n\t\t(2) Rail Fence");
    printf("\n\t\t(3) Hill Cipher");
    printf("\n\t\t(4) Vigenere");
    printf("\n\t\t(5) Exit");
    cout << endl
         << endl
         << endl;
    int option;
    cout << "\nEnter Your Choice: ";
    cin >> option;

    switch (option)
    {

    case 1:

        printf("\n\t\t Caesar Cipher Interface");
        printf("\n\n");
        int key;
        char str[100];

        int choice;

        printf("\n\t\t(1) Encrypt");
        printf("\n\t\t(2) Decrypt");
        printf("\n\t\t(3) Exit");
        printf("\n\t\tEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            key = Input(str, key);
            encrypt(str, key);
            printf("\n\t\tEncrypt text: %s\n", cptext);
            break;
        case 2:
            key = Input(str, key);
            decrypt(str, key);
            printf("\n\t\tDecrypt text: %s\n", cptext);
            break;
        default:
            exit(0);
            break;
        }
        goto label;
        break;

    case 2:

        char str1[1000];
        int key1;

        printf("\tRail Fence Cipher Algorithm\n");
        printf("\t---------------------------\n");

        railFenceCipher(str1, key1); /* algorithm */
        goto label;
        break;

    case 3:

        char str2[100];
        printf("\n\t\tMonoalphabetic Hill Cipher Algorithm");
        printf("\n\t\t-------------------------------\n");

        int choice2;
        printf("\n\t\t(1) Encrypt");
        printf("\n\t\t(2) Decrypt");
        printf("\n\t\t(3) Exit");
        printf("\n\t\tEnter your choice2: ");
        scanf("%d", &choice2);
        getchar();

        switch (choice2)
        {
        case 1:
            input2(str2);
            encrypt2(str2);
            printf("\n\t\tEncrypt text: %s\n", cptext2);
            break;

        case 2:
            input2(str2);
            decrypt2(str2);
            printf("\n\t\tDecrypt text: %s\n", cptext2);
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("\n\t\t---> Invalid Choice!\n\n");
            break;
        }
        goto label;
        break;

    case 4:

        char str3[100], key3[100];
        vigenereCipher(str3, key3);
        goto label;
        break;

    case 5:
        cout << "............. You are Exiting Cipher Interface .............";
        exit(0);

    default:
        cout << " This is an invalid operation. ";
    }

    return 0;
}

// Caesar Cipher

int Input(char str[], int key)
{
    printf("\n\t\tEnter plain text: ");
    gets(str);
    printf("\t\tEnter key: ");
    scanf("%d", &key);
    return key;
}

void encrypt(char str[], int key)
{
    int in = 0;
    for (int i = 0; str[i]; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            char ch = (str[i] >= 'a' && str[i] <= 'z') ? 'a' : 'A';
            int ind = str[i] - ch;
            ind = (ind + key) % 26;
            cptext[in++] = ind + ch;
        }
        else if (str[i] == ' ')
            cptext[in++] = str[i];
    }
    cptext[in] = '\0';
}

void decrypt(char str[], int key)
{
    int in = 0;
    for (int i = 0; str[i]; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            char ch = (str[i] >= 'a' && str[i] <= 'z') ? 'a' : 'A';
            int ind = str[i] - ch;
            for (int k = 0; k < key; k++)
            {
                if (ind - 1 < 0)
                    ind = 25;
                else
                    ind = ind - 1;
            }
            cptext[in++] = ind + ch;
        }
        else if (str[i] == ' ')
            cptext[in++] = str[i];
    }
    cptext[in] = '\0';
}

// Rail Fence

void railFenceCipher(char str1[], int key1)
{

    int choice1;
    printf("\n\t\t(1) Encrypt");
    printf("\n\t\t(2) Decrypt");
    printf("\n\t\t(3) Exit");
    printf("\n\t\tEnter your choice1: ");
    scanf("%d", &choice1);
    getchar();

    switch (choice1)
    {
    case 1:
        key1 = Input1(str1, key1);
        prePosses1(str1, key1);
        encrypt1(str1, key1);
        printf("\n\t\tEncrypt text: %s\n", cptext1);
        break;
    case 2:
        key1 = Input1(str1, key1);
        prePosses1(str1, key1);
        decrypt1(str1, key1);
        printf("\n\t\tDecrypt text: %s\n", cptext1);
        break;
    default:
        exit(0);
        break;
    }
    // goto label;
}

int Input1(char str1[], int key1)
{
    printf("\n\t\tEnter plain text: ");
    gets(str1);
    printf("\t\tEnter key1: ");
    scanf("%d", &key1);
    return key1;
}

void encrypt1(char str1[], int key1)
{
    int msgLen = strlen(str1);
    int in = 0;
    for (int i = 0; i < key1; ++i)
        for (int j = 0; j < msgLen; ++j)
            if (railMatrix[i][j] != '\n')
                cptext1[in++] = railMatrix[i][j];
    cptext1[in] = '\0';
}

void decrypt1(char str1[], int key1)
{
    int msgLen = strlen(str1);
    int in = 0;
    for (int i = 0; i < key1; ++i)
        for (int j = 0; j < msgLen; ++j)
            if (railMatrix[i][j] != '\n')
                railMatrix[i][j] = str1[in++];

    int row = 0, col = 0, k1 = -1;
    for (int i = 0, in = 0; i < msgLen; ++i)
    {
        cptext1[in++] = railMatrix[row][col++];
        if (row == 0 || row == key1 - 1)
            k1 = k1 * (-1);
        row = row + k1;
    }
    cptext1[in] = '\0';
}

void prePosses1(char str1[], int key1)
{
    int msgLen = strlen(str1);
    int k1 = -1, row = 0, col = 0;

    for (int i = 0; i < key1; ++i)
        for (int j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';

    for (int i = 0; i < msgLen; ++i)
    {
        railMatrix[row][col++] = str1[i];
        if (row == 0 || row == key1 - 1)
            k1 = k1 * (-1);
        row = row + k1;
    }
}

// Hill Cipher

void input2(char str2[])
{
    printf("\n\t\tEnter plain text: ");
    gets(str2);
}

void encrypt2(char str2[])
{
    int key2[][3] = {{3, 10, 20},
                     {20, 9, 17},
                     {9, 4, 17}};
    strlwr(str2);
    removeSpaces2(str2);

    int row2, col2 = 3;
    int len2 = strlen(str2);
    (len2 % 3 == 0) ? row2 = len2 / 3 : row2 = (len2 / 3) + 1;

    int messageVector[row2][col2], indx2 = 0;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2;)
        {
            if (indx2 < len2)
            {
                if (str2[indx2] >= 'a' && str2[indx2] <= 'z')
                {
                    messageVector[i][j] = str2[indx2] - 'a';
                    j++;
                }
            }
            else
            {
                messageVector[i][j] = 'z' - 'a';
                j++;
            }
            indx2++;
        }
    }

    indx2 = 0;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            int c0 = messageVector[i][0] * key2[0][j] + messageVector[i][1] * key2[1][j] + messageVector[i][2] * key2[2][j];
            cptext2[indx2++] = (c0 % 26) + 'a';
        }
    }
    cptext2[indx2] = '\0';
}

void decrypt2(char str2[])
{
    int keyIN[][3] = {{3, 10, 20},
                      {20, 9, 17},
                      {9, 4, 17}};

    int Mirror[][3] = {{85, 90, -10},
                       {-187, -129, -349},
                       {-1, -78, -173}};

    /// ((09*Mirror[][]) % 26)
    int CoFactor[][3] = {{11, 22, 14},
                         {7, 9, 21},
                         {17, 0, 3}};

    strlwr(str2);
    removeSpaces2(str2);

    int row2, col2 = 3;
    int len2 = strlen(str2);
    (len2 % 3 == 0) ? row2 = len2 / 3 : row2 = (len2 / 3) + 1;

    int key2[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            key2[i][j] = ((CoFactor[i][j] % 26 + 26) % 26);
        }
    }

    int messageVector[row2][col2], indx2 = 0;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2;)
        {
            if (indx2 < len2)
            {
                if (str2[indx2] >= 'a' && str2[indx2] <= 'z')
                {
                    messageVector[i][j] = str2[indx2] - 'a';
                    j++;
                }
            }
            else
            {
                messageVector[i][j] = 'z' - 'a';
                j++;
            }
            indx2++;
        }
    }

    indx2 = 0;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            int c0 = messageVector[i][0] * key2[0][j] + messageVector[i][1] * key2[1][j] + messageVector[i][2] * key2[2][j];
            cptext2[indx2++] = (c0 % 26) + 'a';
        }
    }
    cptext2[indx2] = '\0';
}

void removeSpaces2(char str2[])
{
    int count = 0;

    for (int i = 0; str2[i]; i++)
        if (str2[i] != ' ')
            str2[count++] = str2[i];
    str2[count] = '\0';
}
// Vigenere Cipher

void vigenereCipher(char str3[], char key3[])
{

    fillTabel3();

    int choice;
    while (1)
    {
        printf("\n\t\t(1) Encrypt");
        printf("\n\t\t(2) Decrypt");
        printf("\n\t\t(3) Exit");
        printf("\n\t\tEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            Input3(str3, key3);
            prePosses3(str3, key3);
            encrypt3(str3, key3);
            printf("\n\t\tEncrypt text: %s\n", cptext3);
            break;
        case 2:
            Input3(str3, key3);
            prePosses3(str3, key3);
            decrypt3(str3, key3);
            printf("\n\t\tDecrypt text: %s\n", cptext3);
            break;
        default:
            exit(0);
            break;
        }
    }
}

void fillTabel3()
{
    for (int col3 = 0; col3 < 26; col3++)
    {
        for (int row3 = 0; row3 < 26; row3++)
        {
            table3[col3][row3] = ((col3 + row3) % 26) + 'A';
        }
    }
}

void Input3(char str3[], char key3[])
{
    printf("\n\t\tEnter plain text: ");
    gets(str3);
    printf("\t\tEnter key3: ");
    scanf("%s", key3);
}

void encrypt3(char str3[], char key3[])
{
    int in = 0;
    for (int i = 0; str3[i]; i++)
    {
        int col3 = key3[i] - 'A';
        int row3 = str3[i] - 'A';

        if (str3[i] >= 'A' && str3[i] <= 'Z')
        {
            cptext3[in++] = table3[col3][row3];
        }
        else
            cptext3[in++] = str3[i];
    }
    cptext3[in] = '\0';
}

void decrypt3(char str3[], char key3[])
{
    int in = 0;
    for (int i = 0; str3[i]; i++)
    {
        if (str3[i] >= 'A' && str3[i] <= 'Z')
        {
            int col3 = key3[i] - 'A';
            char ch = str3[i];
            int row3 = 0;
            for (int i = 0; i < 26; i++)
            {
                if (table3[col3][i] == ch)
                {
                    row3 = i;
                    break;
                }
            }
            cptext3[in++] = table3[0][row3];
        }
        else
            cptext3[in++] = str3[i];
    }
    cptext3[in] = '\0';
}

void prePosses3(char str3[], char key3[])
{
    strupr(str3);
    strupr(key3);

    int len = strlen(str3);
    int lenKey = strlen(key3);
    int index = lenKey;

    if (len > lenKey)
    {
        for (int i = lenKey; i < len; i++)
        {
            if (str3[i] >= 'A' && str3[i] <= 'Z')
            {
                key3[index++] = key3[i % lenKey];
            }
            else
                key3[index++] = ' ';
        }
        key3[index] = '\0';
    }
    else
        key3[len] = '\0';
}
